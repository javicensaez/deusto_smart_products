#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

int wifiTimeOut=10000; //Tiempo de espera a conectarse a una red 10s

void setup() {

  Serial.begin(115200); //Velocidad del terminal

  //Espera 4 segundos a comenzar el programa
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("Esperando %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  //anade todas las redes a las que quieres conectar
  wifiMulti.addAP("smartproduct", "smartproduct");
  wifiMulti.addAP("mimovil", "contrasena");
  wifiMulti.addAP("udmt", "udmt2122");
}

void loop() {
  //Comprueba si estas conectado
  if (wifiMulti.run(wifiTimeOut) == WL_CONNECTED) {
    estadoConectado();
  }
  else {
    estadoDesconectado();
  }
}


void estadoConectado() {
  Serial.print("WiFi connected: ");
  Serial.print(WiFi.SSID());
  Serial.print(" ");
  Serial.println(WiFi.RSSI());
}

void estadoDesconectado() {
  Serial.println("WiFi not connected!");
  delay(1000);
}
