#include <WiFiS3.h>
#include "arduino_secrets.h"
#include <SPI.h>

// Replace with your network credentials
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;


// Server configuration
int status = WL_IDLE_STATUS;
IPAddress serverIP(192,168,0,188);
int serverPort = 8080;
WiFiClient client;

// MIDI note placeholder functions
void handleNoteOnC4() {
  Serial.println("C4 note on");
}

void handleNoteOnD4() {
  Serial.println("D4 note on");
}

void handleNoteOnE4() {
  Serial.println("E4 note on");
}

void setup() {
  Serial.begin(115200);
  while(!Serial){;}
  // Connect to Wi-Fi
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }
  
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
  
  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
     
    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("WiFi connected");
  printWiFiStatus();

  // Connect to the server
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Connected to server");
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  // Check if there's data available from the server
  while (client.available()) {
    byte incomingByte = client.read();
    Serial.println(incomingByte);
    // Check for MIDI note on messages
    if (incomingByte == 0x90) {
      byte note = client.read();
      byte velocity = client.read();

      // Trigger placeholder functions based on the received MIDI note
      switch (note) {
        case 60: // C4
          handleNoteOnC4();
          break;
        case 62: // D4
          handleNoteOnD4();
          break;
        case 64: // E4
          handleNoteOnE4();
          break;
        // Add more cases for additional notes
      }
    }
  }
}

void printWiFiStatus() {
  // Print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // Print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
