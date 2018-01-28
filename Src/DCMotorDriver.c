/**
 * @file    DCMotorDriver.c
 * @author  C-Bot
 * @date    14 jan. 2018
 * @brief   VNH7040 DC Motor Driver
 */

#include "DCMotorDriver.h"

#include "stm32f0xx_hal.h"
#include "main.h"
#include "tim.h"

/**
 * VNH7040
 *
 * Device Power-up end:
 *  - INA : Clockwise
 *  - INB : Counter clockwise
 *  - 
 *  - ...
 *
 */


/*----------------------------------------------------------------------------*/
/* Definitions                                                                */
/*----------------------------------------------------------------------------*/

#define MOT1_TIMER          (&htim15)
#define MOT2_TIMER          (&htim15)
#define MOT1_TIMER_CHANNEL  (TIM_CHANNEL_1)
#define MOT2_TIMER_CHANNEL  (TIM_CHANNEL_2)

/*----------------------------------------------------------------------------*/
/* Private members                                                            */
/*----------------------------------------------------------------------------*/

static enum Direction direction = FORWARD;

/*----------------------------------------------------------------------------*/
/* Private function                                                           */
/*----------------------------------------------------------------------------*/

static void SetSpeed (enum Motor motor, float32_t percent);
static void SetDirection (enum Motor motor, enum Direction direction);
static void Freewheel (enum Motor motor);
static void Brake (enum Motor motor);

/*----------------------------------------------------------------------------*/
/* Implementation                                                             */
/*----------------------------------------------------------------------------*/

void DCMotor_Init ()
{
    // Direction : Forward
    HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
    
    // Power PWM
    HAL_TIM_PWM_Start(MOT1_TIMER, MOT1_TIMER_CHANNEL);
    __HAL_TIM_SET_COMPARE(MOT1_TIMER, MOT1_TIMER_CHANNEL, 0);

    HAL_TIM_PWM_Start(MOT2_TIMER, MOT2_TIMER_CHANNEL);
    __HAL_TIM_SET_COMPARE(MOT2_TIMER, MOT2_TIMER_CHANNEL, 0);
}

void DCMotor_SetMotorSpeed (enum Motor motor, float32_t percent)
{
    // Limits
    if(percent > 1.0f)
        percent = 1.0f;
    else if(percent < -1.0f)
        percent = -1.0f;

    // Simple speed
    if(percent > 0.0f) {
        SetDirection(motor, FORWARD);
        SetSpeed(motor, percent);
    }
    else if(percent < 0.0f) {
        SetDirection(motor, REVERSE);
        SetSpeed(motor, -percent);
    }
    else {
        SetSpeed(motor, 0.0f);
    }
}

void DCMotor_Brake(enum Motor motor, float32_t percent)
{
    if(percent < 0.0f)
        percent = 0.0f;
    else if(percent > 1.0f)
        percent = 1.0f;

    // TODO: percentage braking
	Brake(motor);
}

/*----------------------------------------------------------------------------*/
/* Private function                                                           */
/*----------------------------------------------------------------------------*/

static void SetSpeed (enum Motor motor, float32_t percent)
{
    uint16_t pwm = 0;

    // Limit
    if(percent > 1.0f)
    {
        percent = 1.0f;
    }
    else if (percent < 0.0f)
    {
        percent = 0.0f;
    }

    // Calculate pwm motor (100%=3000)
    pwm = (uint16_t)(3000.0 * percent);

    // Set PWM
    if(motor == MOT1)
    {
        __HAL_TIM_SET_COMPARE(MOT1_TIMER, MOT1_TIMER_CHANNEL, pwm);
    }
    else if (motor == MOT2)
    {
        __HAL_TIM_SET_COMPARE(MOT2_TIMER, MOT2_TIMER_CHANNEL, pwm);
    }
}

static void SetDirection (enum Motor motor, enum Direction direction)
{
    if(motor == MOT1)
    {
        if(direction == FORWARD) {
            HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
        }
        else {
            HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
        }
    }
    else if (motor == MOT2)
    {
        if(direction == FORWARD) {
            HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
        }
        else {
            HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
        }
    }
}

static void Freewheel (enum Motor motor)
{
    // Disable h-bridge
    if(motor == MOT1)
    {
        HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(MOT1_TIMER, MOT1_TIMER_CHANNEL, 0);
    }
    else if (motor == MOT2)
    {
        HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(MOT2_TIMER, MOT2_TIMER_CHANNEL, 0);
    }
}

static void Brake (enum Motor motor)
{
    // Enable lower bridge to gnd braking
    if(motor == MOT1)
    {
        HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(MOT1_TIMER, MOT1_TIMER_CHANNEL, 3000);
    }
    else if (motor == MOT2)
    {
        HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(MOT2_TIMER, MOT2_TIMER_CHANNEL, 3000);
    }
}
