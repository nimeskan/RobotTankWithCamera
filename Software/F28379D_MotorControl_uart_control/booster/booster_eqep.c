
//
// Included Files
//
#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "booster_motor.h"
#include "booster_eqep.h"

MotorInfo LeftMotor =
{
 .motorNumber = LEFT_MOTOR
};
MotorInfo RightMotor =
{
 .motorNumber = RIGHT_MOTOR
};

__interrupt void EQEP1_interrupt();
__interrupt void EQEP2_interrupt();

void booster_eqep_initEQEP(uint32_t base);

//
// Function to configure eQEP1.
//
void booster_eqep_initAllEQEP(void)
{

    booster_eqep_initEQEP(EQEP1_BASE);
    //Register the interrupt
    Interrupt_register(INT_EQEP1, &EQEP1_interrupt);
    //Enable Interrupt
    Interrupt_enable(INT_EQEP1);

    booster_eqep_initEQEP(EQEP2_BASE);
    //Register the interrupt
    Interrupt_register(INT_EQEP2, &EQEP2_interrupt);
    //Enable Interrupt
    Interrupt_enable(INT_EQEP2);


}

void booster_eqep_initEQEP(uint32_t base)
{
    //
    // Configure the decoder for quadrature count mode
    //
    EQEP_setDecoderConfig(base, (EQEP_CONFIG_1X_RESOLUTION |
                                       EQEP_CONFIG_QUADRATURE |
                                       EQEP_CONFIG_NO_SWAP));

    EQEP_setEmulationMode(base, EQEP_EMULATIONMODE_RUNFREE);

    //
    // Configure the position counter to reset on an index event
    //
    EQEP_setPositionCounterConfig(base, EQEP_POSITION_RESET_UNIT_TIME_OUT,
                                  MAX_POSITION);

    //
    // Enable the unit timer, setting the frequency to 1000 Hz
    //
    EQEP_enableUnitTimer(base, (DEVICE_SYSCLK_FREQ/10));

    EQEP_enableInterrupt(base, EQEP_INT_UNIT_TIME_OUT);

    //
    // Configure the position counter to be latched on a unit time out
    //
    EQEP_setLatchMode(base, EQEP_LATCH_UNIT_TIME_OUT);


    //
    // Enable the eQEP1 module
    //
    EQEP_enableModule(base);

}

__interrupt void EQEP2_interrupt()
{
    uint16_t flags = EQEP_getInterruptStatus(EQEP2_BASE);
    if (flags & EQEP_INT_UNIT_TIME_OUT)
    {
        RightMotor.rawCurrentPosition = EQEP_getPositionLatch(EQEP2_BASE);
        if (RightMotor.rawCurrentPosition < MAX_POSITION/2)
        {
            //We moved forward
            RightMotor.currentTraveledDirection = MOTOR_FORWARD;
            RightMotor.currentDisplacedPosition = RightMotor.rawCurrentPosition;

        }
        else
        {
            //We moved Backward
            RightMotor.currentTraveledDirection = MOTOR_REVERSE;
            RightMotor.currentDisplacedPosition = MAX_POSITION - RightMotor.rawCurrentPosition;

        }
        RightMotor.instantaniousDirection = (EQep2Regs.QEPSTS.bit.QDF == 1)? MOTOR_FORWARD: MOTOR_REVERSE;
        if (RightMotor.currentTraveledDirection == MOTOR_FORWARD)
        {
            RightMotor.allTimeDisplacementPosition += RightMotor.currentDisplacedPosition;
            RightMotor.distanceTraveled += RightMotor.currentDisplacedPosition;
        }
        else
        {
            RightMotor.allTimeDisplacementPosition -= RightMotor.currentDisplacedPosition;
            RightMotor.distanceTraveled -= RightMotor.currentDisplacedPosition;
        }
    }

    EQEP_clearInterruptStatus(EQEP2_BASE, flags);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP5);
}


__interrupt void EQEP1_interrupt()
{
    uint16_t flags = EQEP_getInterruptStatus(EQEP1_BASE);
    if (flags & EQEP_INT_UNIT_TIME_OUT)
    {
        LeftMotor.rawCurrentPosition = EQEP_getPositionLatch(EQEP1_BASE);
        if (LeftMotor.rawCurrentPosition < MAX_POSITION/2)
        {
            //We moved forward
            LeftMotor.currentTraveledDirection = MOTOR_FORWARD;
            LeftMotor.currentDisplacedPosition = LeftMotor.rawCurrentPosition;

        }
        else
        {
            //We moved Backward
            LeftMotor.currentTraveledDirection = MOTOR_REVERSE;
            LeftMotor.currentDisplacedPosition = MAX_POSITION - LeftMotor.rawCurrentPosition;

        }
        LeftMotor.instantaniousDirection = (EQep1Regs.QEPSTS.bit.QDF == 1)? MOTOR_FORWARD: MOTOR_REVERSE;

        if (LeftMotor.currentTraveledDirection == MOTOR_FORWARD)
        {
            LeftMotor.allTimeDisplacementPosition += LeftMotor.currentDisplacedPosition;
            LeftMotor.distanceTraveled += LeftMotor.currentDisplacedPosition;
        }
        else
        {
            LeftMotor.allTimeDisplacementPosition -= LeftMotor.currentDisplacedPosition;
            LeftMotor.distanceTraveled -= LeftMotor.currentDisplacedPosition;
        }
    }

    EQEP_clearInterruptStatus(EQEP1_BASE, flags);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP5);
}
