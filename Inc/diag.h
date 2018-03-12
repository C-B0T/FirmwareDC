/**
 * @file    diag.h
 * @author  Jeremy ROULLAND
 * @date    12 mar. 2018
 * @brief   Diagnosis Code on GPIO
 */

#include "stm32f0xx_hal.h"

void Diagnosis_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

void Diagnosis_Process(uint32_t time);

