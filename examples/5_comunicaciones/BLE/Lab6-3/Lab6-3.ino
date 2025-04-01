#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Definición de UUIDs para el servicio y la característica
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// Clase para manejar eventos de escritura en la característica BLE
class WriteCallback: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      // Obtener el valor escrito por el dispositivo central
      std::string value = pCharacteristic->getValue();

      Serial.print("Valor actualizado (texto): ");
      Serial.println(value.c_str());

      Serial.print("Valor actualizado (primer byte como entero): ");
      // Convertir el primer byte del valor a entero y mostrarlo
      uint8_t intValue = (uint8_t)value[0];
      Serial.println(intValue);
    }
};

void setup() {
  Serial.begin(115200);            // Inicializar la comunicación serial
  BLEDevice::init("DeustoESP32-1");  // Inicializar el dispositivo BLE con un nombre único

  // Crear el servidor BLE
  BLEServer *pServer = BLEDevice::createServer();

  // Crear un servicio BLE con el UUID definido
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Crear una característica BLE con propiedades de lectura y escritura
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  // Asociar la clase WriteCallback para gestionar los eventos de escritura
  pCharacteristic->setCallbacks(new WriteCallback());

  // Establecer un valor inicial para la característica
  pCharacteristic->setValue("Hello there!");

  // Iniciar el servicio BLE
  pService->start();

  // Empezar a anunciar el servicio para que otros dispositivos puedan conectarse
  pServer->startAdvertising();
}

void loop() {
  delay(2000); // Esperar 2 segundos en cada iteración del bucle principal
}
