
//
// Included Files
//

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "booster_motor.h"
#include "booster_epwm.h"



void booster_motor_moveForMillis(MotorInfo* motor, MotorDirection dir, uint16_t speed, uint32_t duration_ms)
{
    booster_epwm_startMotor(motor->motorNumber, dir, speed);
    DELAY_US(duration_ms * 1000);
    booster_epwm_stopMotor(motor->motorNumber);
}

int32_t booster_motor_moveForTicks(MotorInfo* motor, uint16_t speed, int32_t distance_ticks)
{
    int32_t actualDistanceTraveled = 0;
    MotorDirection dir;

    motor->distanceTraveled = 0;
    dir = (distance_ticks > 0)?MOTOR_FORWARD:MOTOR_REVERSE;
    booster_epwm_startMotor(motor->motorNumber, dir, speed);
    if (distance_ticks < 0)
    {
        while (distance_ticks < motor->distanceTraveled);
    }
    else
    {
        while (distance_ticks > motor->distanceTraveled);
    }
    actualDistanceTraveled = motor->distanceTraveled;
    booster_epwm_stopMotor(motor->motorNumber);

    return actualDistanceTraveled;
}

void booster_motor_moveTwoMotorsForTicks(MotorInfo* motor1, MotorInfo* motor2, uint16_t speed, int32_t motor1_distance_ticks, int32_t motor2_distance_ticks)
{
    MotorDirection dir;
    uint16_t motor1Off = 0;
    uint16_t motor2Off = 0;

    motor1->distanceTraveled = 0;
    motor2->distanceTraveled = 0;
    dir = (motor1_distance_ticks > 0)?MOTOR_FORWARD:MOTOR_REVERSE;
    booster_epwm_startMotor(motor1->motorNumber, dir, speed);
    dir = (motor2_distance_ticks > 0)?MOTOR_FORWARD:MOTOR_REVERSE;
    booster_epwm_startMotor(motor2->motorNumber, dir, speed);

    if (motor1_distance_ticks < 0 && motor2_distance_ticks < 0)
    {
        while (motor1_distance_ticks < motor1->distanceTraveled ||
               motor2_distance_ticks < motor2->distanceTraveled )
        {
            if (motor1_distance_ticks >= motor1->distanceTraveled && !motor1Off)
            {
                booster_epwm_stopMotor(motor1->motorNumber);
                motor1Off = 1;
            }
            if (motor2_distance_ticks >= motor2->distanceTraveled && !motor2Off)
            {
                booster_epwm_stopMotor(motor2->motorNumber);
                motor2Off = 1;
            }
        }
    }
    else if (motor1_distance_ticks >= 0 && motor2_distance_ticks >= 0)
    {
        while (motor1_distance_ticks > motor1->distanceTraveled ||
               motor2_distance_ticks > motor2->distanceTraveled )
        {
            if (motor1_distance_ticks <= motor1->distanceTraveled && !motor1Off)
            {
                booster_epwm_stopMotor(motor1->motorNumber);
                motor1Off = 1;
            }
            if (motor2_distance_ticks <= motor2->distanceTraveled && !motor2Off)
            {
                booster_epwm_stopMotor(motor2->motorNumber);
                motor2Off = 1;
            }
        }
    }
    else if (motor1_distance_ticks < 0 && motor2_distance_ticks >= 0)
    {
        while (motor1_distance_ticks < motor1->distanceTraveled ||
               motor2_distance_ticks > motor2->distanceTraveled )
        {
            if (motor1_distance_ticks >= motor1->distanceTraveled && !motor1Off)
            {
                booster_epwm_stopMotor(motor1->motorNumber);
                motor1Off = 1;
            }
            if (motor2_distance_ticks <= motor2->distanceTraveled && !motor2Off)
            {
                booster_epwm_stopMotor(motor2->motorNumber);
                motor2Off = 1;
            }
        }
    }
    else if (motor1_distance_ticks >= 0 && motor2_distance_ticks < 0)
    {
        while (motor1_distance_ticks >= motor1->distanceTraveled ||
               motor2_distance_ticks < motor2->distanceTraveled )
        {
            if (motor1_distance_ticks <= motor1->distanceTraveled && !motor1Off)
            {
                booster_epwm_stopMotor(motor1->motorNumber);
                motor1Off = 1;
            }
            if (motor2_distance_ticks >= motor2->distanceTraveled && !motor2Off)
            {
                booster_epwm_stopMotor(motor2->motorNumber);
                motor2Off = 1;
            }
        }
    }

    booster_epwm_stopMotor(motor2->motorNumber);
    booster_epwm_stopMotor(motor1->motorNumber);

    return;
}
