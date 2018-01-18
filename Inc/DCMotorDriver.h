/**
 * @file    DCMotorDriver.h
 * @author  C-Bot
 * @date    14 jan. 2018
 * @brief   VNH7040 DC Motor Driver
 */

#ifndef INC_DCMOTOR_H_
#define INC_DCMOTOR_H_

#include "common.h"

/*----------------------------------------------------------------------------*/
/* Definitions                                                                */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Declaration                                                                */
/*----------------------------------------------------------------------------*/

/**
 * @brief Motor Driver Identifier
 */
enum Motor
{
	MOT1 = 0,
	MOT2,
	MOTOR_MAX
};

/**
 * @brief Motor Direction
 */
enum Direction
{
    FORWARD,
    REVERSE
};

/**
 * @brief
 * @param
 */
void DCMotor_Init ();

/**
 * @brief Set motor speed in percent (-1.0 to 1.0)
 * @param percent : Motor speed in percent
 */
void DCMotor_SetMotorSpeed (enum Motor motor, float32_t percent);

void DCMotor_Brake(enum Motor motor, float32_t percent);


#endif /* INC_DCMOTOR_H_ */
