int ledyellow = 11;
int ledgreen = 12;
int ledred = 13;
int buttonpin = 2;
int buttonValue;
bool buttonON = false;
bool toggle = false;

void setup() {
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(buttonpin, INPUT);
}

void loop() {
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

  delay(10);
}



//buttonON = true;
//digitalWrite(ledred, HIGH);
//digitalWrite(ledgreen, HIGH);
//digitalWrite(ledyellow, HIGH);
