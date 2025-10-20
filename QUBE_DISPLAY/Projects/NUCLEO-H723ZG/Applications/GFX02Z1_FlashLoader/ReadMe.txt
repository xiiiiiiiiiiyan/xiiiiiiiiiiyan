/**
  @page X-NUCLEO-GFX02Z1 FlashLoader application

  @verbatim
  ******************** (C) COPYRIGHT 2023 STMicroelectronics *******************
  * @file    GFX02Z1_FlashLoader/ReadMe.txt
  * @author  MCD Application Team
  * @brief   Description of the X-NUCLEO-GFX02Z1 FlashLoader application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Application Description

How to use the X-CUBE-DISPLAY API to generate the External Flash Loader file MX25L6433F_GFX02Z1_STM32H7.stldr
used for the X-NUCLEO-GFX02Z1 expansion board mounted on a NUCLEO-H723ZG STM32 board.

The EWARM project contain a dedicated Test application for the generated external flash memory loader.

The Test aims to validate all required features from the external loader:
  - Test Init function eachtime the external flash loader is used.
  - Test SectorErase function
  - Test Write function
  - Test Verify function
  - Test MassErase function

BLUE USER Button is used to move onto test steps.

LED are used to follow the progress  and the status
  - LED_YELLOW will toggle waiting for an action from the user
  - LED_GREEN will toggle at the end of the test if everything is OK
  - LED_YELLOW, LED_GREEN and LED_RED LEDs will toggle in case of error

@note The generated MX25L6433F_GFX02Z1_STM32H7.stldr file can be used only by STM32CubeProgrammer or STM32CubeIDE.

@note The generated MX25L6433F_GFX02Z1_STM32H7.stldr file will be placed at the top root folder
Utilities\PC_Software\ExternalLoader

@par Hardware and Software environment

  - This application runs on Display expansion board attached to STM32H723ZGTx devices.
  - If you power the Nucleo board via USB port, please check that you have flashed the last version of
    the firmware of ST-Link inside the Nucleo board. In order to flash the last available firmware of the
	  ST-Link, you can use the STM32CubeProgrammer Utility.
  - This application has been tested with STMicroelectronics NUCLEO-H723ZG RevE and can be easily tailored to
    any other supported device and development board.

@par How to use it ?

This package contains projects for 3 IDEs viz. IAR, µVision and STM32CubeIDE. In order to make the
program work, you must do the following:
 - WARNING: before opening the project with any toolchain be sure your folder
   installation path is not too in-depth since the toolchain may report errors
   after building.

For IAR: (The External FlashLoader Test)
 - Open IAR toolchain.
 - Open the IAR project file EWARM\Project.eww.
 - Select the configuration GFX02Z1_FlashLoader_Tests
 - Rebuild all files and load the binary into target memory
 - Run the application.

For IAR:
 - Open IAR toolchain.
 - Open the IAR project file EWARM\Project.eww.
 - Select the configuration GFX02Z1_FlashLoader
 - Rebuild all files. The generated .stldr will be located inside the root folder Utilities\PC_Software\ExternalLoader.
 - Goto Binary folder of any application (ie. GFX02Z1_HelloWorld) and run the GFX02Z1_HelloWorld.bat script to program the GFX02Z1_HelloWorld.hex into the board.
 - Run the application and follow the instructions displayed on the LCD.

For µVision:
 - Open µVision 5 toolchain.
 - Open the µVision project file MDK-ARM\GFX02Z1_FlashLoader.uvprojx.
 - Rebuild all files. The generated .stldr will be located inside the root folder Utilities\PC_Software\ExternalLoader.
 - Goto Binary folder of any application (ie. GFX02Z1_HelloWorld) and run the GFX02Z1_HelloWorld.bat script to program the GFX02Z1_HelloWorld.hex into the board.
 - Run the application and follow the instructions displayed on the LCD.

For STM32CubeIDE:
 - Open STM32CubeIDE.
 - Set the default workspace proposed by the IDE (please be sure that there are not spaces in the workspace path).
 - Press "File" -> "Import" -> "Existing Projects into Workspace"; press "Browse" in the "Select root directory" and choose the path where the
   project is located (it should be <ProjectName>\STM32CubeIDE).
 - Rebuild all files. The generated .stldr will be located inside the root folder Utilities\PC_Software\ExternalLoader.
 - Goto Binary folder of any application (ie. GFX02Z1_HelloWorld) and run the GFX02Z1_HelloWorld.bat script to program the GFX02Z1_HelloWorld.hex into the board.
 - Run the application and follow the instructions displayed on the LCD.

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

