#include <arduino-timer.h>
#include <WiFiS3.h>
#include <AppleMIDI.h>
#include "arduino_secrets.h"

// Replace with your network credentials
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

// Server configuration
int status = WL_IDLE_STATUS;

APPLEMIDI_CREATE_INSTANCE(WiFiUDP, MIDI, "AppleMIDI-ESP32", DEFAULT_CONTROL_PORT);

auto timer = timer_create_default();

void setup() {
  Serial.begin(115200);
  while (!Serial) { ; }
  // Connect to Wi-Fi
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true)
      ;
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

  MIDI.begin();  // listens on channel 1
  
  timer.every(4000, midiSend); //PLACEHOLDER FUNCTION TO SEND DATA FROM ARDUINO TO COMPUTER EVERY 4 SECONDS
  MIDI.setHandleNoteOn(printNoteOn);
}

void loop() {
  timer.tick();

  // Listen to incoming notes
  MIDI.read();
}

void printNoteOn(byte channel, byte pitch, byte velocity) {
  // FUNCTION RESPONDING TO NOTE ON MESSAGES
  Serial.print("channel ");
  Serial.print(channel);
  Serial.print(" pitch ");
  Serial.print(pitch);
  Serial.print(" velocity ");
  Serial.println(velocity);
}

bool midiSend(void *) {
  //PLACEHOLDER FUNCTION IF WE WANT TO SEND DATA BACK
  // YOU CAN CHANGE FOLLOWING CONTENT
  MIDI.sendNoteOn(40, 55, 1);
  Serial.println("note send");
  // UP TO HERE

  return true;
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