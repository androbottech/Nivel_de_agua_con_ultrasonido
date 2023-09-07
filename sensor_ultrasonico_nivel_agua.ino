const int echo=A1;
const int trigger=A0;
long tiempo;
float distancia;
int leds[]={1,2,3,4,5,6,7,8,9,10};

void setup() 
{
  for(int pin=2;pin<=11;pin++)
    pinMode(pin,OUTPUT);
  
  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() 
{
  medir();
  
  Serial.print("Distancia: ");
  Serial.print(distancia);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();

  indicador_nivel();
}

void medir()
{
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  
  tiempo=pulseIn(echo,HIGH);//us=microsegundos
  distancia = float(tiempo*0.0343)/2;
  delay(10);
}
void indicador_nivel()
{
  if(distancia>11) //distancia maxima , apaga los LEDs
  {for(int k=0;k<=9;k++) 
   {digitalWrite(leds[k],LOW);}
  } 
else if(distancia>10) // primer nivel encender LED 1.
   {for(int k=0;k<=0;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=1;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>9) // 2do nivel encender LED 2 y asi con los demas LED etc...
   {for(int k=0;k<=1;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=2;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>8) 
   {for(int k=0;k<=2;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=3;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>7) 
   {for(int k=0;k<=3;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=4;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>6) 
   {for(int k=0;k<=4;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=5;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>5) 
   {for(int k=0;k<=5;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=6;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>4) 
   {for(int k=0;k<=6;k++) 
    {digitalWrite(leds[k],HIGH);} 
    for(int k=7;k<=9;k++) 
    {digitalWrite(leds[k],LOW);}
   } 
else if(distancia>3) //ultimo nivel indicador LED 8.
   {for(int k=0;k<=8;k++) 
    {digitalWrite(leds[k],HIGH);} 
    tone(12,523, 100);
    tone(12,450, 100);
   }   
}
