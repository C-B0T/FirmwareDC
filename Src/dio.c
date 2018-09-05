/**
 * @file    dio.c
 * @author  C-Bot
 * @date    14 may 2018
 * @brief   Input and Output configuration
 */

#include "dio.h"
#include "main.h"
#include "gpio.h"
#include "adc.h"
#include "tim.h"

#include "stm32f0xx_hal.h"

#include "Config.h"

#define DIO1_CHANNEL	ADC_CHANNEL_0
#define DIO2_CHANNEL	ADC_CHANNEL_1
#define DIO3_CHANNEL	ADC_CHANNEL_6
#define DIO4_CHANNEL	ADC_CHANNEL_7

#define SERVO_TIM_12	(&htim2)
#define SERVO_TIM_34    (&htim3)

void dio_Init (void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    ADC_ChannelConfTypeDef sConfig;

/* # GPIO mux config */
#if defined(DIO1_INPUT)
    /* DIO1 : Input */
    GPIO_InitStruct.Pin = DIO1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO1_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO1_OUTPUT)
    /* DIO1 : Output */
    HAL_GPIO_WritePin(DIO1_GPIO_Port, DIO1_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = DIO1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DIO1_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO1_ADC)
    /* DIO1 : Analog Input */
    GPIO_InitStruct.Pin = DIO1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO1_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO1_DAC)
    /* DIO1 : Analog Output */
#elif defined(DIO1_PWM)
    /* DIO1 : PWM Output */
    GPIO_InitStruct.Pin = DIO1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM2;
    HAL_GPIO_Init(DIO1_GPIO_Port, &GPIO_InitStruct);
#else
#endif

#if defined(DIO2_INPUT)
    /* DIO2 : Input */
    GPIO_InitStruct.Pin = DIO2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO2_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO2_OUTPUT)
    /* DIO2 : Output */
    HAL_GPIO_WritePin(DIO2_GPIO_Port, DIO2_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = DIO2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DIO2_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO2_ADC)
    /* DIO2 : Analog Input */
    GPIO_InitStruct.Pin = DIO2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO2_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO2_DAC)
    /* DIO2 : Analog Output */
#elif defined(DIO2_PWM)
    /* DIO2 : PWM Output */
    GPIO_InitStruct.Pin = DIO2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM2;
    HAL_GPIO_Init(DIO2_GPIO_Port, &GPIO_InitStruct);
#else
#endif


#if defined(DIO3_INPUT)
    /* DIO3 : Input */
    GPIO_InitStruct.Pin = DIO3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO3_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO3_OUTPUT)
    /* DIO3 : Output */
    HAL_GPIO_WritePin(DIO3_GPIO_Port, DIO3_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = DIO3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DIO3_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO3_ADC)
    /* DIO3 : Analog Input */
    GPIO_InitStruct.Pin = DIO3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO3_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO3_DAC)
    /* DIO3 : Analog Output */
#elif defined(DIO3_PWM)
    /* DIO3 : PWM Output */
    GPIO_InitStruct.Pin = DIO3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM2;
    HAL_GPIO_Init(DIO3_GPIO_Port, &GPIO_InitStruct);
#else
#endif


#if defined(DIO4_INPUT)
    /* DIO4 : Input */
    GPIO_InitStruct.Pin = DIO4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO4_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO4_OUTPUT)
    /* DIO4 : Output */
    HAL_GPIO_WritePin(DIO4_GPIO_Port, DIO4_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = DIO4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DIO4_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO4_ADC)
    /* DIO4 : Analog Input */
    GPIO_InitStruct.Pin = DIO4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DIO4_GPIO_Port, &GPIO_InitStruct);
#elif defined(DIO4_DAC)
    /* DIO4 : Analog Output */
#elif defined(DIO4_PWM)
    /* DIO4 : PWM Output */
    GPIO_InitStruct.Pin = DIO4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM2;
    HAL_GPIO_Init(DIO4_GPIO_Port, &GPIO_InitStruct);
#else
#endif


/* # module config */
#if defined(DIO1_ADC)
	sConfig.Channel = DIO1_CHANNEL;
	sConfig.Rank = ADC_RANK_NONE;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);
#elif defined(DIO2_ADC)
	sConfig.Channel = DIO2_CHANNEL;
	sConfig.Rank = ADC_RANK_NONE;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);
#elif defined(DIO3_ADC)
	sConfig.Channel = DIO3_CHANNEL;
	sConfig.Rank = ADC_RANK_NONE;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);
#elif defined(DIO4_ADC)
	sConfig.Channel = DIO4_CHANNEL;
	sConfig.Rank = ADC_RANK_NONE;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);
#endif

}

void dio_Disable (void)
{
	//TODO: If AU then set val to 0
}

