#include <Arduino.h>

void setup() {
  //Inicia a comunicação serial com 115200 bits por segundo
  Serial.begin(115200);
}

void loop() {
  //Envia a mensagem "Ola mundo pela porta serial"
  Serial.println("Ola mundo");

  //Aguarda um segundo antes de enviar novamente
  delay(1000);
}
