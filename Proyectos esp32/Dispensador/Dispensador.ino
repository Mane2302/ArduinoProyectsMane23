#include <ESP32Servo.h> // Biblioteca para controlar el servo
#include <ArduinoJson.h> // Biblioteca para manejar JSON
#include <CTBot.h>       // Biblioteca para interactuar con Telegram

Servo miservo; 
CTBot miBot;

static const int ServoPin = 13;
static const int LedPin = 12;

const char* ssid     = "SLDG2";
const char* password = "2C9569AD7E5B";

#define miBotToken "7797700061:AAF8zpW3Dwd-UNmzjjBH__8yyrglNp9eU9M" 
#define ChatID 1143767637

void setup() {

  Serial.begin(115200);

  miservo.attach(ServoPin);
  pinMode(LedPin, OUTPUT);

  // Red WiFi con SSID y password
  miBot.wifiConnect(ssid, password);
  miBot.setTelegramToken(miBotToken);
  
  if (miBot.testConnection()) {
    Serial.println("WiFi conectado.");
  }

  miBot.sendMessage(ChatID, "Bot iniciado");
}

void loop() {
  TBMessage mensaje;

  if (CTBotMessageText == miBot.getNewMessage(mensaje)) {

    if (mensaje.text == "/alimentar") {
      digitalWrite(LedPin, HIGH);
      delay(2000);                      
      digitalWrite(LedPin, LOW);   
      delay(1000);
      miservo.write(90);             
      delay(500);                       
      miservo.write(0);          
      miBot.sendMessage(ChatID, "Alimentando");   
      
    }

  }
}
