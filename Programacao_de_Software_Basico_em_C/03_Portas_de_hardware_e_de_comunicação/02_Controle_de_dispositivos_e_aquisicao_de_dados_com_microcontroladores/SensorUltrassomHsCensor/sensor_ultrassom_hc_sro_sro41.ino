// Definição dos nomes dos pinos
const int trigPin = 7;
const int echoPin = 8;
 
//define a velocidade do som em cm/uS
#define SOUND_SPEED 0.034
 
long duration;
float distanceCm;
float distanceInch;
 
void setup() {
 
  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT); // Ajusta trigPin como saída
  pinMode(echoPin, INPUT); // Ajusta echoPin como entrada
  pinMode(13, OUTPUT);
}
 
void loop() {
  // limpa trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Mantem trigPin em estado HIGH por 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Lê o echoPin, retorna o tempo de viagem da onda
  // sonora em microssegundos
  duration = pulseIn(echoPin, HIGH);
 
  // Calcula a distância
  distanceCm = duration * SOUND_SPEED/2;
 
  // Imprime a distância no monitor serial
  Serial.print("Distancia (cm): ");
  Serial.println(distanceCm);
 
  delay(1000);
}