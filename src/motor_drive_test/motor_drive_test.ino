/*
 * motor_drive_test.ino
 *
 * Hand transcription of the motoBlockly block program shown in
 * docs/images/blocks/motor-drive-test-blocks.png (screenshot dated 2020-05-04).
 * The Arduino code generated from those blocks was not kept, so this file
 * re-creates the same block sequence one-to-one. It has not been re-tested
 * on the hardware in this form.
 *
 * Wiring used by the blocks (two-channel motor driver, L9110S on this car):
 *   Motor channel 1: D2 (digital) + D3 (PWM)  -> left motor
 *   Motor channel 2: D4 (digital) + D5 (PWM)  -> right motor
 *
 * With an L9110S-style driver, input pair (HIGH, 0) spins a motor one way,
 * (LOW, 255) spins it the other way, and (LOW, 0) stops it. The left/right
 * and forward/backward labels below follow the car's later remote-control
 * program (src/bluetooth_remote_control), where D2/D3 drive "motorl",
 * D4/D5 drive "motorr", and the forward key 'W' sets both motors to (HIGH, 0).
 */
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}


void loop()
{
    // Step 1: both motors, direction A (forward), 10 s
    digitalWrite(2,HIGH);
    analogWrite(3,0);
    digitalWrite(4,HIGH);
    analogWrite(5,0);
    delay(10000);
    // Stop, 2 s
    digitalWrite(4,LOW);
    analogWrite(5,0);
    digitalWrite(2,LOW);
    analogWrite(3,0);
    delay(2000);
    // Step 2: both motors, direction B (backward), 10 s
    digitalWrite(4,LOW);
    analogWrite(5,255);
    digitalWrite(2,LOW);
    analogWrite(3,255);
    delay(10000);
    // Stop, 2 s
    digitalWrite(4,LOW);
    analogWrite(5,0);
    digitalWrite(2,LOW);
    analogWrite(3,0);
    delay(2000);
    // Step 3: left motor only -> turns right around the stopped right wheel, 10 s
    digitalWrite(2,HIGH);
    analogWrite(3,0);
    digitalWrite(4,LOW);
    analogWrite(5,0);
    delay(10000);
    // Stop, 2 s
    digitalWrite(4,LOW);
    analogWrite(5,0);
    digitalWrite(2,LOW);
    analogWrite(3,0);
    delay(2000);
    // Step 4: right motor only -> turns left around the stopped left wheel, 10 s
    digitalWrite(2,LOW);
    analogWrite(3,0);
    digitalWrite(4,HIGH);
    analogWrite(5,0);
    delay(10000);
    // Stop, 2 s
    digitalWrite(4,LOW);
    analogWrite(5,0);
    digitalWrite(2,LOW);
    analogWrite(3,0);
    delay(2000);

}
