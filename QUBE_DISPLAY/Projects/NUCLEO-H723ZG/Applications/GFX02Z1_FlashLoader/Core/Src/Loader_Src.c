/**
  ******************************************************************************
  * @file    Loader_Src.c
  * @author  MCD Tools Team
  * @date    MAY-2020
  * @brief   This file defines the operations of the external loader for
  *          MX66LM1G45G OSPI memory of STM32H735G_CUST.
  ******************************************************************************
  */

#include "main.h"
#include "Loader_Src.h"
#include <string.h>
#include "stm32h7xx.h"
#define BSP_RETURN(ret) return ((ret == BSP_ERROR_NONE ? 1 : ret))

__STATIC_INLINE uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal);

extern void MX_Init(void);

extern void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead);
extern void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint32_t NumByteToWrite);
extern void sFLASH_EraseSector(uint32_t SectorAddr);
extern void sFLASH_EraseBulk(void);
/* HAL functions -------------------------------------------------------------*/
static uint32_t SysTicks;
//static uint8_t MemoryMappedMode;  //不用这个，外扩FALSH不允许直接内存映射，需要通过它的指令读擦

HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  /* Intialize HAL variables */
  uwTickPrio = TickPriority; /* Invalid PRIO */
  uwTickFreq = HAL_TICK_FREQ_DEFAULT;  /* 1KHz */
  uwTick = 0;
  SysTicks = 0;

  SystemCoreClockUpdate();

  return HAL_OK;
}

uint32_t HAL_GetTick(void)
{
  SysTicks += (uint32_t)uwTickFreq;
  if(SysTicks == ((SystemCoreClock / (uwTickFreq * 1000)) / 10))
  {
    SysTicks = 0;
    HAL_IncTick();
  }

  return uwTick;
}

/* Private functions ---------------------------------------------------------*/
__STATIC_INLINE void ResetRamRegions(void)
{
  /*Initialisation*/
#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
  extern char BSS_START asm("_sbss");
  extern char BSS_END asm("_ebss");
  size_t bss_size = (size_t) (&BSS_END - &BSS_START);
  memset((void*)(((uint32_t)&BSS_START)), 0, bss_size);
  extern char DATA_START asm("_sdata");
  extern char DATA_END asm("_edata");
  size_t data_size = (size_t) (&DATA_END - &DATA_START);
  memset((void*)(((uint32_t)&DATA_START)), 0, data_size);
#elif defined ( __CC_ARM   ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  extern uint32_t Image$$PrgData$$ZI$$Base[];
  extern uint32_t Image$$PrgData$$ZI$$Length[];
  memset((void*)(((uint32_t)&Image$$PrgData$$ZI$$Base)), 0, (size_t)Image$$PrgData$$ZI$$Length);
	/*extern uint32_t Image$$PrgData$$RW$$Base[];
  extern uint32_t Image$$PrgData$$RW$$Length[];
  memset((void*)(((uint32_t)&Image$$PrgData$$RW$$Base)), 0, (size_t)Image$$PrgData$$RW$$Length);*/
#elif defined (__ICCARM__)
  #pragma segment="RW_BLOCK"
  size_t size = (size_t)((uint32_t)__sfe("RW_BLOCK") - (uint32_t)__sfb("RW_BLOCK"));
  memset((void*)(((uint32_t)__sfb("RW_BLOCK"))), 0, size);
#endif
}

/**
  * Description :
  * Calculates checksum value of the memory zone
  * Inputs    :
  *      StartAddress  : Flash start address
  *      Size          : Size (in WORD)
  *      InitVal       : Initial CRC value
  * outputs   :
  *     R0             : Checksum value
  * Note: Optional for all types of device
  */

__STATIC_INLINE uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal)
{
  uint8_t missalignementAddress = StartAddress%4;
  uint8_t missalignementSize = Size ;
  int cnt;
  uint32_t Val;

  StartAddress-=StartAddress%4;
  Size += (Size%4==0)?0:4-(Size%4);

  for(cnt=0; cnt<Size ; cnt+=4)
  {
   //if(MemoryMappedMode)
   //{
   //  Val = *(uint32_t*)StartAddress;
   //}
   //else
   //{
      StartAddress &= 0x0FFFFFFF;
      //BSP_MEM_ReadData(0, (uint8_t *)&Val, StartAddress, 4);
      sFLASH_ReadBuffer((uint8_t *)&Val, StartAddress, 4);	
   // }
    if(missalignementAddress)
    {
      switch (missalignementAddress)
      {
        case 1:
          InitVal += (uint8_t) (Val>>8 & 0xff);
          InitVal += (uint8_t) (Val>>16 & 0xff);
          InitVal += (uint8_t) (Val>>24 & 0xff);
          missalignementAddress-=1;
          break;
        case 2:
          InitVal += (uint8_t) (Val>>16 & 0xff);
          InitVal += (uint8_t) (Val>>24 & 0xff);
          missalignementAddress-=2;
          break;
        case 3:
          InitVal += (uint8_t) (Val>>24 & 0xff);
          missalignementAddress-=3;
          break;
      }
    }
    else if((Size-missalignementSize)%4 && (Size-cnt) <=4)
    {
      switch (Size-missalignementSize)
      {
        case 1:
          InitVal += (uint8_t) Val;
          InitVal += (uint8_t) (Val>>8 & 0xff);
          InitVal += (uint8_t) (Val>>16 & 0xff);
          missalignementSize-=1;
          break;
        case 2:
          InitVal += (uint8_t) Val;
          InitVal += (uint8_t) (Val>>8 & 0xff);
          missalignementSize-=2;
          break;
        case 3:
          InitVal += (uint8_t) Val;
          missalignementSize-=3;
          break;
      }
    }
    else
    {
      InitVal += (uint8_t) Val;
      InitVal += (uint8_t) (Val>>8 & 0xff);
      InitVal += (uint8_t) (Val>>16 & 0xff);
      InitVal += (uint8_t) (Val>>24 & 0xff);
    }
    StartAddress+=4;
  }
  return (InitVal);
}

