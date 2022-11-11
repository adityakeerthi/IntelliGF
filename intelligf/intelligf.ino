String inp;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    inp = Serial.readStringUntil('\n');
    if (inp == "on") {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.write("LED on");
    } else if (inp == "off") {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.write("LED off");
    } else {
      Serial.write("Invalid input");
    }
  }
}