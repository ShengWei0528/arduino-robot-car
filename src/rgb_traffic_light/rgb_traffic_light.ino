/*
 * rgb_traffic_light.ino
 *
 * Hand transcription of the motoBlockly block program shown in
 * docs/images/blocks/rgb-traffic-light-blocks.png (screenshot dated 2020-03-16).
 * The Arduino code generated from those blocks was not kept, so this file
 * re-creates the same block sequence one-to-one. It has not been re-tested
 * on the hardware in this form.
 *
 * Only D9 and D10 are used. Assuming the RGB LED module's R pin is wired to
 * D9 and its G pin to D10 (the exact wiring was not recorded), the cycle is:
 *   green 20 s -> red + green (yellow) 2 s -> red 15 s
 * i.e. a traffic-light sequence.
 */
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}


void loop()
{
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(20000);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(2000);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    delay(15000);

}
