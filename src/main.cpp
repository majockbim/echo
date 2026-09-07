#include "../include/main.hpp"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int SERVO_MIN = 150, SERVO_MAX = 600;

/* HAL */
uint8_t readSwitches() {
    // read discrete inputs from module in slot 1
    return P1.readDiscrete(1);
}

void setServoAngle(uint8_t servoNum, int angle) {
    // safety constraints
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    int pulseLength = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);

    pwm.setPWM(servoNum, 0, pulseLength);
}   

/* main lifecycle */
void setup() {
    Serial.begin(115200); // baud rate

    Serial.println("initializing P1AM backplane");
    while (!P1.init()) {
        delay(100);
    }
    Serial.println("P1AM backplane initialized");

    Serial.println("initializing PWM driver");
    pwm.begin();

    pwm.setPWMFreq(50); // 20ms period
    
    Serial.println("hardware initialized!");
}

void loop() {
    // todo: state machine logic
}
