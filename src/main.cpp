#include "../include/main.hpp"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int SERVO_MIN = 150, SERVO_MAX = 600;

/* memory & state */
struct Waypoint {
    int angles[4];
};

const int MAX_WAYPOINTS = 50;
Waypoint sequence[MAX_WAYPOINTS];
int waypointCount = 0;

int currentAngles[4] = {90, 90, 90, 90}; // start at 90deg

// rate limit jog speed for smoothness
unsigned long lastJogTime = 0;
const int JOG_DELAY_MS = 20;

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
    uint8_t switches = readSwitches();

    uint8_t switch2 = bitRead(switches, 1); // sw2 -> bit 1
    uint8_t switch3 = bitRead(switches, 2);

    uint8_t selectedServo = (sw3 << 1) | sw2; // 0-3

    /* jogging logic */
    bool jogForward = bitRead(switches, 4); // sw5 -> bit 4
    bool jogBackward = bitRead(switches, 5);


    
}
