//Conexiones
//Analogico MQ2 = A0
//Analogico MQ7 = A1


//Declarar variables
int zumbador = 5; //Es el pin donde va conectado el buzzer
int led = 2; //Es el pin donde va conectado el led
int led2 = 3;
int ledon = 13;
int gastotal; //Qué es gt?????

char dato_MQ2;
char dato_MQ7;
char buffer(10);
int lectura_MQ2;
int Lectura_MQ7;

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
dato_MQ2=map(lectura_MQ2, 0, 1023, 20, 10000);
Serial.print("   MQ2:");
Serial.print(dato_MQ2);

Lectura_MQ7=analogRead(A1); //Convertir la medicion a PPM del Sensor de A0
dato_MQ7=map(Lectura_MQ7, 0, 1023, 20, 10000);
Serial.print("      MQ7:");
Serial.print(dato_MQ7);


if (dato_MQ2 >= 0){ //Rangos para el sensor MQ2
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(zumbador, HIGH);
  delay (150);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(zumbador, LOW);
  delay (150);

if (dato_MQ7>= 0 ){ //Rangos para el sensor MQ
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(zumbador, HIGH);
  delay (150);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(zumbador, LOW);
  delay (150); 
  }


sprintf(buffer, "%d,%d", dato_MQ2,dato_MQ7);
Serial.println(buffer);
Serial.println("MQ2=");
Serial.println(dato_MQ2);
Serial.println("  MQ7=");
Serial.println(dato_MQ7);
}
}
