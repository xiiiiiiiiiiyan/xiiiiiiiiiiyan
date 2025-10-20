/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32H7xx_H
#define __STM32H7xx_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"    
//************************************STM32 SPI接口定义********************************
#define SPIx_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()
   
#define SPIx_FORCE_RESET()               __HAL_RCC_SPI1_FORCE_RESET()
#define SPIx_RELEASE_RESET()             __HAL_RCC_SPI1_RELEASE_RESET()   
   
#define FLASH_SPI_CS_LOW()       HAL_GPIO_WritePin(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN, GPIO_PIN_RESET)
#define FLASH_SPI_CS_HIGH()      HAL_GPIO_WritePin(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN, GPIO_PIN_SET)
   
#define sFLASH_SPI                       SPI1

#define sFLASH_SPI_SCK_PIN               GPIO_PIN_5                 /* PA.5 */
#define sFLASH_SPI_SCK_GPIO_PORT         GPIOA                       /* GPIOA */
#define SPIx_SCK_AF                      GPIO_AF5_SPI1   

#define sFLASH_SPI_MISO_PIN              GPIO_PIN_6                 /* PA.6 */
#define sFLASH_SPI_MISO_GPIO_PORT        GPIOA                       /* GPIOA */
#define SPIx_MISO_AF                     GPIO_AF5_SPI1

#define sFLASH_SPI_MOSI_PIN              GPIO_PIN_5                 /* PB.5 */
#define sFLASH_SPI_MOSI_GPIO_PORT        GPIOB                       /* GPIOB */
#define SPIx_MOSI_AF                     GPIO_AF5_SPI1

#define sFLASH_CS_PIN                    GPIO_PIN_4                 /* PA.4 */
#define sFLASH_CS_GPIO_PORT              GPIOA                       /* GPIOA */
#define FLASH_SPI_CS_AF                  GPIO_AF5_SPI1



void sFLASH_LowLevel_DeInit(void);
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi); 

/**
  * @}
  */
#ifdef __cplusplus
}
#endif
  
#endif /* __STM32H7xx_H */
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