enum dio dio_GetDIO(uint8_t unit)
{
	enum dio io = DIO1;
	switch(unit)
	{
		case 1:
			io = DIO1;
			break;
		case 2:
			io = DIO2;
			break;
		case 3:
			io = DIO3;
			break;
		case 4:
			io = DIO4;
			break;
		default:
			break;
	}
	return io;
}


int8_t dio_Digital_Read(enum dio unit, uint8_t* ret)
{
	uint8_t val;
	GPIO_TypeDef* gpio_port;
	uint16_t gpio_pin;

	switch(unit)
	{
#if defined(DIO1_INPUT)
		case DIO1:
			gpio_port = DIO1_GPIO_Port;
			gpio_pin  = DIO1_Pin;
			break;
#endif
#if defined(DIO2_INPUT)
		case DIO2:
			gpio_port = DIO2_GPIO_Port;
			gpio_pin  = DIO2_Pin;
			break;
#endif
#if defined(DIO3_INPUT)
		case DIO3:
			gpio_port = DIO3_GPIO_Port;
			gpio_pin  = DIO3_Pin;
			break;
#endif
#if defined(DIO4_INPUT)
		case DIO4:
			gpio_port = DIO4_GPIO_Port;
			gpio_pin  = DIO4_Pin;
			break;
#endif
		default:
			return -1;    /*abort*/
			break;
	}

	if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(gpio_port, gpio_pin))
		val = 0;
	else
		val = 255;

	*ret = val;

	return 0;	/*okay*/
}

int8_t dio_Digital_Write(enum dio unit, uint8_t val)
{
	GPIO_TypeDef* gpio_port;
	uint16_t gpio_pin;

	switch(unit)
	{
#if defined(DIO1_OUTPUT)
		case DIO1:
			gpio_port = DIO1_GPIO_Port;
			gpio_pin  = DIO1_Pin;
			break;
#endif
#if defined(DIO2_OUTPUT)
		case DIO2:
			gpio_port = DIO2_GPIO_Port;
			gpio_pin  = DIO2_Pin;
			break;
#endif
#if defined(DIO3_OUTPUT)
		case DIO3:
			gpio_port = DIO3_GPIO_Port;
			gpio_pin  = DIO3_Pin;
			break;
#endif
#if defined(DIO4_OUTPUT)
		case DIO4:
			gpio_port = DIO4_GPIO_Port;
			gpio_pin  = DIO4_Pin;
			break;
#endif
		default:
			return -1;    /*abort*/
			break;
	}

	if(val > 0)
		HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_RESET);

	return 0; /*okay*/
}

int8_t dio_Analog_Read(enum dio unit, uint8_t* ret)
{
	uint8_t val = 0;
	ADC_ChannelConfTypeDef sConfig = {0, ADC_RANK_NONE, ADC_SAMPLETIME_1CYCLE_5};

	switch (unit)
	{
#if defined(DIO1_ADC)
		case DIO1:
			sConfig.Channel = DIO1_CHANNEL;
			break;
#endif
#if defined(DIO2_ADC)
		case DIO2:
			sConfig.Channel = DIO2_CHANNEL;
			break;
#endif
#if defined(DIO3_ADC)
		case DIO3:
			sConfig.Channel = DIO3_CHANNEL;
			break;
#endif
#if defined(DIO4_ADC)
		case DIO4:
			sConfig.Channel = DIO4_CHANNEL;
			break;
#endif
		default:
			return -1;    /*abort*/
			break;
	}

	// Enable the channel
	sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);

	// Convert Analog to Digital
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 1);	// Timeout: 1ms
	val = HAL_ADC_GetValue(&hadc);

	// Disable the channel
	sConfig.Rank = ADC_RANK_NONE;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);

	*ret = val;

	return 0; /*okay*/
}

int8_t dio_Analog_Write(enum dio unit, uint8_t val)
{
	//TODO: DAC to do
	return -2;
}

int8_t dio_Pwm_Write(enum dio unit, uint32_t val)
{
	TIM_HandleTypeDef* htim;
	uint32_t channel;

	switch (unit)
	{
#if defined(DIO1_PWM)
		case DIO1:
			htim = SERVO_TIM_12;
			channel = TIM_CHANNEL_1;
			break;
#endif
#if defined(DIO2_PWM)
		case DIO2:
			htim = SERVO_TIM_12;
			channel = TIM_CHANNEL_2;
			break;
#endif
#if defined(DIO3_PWM)
		case DIO3:
			htim = SERVO_TIM_34;
			channel = TIM_CHANNEL_1;
			break;
#endif
#if defined(DIO4_PWM)
		case DIO4:
			htim = SERVO_TIM_34;
			channel = TIM_CHANNEL_2;
			break;
#endif
		default:
			return -1; /*abort*/
			break;
	}

	__HAL_TIM_SET_COMPARE(htim, channel, val);
	HAL_TIM_PWM_Start_IT(htim, channel);

	return 0; /*okay*/
}

