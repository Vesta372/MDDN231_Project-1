//LED
int ledyellow = 11;
int ledgreen = 10;
int ledred = 9;
//Button
int buttonpin = 2;
int buttonValue;
//Potentiometer
int potVal;
int brightness = 0;

bool buttonON = false;
bool toggle = false;

void setup() {
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
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
          digitalWrite(ledred, LOW);
          digitalWrite(ledgreen, LOW);
          digitalWrite(ledyellow, LOW);
        } else {
          buttonON = true;
          digitalWrite(ledred, HIGH);
          digitalWrite(ledgreen, HIGH);
          digitalWrite(ledyellow, HIGH);
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

analogWrite(ledyellow, brightness);
analogWrite(ledgreen, brightness);
analogWrite(ledred, brightness);
Serial.print(potVal);
Serial.print(" mapped: ");
Serial.println(brightness);
delay(10);
}
