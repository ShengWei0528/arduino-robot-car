/*
 * bluetooth_remote_control.ino
 *
 * Final program of the car: drive it from a phone over Bluetooth.
 *
 * Hand transcription of the motoBlockly-generated code shown in the project's
 * final report (slides "小車程式編寫", July 2020). The block version is in
 * docs/images/blocks/bluetooth-remote-control-blocks.png and the code
 * screenshots are bluetooth-remote-control-code-1.png / -code-2.png.
 * The original .ino file was not kept, so this file re-creates the code
 * line by line. It has not been re-tested on the hardware in this form.
 *
 * Wiring:
 *   Bluetooth serial module on the hardware serial port (D0 RX / D1 TX),
 *   9600 baud. Unplug it while uploading, because USB uses the same pins.
 *   Left motor  (motorl): D2 (digital) + D3 (PWM), L9110S channel 1
 *   Right motor (motorr): D4 (digital) + D5 (PWM), L9110S channel 2
 *
 * Commands (one character, sent by the phone app):
 *   'W' forward      go( 255,  255)
 *   'S' backward     go(-255, -255)
 *   'D' turn right   go( 255,    0)  left wheel only
 *   'A' turn left    go(   0,  255)  right wheel only
 *   'F' stop         go(   0,    0)
 * KEY keeps the last command, so the car keeps moving until a new character
 * arrives. The app sends W/S/A/D when an arrow button is pressed and F when
 * it is released, so the car moves only while a button is held.
 *
 * The helper s() (stop) is defined but never called; it is kept as in the
 * original.
 */
char  KEY;
void motorl(int speed) {
  if (speed > 0) {
    digitalWrite(2,HIGH);
    analogWrite(3,(255 - speed));
  } else {
    digitalWrite(2,LOW);
    analogWrite(3,(0 - speed));
  }
}

void motorr(int speed) {
  if (speed > 0) {
    digitalWrite(4,HIGH);
    analogWrite(5,(255 - speed));
  } else {
    digitalWrite(4,LOW);
    analogWrite(5,(0 - speed));
  }
}

void s() {
  digitalWrite(2,LOW);
  analogWrite(3,0);
  digitalWrite(4,LOW);
  analogWrite(5,0);
}

void go(int speedl, int speedr) {
  motorl(speedl);
  motorr(speedr);
}

void setup()
{
  Serial.begin(9600);
  KEY = ' ';
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}


void loop()
{
    if (Serial.available() > 0) {
      KEY = Serial.read();
    }
    if (KEY == 'W') {
      go(255, 255);
    }
    if (KEY == 'S') {
      go(-255, -255);
    }
    if (KEY == 'D') {
      go(255, 0);
    }
    if (KEY == 'A') {
      go(0, 255);
    }
    if (KEY == 'F') {
      go(0, 0);
    }

}
