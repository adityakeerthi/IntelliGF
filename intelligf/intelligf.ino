#include <Stepper.h>

const int steps_per_output_revolution = 32 * 64; // 2048
const int steps_per_motor_revolution = 32;
const int rpm = 5;
const int categories = 3; // number of categories that we are sorting

int position = 0;
// position will always be (position % 3)
// if position = 0, then it's at recycling
// if position = 1, then it's at trash
// if position = 2, then it's at gm (glass and metal)

String inputStream;
const float resolution = 5.625; // 360/64 = 5.625 --> each step spins 5.625 degrees for the 28BYJ-48 Motor

int step_degree(float desiredDegree) {
  return (desiredDegree/resolution);
};

int position_conversion(String state) {
  if (state == "recycling") return 0;
  if (state == "trash") return 1;
  if (state == "gm") return 2;
}

// Current wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

Stepper motor = Stepper(steps_per_output_revolution, 8, 9, 10, 11);

void setup() {
  motor.setSpeed(rpm);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    inputStream = Serial.readStringUntil('\n');
    position = position % categories;
    int desiredPosition = position_conversion(inputStream);

    if (position == desiredPosition) {
      // We are already in the position so we don't need to move
      Serial.write("Stay at the same place");
    }
    else {
      int direction = desiredPosition - position;
      if (inputStream == "recycling") {
        Serial.write("Recycking yeah?");
        direction = 0 - position;
      } else if (inputStream == "trash") {
        direction = 1 - position;
      } else if (inputStream == "gm") {
        direction = 2 - position;
      } else {
        Serial.write("Invalid Input");
      }


      if (abs(direction) == 2) {
        direction = (direction/abs(direction)) * -1;
      }

      if (direction == -1) {
        Serial.write("Move counterclockwise");
        position += 2;
      } else {
        Serial.write("Move clockwise");
        position += 1;
      }

      motor.step(step_degree((360/categories) * direction));      
    }

  }
  motor.step(steps_per_output_revolution);
  delay(1000);
}