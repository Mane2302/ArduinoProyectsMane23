int pinMQ2 = 34;
int buzzer = 13;
int ledVerde = 12;
int ledRojo = 14;

int valorMQ2;
int umbral = 250;

void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  valorMQ2 = analogRead(pinMQ2);
  Serial.println(valorMQ2);

  if (valorMQ2 > umbral) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
  }

  delay(100);
}