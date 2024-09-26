void setup() {
  pinMode(2, INPUT); //Pino 2 como Entrada
  pinMode(13, OUTPUT) //PINO 3 como saída
}

void loop() {
  if(digitalRead(2)== HIGH){ //Verifica se o sensor PIR está acionado 
    digitalWrite(13, HiGH); //Liga o led da placa
    delay(100); //Espera 100 milisecondos
    digitalWrite(13,LOW); //Desliga o led da placa
    delay(100); //Espera 100 milisecondos
  }

}
