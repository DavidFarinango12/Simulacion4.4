/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * CODIGO 17: USO DE TIMER 1
 * OBJETIVO: MANEJO DE LUCES LED EN DIFERENTES TIEMPOS CONTROLADOS POR TIMER 1
 * NOMBRE: RAFAEL FARINANGO
 * FUNCIONES:     Timer1.initialize(1000000); 1M = 1seg
 *                Timer.pwm(pin,dutty)
 */

#include <TimerOne.h>

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
int cont = 0;


void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000);         //configura timer a 1 seg
  Timer1.attachInterrupt(subrutina);  //interrupcion de timer
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}


void loop() {
  Serial.println("PROGRAMA PRINCIPAL");
  delay(300);
}


void subrutina(){
  cont++;
  switch(cont){
    case 8:       //en 8 seg enciende el led 1
      digitalWrite(led1,HIGH);
    break;
    case 10:
      digitalWrite(led2,HIGH);
    break;
    case 12:
      digitalWrite(led2,LOW);
    break;
    case 15:
      digitalWrite(led3,HIGH);
    break;
    case 18:
      digitalWrite(led1,LOW);
    break;
    case 22:
      digitalWrite(led3,LOW);
      cont = 0;
    break;
  }
}
