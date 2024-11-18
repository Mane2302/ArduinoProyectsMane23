#include <ArduinoJson.h> // Biblioteca para manejar JSON
#include <CTBot.h>       // Biblioteca para interactuar con Telegram

CTBot miBot;
//UCC a los 5V del arduino
const int buzzer = 26;    //positivo en D11
const int SensorA0 = 35;  //A0 del sensor a A13 del ESP32
const int LED = 14;
int lecturaSensor = 0;

//valor del umbral al que se activa el buzzer
int Umbral = 1200;  // podemos variar la sensibilidad
//wifi
const char* ssid     = "SLDG2";
const char* password = "2C9569AD7E5B";

//telegram
#define miBotToken "7797700061:AAF8zpW3Dwd-UNmzjjBH__8yyrglNp9eU9M" 
#define ChatID 1143767637



void setup() {
  pinMode(buzzer, OUTPUT);
  //pinMode(SensorA0, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  // Red WiFi con SSID y password
  miBot.wifiConnect(ssid, password);
  miBot.setTelegramToken(miBotToken);

  if (miBot.testConnection()) {

    Serial.println("WiFi conectado.");
  }

  miBot.sendMessage(ChatID, "Bot iniciado y sistema preparado");

}

void loop() {
  //Lectura analogica del sensor MQ2
  lecturaSensor = analogRead(SensorA0);

  Serial.print("Pin A0: ");
  Serial.println(lecturaSensor);

  //Verifica si la lectura es mayor al umbral
  if (lecturaSensor > Umbral) {
    Serial.println("HUMO O GAS DETECTADO!!!");
    miBot.sendMessage(ChatID, "HUMO O GAS DETECTADO, LLAMA A LOS BOMBEROS WIU WIU");
    digitalWrite(LED, HIGH);
    for(int a =0; a <=28; a++){//Sonido del buzzer intermitente
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW); 
    delay(75);
    }
    
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}

