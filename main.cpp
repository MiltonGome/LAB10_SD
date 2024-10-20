#include <Arduino.h>
#include "driver/adc.h"

#define pot1 5


void lecturaADC(void);


void setup() {
  Serial.begin(115200);  // Inicia comunicación serial
  pinMode(pot1, INPUT);
  
}

void loop() {
  if (Serial.available() > 0) {  // Verifica si hay datos disponibles en el buffer serial
    char command = Serial.read(); // Lee el comando enviado desde el STM32
    if (command == '1') {  // Si el STM32 envía '1', lee el potenciómetro 1
      lecturaADC();
    } 
  }
}

void lecturaADC(void) {
  int potval11 = analogRead(pot1);  // Lee el valor del potenciómetro 1
  int potval1 = map(potval11, 0, 1023, 0, 15);
  Serial.println(potval1);         // Envía el valor leído por el serial
}