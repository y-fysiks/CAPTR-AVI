/*

██████ ██████ ██████ ██████ ██████
██     ██  ██ ██  ██   ██   ██  ██
██     ██████ ██████   ██   ██████ 
██     ██  ██ ██       ██   ██ ██  
██████ ██  ██ ██       ██   ██  ██ 

File: main.cpp
Auth: Alex Wang, Yubo Wang
Desc: Main file for PMCU

*/

#include "Arduino.h"
#include "main.h"

#include "CAPTR_PIN_DRIVER.hpp"

#include "SPI.h"

ControllerState PMCU_state = ControllerState::LV_ON;

// Watchdogs

void setup()
{
  HwSetupPins();
}

void loop() 
{
  loop_start = micros();

  switch(PMCU_state)
  {
    case ControllerState::LV_ON:

    case ControllerState::TVC_UP:

    case ControllerState::TVC_DOWN:
  }
}

void LED_Init();

int main(void)
{
    HAL_Init();
    LED_Init();

    while (true)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        HAL_Delay(1000);
    }
}

void LED_Init()
{
  LED_GPIO_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}