//LED
// can be dimmed
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 6;
int led5 = 5;
int led6 = 3;

//Button
int buttonpin = 2;
int buttonValue;

//Potentiometer
int potVal;
int brightness = 0;

bool buttonON = false;
bool toggle = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
}

void loop() {
 // button on and off
  buttonValue = digitalRead(buttonpin);
    if (buttonValue == HIGH) {
      if (toggle  == false) {
        toggle = true;
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
          digitalWrite(led6, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led1, HIGH);
        }
      }
    }
   if (buttonValue == LOW) {
    toggle = false;
   }

   if (buttonON == true) {
   potentimeter ();
   }
  
  delay(10);
}

void potentimeter () {
potVal = analogRead(A0);

brightness = map(potVal, 0, 1023, 0, 255);

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

