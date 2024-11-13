int ledPin = 8; // el pasador del LED
void setup ()
{
pinMode (ledPin, OUTPUT);// inicializar LED_BUILTIN pin digital como salida.
}
void loop ()
{
digitalWrite (ledPin, HIGH); // enciende el LED (HIGH es el nivelde voltaje)
delay(1000); //Espera un segundo

digitalWrite (ledPin, LOW); // apagar el LED, haciendo que elvoltaje BAJO
delay(1000); //Espera un segundo
}