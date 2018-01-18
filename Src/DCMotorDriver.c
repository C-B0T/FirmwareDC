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
static void Move (enum Motor motor);
static void Freewheel (enum Motor motor);

/*----------------------------------------------------------------------------*/
/* Implementation                                                             */
/*----------------------------------------------------------------------------*/

void DCMotor_Init ()
{
    // Standby
//  HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_SET);    // Running
    
    // Direction
//  HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);    // Forward
    
    // Power PWM
    HAL_TIM_PWM_Stop(MOT1_TIMER, MOT1_TIMER_CHANNEL);
    HAL_TIM_PWM_Stop(MOT2_TIMER, MOT2_TIMER_CHANNEL);
}

void DCMotor_SetMotorSpeed (enum Motor motor, float32_t percent)
{
    // Limits
    if(percent > 1.0f)
    {
        percent = 1.0f;
    }
    else if(percent < -1.0f)
    {
        percent = -1.0f;
    }

    // Simple speed
    if(percent > 0.0f)
    {
        SetDirection(motor, FORWARD);
        SetSpeed(motor, percent);
        Move(motor);
    }
    else if(percent < 0.0f)
    {
        SetDirection(motor, REVERSE);
        SetSpeed(motor, -percent);
        Move(motor);
    }
    else
    {
        SetSpeed(motor, 0.0f);
        Freewheel(motor);
    }
}

void DCMotor_Brake(enum Motor motor, float32_t percent)
{
    if(percent < 0.0f)
        percent = 0.0f;
    else if(percent > 1.0f)
        percent = 1.0f;

    if(motor == MOT1)
    {
        //TODO
    }
    else if (motor == MOT2)
    {
        //TODO
    }
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
        /*if(direction == FORWARD)
            HAL_GPIO_WritePin(MOT0_DIR_GPIO_Port,   MOT0_DIR_Pin,   GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(MOT0_DIR_GPIO_Port,   MOT0_DIR_Pin,   GPIO_PIN_RESET);*/
    }
    else if (motor == MOT2)
    {
        /*if(direction == FORWARD)
            HAL_GPIO_WritePin(MOT1_DIR_GPIO_Port,   MOT1_DIR_Pin,   GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(MOT1_DIR_GPIO_Port,   MOT1_DIR_Pin,   GPIO_PIN_RESET);*/
    }
}

static void Move (enum Motor motor)
{
    // Run PWM
    if(motor == MOT1)
    {
        HAL_TIM_PWM_Start(MOT1_TIMER, MOT2_TIMER_CHANNEL);
    }
    else if (motor == MOT2)
    {
        HAL_TIM_PWM_Start(MOT2_TIMER, MOT2_TIMER_CHANNEL);
    }
}

static void Freewheel (enum Motor motor)
{
    // Disable h-bridge
    if(motor == MOT1)
    {
        //__HAL_TIM_SET_COMPARE(MOT0_TIMER, MOT0_TIMER_CHANNEL, 0);
        //HAL_TIM_PWM_Stop(MOT0_TIMER, MOT0_TIMER_CHANNEL);
    }
    else if (motor == MOT2)
    {
        //__HAL_TIM_SET_COMPARE(MOT1_TIMER, MOT1_TIMER_CHANNEL, 0);
        //HAL_TIM_PWM_Stop(MOT1_TIMER, MOT1_TIMER_CHANNEL);
    }
}