/**
  * @brief  System initialization.
  * @param  None
  * @retval  1      : Operation succeeded
  * @retval  0      : Operation failed
  */
KeepInCompilation int Init(void)
{
  int32_t ret = BSP_ERROR_NONE;

  /* De-Initialize External Memory */
  //BSP_MEM_DeInit(0);

  /* Reset RAM RW/ZI regions */
  ResetRamRegions();

#if !defined(EXTERNAL_LOADER_TEST)
  SystemInit();
#endif /* EXTERNAL_LOADER_TEST */

  /* Set Memory Mapped Mode status to 'Disabled' */
  //MemoryMappedMode = 0;

  /* Initialize HW */
  MX_Init();

  /* Initialize External Memory */
  //ret = BSP_MEM_Init(0);

  BSP_RETURN(ret);
}

/**
  * @brief   erase memory.
  * @retval  1      : Operation succeeded
  * @retval  0      : Operation failed
  */
KeepInCompilation int MassErase (uint32_t Parallelism )
{
  int32_t ret = BSP_ERROR_NONE;
  UNUSED(Parallelism);
  //ret = BSP_MEM_ChipErase(0);

  //BSP_MEM_DeInit(0);
  sFLASH_EraseBulk();
  BSP_RETURN(ret);
}

/**
  * @brief   Sector erase.
  * @param   EraseStartAddress :  erase start address
  * @param   EraseEndAddress   :  erase end address
  * @retval  None
  */
KeepInCompilation int SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress)
{
  int32_t ret = BSP_ERROR_NONE;
  /*
  uint32_t BlockAddr;
  uint32_t BlockStartAddress = EraseStartAddress - EraseStartAddress % MX25L6433F_BLOCK_64K;

  do
  {
    BlockAddr = BlockStartAddress & 0x00FFFFFF;

    //ret = BSP_MEM_BlockErase(0, BlockAddr, MX25L6433F_ERASE_64K);

    BlockStartAddress+=MX25L6433F_BLOCK_64K;
  } while ((EraseEndAddress>=BlockStartAddress) && (BSP_ERROR_NONE == ret));
  */
  //BSP_MEM_DeInit(0);
  EraseStartAddress = EraseStartAddress -  EraseStartAddress%0x10000;   //一个sector为64K
  while (EraseEndAddress>=EraseStartAddress)
  {
   sFLASH_EraseSector(EraseStartAddress);
   EraseStartAddress += 0x10000;
  }
  BSP_RETURN(ret);
}

/**
  * Description :
  * Read data from the device
  * Inputs    :
  *     None
  * outputs   :
  *     R0             : "1" : Operation succeeded
  * 			 "0" : Operation failure
  * Note: Not Mandatory for SRAM PSRAM and NOR_FLASH
  */
KeepInCompilation int Read (uint32_t Address, uint32_t Size, uint8_t* Buffer)
{
  int32_t ret = BSP_ERROR_NONE;
  
 //uint32_t StartAddr = Address & 0x00FFFFFF;
 //int NumOfBlock = 0, NumOfSingle = 0;
 //uint8_t *data_addr = Buffer;
 //
 //NumOfBlock =  Size / MX25L6433F_SECTOR_4K;
 //NumOfSingle = Size % MX25L6433F_SECTOR_4K;
 //
 //if (NumOfBlock == 0) /*!< NumByteToRead < MX25L6433F_SECTOR_4K */
 //{
 //  //ret = BSP_MEM_ReadData(0, data_addr, StartAddr, Size);
 //}
 //else /*!< Size > MX25L6433F_SECTOR_4K */
 //{
 //  while ((ret == BSP_ERROR_NONE) && (NumOfBlock--))
 //  {
 //    //ret = BSP_MEM_ReadData(0, data_addr, StartAddr, MX25L6433F_SECTOR_4K);
 //    StartAddr +=  MX25L6433F_SECTOR_4K;
 //    data_addr += MX25L6433F_SECTOR_4K;
 //  }
 //
 //  if(NumOfSingle)
 //  {
 //    //ret = BSP_MEM_ReadData(0, data_addr, StartAddr, NumOfSingle);
 //  }
 //}

  //BSP_MEM_DeInit(0);
  sFLASH_ReadBuffer(Buffer, Address, Size);	
  BSP_RETURN(ret);
}

