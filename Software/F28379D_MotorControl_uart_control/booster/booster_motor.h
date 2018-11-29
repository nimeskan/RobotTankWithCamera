/*
 * motor.h
 *
 *  Created on: Sep 30, 2018
 *      Author: a0225962
 */

#ifndef BOOSTER_BOOSTER_MOTOR_H_
#define BOOSTER_BOOSTER_MOTOR_H_


#define LAST_MOTOR_INDEX        6
#define FIRST_MOTOR_INDEX       1


typedef enum{
    MOTOR_1 = 1,
    MOTOR_2 = 2,
    MOTOR_3 = 3,
    MOTOR_4 = 4,
    MOTOR_5 = 5,
    MOTOR_6 = 6
} MotorNumber;

typedef enum{
    MOTOR_FORWARD = 0,
    MOTOR_REVERSE = 1
} MotorDirection;

typedef struct{
    MotorNumber motorNumber;

    MotorDirection instantaniousDirection;
    MotorDirection currentTraveledDirection;
    uint32_t rawCurrentPosition;
    uint32_t currentDisplacedPosition;
    int32_t allTimeDisplacementPosition;

    int32_t currentSpeed;

    int32_t distanceTraveled;

} MotorInfo;

#define LEFT_MOTOR      MOTOR_6 //Bot
#define RIGHT_MOTOR     MOTOR_5 //Top

extern MotorInfo LeftMotor;
extern MotorInfo RightMotor;

void booster_motor_moveForMillis(MotorInfo* motor, MotorDirection dir, uint16_t speed, uint32_t duration_ms);
int32_t booster_motor_moveForTicks(MotorInfo* motor, uint16_t speed, int32_t distance_ticks);
void booster_motor_moveTwoMotorsForTicks(MotorInfo* motor1, MotorInfo* motor2, uint16_t speed, int32_t motor1_distance_ticks, int32_t motor2_distance_ticks);
#endif /* BOOSTER_BOOSTER_MOTOR_H_ */
