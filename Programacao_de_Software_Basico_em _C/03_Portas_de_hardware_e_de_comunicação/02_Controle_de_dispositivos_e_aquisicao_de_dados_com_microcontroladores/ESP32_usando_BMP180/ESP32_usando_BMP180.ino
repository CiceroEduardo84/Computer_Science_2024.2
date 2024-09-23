#include <Adafruit_BMP085.h>
#include <Wire.h> //Biblioteca para usar I2C

Adafruit_BMP085 bmp; // Cria um aintancia do projeto bmp para interagir com o sensor

void setup() {
Serial.begin(115200);

  if(!bmp.begin()){ //Inicializa a comunicação com o sensor BMP085
  Serial.println("Sensor BMP085 não encontrado!");
  while(1){} //Entra em um lup infinito, efetivamente parando o programa se o sensor não for encontrado
  
  }
}

void loop() {
Serial.println("");
Serial.println("Temp: ");
Serial.print(bmp.readTemperature()); //Lê a temperatura atual do sensor BMP085 e imprime na porta serial
Serial.println("C");

Serial.println("Pres: ");
Serial.print(bmp.readPressure());
Serial.println(" Pa");

Serial.println("Alt: ");
Serial.print(bmp.readAltitude(102300)); //Calcula a altitute baseada na pressão atmosférica
//medida em comparaçaõ com a pressão do mar especificada como parâmetro
//(102300 Pa neste exemplo)
Serial.println(" metros");

delay(2000);
}
