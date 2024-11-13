int buzzer = 12;//el pin del zumbador activo
void setup()
{
  pinMode(buzzer,OUTPUT);//Inicializa el pin del zumbador como una salida
}
void loop()
{
unsigned char i;
while(1)
{
//proporciona una frecuencia
for(i=0;i<80;i++)
{
digitalWrite(buzzer,HIGH);
delay(1);//espera 1ms
digitalWrite(buzzer,LOW);
delay(1);//espera 1ms
}

//proporciona otra frecuencia
for(i=0;i<100;i++)
{
digitalWrite(buzzer,HIGH);
delay(2);//espera 2ms
digitalWrite(buzzer,LOW);
delay(2);//espera 2ms
}
}
}