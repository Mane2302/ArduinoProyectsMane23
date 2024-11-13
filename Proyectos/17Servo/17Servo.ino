#include <Servo.h>
Servo myservo; // Crea un objeto servo para controlar un servo,puede llegar hasta ocho
int pos = 0; // Variable para almacenar la posición del servo
void setup() {
myservo.attach(9); // Une el servo en el pin 9 al objeto servo
}
void loop() {
for (pos = 0; pos <= 180; pos += 1) { // Va de 0 grados a 180 grados
// en pasos de 1 grado
myservo.write(pos);
delay(15); // Espera 15ms para que el servo llegue a la posición
}
for (pos = 180; pos >= 0; pos -= 1) { // Va de 180 grados a 0 grados

myservo.write(pos);
delay(15); // Espera 15ms para que el servo llegue a la posición
}
}