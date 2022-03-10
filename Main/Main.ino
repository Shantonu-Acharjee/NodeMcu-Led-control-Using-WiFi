//Bord Name :- NodeMcu 1.0 (ESP-12E Module)
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80); // port 80

#define led D7

void setup() {
  
  Serial.begin(9600);
  WiFi.begin("Azad Sir Mess", "12345678");
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Connecting...!");
    delay(200);
  }// while End

  Serial.println();
  Serial.println("NodeMcu Connected!");
  Serial.print("Node Mcu IP Address : ");
  Serial.println(WiFi.localIP()); // Print Ip 

  server.begin();

  pinMode(led, OUTPUT);
} // Void Setup End




void loop() { // Void Lopp Start
  client = server.available();


  if (client == 1){
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();

    if (request == "GET /LedOn HTTP/1.1"){
      digitalWrite(led,HIGH);
    }

    else if (request == "GET /LedOff HTTP/1.1"){
      digitalWrite(led,LOW);
    }


  }







  
}// Void Loop End
