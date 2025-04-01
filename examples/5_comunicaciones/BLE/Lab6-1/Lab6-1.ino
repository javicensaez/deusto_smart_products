#include <BLEDevice.h>
#include <BLEServer.h>

// URL para generar UUIDs: https://www.uuidgenerator.net/

#define SERVICE_UUID_RANDOMNUMBER        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_RANDOMNUMBER "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLEServer *pServer;             // Puntero al servidor BLE
BLEService *pService;           // Puntero al servicio BLE
BLECharacteristic *pCharacteristic; // Puntero a la característica BLE

uint8_t number = 0;             // Valor numérico que se enviará por BLE

void setup() {
  Serial.begin(115200);         // Iniciar comunicación serial
  Serial.println("Comenzando BLE!");

  BLEDevice::init("DeustoESP32-456"); // Inicializar dispositivo BLE con un nombre único
  
  pServer = BLEDevice::createServer(); // Crear el servidor BLE
  
  pService = pServer->createService(SERVICE_UUID_RANDOMNUMBER); // Crear servicio BLE con el UUID definido
  
  // Crear característica BLE con propiedades de lectura y escritura
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_RANDOMNUMBER,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue(String(number).c_str()); // Establecer el valor inicial de la característica
  
  pService->start();            // Iniciar el servicio BLE
  pServer->startAdvertising();  // Iniciar la publicidad BLE para que otros dispositivos puedan encontrarlo
  Serial.println("La característica está definida. Ahora puedes escanearla desde tu móvil");
}

void loop() {
  number = random(100);         // Generar un número aleatorio entre 0 y 99
  pCharacteristic->setValue(String(number).c_str()); // Actualizar el valor de la característica BLE con el nuevo número

  delay(5000);                  // Esperar 5 segundos antes de actualizar nuevamente
}
