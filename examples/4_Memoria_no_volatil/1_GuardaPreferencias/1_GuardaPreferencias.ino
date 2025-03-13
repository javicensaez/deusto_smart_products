#include <Preferences.h>

Preferences preferences;

void setup()
{
    Serial.begin(115200);
    Serial.println();

    // Abre las preferencias con el espacio de nombres my-app. Cada módulo de aplicación, biblioteca, etc.
    // tiene que usar un nombre de espacio para evitar colisiones de nombres de clave. Abriremos el almacenamiento en
    // modo RW (el segundo parámetro tiene que ser false).
    // Nota: El nombre del espacio de nombres está limitado a 15 caracteres.
    preferences.begin("my-app", false);
    // Almacena la temperatura maximas y minimas
    preferences.putInt("TempMax", 30);
    preferences.putInt("TempMin", 15);

    // Close the Preferences
    preferences.end();

    // Wait 10 seconds
    Serial.println("Resetenado en 10s..");
    delay(10000);

    // Restart ESP
    ESP.restart();
}

void loop()
{
}