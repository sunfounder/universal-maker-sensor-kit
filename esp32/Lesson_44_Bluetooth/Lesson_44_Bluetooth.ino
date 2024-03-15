#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEUtils.h"
#include "BLE2902.h"

// Define the Bluetooth device name
const char *bleName = "ESP32_Bluetooth";

// Define the received text and the time of the last message
String receivedText = "";
unsigned long lastMessageTime = 0;

// Define the UUIDs of the service and characteristics
#define SERVICE_UUID "15d738e4-ed6e-11ed-a05b-0242ac120003"
#define CHARACTERISTIC_UUID_RX "06015e54-ed6e-11ed-a05b-0242ac120003"
#define CHARACTERISTIC_UUID_TX "0e8b42ba-ed6e-11ed-a05b-0242ac120003"

// Define the Bluetooth characteristic
BLECharacteristic *pCharacteristic;

void setup() {
  Serial.begin(115200);  // Initialize the serial port
  setupBLE();            // Initialize the Bluetooth BLE
}

void loop() {
  // When the received text is not empty and the time since the last message is over 1 second
  // Send a notification and print the received text
  if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
    Serial.print("Received message: ");
    Serial.println(receivedText);
    pCharacteristic->setValue(receivedText.c_str());
    pCharacteristic->notify();
    receivedText = "";
  }

  // Read data from the serial port and send it to BLE characteristic
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    const char *newValue = str.c_str();
    pCharacteristic->setValue(newValue);
    pCharacteristic->notify();
  }
}

// Define the BLE server callbacks
class MyServerCallbacks : public BLEServerCallbacks {
  // Print the connection message when a client is connected
  void onConnect(BLEServer *pServer) {
    Serial.println("Connected");
  }
  // Print the disconnection message when a client is disconnected
  void onDisconnect(BLEServer *pServer) {
    Serial.println("Disconnected");
  }
};

// Define the BLE characteristic callbacks
class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    // When data is received, get the data and save it to receivedText, and record the time
    std::string value = pCharacteristic->getValue();
    receivedText = String(value.c_str());
    lastMessageTime = millis();
    Serial.print("Received: ");
    Serial.println(receivedText);
  }
};

// Initialize the Bluetooth BLE
void setupBLE() {
  BLEDevice::init(bleName);                        // Initialize the BLE device
  BLEServer *pServer = BLEDevice::createServer();  // Create the BLE server
  // Print the error message if the BLE server creation fails
  if (pServer == nullptr) {
    Serial.println("Error creating BLE server");
    return;
  }
  pServer->setCallbacks(new MyServerCallbacks());  // Set the BLE server callbacks

  // Create the BLE service
  BLEService *pService = pServer->createService(SERVICE_UUID);
  // Print the error message if the BLE service creation fails
  if (pService == nullptr) {
    Serial.println("Error creating BLE service");
    return;
  }
  // Create the BLE characteristic for sending notifications
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->addDescriptor(new BLE2902());  // Add the descriptor
  // Create the BLE characteristic for receiving data
  BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Set the BLE characteristic callbacks
  pService->start();                                                 // Start the BLE service
  pServer->getAdvertising()->start();                                // Start advertising
  Serial.println("Waiting for a client connection...");              // Wait for a client connection
}
