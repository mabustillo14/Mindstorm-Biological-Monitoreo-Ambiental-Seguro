//Conexiones
//Analogico MQ2 = A0
//Analogico MQ7 = A1
//Rx Bluetooth = 

#include <SoftwareSerial.h>
SoftwareSerial BT1(7,6); // RX, TX
//Declarar variables
int zumbador = 5; //Es el pin donde va conectado el buzzer
int led = 2; //Es el pin donde va conectado el led
int led2 = 3;
int ledon = 13;
int gastotal; //

int dato_MQ2;
int dato_MQ7;
char buffer(20);
int lectura_MQ2;
int Lectura_MQ7;
int Lectura_MQ71;

float sensorValor;
float rango;
int analogpin2 = A0;
int analogpin7 = A1;
char datoSerial;
char enviarDato;
int duracion;

 
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT); //Es el pin del led
pinMode(2, INPUT); //Es el pin del sensor
pinMode(zumbador,OUTPUT);
digitalWrite(ledon, HIGH);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  

lectura_MQ2=analogRead(A0); //Convertir la medicion a PPM del Sensor de A0
float voltaje = lectura_MQ2*(5.0/1023.0);
float Rs=1000*((5-voltaje)/voltaje);
double dato_MQ2=0.4091*pow(Rs/5463, -1.497); // esta en mg/L el dato proporcionado

//Lectura_MQ7=analogRead(A0); //Convertir la medicion a PPM del Sensor de A0
//float voltaje1 = lectura_MQ2*(5.0/1023.0);
//float Rs1=1000*((5-voltaje+0.364)/voltaje1);
//double dato_MQ7=0.4091*pow(Rs1/5463, -1.497+0.0268)+0.26843; // esta en mg/L el dato proporcionado


Lectura_MQ71=analogRead(A1); //Convertir la medicion a PPM del Sensor de A0
float voltaje2 = Lectura_MQ71*(5.0/1023.0);
float Rs2=1000*((5-voltaje2)/voltaje2);
double dato_MQ7=0.4091*pow(Rs2/5463, -1.497); // esta en mg/L el dato proporcionado

//Serial.print(" MQ2: ");
Serial.print(dato_MQ2); // esta en mg/L el dato proporcionado
Serial.print(",");
//Serial.print(" MQ7: "); // 
Serial.println(dato_MQ7); // esta en mg/L el dato proporcionado
//Serial.print(",");
//Serial.println(dato_MQ71); // esta en mg/L el dato proporcionado
Serial.println(buffer);
delay(700);

if (dato_MQ2 >= 100){ //Rangos para el sensor MQ2
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(zumbador, HIGH);
  delay (150);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(zumbador, LOW);
  delay (150);

if (dato_MQ7>= 100 ){ //Rangos para el sensor MQ
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(zumbador, HIGH);
  delay (150);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(zumbador, LOW);
  delay (150); 
  }


//sprintf(buffer, "%d,%d", dato_MQ2,dato_MQ7);
//Serial.println(buffer);
//Serial.print("MQ2=");
//Serial.print(dato_MQ2);
//Serial.print("  MQ7=");
//Serial.println(dato_MQ7);

}
}
