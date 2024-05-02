// Define pin numbers for the motor control
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int enablePin1 = 6;
const int enablePin2 = 9;
// Define pin numbers for the IR sensors
const int leftSensorPin = A0;  // Analog pin for left sensor
const int rightSensorPin = A1; // Analog pin for right sensor

// Define threshold values for sensor readings
const int sensorThreshold = 700; // Adjust this value as needed

void setup() {
  // Initialize motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  // Initialize IR sensor pins as inputs
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(leftSensorPin);
  int rightSensorValue = analogRead(rightSensorPin);

  // Determine robot movement based on sensor readings
  if (leftSensorValue < sensorThreshold && rightSensorValue < sensorThreshold) {
    // Both sensors detect the line -> move forward
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin1, 150);
    analogWrite(enablePin2, 150);
  } else if (leftSensorValue < sensorThreshold && rightSensorValue >= sensorThreshold) {
    // Left sensor detects the line -> turn left
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin1, 100);
    analogWrite(enablePin2, 100);
  } else if (leftSensorValue >= sensorThreshold && rightSensorValue < sensorThreshold) {
    // Right sensor detects the line -> turn right
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(enablePin1, 100);
    analogWrite(enablePin2, 100);
  } else {
    // No sensor detects the line -> stop
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin1, 0);
    analogWrite(enablePin2, 0);
  }
}