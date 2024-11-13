int redPin = 3;

int greenPin = 5;

int bluePin = 6;

void setup () {
	pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  
	}

void loop () {
  setColor (255, 0, 0); // Color rojo
  delay(1000);
  setColor (0, 255, 0); // Color verde
  delay(1000);
  setColor (0, 0, 255); // Color azul
  delay(1000);
  setColor (255, 255, 255); // Color blanco
  delay(1000);
  setColor (144, 12, 63); // Color púrpura
  delay(1000);
}
void setColor (int redValue, int greenValue, int blueValue) {
analogWrite (redPin, redValue);
analogWrite (greenPin, greenValue);

analogWrite (bluePin, blueValue);
}