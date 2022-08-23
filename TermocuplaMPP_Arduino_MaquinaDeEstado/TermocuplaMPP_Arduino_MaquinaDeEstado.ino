#include "max6675.h"

int IN1 = 8;      // pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 9;      // pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 10;     // pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 11;     // pin digital 11 de Arduino a IN4 de modulo controlador
int demora = 10;      // demora entre pasos, no debe ser menor a 10 ms.

int ktcS0 = 5;
int ktcCS = 6;
int ktcCLK = 7;
int mene;
int carr = 0;
int term = 0;
MAX6675 ktc(ktcCLK, ktcCS, ktcS0);


void setup()
{
  pinMode(IN1, OUTPUT);   // todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  delay(10);
}

void loop()
{
  for (int i = 0; i < 20; i++) // 512*4 = 2048 pasos
  {
    switch(carr){
    if(carr == 0){
    case 0:
    digitalWrite(IN1, HIGH);  // paso 1
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(demora);
    carr++;
    }
    break;
    
    if(carr == 1){
    case 1:
    digitalWrite(IN1, LOW); // paso 2
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(demora);
    carr++;
    }
    break;

    if(carr == 2){
    case 2:
    digitalWrite(IN1, LOW); // paso 3
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(demora);
    carr++;
    }
    break;

    if(carr == 3){
    case 3:
    digitalWrite(IN1, LOW); // paso 4
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(demora);
    carr = 0;
    }
    break;
    
    }
    

    

  }
  
  mene = ktc.readCelsius();
  Serial.println(mene);
  switch(term){
 
  case 0:
  if(term == 0){
  if (mene >= 70)
  {
    Serial.print(" apagar-extrusor ");
  }
  }
  default:
  if (mene <= 40)
  {
    Serial.print(" encender-extrusor ");
  }

  }
  



}
