/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEV_INF_H
#define __DEV_INF_H

//#include "mem_io.h"
#include "stm32h7xx.h"
#define 	MCU_FLASH 	    1
#define 	NAND_FLASH      2
#define 	NOR_FLASH       3
#define 	SRAM            4
#define 	PSRAM           5
#define 	PC_CARD         6
#define 	SPI_FLASH       7
#define 	I2C_FLASH       8
#define 	SDRAM           9
#define 	I2C_EEPROM      10

#define   SECTOR_NUM      10                 // Max Number of Sector types£¨÷ª”√¡ÀSector[0]

#if defined(EXT_BOARD_GFX01M1)
  #if defined(STM32G0xx)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX01M1_STM32G0"
  #elif defined(STM32L4xx)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX01M1_STM32L4"
  #else
   #error "Please select first the target device used in your application"
  #endif
#elif defined(EXT_BOARD_GFX01M2)
  #define FLASH_DEVICE_TYPE SPI_FLASH
  #if defined(STM32G0)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX01M2_STM32G0"
  #elif defined(STM32L4)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX01M2_STM32L4"
  #elif defined(STM32WB)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX01M2_STM32WB"
  #else
   #error "Please select first the target device used in your application"
  #endif
#elif defined(EXT_BOARD_GFX02Z1)
  #define FLASH_DEVICE_TYPE NOR_FLASH
  #if defined(STM32L4)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX02Z1_STM32L4"
  #elif defined(STM32U5)
    #define FLASH_DEVICE_NAME "MX25L6433F_GFX02Z1_STM32U5"
  #elif defined(STM32H7)
    #define FLASH_DEVICE_NAME "ITA_EXTFLASH_STM32H7"
  #else
   #error "Please select first the target device used in your application"
  #endif
#else
 #error "Please select first the expansion board"
#endif

struct DeviceSectors
{
  unsigned long		SectorNum;                      // Number of Sectors
  unsigned long		SectorSize;                     // Sector Size in Bytes
};

struct StorageInfo
{
   char                 DeviceName[100];          	// Device Name and Description
   unsigned short       DeviceType;               	// Device Type: ONCHIP, EXT8BIT, EXT16BIT, ...
   unsigned long        DeviceStartAddress;       	// Default Device Start Address
   unsigned long        DeviceSize;					// Total Size of Device
   unsigned long        PageSize;					// Programming Page Size
   unsigned char        EraseValue;               	// Content of Erased Memory
   struct DeviceSectors	sectors[SECTOR_NUM];
};

#endif /* __DEV_INF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