/**
  * @brief   Program memory.
  * @param   Address: page address
  * @param   Size   : size of data
  * @param   buffer : pointer to data buffer
  * @retval  1      : Operation succeeded
  * @retval  0      : Operation failed
  */
KeepInCompilation int Write (uint32_t Address, uint32_t Size, uint8_t* buffer, uint32_t block_cnt)
{
  int32_t ret = BSP_ERROR_NONE;
//  uint32_t end_addr, current_size;
//  uint8_t *data_addr;

  UNUSED(block_cnt);

//  /* Initialize the address variables */
//  Address = Address & 0x00FFFFFF;
//  end_addr = Address + Size;
//  data_addr = buffer;
//
//  /* Calculation of the size between the write address and the end of the page */
//  current_size = MX25L6433F_PAGE_SIZE - (Address % MX25L6433F_PAGE_SIZE);
//
//  /* Check if the size of the data is less than the remaining place in the page */
//  if (current_size > Size)
//  {
//    current_size = Size;
//  }
//
//  /* Perform the write page by page */
//  do
//  {
//   // ret = BSP_MEM_WriteData(0, data_addr, Address, current_size);
//
//    /* Update the address and size variables for next page programming */
//    Address += current_size;
//    data_addr += current_size;
//    current_size = ((Address + MX25L6433F_PAGE_SIZE) > end_addr) ? (end_addr - Address) : MX25L6433F_PAGE_SIZE;
//  } while ((Address < end_addr) && (BSP_ERROR_NONE == ret));
  sFLASH_WriteBuffer(buffer, Address, Size);	
  BSP_RETURN(ret);
}

/**
  * Description :
  * Verify flash memory with RAM buffer and calculates checksum value of
  * the programmed memory
  * Inputs    :
  *      FlashAddr     : Flash address
  *      RAMBufferAddr : RAM buffer address
  *      Size          : Size (in WORD)
  *      InitVal       : Initial CRC value
  * outputs   :
  *     R0             : Operation failed (address of failure)
  *     R1             : Checksum value
  * Note: Optional for all types of device
  */
KeepInCompilation uint64_t Verify (uint32_t MemoryAddr, uint32_t RAMBufferAddr, uint32_t Size, uint32_t missalignement)
{
  
  //int32_t ret = BSP_ERROR_NONE;
  uint32_t VerifiedData = 0, InitVal = 0;
  uint8_t TmpBuffer[4] = {0};
  uint64_t checksum;
  Size*=4;

  //MemoryMappedMode = 0;
  //ret = BSP_MEM_EnableMemoryMappedMode(0);
 //if(BSP_ERROR_NONE == ret)
 //{
 //  MemoryMappedMode = 1;
 //}

  checksum = CheckSum((uint32_t)MemoryAddr + (missalignement & 0xf), Size - ((missalignement >> 16) & 0xF), InitVal);

 //if(MemoryMappedMode)
 //{
 //  while (Size>VerifiedData)
 //  {
 //    if (*(uint32_t*)(MemoryAddr + VerifiedData) != *((uint32_t*)(RAMBufferAddr + VerifiedData)))
 //      return ((checksum<<32) + (MemoryAddr + VerifiedData));
 //
 //    VerifiedData += 4;
 //  }
 //}
 // else if(BSP_ERROR_FEATURE_NOT_SUPPORTED == ret)
 // {
    while (Size>VerifiedData)
    {
      //ret = BSP_MEM_ReadData(0, TmpBuffer, (MemoryAddr + VerifiedData), 4);
      sFLASH_ReadBuffer(TmpBuffer, MemoryAddr+VerifiedData, 4);
     // if ((BSP_ERROR_NONE != ret) || (*(uint32_t *)TmpBuffer != *((uint32_t *)(RAMBufferAddr + VerifiedData))))
      if ( (*(uint32_t *)TmpBuffer != *((uint32_t *)(RAMBufferAddr + VerifiedData))))
        return ((checksum<<32) + (MemoryAddr + VerifiedData));

      VerifiedData += 4;
    }
 // }

  //BSP_MEM_DeInit(0);

    /*
  uint32_t VerifiedData = 0;
  uint8_t TmpBuffer = 0x00;
  Size*=4;  //一个地址存4字节，所以1个size则循环读取4byte
  
  while (Size>VerifiedData)
  {
    sFLASH_ReadBuffer(&TmpBuffer, MemoryAddr+VerifiedData, 1);
    
    if (TmpBuffer != *((uint8_t*)RAMBufferAddr+VerifiedData))
      return (uint64_t)(MemoryAddr+VerifiedData);
    
    VerifiedData++;  
  }
*/
  return (checksum<<32);
   
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
