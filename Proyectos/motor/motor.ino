#define E1 5 // Habilita el Pin para el motor
#define I1 3// Control del pin 1 para el motor
#define I2 4 // Control del pin 2 para el motor
void setup() {

pinMode(E1, OUTPUT);
pinMode(I1, OUTPUT);
pinMode(I2, OUTPUT);
}
void loop() {
analogWrite(E1, 153); // Correr a la mitad de la velocidad
digitalWrite(I1, HIGH);
digitalWrite(I2, LOW);
delay(10000);

// Cambia la dirección
digitalWrite(E1, LOW);
delay(2000);
analogWrite(E1, 255); // Correr a toda velocidad
digitalWrite(I1, LOW);
digitalWrite(I2, HIGH);
delay(10000);
}