/*
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/esp32-http-get-open-weather-map-thingspeak-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>


// Replace the next variables with your SSID/Password combination
const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

// Your Domain name with URL path or IP address with path
String openWeatherMapApiKey = "<openWeatherMapApiKey>";

// Replace with your country code and city
// Fine the country code by https://openweathermap.org/find
String city = "<CITY>";
String countryCode = "<COUNTRY CODE>";

// THE DEFAULT TIMER IS SET TO 10 SECONDS FOR TESTING PURPOSES
// For a final application, check the API call limits per hour/minute to avoid getting blocked/banned
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 10 seconds (10000)
unsigned long timerDelay = 10000;

String jsonBuffer;

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// SDA -> GPIO21, SCL -> GPIO22
// lcd address is 0x27, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

// NTP Server time
const char* ntpServer = "pool.ntp.org";
long  gmtOffset_sec = 0;
int   daylightOffset_sec = 0; //3600;

void setup() {
  Serial.begin(115200);

  // WiFi 
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 10 seconds (timerDelay variable), it will take 10 seconds before publishing the first reading.");

  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

}

void loop() {
  // Send an HTTP GET request
  if ((millis() - lastTime) > timerDelay) {
    // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&units=metric" + "&APPID=" + openWeatherMapApiKey;
      
      jsonBuffer = httpGETRequest(serverPath.c_str());
      Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);
  
      // JSON.typeof(jsonVar) can be used to get the type of the var
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }
    
      // Serial.print("JSON object = ");
      // Serial.println(myObject);
      // Serial.print("Temperature: ");
      // Serial.println(myObject["main"]["temp"]);
      // Serial.print("Pressure: ");
      // Serial.println(myObject["main"]["pressure"]);
      // Serial.print("Humidity: ");
      // Serial.println(myObject["main"]["humidity"]);
      // Serial.print("Wind Speed: ");
      // Serial.println(myObject["wind"]["speed"]);

      // Get time
      gmtOffset_sec =  myObject["timezone"]; 
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
      // time =  
      String time = printLocalTime();                     
  
      // LCD Print
      lcd.clear(); 
      lcd.setCursor(0, 0); 
      lcd.print(time);
      lcd.print(" ");        
      lcd.print(myObject["weather"][0]["main"]);             
      lcd.setCursor(0, 1);
      lcd.print("T:");    
      lcd.print(myObject["main"]["temp"]); 
      lcd.print("\xDF");  // "°" char
      lcd.print("C ");    
      lcd.print("H:");    
      lcd.print(myObject["main"]["humidity"]);  
      lcd.print("%");          
      
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}

String printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return "null";
  }
  // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

  // get time format HH:MM
  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
  char timeMinute[3];
  strftime(timeMinute,3, "%M", &timeinfo); 
  String time = String(timeHour) + ":" + String(timeMinute);
  Serial.println(time)  
;  return time;
}


String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
