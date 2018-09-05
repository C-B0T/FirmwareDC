/**
 * @file    dio.h
 * @author  C-Bot
 * @date    14 may 2018
 * @brief   Input and Output configuration
 */

#ifndef INC_DIO_H_
#define INC_DIO_H_

#include <stdint.h>

#define DIO_INPUT   (1U)
#define DIO_OUTPUT  (2U)
#define DIO_ADC     (3U)
#define DIO_DAC     (4U)
#define DIO_PWM     (5U)

#define DIO_MAX	(4)
enum dio {DIO1 = 1, DIO2, DIO3, DIO4};

void dio_Init (void);
uint8_t dio_GetConfig(uint8_t *conf, uint8_t len);

void dio_Disable (void);

enum dio dio_GetDIO(uint8_t unit);

/* Digital */
int8_t dio_Digital_Read(enum dio unit, uint8_t* ret);
int8_t dio_Digital_Write(enum dio, uint8_t val);

/* Analog */
int8_t dio_Analog_Read(enum dio unit, uint8_t* ret);
int8_t dio_Analog_Write(enum dio unit, uint8_t val);

/* Pwm */
int8_t dio_Pwm_Write(enum dio unit, uint32_t val);


#endif /* INC_DIO_H_ */
