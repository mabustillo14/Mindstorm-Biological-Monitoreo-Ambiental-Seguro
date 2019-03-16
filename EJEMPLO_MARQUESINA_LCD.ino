#include <LiquidCrystal.h> // Entre los símbolos <> buscará en la carpeta de librerías configurada
 
// Definimos las constantes
#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD
#define VELOCIDAD 300 // Velocidad a la que se mueve el texto
 
// Lo primero is inicializar la librería indicando los pins de la interfaz
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
 
// Textos
String texto_fila1 = "Mindstorm Biological: Monitoreo Ambiental Seguro";
String texto_fila2 = "Monitoreo Ambiental Seguro";
void setup() {
  // Configuración monitor serie
  Serial.begin(9600);
 
  // Configuramos las filas y las columnas del LCD en este caso 16 columnas y 2 filas
  lcd.begin(COLS, ROWS);
}
 
void loop() {
 
  // Obtenemos el tamaño del texto
  int tam_texto=texto_fila1.length();
  int tam_texto2=texto_fila2.length();
   
  // Desplazamos el texto hacia la izquierda en la segunda fila
  for(int i=16;i>=1;i--)
  {
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(i, 1);
 
    // Escribimos el texto
    lcd.print(texto_fila1);
    lcd.print(texto_fila2);
    // Esperamos
    delay(VELOCIDAD);
  }
 
  // Mostramos salida del texto por la izquierda
  for(int i=1; i<=tam_texto ; i++)
  {
    String texto = texto_fila1.substring(i-1);
    String texto2 = texto_fila2.substring(i-1);
 
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(0, 1);
 
    // Escribimos el texto
    lcd.print(texto);
 
    // Esperamos
    delay(VELOCIDAD);
  }
}
