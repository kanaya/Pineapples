
const int SW0 = A0;
const int SW1 = A1;
const int SW2 = A2;
const int SW3 = A3;
const int SW4 = A4;
const int SW5 = A5;
const int SW6 = 4;
const int SW7 = 8;

const int LED0 = 3;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 9;
const int LED4 = 10;
const int LED5 = 11;
const int LED6 = 13;
const int LED7 = 2;

const int SWs[] = { SW0, SW1, SW2, SW3, SW4, SW5, SW6, SW7 };
const int LEDs[] = { LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7 };

// the setup function runs once when you press reset or power the board
void setup() {
  for (int i = 0; i < 8; ++i) {
    pinMode(SWs[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 8; ++i) {
    pinMode(LEDs[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 8; ++i) {
    int sw = digitalRead(SWs[i]);
    if (!sw) {
      digitalWrite(LEDs[i], HIGH);
    }
    else {
      digitalWrite(LEDs[i], LOW);
    }
  }
  delay(200);
}
