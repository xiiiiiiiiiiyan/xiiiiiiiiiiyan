/* Includes ------------------------------------------------------------------*/
#include "stm32_eval_spi_flash.h"
#include "stm32h7xx_.h"

 
    
SPI_HandleTypeDef SpiHandle;    
static uint8_t SPIx_Write(uint8_t u8WriteValue);

void sFLASH_DeInit(void)
{
  sFLASH_LowLevel_DeInit();
}

/**
  * @brief  Initializes the peripherals used by the SPI FLASH driver.
  * @param  None
  * @retval None
  */
void sFLASH_Init(void)
{
  HAL_StatusTypeDef Status         = HAL_OK;
  SpiHandle.Instance               = sFLASH_SPI;
  
  SpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  SpiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
  SpiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
  SpiHandle.Init.CLKPolarity       = SPI_POLARITY_LOW;
  SpiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
  SpiHandle.Init.CRCPolynomial     = 7;
  SpiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
  SpiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
  SpiHandle.Init.NSS               = SPI_NSS_SOFT;
  SpiHandle.Init.TIMode            = SPI_TIMODE_DISABLE;
  SpiHandle.Init.Mode              = SPI_MODE_MASTER;

  Status = HAL_SPI_Init(&SpiHandle);
  Status = Status;
}

/**
  * @brief  Erases the specified FLASH sector.
  * @param  SectorAddr: address of the sector to erase.
  * @retval None
  */
void sFLASH_EraseSector(uint32_t SectorAddr)
{
   /*!< Sector Erase */
    /*!< Select the FLASH  and send "Write Enable" instruction */
    sFLASH_WriteEnable();
    
    /*!< Send Sector Erase instruction */
   sFLASH_SendByte(sFLASH_CMD_SE);
    /*!< Send SectorAddr most high nibble address byte */
    sFLASH_SendByte((SectorAddr & 0xFF000000) >> 24);
    /*!< Send SectorAddr high nibble address byte */
    sFLASH_SendByte((SectorAddr & 0xFF0000) >> 16);
    /*!< Send SectorAddr medium nibble address byte */
    sFLASH_SendByte((SectorAddr & 0xFF00) >> 8);
    /*!< Send SectorAddr low nibble address byte */
    sFLASH_SendByte(SectorAddr & 0xFF);
    
    /*!< Wait the end of Flash writing and Deselect the FLASH*/
    sFLASH_WaitForWriteEnd();
}

/**
  * @brief  Erases the entire FLASH.
  * @param  None
  * @retval None
  */
void sFLASH_EraseBulk(void)
{
    /*!< Bulk Erase */
    /*!< Select the FLASH  and send "Write Enable" instruction */
    sFLASH_WriteEnable();

    /*!< Send Bulk Erase instruction  */
    sFLASH_SendByte(sFLASH_CMD_BE);

  /*!< Wait the end of Flash writing and Deselect the FLASH*/
    sFLASH_WaitForWriteEnd();
}

/**
  * @brief  Writes more than one byte to the FLASH with a single WRITE cycle 
  *         (Page WRITE sequence).
  * @note   The number of byte can't exceed the FLASH page size.
  * @param  pBuffer: pointer to the buffer  containing the data to be written
  *         to the FLASH.
  * @param  WriteAddr: FLASH's internal address to write to.
  * @param  NumByteToWrite: number of bytes to write to the FLASH, must be equal
  *         or less than "sFLASH_PAGESIZE" value.
  * @retval None
  */
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint32_t NumByteToWrite)
{
   if(NumByteToWrite > sFLASH_SPI_PAGESIZE)   
    {
      while(1){;}
    }
  /*!< Enable the write access to the FLASH */
  sFLASH_WriteEnable();

  /*!< Send "Write to Memory " instruction */
  sFLASH_SendByte(sFLASH_CMD_WRITE);
  /*!< Send uwStartAddress most high nibble address byte to write to */
  sFLASH_SendByte((WriteAddr & 0xFF000000) >> 24);
  /*!< Send WriteAddr high nibble address byte to write to */
  sFLASH_SendByte((WriteAddr & 0xFF0000) >> 16);
  /*!< Send WriteAddr medium nibble address byte to write to */
  sFLASH_SendByte((WriteAddr & 0xFF00) >> 8);
  /*!< Send WriteAddr low nibble address byte to write to */
  sFLASH_SendByte(WriteAddr & 0xFF);

  /*!< while there is data to be written on the FLASH */
  while (NumByteToWrite--)
  {
    /*!< Send the current byte */
    sFLASH_SendByte(*pBuffer);
    /*!< Point on the next byte to be written */
    pBuffer++;
  }

  /*!< Wait the end of Flash writing */
  sFLASH_WaitForWriteEnd();
}

