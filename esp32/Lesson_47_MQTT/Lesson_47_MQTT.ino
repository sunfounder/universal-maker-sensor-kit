
#include <WiFi.h>
#include <PubSubClient.h>
//#include <Wire.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

// Add your MQTT Broker address, example:
const char* mqtt_server = "broker.hivemq.com";
const char* unique_identifier = "sunfounder-client-sdgvsda";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
int value = 0;


// LED Pin, Button Pin
const int ledPin = 25;
const int buttonPin = 26;


void setup() {
  Serial.begin(115200);

  // default settings
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
  // Changes the output state according to the message
  if (String(topic) == "SF/LED") {
    Serial.print("Changing state to ");
    if (messageTemp == "on") {
      Serial.println("on");
      digitalWrite(ledPin, HIGH);
    } else if (messageTemp == "off") {
      Serial.println("off");
      digitalWrite(ledPin, LOW);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(unique_identifier)) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("SF/LED");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // if the button pressed, publish the temperature to topic "SF/TEMP"
  if (digitalRead(buttonPin)) {
    long now = millis();
    if (now - lastMsg > 5000) {
      lastMsg = now;
      char tempString[8];
      strcpy(tempString,"hello");
      client.publish("SF/TEMP", tempString);
    }
  }
}