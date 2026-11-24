#include <Arduino.h>

constexpr uint8_t DoorPin = 2;
constexpr uint8_t ResetPin = 3;
constexpr uint8_t BuzzerPin = 8;
constexpr uint8_t AlarmLed = 9;
constexpr uint8_t ReadyLed = 10;

bool alarmActive = false;

void setup() {
  pinMode(DoorPin, INPUT_PULLUP);
  pinMode(ResetPin, INPUT_PULLUP);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(AlarmLed, OUTPUT);
  pinMode(ReadyLed, OUTPUT);
  digitalWrite(ReadyLed, HIGH);
  Serial.begin(9600);
  Serial.println(F("RPDT Class Home Alarm System"));
  Serial.println(F("Armed"));
}

void loop() {
  const bool doorOpen = digitalRead(DoorPin) == HIGH;
  const bool resetPressed = digitalRead(ResetPin) == LOW;
  const bool nextAlarmState = doorOpen || (alarmActive && !resetPressed);

  if (nextAlarmState != alarmActive) {
    alarmActive = nextAlarmState;
    digitalWrite(AlarmLed, alarmActive);
    digitalWrite(ReadyLed, !alarmActive);
    if (alarmActive) {
      tone(BuzzerPin, 1400);
      Serial.println(F("ALARM: Door opened"));
    } else {
      noTone(BuzzerPin);
      Serial.println(F("Alarm reset. Armed"));
    }
  }
}
