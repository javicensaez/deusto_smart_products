#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLE2902.h> // Biblioteca para el descriptor de notificaciones

// Generar UUIDs: https://www.uuidgenerator.net/

#define SERVICE_UUID_RANDOMNUMBER        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_RANDOMNUMBER "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLEServer *pServer;               // Servidor BLE
BLEService *pService;             // Servicio BLE
BLECharacteristic *pCharacteristic; // Característica BLE

uint8_t number = 0;               // Valor numérico que se enviará por BLE

void setup() {
  Serial.begin(115200);           // Iniciar comunicación serial
  Serial.println("Iniciando trabajo con BLE...");

  BLEDevice::init("DeustoESP32-1"); // Inicializar el dispositivo BLE con un nombre único

  pServer = BLEDevice::createServer();  // Crear el servidor BLE
  pService = pServer->createService(SERVICE_UUID_RANDOMNUMBER); // Crear el servicio con el UUID definido
  
  // Crear la característica BLE con propiedades de lectura, escritura y notificación
  pCharacteristic = pService->createCharacteristic(
                                      CHARACTERISTIC_UUID_RANDOMNUMBER,
                                      BLECharacteristic::PROPERTY_READ   |
                                      BLECharacteristic::PROPERTY_WRITE  |
                                      BLECharacteristic::PROPERTY_NOTIFY 
                                       );

  // Agregar un descriptor para habilitar notificaciones en la característica
  pCharacteristic->addDescriptor(new BLE2902());

  // Inicializar el valor de la característica
  pCharacteristic->setValue(String(number).c_str());
  
  pService->start();             // Iniciar el servicio BLE
  pServer->startAdvertising();   // Comenzar a anunciar el servicio para que otros dispositivos lo detecten
  Serial.println("Característica definida. Ahora puedes leerla en tu teléfono!");
}

void loop() {
  number = random(100);          // Generar un número aleatorio entre 0 y 99
  pCharacteristic->setValue(String(number).c_str()); // Actualizar el valor de la característica

  // Si hay dispositivos conectados, enviar una notificación con el nuevo valor
  if(pServer->getConnectedCount() > 0) {
    pCharacteristic->notify();
  }

  delay(5000);                   // Esperar 5 segundos antes de la siguiente actualización
}
