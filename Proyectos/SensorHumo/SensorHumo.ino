//UCC a los 5V del arduino
int buzzer = 11;    //positivo en D11
int SensorA0 = A5;  //A0 del sensor a A5 del arduino

//valor del umbral al que se activa el buzzer
int Umbral = 390;  // podemos variar la sensibilidad

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(SensorA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Lectura analogica del sensor MQ2
  int lecturaSensor = analogRead(SensorA0);

  Serial.print("Pin A0: ");
  Serial.println(lecturaSensor);

  //Verifica si la lectura es mayor al umbral
  if (lecturaSensor > Umbral) {
    digitalWrite(buzzer, HIGH);
  } 
  else {
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
