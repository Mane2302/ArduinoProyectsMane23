int LED = 3;
int BRILLO;
int POTEN = 0;

void setup() {
  pinMode(LED, OUTPUT);
  //las entradas analogicas como A0 no requiren inicializacion ya que solo son de entrada

}

void loop() {
  BRILLO = analogRead(POTEN) / 4; // 1023 es el reango de la entrada analogica de arduino
                                  //y analogRead solo va de 0  a 255 asi que dividimos por 4
                                  //para estaer dentro de este rango
  analogWrite(LED, BRILLO);
}