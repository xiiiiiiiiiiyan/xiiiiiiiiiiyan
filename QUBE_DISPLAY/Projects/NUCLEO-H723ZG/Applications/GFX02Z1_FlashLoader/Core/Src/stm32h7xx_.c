/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_.h"
#include "stm32h7xx_hal_spi.h"

/**
  * @brief  DeInitializes the peripherals used by the SPI FLASH driver.
  * @param  None
  * @retval None
  */
void sFLASH_LowLevel_DeInit(void)
{
    /*##-1- Reset peripherals ##################################################*/
  SPIx_FORCE_RESET();
  SPIx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks ################################*/
  /* Configure SPI SCK as alternate function  */
  HAL_GPIO_DeInit(sFLASH_SPI_SCK_GPIO_PORT, sFLASH_SPI_SCK_PIN);
  /* Configure SPI MISO as alternate function  */
  HAL_GPIO_DeInit(sFLASH_SPI_MISO_GPIO_PORT, sFLASH_SPI_MISO_PIN);
  /* Configure SPI MOSI as alternate function  */
  HAL_GPIO_DeInit(sFLASH_SPI_MOSI_GPIO_PORT, sFLASH_SPI_MOSI_PIN);
}

/**
  * @brief  Initializes the peripherals used by the SPI FLASH driver.
  * @param  None
  * @retval None
  */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable SPI clock */
  SPIx_CLK_ENABLE(); 
  
  /* 启用 SPI 引脚所需的 GPIO 时钟 */
  __GPIOA_CLK_ENABLE(); // SCK、CS、MISO 引脚所在端口
  __GPIOB_CLK_ENABLE(); //  MOSI 引脚所在端口
  
  /*##-2- Configure peripheral GPIO ##########################################*/ 
  
  /* Configure EEPROM_CS_PIN pin: EEPROM SPI CS pin */
  GPIO_InitStruct.Pin    = sFLASH_CS_PIN;
  GPIO_InitStruct.Mode   = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull   = GPIO_PULLUP;
  GPIO_InitStruct.Speed  = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Alternate = FLASH_SPI_CS_AF;
  
  HAL_GPIO_Init(sFLASH_CS_GPIO_PORT, &GPIO_InitStruct);
  
  /* SPI SCK GPIO pin configuration  */
  GPIO_InitStruct.Pin       = sFLASH_SPI_SCK_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
  GPIO_InitStruct.Alternate = SPIx_SCK_AF;
  
  HAL_GPIO_Init(sFLASH_SPI_SCK_GPIO_PORT, &GPIO_InitStruct);
    
  /* SPI MISO GPIO pin configuration  */
  GPIO_InitStruct.Pin = sFLASH_SPI_MISO_PIN;
  GPIO_InitStruct.Alternate = SPIx_MISO_AF;
  
  HAL_GPIO_Init(sFLASH_SPI_MISO_GPIO_PORT, &GPIO_InitStruct);
  
  /* SPI MOSI GPIO pin configuration  */
  GPIO_InitStruct.Pin = sFLASH_SPI_MOSI_PIN;
  GPIO_InitStruct.Alternate = SPIx_MOSI_AF;
    
  HAL_GPIO_Init(sFLASH_SPI_MOSI_GPIO_PORT, &GPIO_InitStruct); 
  
  /* EEPROM chip select high */
  FLASH_SPI_CS_HIGH();
}

    
