/**
 * @file    actions.c
 * @author  Jeremy ROULLAND
 * @date    13 mar. 2018
 * @brief   Actions (Simple, Complex, Control, ...)
 */

#include "actions.h"

#include "stm32f0xx_hal.h"
#include "smbus2_cmd.h"
#include "status.h"

/*----------------------------------------------------------------------------*/
/* Definitions                                                                */
/*----------------------------------------------------------------------------*/

#define false (0U)
#define true  (1U)

/*----------------------------------------------------------------------------*/
/* Private Members                                                            */
/*----------------------------------------------------------------------------*/

static uint8_t _emergencyStop = false;

/*----------------------------------------------------------------------------*/
/* Private Functions                                                          */
/*----------------------------------------------------------------------------*/

void _readInputs(void)
{
	GPIO_PinState input[4] = {GPIO_PIN_RESET};
	uint8_t buff[4] = {0};
	int16_t i = 0;

	input[0] = HAL_GPIO_ReadPin(DIO1_GPIO_Port, DIO1_Pin);
	input[1] = HAL_GPIO_ReadPin(DIO2_GPIO_Port, DIO2_Pin);
	input[2] = HAL_GPIO_ReadPin(DIO3_GPIO_Port, DIO3_Pin);
	input[3] = HAL_GPIO_ReadPin(DIO4_GPIO_Port, DIO4_Pin);

	for(i = 0 ; i < 4 ; i++) {
		if(input[i] == GPIO_PIN_RESET)
			buff[i] = 0U;
		else
			buff[i] = 255U;
	}
	
	smbus2_cmd_SetData(0x05, 4, buff);
}

void _stop(void)
{
	HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}

void _control_S_AU(void)
{

}

/*----------------------------------------------------------------------------*/
/* Implementation                                                             */
/*----------------------------------------------------------------------------*/

void Actions_Process(void)
{
	// Read Inputs
	_readInputs();
	
	// Control S_AU

	// Execute Command
	/* PowerOut : Nothing to do */
}

void EmergencyStop(uint8_t len, uint8_t *buff)
{
	if(buff[0] == 0xFF) {
		_emergencyStop = true;
		_stop();
	}
}

void SetSpeed(uint8_t len, uint8_t *buff)
{
	/* TODO : push data to pwm modules */
}

void SetOutput(uint8_t len, uint8_t *buff)
{
	uint8_t unit    = buff[0];
	uint8_t subunit = buff[1];
	
	GPIO_PinState state = GPIO_PIN_RESET;

	// Check initial conditions
	if(_emergencyStop)
		return;
	if(Status_isBusy()) 
		return;

	Status_SetBusy(true);
	
	if(buff[2] == 0x00)
		state = GPIO_PIN_RESET;
	else
		state = GPIO_PIN_SET;
	
	if( ((unit == 0x01) || (unit == 0x0A)) && (subunit == 0x01) )
		HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, state);
	else if( ((unit == 0x02) || (unit == 0x0B)) && (subunit == 0x01) )
		HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, state);
	else if( ((unit == 0x01) || (unit == 0x0A)) && (subunit == 0x02) )
		HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, state);
	else if( ((unit == 0x02) || (unit == 0x0B)) && (subunit == 0x02) )
		HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, state);

	Status_SetBusy(false);
}


/*----------------------------------------------------------------------------*/
/* Callbacks                                                                  */
/*----------------------------------------------------------------------------*/

