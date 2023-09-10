/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

const int N_PWMPins = 7;
const int PWMPins[] = { 3, 5, 6, 9, 10, 11, 13 };
const int COUNT = 1024;

// returns 0-255 value
int powan(int a) {
  // 0 <= a < 1024
  float x, y;
  int r;
  x = (float)a / 1024.0 * 2.0 * M_PI;
  y = (sin(x) + 1.0) * 120.0 + 15.0;
  r = (int)y;
  return (r > 256) ? 255 : r;
}

int saw(int a) {
  // 0 <= a < 1024
  int b;
  if (a < COUNT / 2) {
    b = a / 2;
  }
  else {
    b = (COUNT - a - 1) / 2;
  }
  return (b > 256) ? 255 : b;
}


// the setup function runs once when you press reset or power the board
void setup() {
  for (int n = 0; n < N_PWMPins; ++n) {
    pinMode(PWMPins[n], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  for (int a = 0; a < COUNT; ++a) {
    for (int n = 0; n < N_PWMPins; ++n) {
      int v = saw(a);
      analogWrite(PWMPins[n], v);
    }
    delay(10);
  }
}
