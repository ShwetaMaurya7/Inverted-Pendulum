#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

// MOTOR PINS
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int ENA = 5;
int ENB = 6;

// PID GAINS
float Kp = 25.0;
float Ki = 0.0;
float Kd = 1.2;

// VARIABLES
float angle = 0, gyroRate = 0;
float error, prevError = 0, integral = 0, derivative;
unsigned long lastTime = 0;
unsigned long startTime;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize MPU6050
  byte status = mpu.begin();
  Serial.print("MPU6050 status: ");
  Serial.println(status);
  delay(1000);
  mpu.calcOffsets(true, true);   // gyro + accel calibration

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  lastTime = micros();
  startTime = millis(); // 20-sec timer
}

void loop() {

  // Stop after 20 seconds
  if (millis() - startTime > 20000) {
    stopMotors();
    return;
  }

  mpu.update();
  angle = mpu.getAngleX();       // tilt angle in degrees
  gyroRate = mpu.getGyroX();     // gyro rate

  // PID calculations
  error = angle;
  integral += error;
  derivative = error - prevError;
  prevError = error;

  float control = (Kp * error) + (Ki * integral) + (Kd * derivative);
  control = constrain(control, -255, 255);

  driveMotors(control);
}

void driveMotors(float pwm) {
  int speed = abs(pwm);
  speed = constrain(speed, 0, 255);

  if (pwm > 0) {
    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    // Move backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
