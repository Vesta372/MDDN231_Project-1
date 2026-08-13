//LED
// can be dimmed
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 6;
int led5 = 5;
int led6 = 3;

// On/Off Button
int powerbutton = 2;
int buttonValuePower;

//Flashing Lights Button
int flashingbutton = 4;
int buttonValueLight; 

//Potentiometer
int potVal;
int brightness = 0;

// On/Off Button
bool buttonON = false;
bool pressedbeforePower = false;

// Flashing Lights Button
bool buttonFlashing = false;
bool pressedbeforeLight = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(powerbutton, INPUT);
  Serial.begin(9600);
}

void loop() {
 // button on and off
  buttonValuePower = digitalRead(powerbutton);
    if (buttonValuePower == HIGH) {
      if (pressedbeforePower  == false) {
        pressedbeforePower = true;
        if (buttonON == true) {
          buttonON = false;
          digitalWrite(led6, LOW);
          digitalWrite(led5, LOW);
          digitalWrite(led4, LOW); 
          digitalWrite(led3, LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led1, LOW);
        } else {
          buttonON = true;
          buttonFlashing = false;
          digitalWrite(led6, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led1, HIGH);
        }
      }
    }

   if (buttonValuePower == LOW) {
    pressedbeforePower = false;
   }

   if (buttonON == true) {
   potentimeter ();
   lightflashing ();
    if (buttonFlashing == true) {
      flashinglights ();
    }
   }
  
  delay(10);
}

void potentimeter () {
potVal = analogRead(A0);

brightness = map(potVal, 0, 1023, 20, 255);

analogWrite(led6, brightness);
analogWrite(led5, brightness);
analogWrite(led4, brightness);
analogWrite(led1, brightness);
analogWrite(led2, brightness);
analogWrite(led3, brightness);
Serial.print(potVal);
Serial.print(" mapped: ");
Serial.println(brightness);
delay(10);
}

void lightflashing () {
 buttonValueLight = digitalRead(flashingbutton);
  if (buttonValueLight == HIGH) {
   if (pressedbeforeLight == false) {
     pressedbeforeLight = true;
     if (buttonFlashing == true) {
      buttonFlashing = false;
    } else {
      buttonFlashing = true;
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
    }
  }
 }

 if (buttonValueLight == LOW) {
  pressedbeforeLight = false;
 }

 delay(10);
}

void flashinglights () {
  digitalWrite(led1, LOW);
  digitalWrite(led6, HIGH);
  delay(100);
  digitalWrite(led6, LOW);
  digitalWrite(led5, HIGH);
  delay(100);
  digitalWrite(led5, LOW);
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led4, LOW);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  digitalWrite(led1, HIGH);
  delay(100);
}
