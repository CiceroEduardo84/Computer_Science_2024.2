// Define o pino onde o sinal analógico é lido
int sensorPin = A0;
 
void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);
}
 
void loop() {
  // Lê o valor do pino analógico
  int reading = analogRead(sensorPin);
 
  // Converte o valor lido (0 a 1023) em tensão (0V a 5V)
  float voltage = reading * 5.0 / 1023.0;
 
  // Converte a tensão em temperatura (cada 10mV equivale a 1°C)
  float temperatureC = (voltage - 0.5) * 100.0;  // Subtrai 0.5V e multiplica por 100 para converter a 
  //tensão em temperatura. A subtração de 0.5V é necessária porque o TMP36 tem uma saída de 0.5V a 0°C. 
  //Cada aumento de 0.01V(10mV) na saída representa um aumento de 1°C na temperatura, e assim é necessário multiplicar por 100.
 
  // Exibe a temperatura na serial
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" C");
 
  // Aguarda um segundo antes da próxima leitura
  delay(1000);
}