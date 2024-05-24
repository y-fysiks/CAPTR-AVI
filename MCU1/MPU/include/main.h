#ifndef MAIN_H
#define MAIN_H

#include "stm32h7xx_hal.h"

#define LED_PIN                                GPIO_PIN_5
#define LED_GPIO_PORT                          GPIOA
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()

enum class ControllerState
{
    LV_ON,
    TVC_UP,
    RECOVERY,
    TVC_DOWN,
    LAND,
};

enum class ErrorState
{
    NONE,

    GENERAL,               

    IMU, 
    BARO,
    RF
};

#endif // MAIN_H