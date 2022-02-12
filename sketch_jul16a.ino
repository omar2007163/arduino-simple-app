#include <LCD_I2C.h>
#include "DHT.h"
LCD_I2C lcd(0x27);
DHT dht(7, DHT11);// Default address of most PCF8574 modules, change according
#define joy_X//=analogRead(A0);
#define joy_Y//=analogRead(A1);
int hh;
int i;
int j;
int cont;
int ff;
int game;
uint8_t man[] =
{
   B01100,
    B01100,
    B00000,
    B01111,
    B11100,
    B01100,
    B11010,
    B10011,
    
};

uint8_t bullt[] =
{
    B00000, 
    B00000,
    B10000,
    B01111,
    B10000,
    B00000,
    B00000,
    B00000,

    
};

uint8_t enimy[] =
{
    B11111, 
    B10101,
    B11111,
    B11111,
    B01110,
    B01110,
    B11111,
    B10101,

    
};
void setup() {
  hh=0;
  cont=0;
  
  // put your setup code here, to run once:
lcd.begin();
lcd.backlight();
Serial.begin(9600);
Serial.println("PLAY");
delay(1000);
Serial.println("lcd i2c");
pinMode(2,INPUT_PULLUP);
  dht.begin();
  pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(3,INPUT_PULLUP);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
}
void game ()
{
  if(game==1)
  {
    lcd.clear();
    game=0;
  }
  ff=1;
  analogRead(A2);
analogRead(A3);
//Serial.println( analogRead(A2));
lcd.createChar(1,man);
lcd.createChar(3,enimy);
lcd.createChar(2,bullt);
lcd.setCursor(0,hh);
lcd.write(1);
if(analogRead(A3)>=900 && analogRead(A3)<=1023)
{
Serial.println( analogRead(A3));
hh=0;
lcd.setCursor(0,1);
lcd.print(" ");
delay(10);
}

if(analogRead(A3)<=100 && analogRead(A3) >=0
){Serial.println( analogRead(A3));
hh=1;
lcd.setCursor(0,0);
lcd.print(" ");
delay(10);
}
if(hh>1){hh=1;}
if(hh < 0)
{
  hh=0;
}

if(digitalRead(2)==0)
{
  for(i=2;i<12;i++)
  {
  lcd.setCursor(i,hh);
  lcd.write(2);
  lcd.setCursor(i-1,hh);
  lcd.print(" ");
  delay(65);  
  }
  i=2;
  
   lcd.setCursor(11,hh);
  lcd.print(" ");
}else
{
  i=12;
}
//العدو
/*if(analogRead(A3)<=100 && analogRead(A3) >=0 || analogRead(A3)>=900 && analogRead(A3)<=1023)
{
 for(j=15;j>=0;j--)
  {
   lcd.setCursor(j,0);
   lcd.write(3);
   lcd.setCursor(i+1,hh);
  lcd.print(" ");
  delay(1111);  
  } 
}*/
}

void tempe()
{
  if(ff==1)
  {
    lcd.clear();
    ff=0;
  }
  game=1;
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
   lcd.setCursor(0,0);
   lcd.print("Temp");
   lcd.setCursor(5,0);
   lcd.print(t);
 lcd.setCursor(10,0);
   lcd.print("C");

   lcd.setCursor(0,1);
  lcd.print("Hum");
   lcd.setCursor(5,1);
  lcd.print(h);
   lcd.setCursor(10,1);
  lcd.print("%");

  if(digitalRead(2)==0 )
  {
     lcd.setCursor(5,0);
   lcd.print("          ");
     lcd.setCursor(5,0);
   lcd.print(f);
    lcd.setCursor(10,0);
   lcd.print("F");
   delay(1000);
  }
}

void loop() {
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  analogRead(A3);
  
  if(digitalRead(3==0))
  {
    while(digitalRead(3)==0)
    {
      cont++;  
    }
  }


if(cont>1){cont=1;}
if(cont<0){cont=0;}

switch(cont)
{
  case 1:
 game();//whatch();
  break;

  case 0:
  tempe();
  break;
  
}















  
/* 
  
analogRead(A0);
analogRead(A3);
//Serial.println( analogRead(A2));
lcd.createChar(1,man);
lcd.createChar(3,enimy);
lcd.createChar(2,bullt);
lcd.setCursor(0,hh);
lcd.write(1);
if(analogRead(A3)>=900 && analogRead(A3)<=1023)
{
Serial.println( analogRead(A3));
hh=0;
lcd.setCursor(0,1);
lcd.print(" ");
delay(10);
}

if(analogRead(A3)<=100 && analogRead(A3) >=0
){Serial.println( analogRead(A3));
hh=1;
lcd.setCursor(0,0);
lcd.print(" ");
delay(10);
}
if(hh>1){hh=1;}
if(hh < 0)
{
  hh=0;
}

if(digitalRead(2)==0)
{
  for(i=2;i<12;i++)
  {
  lcd.setCursor(i,hh);
  lcd.write(2);
  lcd.setCursor(i-1,hh);
  lcd.print(" ");
  delay(65);  
  }
  i=2;
  
   lcd.setCursor(11,hh);
  lcd.print(" ");
}else
{
  i=12;
}
//العدو
/*if(analogRead(A3)<=100 && analogRead(A3) >=0 || analogRead(A3)>=900 && analogRead(A3)<=1023)
{
 for(j=15;j>=0;j--)
  {
   lcd.setCursor(j,0);
   lcd.write(3);
   lcd.setCursor(i+1,hh);
  lcd.print(" ");
  delay(1111);  
  } 
}*/
 
}
