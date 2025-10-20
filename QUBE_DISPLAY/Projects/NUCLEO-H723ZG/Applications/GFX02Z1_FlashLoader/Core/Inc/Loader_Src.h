/**
  ******************************************************************************
  * @file    Loader_Src.h
  * @author  MCD Tools Team
  * @date    November-2016
  * @brief   Loader Header file.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LOADER_SRC_H
#define __LOADER_SRC_H

/* Includes ------------------------------------------------------------------*/
#include "Dev_Inf.h"

/* Defines -------------------------------------------------------------------*/
#define BSP_ERROR_NONE                      0     /*!< \hideinitializer No error occured */
#define TIMEOUT 5000U
#if defined ( __ICCARM__ )
#define KeepInCompilation __root
#else
#define KeepInCompilation __attribute__ ((__used__))
#endif

/* Private function prototypes -----------------------------------------------*/
KeepInCompilation int Init (void);
KeepInCompilation int MassErase (uint32_t Parallelism );
KeepInCompilation int SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress);
KeepInCompilation int Read (uint32_t Address, uint32_t Size, uint8_t* Buffer);
KeepInCompilation int Write (uint32_t Address, uint32_t Size, uint8_t* buffer, uint32_t block_cnt);
KeepInCompilation uint64_t Verify (uint32_t MemoryAddr, uint32_t RAMBufferAddr, uint32_t Size, uint32_t missalignement);

#endif /* __LOADER_SRC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
