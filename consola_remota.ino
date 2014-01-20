/*
   Demostracion del uso de la consola remota con Arduino Yun

   Jorge Gomez / Sindormir.net 
    jorge@sindormir.net 2014
     
    Una vez conectado a la consola se puede comprobar el funcionamiento 
    mandando los caracterer + y - para modificar la frecuencia de parpapedo
    del LED en el pin 13.

    Licencia GPLv3

*/

#include <Console.h>

#define LED 13
 
void setup() {
  pinMode(LED, OUTPUT);

  Bridge.begin();
  Console.begin();
 
  while (!Console); //Necesario si queremos ver el siguiente mensaje
  Console.println("Conectado a la consola!");
}
 
void loop() {
  static unsigned int periodo = 1024;
  char operacion;
  
  if (Console.available() > 0) {
    operacion = Console.read();

    if (operacion == '+') periodo *=2;
    if (operacion == '-') periodo /=2;
    if (operacion != '\n' && operacion != '\r'){    
      Console.print("periodo es ahora: ");      
      Console.println(periodo);
    }
  }
  
  digitalWrite(LED, !digitalRead(LED));
  delay(periodo);

}
