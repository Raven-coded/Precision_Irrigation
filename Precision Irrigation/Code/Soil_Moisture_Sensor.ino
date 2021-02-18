#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
int sensor_pin = A0;
int value;

const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// Domain Name with full URL Path for HTTP POST Request
// REPLACE WITH YOUR EVENT NAME AND API KEY - open the documentation: https://ifttt.com/maker_webhooks
const char* serverName = "http://maker.ifttt.com/trigger/REPLACE_WITH_YOUR_EVENT/with/key/REPLACE_WITH_YOUR_API_KEY";
// Example:
//const char* serverName = "http://maker.ifttt.com/trigger/test_event/with/key/nAZjOphL3d-ZO4N3k64-1A7gTlNSrxMJdmqy3tC";

unsigned long lastTime = 0;
// Timer set to 30 seconds (10000)
unsigned long timerDelay = 30000;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 30 seconds (timerDelay variable), it will take 30 seconds before publishing the first reading.");

  // Random seed is a number used to initialize a pseudorandom number generator
  randomSeed(analogRead(33));

  pinMode(sensor_pin, INPUT);
  delay(1000);
}

void loop() {

value= analogRead(sensor_pin);
value = map(value,550,0,0,100);
Serial.print("Moisture : ");
Serial.print(value);
Serial.println("%");
delay(10000);
  
  //Send an HTTP POST request every 30 seconds
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverName);
      
      
      String mois = String(value);
      // If you need an HTTP request with a content type: application/json, use the following:
      http.addHeader("Content-Type", "application/json");
      // JSON data to send with HTTP POST
     String httpRequestData = "{\"value1\":\""+mois+ "\"}";
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
     
     
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
