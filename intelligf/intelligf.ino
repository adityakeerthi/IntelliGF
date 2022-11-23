String inp;
#define LED_R 10
#define LED_C 11
#define LED_G 12

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_G, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    inp = Serial.readStringUntil('\n');
    if (inp == "r") {
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_G, LOW);
      Serial.write("Recycling on");
    } else if (inp == "c") {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_G, LOW);
      Serial.write("Compost on");
    } else if (inp == "g") {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_G, HIGH);
      Serial.write("Garbage on");
    } else if (inp == "done") {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_G, LOW);
      Serial.write("All of");
    } else if (inp == "clear") {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_G, LOW);
      Serial.write("Clear");
    } else {
      Serial.write("Invalid input");
    }
  }
}