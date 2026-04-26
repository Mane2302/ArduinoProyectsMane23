#include <WiFiManager.h> //de tzapu
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h> // de Brian Lough
#include <ArduinoJson.h> //ArduinoJson de Benoit

int LEDR = 14;

const char* BOT_TOKEN = "8612623723:AAHGvM86K2NZdimc-P0MkugujDT0plt22o4";
const char* CHAT_ID  = "8728136816";

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);
WebServer server(80);

void sendTelegram(const String& msg) {
  if (WiFi.status() == WL_CONNECTED) {
    bot.sendMessage(CHAT_ID, msg, "");
  }
}

void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
      body { margin:0; font-family:Arial; background:#0f172a; color:white; display:flex; justify-content:center; align-items:center; height:100vh;}
      .container { text-align:center; width:90%; max-width:400px;}
      button { width:100%; padding:20px; margin:10px 0; font-size:18px; border:none; border-radius:15px; color:white;}
      .on { background:#22c55e; }
      .off { background:#ef4444; }
    </style>
  </head>
  <body>
    <div class="container">
      <h1>Control LED</h1>
      <button class="on" onclick="fetch('/on')">Encender</button>
      <button class="off" onclick="fetch('/off')">Apagar</button>
    </div>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(LEDR, HIGH);
  sendTelegram("LED encendido 💡");
  server.send(200, "text/plain", "ON");
}

void handleOff() {
  digitalWrite(LEDR, LOW);
  sendTelegram("LED apagado");
  server.send(200, "text/plain", "OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(LEDR, OUTPUT);
  digitalWrite(LEDR, LOW); //para iniciar con el led apagado

  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  wm.autoConnect("ESP32_LED","12345678");

  Serial.println(WiFi.localIP());

  client.setInsecure(); // evita problemas SSL
  delay(1000);
  sendTelegram("ESP32 conectado");

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop() {
  server.handleClient();
}