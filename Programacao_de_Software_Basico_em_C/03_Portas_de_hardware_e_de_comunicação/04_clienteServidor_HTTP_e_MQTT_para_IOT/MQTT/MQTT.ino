#include <WiFi.h>
#include <PubSubClient.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bme;
float temperature;

String temperatureString = "";

// WiFi
const char *ssid = "xxxxxx"; // Digite o nome do seu Wi-Fi
const char *password = "xxxxxx";  // Digite a senha do Wi-Fi

// Corretor MQTT
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "emqx/esp32";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

// Inicializar BMP180
void initBME(){
  if (!bme.begin()) {
    Serial.println("Não foi possível encontrar um sensor BMP180 válido, verifique a fiação!");
    while (1);
  }
}

void setup() {
  
  initBME();
  
    // Configurar baud rate do software serial para 115200;
    Serial.begin(115200);
    // Conectando-se a uma rede Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Conectando ao WiFi..");
    }
    Serial.println("Conectado à rede Wi-Fi");
    // conectando a um corretor mqtt
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("O cliente %s se conecta ao corretor MQTT público\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Conectado ao corretor MQTT público EMQX");
        } else {
            Serial.print("falhou com o estado ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    // Publicar e subscrever
    client.publish(topic, "Olá ESP32");
    client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Mensagem chegou no tópico: ");
    Serial.println(topic);
    Serial.print("Mensagem:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void loop() {
    temperature = bme.readTemperature();

    temperatureString = String(temperature);
    
    client.publish(topic, temperatureString.c_str());
    client.loop();
    delay(3000);
}
