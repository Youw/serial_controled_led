#include <SoftwareSerial.h>

const byte rx_pin = 2;
const byte tx_pin = 3;
SoftwareSerial bluetooth_hc06(rx_pin, tx_pin);
SoftwareSerial *hc06 = &bluetooth_hc06;

const int WorkingPin = 10;

void setup() {
  hc06->begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // turn if off
  pinMode(WorkingPin, OUTPUT);
}

void loop() {
  if(hc06->available() > 0) {
      const char cmd = hc06->read();
      digitalWrite(LED_BUILTIN, HIGH);
      delay(50);
      digitalWrite(LED_BUILTIN, LOW);
      delay(50);
      if (cmd == '0') {
        digitalWrite(WorkingPin, LOW);
      }
      else if (cmd == '1') {
        digitalWrite(WorkingPin, HIGH);
      }
//      else {
//        digitalWrite(WorkingPin, HIGH);
//        delay(200);
//        digitalWrite(WorkingPin, LOW);
//        delay(200);
//        digitalWrite(WorkingPin, HIGH);
//        delay(200);
//        digitalWrite(WorkingPin, LOW);
//        delay(200);
//      }
  }
}
