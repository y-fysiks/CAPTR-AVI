#ifndef MAIN_HPP
#define MAIN_HPP

#define USE_FULL_LL_DRIVER

#include "stm32h7xx_hal.h"

#define LED_PIN                                GPIO_PIN_1
#define LED_GPIO_PORT                          GPIOE
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()

#endif // MAIN_H