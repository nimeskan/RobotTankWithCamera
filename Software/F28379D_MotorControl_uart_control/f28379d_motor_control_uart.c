
//
// Included Files
//
#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "booster/booster_motor.h"
#include "booster/booster_pinout.h"
#include "booster/booster_epwm.h"
#include "booster/booster_eqep.h"
#include "booster/booster_sci.h"

uint16_t motor_speed = 75;
MotorNumber motor = MOTOR_1;
uint16_t doCMD = 0;
uint16_t duration = 800;
int32_t leftTicks = 0;
int32_t RightTicks = 0;
MotorDirection dir = MOTOR_REVERSE;



//
// Main
//
void main(void)
{
   // Initialize device clock and peripherals
   Device_init();
   // Disable pin locks and enable internal pull ups.
   Device_initGPIO();
   // Initialize PIE and clear PIE registers. Disables CPU interrupts.
   Interrupt_initModule();
   // Initialize the PIE vector table with pointers to the shell Interrupt
   Interrupt_initVectorTable();

   booster_Pinout_init();

   SysCtl_delay(200000000/4);
   GPIO_writePin(34, 0);

   booster_epwm_initAllEPWMs();

   booster_sci_init();
   // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
   EINT;
   ERTM;

   booster_eqep_initAllEQEP();


   while(1)
   {
       if (NewCommandAvailable)
       {
           NewCommandAvailable = 0;

           GPIO_writePin(31, 0);
           leftTicks = (int32_t)((CommandReceivedData[1] << 8u) + CommandReceivedData[2]);
           RightTicks = (int32_t)((CommandReceivedData[4] << 8u) + CommandReceivedData[5]);
           if (CommandReceivedData[0]) {leftTicks = -1*leftTicks;}
           if (CommandReceivedData[3]) {RightTicks = -1*RightTicks;}
           booster_motor_moveTwoMotorsForTicks(&RightMotor, &LeftMotor, motor_speed, RightTicks, leftTicks);

           GPIO_writePin(31, 1);
       }
   }
}

//
// End of File
//
