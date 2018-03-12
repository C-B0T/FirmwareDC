/**
 * @file    traces.h
 * @author  Jeremy ROULLAND
 * @date    12 mar. 2018
 * @brief   Diagnosis
 */

#include "stm32f0xx_hal.h"

void Traces_Init(UART_HandleTypeDef* huart);

void Traces_Process(void);

