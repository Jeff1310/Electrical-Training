//Sophia Chen

// Complete the following TODOs for this program, then upload to your board.
// Correction in the lecture video: we provided a table for
// analog inputs -> expected output, but provided the wrong values
// analog inputs should be the following: 0 - 341, 342 - 682, and 683 - 1023

void setup() {
  // Any code you put here (in this function) will only be ran once
  // Typically you want to intialize your variables/IO pins

  Serial.begin(9600);
  pinMode(A0, INPUT);

  //PWM output pins
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  // ==========================================================================================
  // TODO: Intialize three PWM output pins and one analog input pin. Makesure the pins selected
  //       have PWM capabilities.
  // ==========================================================================================
}

void loop() {
  // Any code you put here (in this function) will be looped (ran over and over again)
  int val = analogRead(A0);
  int output = 0;                             

  if (val < 342) { // LED 1
    output = map(val, 0, 341, 0, 255);
    analogWrite(9, output);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    // TODO: Output the mapped PWM onto the LED. LED 2 and LED 3 should be OFF
    //       LED 1 will vary depending on analog input

  }

  if (val >= 342 && val <= 682) { // LED 2
    output = map(val, 0, 341, 0, 255);
    digitalWrite(9, HIGH);
    analogWrite(10, output);
    digitalWrite(11, LOW);
    // TODO: Map out the val of the potentiometer and output the mapped PWM onto the LED.
    //       LED 1 should be fully lit. LED 3 should be off. LED 2 will vary depending on analog input

  }


  if (val >= 683 && val <= 1023) { // LED 3
    output = map(val, 0, 341, 0, 255);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    analogWrite(11, output);
    // TODO: Insert missing values of if statement above.
    //       Map out the val of the potentiometer and output the mapped PWM onto the LED.
    //       LED 1 and 2 should be fully lit. LED 3 will vary depending on analog output
  }
}
