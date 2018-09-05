/**
 * @file    Config.h
 * @author  C-Bot
 * @date    21 feb. 2018
 * @brief   Configuration file
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "dio.h"

// Possible configurations are:
//#define CONF_NONE			(0U)
#define CONF_INPUT			(1U)
#define CONF_OUTPUT			(2U)
//#define CONF_PWM			(3U)
#define CONF_SERVO_GENERIC	(4U)
#define CONF_SERVO_GOTECK	(5U)
#define CONF_SERVO_FUTABA	(6U)
#define CONF_SHARP			(7U)


/*----------------------------------------------------------------------------*/
/*                      === CONFIGURATION ====                                */
/*                      === CONFIGURATION ====                                */
/*                      === CONFIGURATION ====                                */
/*----------------------------------------------------------------------------*/

#define VERSION_MAJOR	2
#define VERSION_MINOR	0


// ## Functional Configuration

#define I2C_ADDRESS (0x31)

//#define DIO1_CONF_NONE
#define DIO1_CONF_INPUT
//#define DIO1_CONF_OUTPUT

//#define DIO2_CONF_NONE
#define DIO2_CONF_INPUT
//#define DIO2_CONF_OUTPUT

//#define DIO3_CONF_NONE
#define DIO3_CONF_INPUT
//#define DIO3_CONF_OUTPUT

//#define DIO4_CONF_NONE
#define DIO4_CONF_INPUT
//#define DIO4_CONF_OUTPUT


/*----------------------------------------------------------------------------*/
/*                    === CONFIGURATION END ====                              */
/*                    === CONFIGURATION END ====                              */
/*                    === CONFIGURATION END ====                              */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Decoding config - Do not modify                                            */
/*----------------------------------------------------------------------------*/

/* Types:
#define DIOx_NONE
#define DIOx_INPUT
#define DIOx_OUTPUT
#define DIOx_ADC
#define DIOx_DAC
#define DIOx_PWM
*/

#if defined(DIO1_CONF_NONE)
#define DIO1_CONF	CONF_NONE
#elif defined(DIO1_CONF_INPUT)
#define DIO1_CONF	CONF_INPUT
#define DIO1_INPUT
#elif defined(DIO1_CONF_OUTPUT)
#define DIO1_CONF	CONF_OUTPUT
#define DIO1_OUTPUT
#endif

#if defined(DIO2_CONF_NONE)
#define DIO2_CONF	CONF_NONE
#elif defined(DIO2_CONF_INPUT)
#define DIO2_CONF	CONF_INPUT
#define DIO2_INPUT
#elif defined(DIO2_CONF_OUTPUT)
#define DIO2_CONF	CONF_OUTPUT
#define DIO2_OUTPUT
#endif

#if defined(DIO3_CONF_NONE)
#define DIO3_CONF	CONF_NONE
#elif defined(DIO3_CONF_INPUT)
#define DIO3_CONF	CONF_INPUT
#define DIO3_INPUT
#elif defined(DIO3_CONF_OUTPUT)
#define DIO3_CONF	CONF_OUTPUT
#define DIO3_OUTPUT
#endif

#if defined(DIO4_CONF_NONE)
#define DIO4_CONF	CONF_NONE
#elif defined(DIO4_CONF_INPUT)
#define DIO4_CONF	CONF_INPUT
#define DIO4_INPUT
#elif defined(DIO4_CONF_OUTPUT)
#define DIO4_CONF	CONF_OUTPUT
#define DIO4_OUTPUT
#endif


extern const uint8_t conf[4];

#endif /* INC_CONFIG_H_ */

