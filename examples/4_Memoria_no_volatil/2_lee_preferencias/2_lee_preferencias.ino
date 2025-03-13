#include <Preferences.h>

Preferences preferences;

int temperaturaMax;
int temperaturaMin;


void setup()
{
    Serial.begin(115200);
    Serial.println();

    // Abre las preferencias con el espacio de nombres my-app. Cada módulo de aplicación, biblioteca, etc.
    // tiene que usar un nombre de espacio para evitar colisiones de nombres de clave. Abriremos el almacenamiento en
    // modo R (el segundo parámetro tiene que ser true).
    // Nota: El nombre del espacio de nombres está limitado a 15 caracteres.
    preferences.begin("my-app", true);
    // lee la temperatura maximas y minimas, si no existen se devuelven los valores por defecto
    temperaturaMax=preferences.getInt("TempMax",50);
    temperaturaMin=preferences.getInt("TempMim",0);

    // Close the Preferences
    preferences.end();

    Serial.println("Configuracion terminada");

}

void loop()
{
    Serial.print("Temperatura maxima: ");
    Serial.println(temperaturaMax);
    Serial.print("Temperatura minima: ");
    Serial.println(temperaturaMin);
    delay(1000);
}