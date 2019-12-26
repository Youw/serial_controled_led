#include <SoftwareSerial.h>

//const byte rx_pin = 2;
//const byte tx_pin = 3;
//SoftwareSerial bluetooth_hc06(rx_pin, tx_pin);
//SoftwareSerial *hc06 = &bluetooth_hc06;

const int WorkingPin = 10;
const int ResponcePin = 9;

void setup() {
  Serial1.begin(9600);
  pinMode(ResponcePin, OUTPUT); // turn if off
  pinMode(WorkingPin, OUTPUT);
}

void loop() {
  int in_data = Serial1.read();
  if(in_data >= 0) {
      const char cmd = in_data;
      digitalWrite(ResponcePin, HIGH);
      delay(20);
      digitalWrite(ResponcePin, LOW);
      delay(20);
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
