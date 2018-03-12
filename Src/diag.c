/**
 * @file    diag.c
 * @author  Jeremy ROULLAND
 * @date    12 mar. 2018
 * @brief   Diagnosis Code on GPIO
 */

#include "diag.h"

/*----------------------------------------------------------------------------*/
/* Definitions                                                                */
/*----------------------------------------------------------------------------*/

// Level
#define DIAG_OKAY       (1U)
#define DIAG_WARNING    (2U)
#define DIAG_ERROR      (3U)

// Period (ms)
#define DIAG_PERIOD_OKAY       (1400U)
#define DIAG_PERIOD_WARNING    (400U)
#define DIAG_PERIOD_ERROR      (200U)


/*----------------------------------------------------------------------------*/
/* Private Members                                                            */
/*----------------------------------------------------------------------------*/

static GPIO_TypeDef* _GPIOx    = NULL;
static uint16_t      _GPIO_Pin = 0U;

static uint8_t level = DIAG_OKAY;

/*----------------------------------------------------------------------------*/
/* Private Functions                                                          */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Implementation                                                             */
/*----------------------------------------------------------------------------*/

void Diagnosis_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    _GPIOx    = GPIOx;
    _GPIO_Pin = GPIO_Pin;
}

void Diagnosis_Process(uint32_t time)
{
    static uint32_t t0 = 0;
    
    uint16_t local_time = 0;
    uint16_t period = 0;
    
    local_time = time - t0;
    
    // Check level
    if(level == DIAG_OKAY)
        period = DIAG_PERIOD_OKAY;
    else if(level == DIAG_WARNING)
        period = DIAG_PERIOD_WARNING;
    else if(level == DIAG_ERROR)
        period = DIAG_PERIOD_ERROR;

    // GPIO Blink
    if(level == DIAG_OKAY)
	{
		if(local_time <= period/2U)
			HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, GPIO_PIN_RESET);
	}
    else
	{
		if(local_time <= period/2U)
			HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, GPIO_PIN_RESET);
	}

    if(local_time >= period)
        t0 = time;
}

/*----------------------------------------------------------------------------*/
/* Callbacks                                                                  */
/*----------------------------------------------------------------------------*/

