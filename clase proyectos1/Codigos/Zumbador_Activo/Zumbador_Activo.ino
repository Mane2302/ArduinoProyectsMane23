int buzzer = 8;//el pin del zumbador activo
void setup()
{
  pinMode(buzzer,OUTPUT);//Inicializa el pin del zumbador como una salida
}
void loop()
{

digitalWrite(buzzer,HIGH);
delay(100);//espera 1ms
digitalWrite(buzzer,LOW);
delay(100);//espera 1ms

}