#include "main.hpp"

void LED_Init();

int main(void)
{
    HAL_Init();
    LED_Init();

    while (1)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        HAL_Delay(2000);
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

extern "C" void SysTick_Handler(void)
{
  HAL_IncTick();
}

extern "C" void NMI_Handler(void)
{
}

extern "C" void HardFault_Handler(void)
{
  while (1) {}
}


extern "C" void MemManage_Handler(void)
{
  while (1) {}
}

extern "C" void BusFault_Handler(void)
{
  while (1) {}
}

extern "C" void UsageFault_Handler(void)
{
  while (1) {}
}

extern "C" void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}