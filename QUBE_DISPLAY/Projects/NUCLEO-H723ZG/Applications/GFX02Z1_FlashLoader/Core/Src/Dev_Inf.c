/**
  ******************************************************************************
  * @file    Dev_Inf.c
  * @author  MCD Application Team
  * @brief   This file defines the structure containing informations about the
  *          external flash memories used by STM32CubeProgramer in
  *          programming/erasing the device.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
  
#include "Dev_Inf.h"

/* This structure containes information used by ST-LINK Utility to program and erase the device */
#if defined (__ICCARM__)
__root const struct StorageInfo StorageInfo  =  {
#else
__attribute__((section(".StorageInfo"))) __attribute__ ((__used__)) __attribute__((aligned (8)))
const struct StorageInfo StorageInfo  =  {
#endif
   { FLASH_DEVICE_NAME },                       // Device Name + CUST Borad name
   SPI_FLASH,                                   // Device Type
   0x00000000,                                  // Device Start Address
   0x02000000,                                  // Device Size in Bytes (32MBytes)
   256,                                         // Programming Page Size 256Bytes
   0xFF,                                        // Initial Content of Erased Memory
   // Specify Size and Address of Sectors (view example below)
   {
     { 0x00000200, 0x00010000 },            // Sector Num : 512 ,Sector Size: 64KBytes
     { 0x00000000, 0x00000000 }
   },
};
