#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const char *ssid = "ESP8266_Relay";
const char *password = "12345678";

#define RELAY1 D1
#define RELAY2 D2
#define RELAY3 D6
#define RELAY4 D7
#define IR_RECEIVE_PIN D5

ESP8266WebServer server(80);

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

const uint32_t IR_CODE_RELAY1 = 0xFFA25D;
const uint32_t IR_CODE_RELAY2 = 0xFF629D;
const uint32_t IR_CODE_RELAY3 = 0xFFE21D;
const uint32_t IR_CODE_RELAY4 = 0xFF22DD;

bool relay1State = false;
bool relay2State = false;
bool relay3State = false;
bool relay4State = false;

void toggleRelay1() {
    relay1State = !relay1State;
    digitalWrite(RELAY1, relay1State ? LOW : HIGH);
    Serial.println(relay1State ? "Relay 1 ON (IR)" : "Relay 1 OFF (IR)");
}

void toggleRelay2() {
    relay2State = !relay2State;
    digitalWrite(RELAY2, relay2State ? LOW : HIGH);
    Serial.println(relay2State ? "Relay 2 ON (IR)" : "Relay 2 OFF (IR)");
}

void toggleRelay3() {
    relay3State = !relay3State;
    digitalWrite(RELAY3, relay3State ? LOW : HIGH);
    Serial.println(relay3State ? "Relay 3 ON (IR)" : "Relay 3 OFF (IR)");
}

void toggleRelay4() {
    relay4State = !relay4State;
    digitalWrite(RELAY4, relay4State ? LOW : HIGH);
    Serial.println(relay4State ? "Relay 4 ON (IR)" : "Relay 4 OFF (IR)");
}

void handleRelay1On() {
    relay1State = true;
    digitalWrite(RELAY1, LOW);
    server.send(200, "text/plain", "Relay 1 ON");
}

void handleRelay1Off() {
    relay1State = false;
    digitalWrite(RELAY1, HIGH);
    server.send(200, "text/plain", "Relay 1 OFF");
}

void handleRelay2On() {
    relay2State = true;
    digitalWrite(RELAY2, LOW);
    server.send(200, "text/plain", "Relay 2 ON");
}

void handleRelay2Off() {
    relay2State = false;
    digitalWrite(RELAY2, HIGH);
    server.send(200, "text/plain", "Relay 2 OFF");
}

void handleRelay3On() {
    relay3State = true;
    digitalWrite(RELAY3, LOW);
    server.send(200, "text/plain", "Relay 3 ON");
}

void handleRelay3Off() {
    relay3State = false;
    digitalWrite(RELAY3, HIGH);
    server.send(200, "text/plain", "Relay 3 OFF");
}

void handleRelay4On() {
    relay4State = true;
    digitalWrite(RELAY4, LOW);
    server.send(200, "text/plain", "Relay 4 ON");
}

void handleRelay4Off() {
    relay4State = false;
    digitalWrite(RELAY4, HIGH);
    server.send(200, "text/plain", "Relay 4 OFF");
}

void setup() {
    Serial.begin(115200);
    WiFi.softAP(ssid, password);
    Serial.println("Access Point Started");

    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
    pinMode(RELAY3, OUTPUT);
    pinMode(RELAY4, OUTPUT);

    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);
    digitalWrite(RELAY3, HIGH);
    digitalWrite(RELAY4, HIGH);

    irrecv.enableIRIn();
    Serial.println("IR Receiver Started");

    server.on("/relay1/on", handleRelay1On);
    server.on("/relay1/off", handleRelay1Off);
    server.on("/relay2/on", handleRelay2On);
    server.on("/relay2/off", handleRelay2Off);
    server.on("/relay3/on", handleRelay3On);
    server.on("/relay3/off", handleRelay3Off);
    server.on("/relay4/on", handleRelay4On);
    server.on("/relay4/off", handleRelay4Off);

    server.begin();
    Serial.println("HTTP Server Started");
}

void loop() {
    server.handleClient();

    if (irrecv.decode(&results)) {
        Serial.printf("IR Received: 0x%X\n", results.value);

        if (results.value == IR_CODE_RELAY1) {
            toggleRelay1();
        } else if (results.value == IR_CODE_RELAY2) {
            toggleRelay2();
        } else if (results.value == IR_CODE_RELAY3) {
            toggleRelay3();
        } else if (results.value == IR_CODE_RELAY4) {
            toggleRelay4();
        }

        irrecv.resume();
    }
}
