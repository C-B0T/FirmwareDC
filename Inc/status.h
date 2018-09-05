/**
 * @file    status.h
 * @author  Jeremy ROULLAND
 * @date    12 mar. 2018
 * @brief   Status Code on GPIO
 */

#include "stm32f0xx_hal.h"


void Status_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void Status_Process(uint32_t time);


uint8_t Status_GetGlobalStatus(void);

