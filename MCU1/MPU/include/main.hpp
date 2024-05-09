#ifndef MAIN_HPP
#define MAIN_HPP

#define USE_FULL_LL_DRIVER

#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_i2c.h"
#include "stm32h7xx_hal_gpio.h"
#include "stm32h7xx_hal_rcc.h"
#include "stm32h7xx_hal_rcc_ex.h"
#include "stm32h7xx_hal_usart.h"
#include "stm32h7xx_hal_uart.h"


#define LED_PIN                                GPIO_PIN_1
#define LED_GPIO_PORT                          GPIOE
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()

//****** Function Prototypes ******//

// handlers for libraries
extern "C" static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp,
                              uint16_t len);
extern "C" static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len);

// Others
void initialize();



//****** global variables ******//

#endif // MAIN_H