/**
  * @brief  Writes block of data to the FLASH. In this function, the number of
  *         WRITE cycles are reduced, using Page WRITE sequence.
  * @param  pBuffer: pointer to the buffer  containing the data to be written
  *         to the FLASH.
  * @param  WriteAddr: FLASH's internal address to write to.
  * @param  NumByteToWrite: number of bytes to write to the FLASH.
  * @retval None
  */
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint32_t NumByteToWrite)
{
  
    uint32_t WroteSize = 0;     //已写入的字节数
    uint32_t StartPageSpace = (uint32_t)(sFLASH_SPI_PAGESIZE - WriteAddr % sFLASH_SPI_PAGESIZE);    //（位于起始地址之后的，到起始地址所在页末尾之间的）起始页可用空间
    uint32_t StartPageCnt = 0; //起始页要写入多少字节
    
    //防止写入的长度超过芯片剩余容量
    if(NumByteToWrite > FLASH_SPI_TOTALSIZE - WriteAddr)     //欲写入数据量 > 芯片（起始地址后的）剩余容量，超限
    {
       NumByteToWrite = FLASH_SPI_TOTALSIZE - WriteAddr;    //将 欲写入数据量 强制设为 剩余容量，防止“回卷”
    }
    
    StartPageCnt = ( NumByteToWrite > StartPageSpace ) ? StartPageSpace : NumByteToWrite;
    
    //第1步：先写起始页
    sFLASH_WritePage(pBuffer, WriteAddr, StartPageCnt);
    WroteSize = StartPageCnt;
    
    
    //第2步：如果 剩余待写数据量 大于1页
    while( NumByteToWrite >= (WroteSize + sFLASH_SPI_PAGESIZE) )
    {
        sFLASH_WritePage(pBuffer + WroteSize,  WriteAddr + WroteSize, sFLASH_SPI_PAGESIZE);  //每次写入1页，然后换页
        WroteSize += sFLASH_SPI_PAGESIZE;
    }
    
    //第3步：如果还没写完（但剩余数据量不足1页）
    if( NumByteToWrite > WroteSize )
    {
        sFLASH_WritePage(pBuffer + WroteSize, WriteAddr + WroteSize, NumByteToWrite - WroteSize);   //写完剩余部分
    }
    
}

/**
  * @brief  Reads a block of data from the FLASH.
  * @param  pBuffer: pointer to the buffer that receives the data read from the FLASH.
  * @param  ReadAddr: FLASH's internal address to read from.
  * @param  NumByteToRead: number of bytes to read from the FLASH.
  * @retval None
  */
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead)
{
  /*!< Select the FLASH: Chip Select low */
   FLASH_SPI_CS_LOW();

  /*!< Send "Read from Memory " instruction */
  sFLASH_SendByte(sFLASH_CMD_READ);
  /*!< Send ReadAddr most high nibble address byte to read from */
  sFLASH_SendByte((ReadAddr & 0xFF000000) >> 24);
  /*!< Send ReadAddr high nibble address byte to read from */
  sFLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
  /*!< Send ReadAddr medium nibble address byte to read from */
  sFLASH_SendByte((ReadAddr& 0xFF00) >> 8);
  /*!< Send ReadAddr low nibble address byte to read from */
  sFLASH_SendByte(ReadAddr & 0xFF);

  while (NumByteToRead--) /*!< while there is data to be read */
  {
    /*!< Read a byte from the FLASH */
    *pBuffer = sFLASH_SendByte(sFLASH_DUMMY_BYTE);
    /*!< Point to the next location where the byte read will be saved */
    pBuffer++;
  }

  /*!< Deselect the FLASH: Chip Select high */
   FLASH_SPI_CS_HIGH();
}



/**
  * @brief  Sends a byte through the SPI interface and return the byte received
  *         from the SPI bus.
  * @param  byte: byte to send.
  * @retval The value of the received byte.
  */
uint8_t sFLASH_SendByte(uint8_t byte)
{
  /* Send the byte */
  return (SPIx_Write(byte));
}

/**
  * @brief  Enables the write access to the FLASH.
  * @param  None
  * @retval None
  */
void sFLASH_WriteEnable(void)
{
   /*!< Select the FLASH: Chip Select low */
  FLASH_SPI_CS_LOW();
  
  /*!< Send "Write Enable" instruction */
  SPIx_Write(sFLASH_CMD_WREN);
  
  /*!< Select the FLASH: Chip Select low */
  FLASH_SPI_CS_HIGH();
  
    /*!< Select the FLASH: Chip Select low */
  FLASH_SPI_CS_LOW();
}

/**
  * @brief  Polls the status of the Write In Progress (WIP) flag in the FLASH's
  *         status register and loop until write opertaion has completed.
  * @param  None
  * @retval None
  */
void sFLASH_WaitForWriteEnd(void)
{
  /*!< Select the FLASH: Chip Select low */
  FLASH_SPI_CS_HIGH();
  
  /*!< Select the FLASH: Chip Select low */
  FLASH_SPI_CS_LOW();
  
  uint8_t flashstatus = 0;

  /*!< Send "Read Status Register" instruction */
  SPIx_Write(sFLASH_CMD_RDSR);

  /*!< Loop as long as the memory is busy with a write cycle */
  do
  {
    /*!< Send a dummy byte to generate the clock needed by the FLASH
    and put the value of the status register in FLASH_Status variable */
    flashstatus = SPIx_Write(sFLASH_DUMMY_BYTE);

  }
  while ((flashstatus & sFLASH_WIP_FLAG) == SET); /* Write in progress */

  /*!< Deselect the FLASH: Chip Select high */
  FLASH_SPI_CS_HIGH();
}

/**
  * @brief  SPI Write a byte to device
  * @param  u8WriteValue to be written
  * @retval The value of the received byte.
  */
static uint8_t SPIx_Write(uint8_t u8WriteValue)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t u8ReadValue = 0;

  status = HAL_SPI_TransmitReceive(&SpiHandle, (uint8_t*) &u8WriteValue, (uint8_t*) &u8ReadValue, 1, 1000);
  status = status;//消除告警
 
  
   return u8ReadValue;
}

