/*
 * booster_pinout.h
 *
 *  Created on: Sep 14, 2018
 *      Author: a0225962
 */

#ifndef BOOSTER_PINOUT_H_
#define BOOSTER_PINOUT_H_

// PINMAP

// CHANNEL1
#define CH1_BIN2                0
#define CH1_BIN1                1

#define CH1_AIN2                3
#define CH1_AIN1                2

#define CH1_DEC                 58
#define CH1_FAULT               61

#define CH1_BI1                 29
#define CH1_BI0                 125

#define CH1_AI1                 124
#define CH1_AI0                 59

#define CH1_BIN2_CONFIG         GPIO_0_EPWM1A
#define CH1_BIN1_CONFIG         GPIO_1_EPWM1B

#define CH1_AIN2_CONFIG         GPIO_3_EPWM2B
#define CH1_AIN1_CONFIG         GPIO_2_EPWM2A

#define CH1_DEC_CONFIG          GPIO_58_GPIO58
#define CH1_FAULT_CONFIG        GPIO_61_GPIO61

#define CH1_BI1_CONFIG          GPIO_29_GPIO29
#define CH1_BI0_CONFIG          GPIO_125_GPIO125

#define CH1_AI1_CONFIG          GPIO_124_GPIO124
#define CH1_AI0_CONFIG          GPIO_59_GPIO59

// CHANNEL 2
#define CH2_BIN2                4
#define CH2_BIN1                5

#define CH2_AIN2                6
#define CH2_AIN1                7

#define CH2_DEC                 63
#define CH2_FAULT               66

#define CH2_BI1                 24
#define CH2_BI0                 16

//#define CH2_AI1                 DAC3
//#define CH2_AI0                 DAC2

#define CH2_BIN2_CONFIG         GPIO_4_EPWM3A
#define CH2_BIN1_CONFIG         GPIO_5_EPWM3B

#define CH2_AIN2_CONFIG         GPIO_6_EPWM4A
#define CH2_AIN1_CONFIG         GPIO_7_EPWM4B

#define CH2_DEC_CONFIG          GPIO_63_GPIO63
#define CH2_FAULT_CONFIG        GPIO_66_GPIO66

#define CH2_BI1_CONFIG          GPIO_24_GPIO24
#define CH2_BI0_CONFIG          GPIO_16_GPIO16

//#define CH2_AI1_CONFIG          GPIO_14_GPIO14
//#define CH2_AI0_CONFIG          GPIO_25_GPIO25

// CHANNEL 3
#define CH3_BIN2                8
#define CH3_BIN1                9

#define CH3_AIN2                11
#define CH3_AIN1                10

#define CH3_DEC                 14
#define CH3_FAULT               15

#define CH3_BIN2_CONFIG         GPIO_8_EPWM5A
#define CH3_BIN1_CONFIG         GPIO_9_EPWM5B

#define CH3_AIN2_CONFIG         GPIO_11_EPWM6B
#define CH3_AIN1_CONFIG         GPIO_10_EPWM6A

#define CH3_DEC_CONFIG          GPIO_14_GPIO14
#define CH3_FAULT_CONFIG        GPIO_15_GPIO15

// EQEPs
// Channel1
#define CH1_EQEPA               20
#define CH1_EQEPB               21
#define CH1_EQEPI               99

#define CH2_EQEPA               54
#define CH2_EQEPB               55
#define CH2_EQEPI               57

#define CH1_EQEPA_CONFIG        GPIO_20_EQEP1A
#define CH1_EQEPB_CONFIG        GPIO_21_EQEP1B
#define CH1_EQEPI_CONFIG        GPIO_99_EQEP1I

#define CH2_EQEPA_CONFIG        GPIO_54_EQEP2A
#define CH2_EQEPB_CONFIG        GPIO_55_EQEP2B
#define CH2_EQEPI_CONFIG        GPIO_57_EQEP2I

void booster_Pinout_init();


#endif /* BOOSTER_PINOUT_H_ */
