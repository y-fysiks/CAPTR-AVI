#include "main.hpp"
#include "lsm6ds3tr-c_reg.h"

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

//****** handlers for libraries ******//

extern "C" static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp,
                              uint16_t len)
{
  HAL_I2C_Mem_Write((I2C_HandleTypeDef*)handle, LSM6DS3TR_C_I2C_ADD_L, reg,
                    I2C_MEMADD_SIZE_8BIT, (uint8_t*) bufp, len, 1000);
}

extern "C" static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len)
{
  HAL_I2C_Mem_Read((I2C_HandleTypeDef*)handle, LSM6DS3TR_C_I2C_ADD_L, reg,
                   I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
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


extern "C" void DebugMon_Handler(void)
{
}

extern "C" void PendSV_Handler(void)
{
}