/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32_EVAL_SPI_FLASH_H
#define __STM32_EVAL_SPI_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_spi.h"

 
/**
  * @brief  M25P SPI Flash supported commands
  */  
#define sFLASH_CMD_WRITE          0x12  /*!< Write to Memory instruction */
#define sFLASH_CMD_WREN           0x06  /*!< Write enable instruction */
#define sFLASH_CMD_READ           0x13  /*!< Read from Memory instruction */
#define sFLASH_CMD_RDSR           0x05  /*!< Read Status Register instruction  */
#define sFLASH_CMD_SE             0xDC  /*!< Sector Erase instruction */
#define sFLASH_CMD_BE             0x60  /*!< Bulk Erase instruction */

#define sFLASH_WIP_FLAG           0x01  /*!< Write In Progress (WIP) flag */

#define sFLASH_DUMMY_BYTE         0xFF
#define sFLASH_SPI_PAGESIZE       0x100	//256 bytes/page = 0x100 bytes/page
#define FLASH_SPI_TOTALSIZE         (32*1024*1024) //32MB = 33,554,432 bytes¡£µØÖ··¶Î§£º0x0000000~0x1FFFFFF 
//¶ÁÐ´Flash£¬·µ»ØµÄ×´Ì¬£º
typedef enum
{
    FLASH_OK = 0,
    FLASH_ERROR = 1,
} FlashStatus_e;    
    


/** @defgroup STM32_EVAL_SPI_FLASH_Exported_Functions
  * @{
  */
/**
  * @brief  High layer functions
  */
void sFLASH_DeInit(void);
void sFLASH_Init(void);
void sFLASH_EraseSector(uint32_t SectorAddr);
void sFLASH_EraseBulk(void);
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint32_t NumByteToWrite);
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint32_t NumByteToWrite);
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead);


/**
  * @brief  Low layer functions
  */
uint8_t sFLASH_SendByte(uint8_t byte);
void sFLASH_WriteEnable(void);
void sFLASH_WaitForWriteEnd(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32_EVAL_SPI_FLASH_H */

