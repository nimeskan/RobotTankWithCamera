
//
// Included Files
//
#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "booster_motor.h"
#include "booster_epwm.h"


#define EPWM_TBPRD  2000U

uint32_t MotorBases[LAST_MOTOR_INDEX + 1] =
{
     0,
     EPWM_M1_BASE, EPWM_M2_BASE, EPWM_M3_BASE,
     EPWM_M4_BASE, EPWM_M5_BASE, EPWM_M6_BASE
};

void booster_epwm_startMotor(MotorNumber motor, MotorDirection dir, uint16_t speed)
{
    uint32_t motor_base = MotorBases[motor];

    if (speed > 100)
        speed = 100;

    if (dir == MOTOR_FORWARD)
    {
        booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_B, 0);
        booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_A, speed);
    }
    else
    {
        booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_B, speed);
        booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_A, 0);
    }
}

void booster_epwm_stopMotor(MotorNumber motor)
{
    uint32_t motor_base = MotorBases[motor];
    booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_B, 100);
    booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_A, 100);
}

void booster_epwm_stopFree(MotorNumber motor)
{
    uint32_t motor_base = MotorBases[motor];
    booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_B, 0);
    booster_epwm_setDuty(motor_base, EPWM_COUNTER_COMPARE_A, 0);
}

void booster_epwm_initAllEPWMs()
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    booster_epwm_init(EPWM1_BASE);
    booster_epwm_init(EPWM2_BASE);
    booster_epwm_init(EPWM3_BASE);
    booster_epwm_init(EPWM4_BASE);
    booster_epwm_init(EPWM5_BASE);
    booster_epwm_init(EPWM6_BASE);

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

}

void booster_epwm_setDuty(uint32_t epwm_base, EPWM_CounterCompareModule cmp_module, uint32_t duty)
{
    uint16_t result = (uint16_t)(((duty *(EPWM_TBPRD)))/100);
    EPWM_setCounterCompareValue(epwm_base,
                                cmp_module,
                                result);
}

void booster_epwm_init(uint32_t epwm_base)
{

    EPWM_setTimeBasePeriod(epwm_base, EPWM_TBPRD - 1);
    EPWM_setPhaseShift(epwm_base, 0U);
    EPWM_setTimeBaseCounter(epwm_base, 0U);
    EPWM_setEmulationMode(epwm_base, EPWM_EMULATION_FREE_RUN);

    EPWM_setCounterCompareValue(epwm_base,
                                EPWM_COUNTER_COMPARE_A,
                                0);
    EPWM_setCounterCompareValue(epwm_base,
                                EPWM_COUNTER_COMPARE_B,
                                0);

    EPWM_setTimeBaseCounterMode(epwm_base, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(epwm_base);
    EPWM_setClockPrescaler(epwm_base,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(epwm_base,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(epwm_base,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);


    EPWM_setActionQualifierAction(epwm_base,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    EPWM_setActionQualifierAction(epwm_base,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    EPWM_setActionQualifierAction(epwm_base,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);


    //EPWM_setInterruptSource(epwm_base, EPWM_INT_TBCTR_ZERO);
    //EPWM_enableInterrupt(epwm_base);
    //EPWM_setInterruptEventCount(epwm_base, 3U);

}
