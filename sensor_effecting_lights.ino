int ledyellow = 11;
int ledgreen = 12;
int ledred = 13;
int buttonpin = 2;
int buttonValue;

bool buttonON = false;
bool toggle = false;

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;


void setup() {
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(buttonpin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // distance sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");             
  Serial.println(distance);

  updateled(ledyellow, 20);
  updateled(ledgreen, 10);
  updateled(ledred, 5);

// turn lights on and off
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



