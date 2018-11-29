/*
 * booster_epwm.h
 *
 *  Created on: Sep 16, 2018
 *      Author: a0225962
 */

#ifndef BOOSTER_BOOSTER_EPWM_H_
#define BOOSTER_BOOSTER_EPWM_H_

#define EPWM_M1_BASE     EPWM2_BASE
#define EPWM_M2_BASE     EPWM1_BASE

#define EPWM_M3_BASE     EPWM4_BASE
#define EPWM_M4_BASE     EPWM3_BASE

#define EPWM_M5_BASE     EPWM5_BASE
#define EPWM_M6_BASE     EPWM6_BASE

extern uint32_t MotorBases[LAST_MOTOR_INDEX + 1];

void booster_epwm_initAllEPWMs();
void booster_epwm_init(uint32_t epwm_base);
void booster_epwm_setDuty(uint32_t epwm_base, EPWM_CounterCompareModule cmp_module, uint32_t duty);
void booster_epwm_startMotor(MotorNumber motor, MotorDirection dir, uint16_t speed);
void booster_epwm_stopMotor(MotorNumber motor);
void booster_epwm_stopFree(MotorNumber motor);

void booster_motor_moveMotor(MotorNumber motor, MotorDirection dir, uint16_t speed, uint32_t duration_ms);
#endif /* BOOSTER_BOOSTER_EPWM_H_ */
