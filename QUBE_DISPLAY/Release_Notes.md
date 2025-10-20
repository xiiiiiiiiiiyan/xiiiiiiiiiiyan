---
pagetitle: Release Notes for X-CUBE-DISPLAY Package
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for <X-CUBE-DISPLAY\
Copyright &copy; \<2023\> STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# Purpose

**X-CUBE-DISPLAY** enable display, external memories and user interface features on top of STM32 boards.

Various user interfaces are supported by the **X-CUBE-DISPLAY** Expansion Package such as :

- LCD controllers (***ILI9341***, ***ST7789V***, ***Custom***)
- External Memory devices (***MX25L6433F***, ***Custom***)
- User buttons (***Joystick***)

This package offers also a complete project examples enabling easy and simple use of the GFX display
module extensions for STM32 NUCLEO boards. These project examples include STM32CubeMX configuration
project, as well embedded software extending NUCLLEO boards with graphic user interface capability,
including display, joystick control and external memory management.

It also provides needed external loaders to allow users programming the external flash memories
used with all supported GFX Expansion boards


<center>

![\<X-CUBE-DISPLAY Components\>](_htmresc/x-cube-display.png)\

</center>

Here is the list of references to the user documents:

-   [DB4299](https://www.st.com/resource/en/data_brief/x-cube-display.pdf): Display module software expansion for STM32Cube
-   [UM2787](https://www.st.com/resource/en/user_manual/um2787-getting-started-with-the-xcubedisplay-display-module-expansion-package-for-stm32cube-stmicroelectronics.pdf): Getting started with the X-CUBE-DISPLAY display module Expansion Package for STM32Cube
-   [STM32Cube](http://www.st.com/stm32cube)
-   [STM32 Nucleo boards](http://www.st.com/stm32nucleo)
-   [STM32 Nucleo expansion boards](http://www.st.com/x-nucleo)
:::

::: {.col-sm-12 .col-lg-8}
# Update history

::: {.collapse}
<input type="checkbox" id="collapse-section_3_0_0" checked aria-hidden="true">
<label for="collapse-section_3_0_0" aria-hidden="true">__3.0.0 / 18-Jan-2023__</label>
<div>

## Main changes

### New Major release with new features and fixes

  New features
  ----------------------------------------------------------
  Added support for Cortex-M7 devices
  Added LCD Utilities to support displaying transparent Texts
  Added new application examples for the Custom LCD and Memory Controllers
  Added new application examples for the external flash loaders
  Removed deprecated functions

  Updated Component drivers
  ----------------------------------------------------------
  Common BSP Drivers
  ILI9341 LCD Controller's Drivers
  ST7789V LCD Controller's Drivers
  MX25L6433F QuadSPI Memory Drivers

  Updated HAL and CMSIS Drivers
  ----------------------------------------------------------
  Added STM32H7xx CMSIS and HAL Drivers
  Updated STM32WBxx HAL Drivers

  Bugfixes
  ----------------------------------------------------------
  Fixed issue with generated mem_io code when using DMA
  Fixed issues with Custom LCD and external memory interfaces

  Updated Applications
  ----------------------------------------------------------
  GFX01M1_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M1_HelloWorld Application example for the NUCLEO-L476RG board
  GFX01M2_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M2_FreeRTOS Application example for the NUCLEO-L476RG board
  GFX01M2_HelloWorld Application example for the NUCLEO-WB55RG board
  GFX02Z1_HelloWorld Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_FreeRTOS Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_HelloWorld Application example for the NUCLEO-U575ZI-Q board
  GFX02Z1_ThreadX Application example for the NUCLEO-U575ZI-Q board

  New Applications
  ----------------------------------------------------------
  GFX01M2_Custom Application example for the NUCLEO-WB55RG board
  GFX02Z1_Custom Application example for the NUCLEO-U575ZI board
  GFX01M2_FlashLoader Application example for the NUCLEO-WB55RG board
  GFX02Z1_FlashLoader Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_FlashLoader Application example for the NUCLEO-U575ZI board
  GFX02Z1_HelloWorld Application example for the NUCLEO-H723ZG board
  GFX02Z1_FlashLoader Application example for the NUCLEO-H723ZG board

## Contents

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

Components

  Name                                                        Version                                           Release note
  ----------------------------------------------------------- ------------------------------------------------- -------------------------------------------------------------------------------------------------------------------------
  STM32G0xx HAL                                               V1.4.2                                            [release note](Drivers/STM32G0xx_HAL_Driver/Release_Notes.html)
  STM32L4xx HAL                                               V1.13.2                                           [release note](Drivers/STM32L4xx_HAL_Driver/Release_Notes.html)
  STM32U5xx HAL                                               V1.1.0                                            [release note](Drivers/STM32U5xx_HAL_Driver/Release_Notes.html)
  STM32WBxx HAL                                               V1.11.0   []{.icon-st-update}                     [release note](Drivers/STM32WBxx_HAL_Driver/Release_Notes.html)
  STM32H7xx HAL                                               V1.11.0   []{.icon-st-add}                        [release note](Drivers/STM32H7xx_HAL_Driver/Release_Notes.html)
  BSP Common                                                  V3.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/common/Release_Notes.html)
  BSP IL9341                                                  V3.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/ili9341/Release_Notes.html)
  BSP ST7789V                                                 V3.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/st7789v/Release_Notes.html)
  BSP MX25L6433F                                              V2.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/mx25l6433f/Release_Notes.html)

## Development toolchains and compilers

- IAR Embedded Workbench for ARM (EWARM)toolchain 8.50.9
- [STM32CubeIDE V1.11.0](https://www.st.com/en/development-tools/stm32cubeide.html)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.38
- [STM32CubeProgrammer V2.11.0](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Supported STM32 devices and boards

- [NUCLEO-G071RB](https://www.st.com/en/evaluation-tools/nucleo-g071rb.html)
- [NUCLEO-L4R5ZI](https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html)
- [NUCLEO-L476RG](https://www.st.com/en/evaluation-tools/nucleo-l476rg.html)
- [NUCLEO-U575ZI-Q](https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html)
- [NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)
- [NUCLEO-H723ZG](https://www.st.com/en/evaluation-tools/nucleo-h723zg.html)

## Supported GFX boards

- [X-NUCLEO-GFX01M1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m1.html)
- [X-NUCLEO-GFX01M2](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html)
- [X-NUCLEO-GFX02Z1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx02z1.html)

## Backward compatibility

- This is a major release which should be compatible with former releases when using STM32CubeMX
to re-generate code for old IOC files

## Dependencies

This software release is compatible with:

- This release is compatible with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html#get-software) version **6.7.0** or higher

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section_2_2_0" checked aria-hidden="true">
<label for="collapse-section_2_2_0" aria-hidden="true">__2.2.0 / 02-May-2022__</label>
<div>

## Main changes

### New Patch release with minor changes and fixes

  New features
  ----------------------------------------------------------
  Added Support for Custom LCD Controllers
  Added Support for Custom External Memory Controllers
  Generated PDF and CHM API Documentation

  Bugfixes
  ----------------------------------------------------------
  Fix Issue with undefined BRR for non supported series F7 and H7
  Disable the SW pack when TrustZone is enabled
  Disable the SW pack for non-supported STM32 Families
  STM32CubeIDE: add debug launcher files

  Updated Applications
  ----------------------------------------------------------
  GFX01M1_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M1_HelloWorld Application example for the NUCLEO-L476RG board
  GFX01M2_FreeRTOS Application example for the NUCLEO-L476RG board
  GFX01M2_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M2_HelloWorld Application example for the NUCLEO-WB55RG board
  GFX02Z1_HelloWorld Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_FreeRTOS Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_HelloWorld Application example for the NUCLEO-U575ZI-Q board
  GFX02Z1_ThreadX Application example for the NUCLEO-U575ZI-Q board

## Contents

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

Components

  Name                                                        Version                                           Release note
  ----------------------------------------------------------- ------------------------------------------------- -------------------------------------------------------------------------------------------------------------------------
  STM32G0xx HAL                                               V1.4.2                                            [release note](Drivers/STM32G0xx_HAL_Driver/Release_Notes.html)
  STM32L4xx HAL                                               V1.13.2                                           [release note](Drivers/STM32L4xx_HAL_Driver/Release_Notes.html)
  STM32U5xx HAL                                               V1.1.0                                            [release note](Drivers/STM32U5xx_HAL_Driver/Release_Notes.html)
  STM32WBxx HAL                                               V1.10.0                                           [release note](Drivers/STM32WBxx_HAL_Driver/Release_Notes.html)
  BSP Common                                                  V2.1.0                                            [release note](Drivers/BSP/Components/common/Release_Notes.html)
  BSP IL9341                                                  V2.1.0                                            [release note](Drivers/BSP/Components/ili9341/Release_Notes.html)
  BSP ST7789V                                                 V2.1.0                                            [release note](Drivers/BSP/Components/st7789v/Release_Notes.html)
  BSP MX25L6433F                                              V1.0.1                                            [release note](Drivers/BSP/Components/mx25l6433f/Release_Notes.html)

## Development toolchains and compilers

- IAR Embedded Workbench for ARM (EWARM)toolchain 8.50.9
- [STM32CubeIDE V1.9.0](https://www.st.com/en/development-tools/stm32cubeide.html)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.35
- [STM32CubeProgrammer V2.10.0](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Supported STM32 devices and boards

- [NUCLEO-G071RB](https://www.st.com/en/evaluation-tools/nucleo-g071rb.html)
- [NUCLEO-L4R5ZI](https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html)
- [NUCLEO-L476RG](https://www.st.com/en/evaluation-tools/nucleo-l476rg.html)
- [NUCLEO-U575ZI-Q](https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html)
- [NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)

## Supported GFX boards

- [X-NUCLEO-GFX01M1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m1.html)
- [X-NUCLEO-GFX01M2](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html)
- [X-NUCLEO-GFX02Z1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx02z1.html)

## Backward compatibility

- This is a minor release which should be compatible with former releases
- Please consider replacing deprecated APIs from your application code before next major release

## Dependencies

This software release is compatible with:

- This release is compatible with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html#get-software) version **6.5.0** or higher

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section_2_1_0" checked aria-hidden="true">
<label for="collapse-section_2_1_0" aria-hidden="true">__2.1.0 / 08-April-2022__</label>
<div>

## Main changes

### New Patch release with minor changes and fixes

  New features
  ----------------------------------------------------------
  Support Real Time Operating systems: FreeRTOS and ThreadX Native Middleware
  Support HW Timers for TE Event and line counting
  Support disabling TE Events
  Support Little and Big ENDIANS
  Support swap of Red and Blue components
  Support Linked list GPDMA requests for FMC LCD Controllers
  MEM: Exported size of external Flash memory
  ExternalLoaders : Added MX25L6433F_GFX01M2_STM32L4.stldr

  Bugfixes
  ----------------------------------------------------------
  Deprecated API BSP_MEM_GetTransfertStatus() and renamed to BSP_MEM_GetTransferStatus()
  Deprecated API BSP_MEM_SignalTransfertDone() and renamed to BSP_MEM_SignalTransferDone()
  Deprecated API BSP_LCD_GetTransfertStatus() and renamed to BSP_LCD_GetTransferStatus()
  Deprecated API BSP_LCD_SignalTransfertDone() and renamed to BSP_LCD_SignalTransferDone()
  Release LCD/MEM locks before notifying upper levels
  Disable DMA parameter for OCTOSPI external memories
  Fixed Dependencies for Board Part
  LCD: Set default Vsync Frequency to 60 Hz
  Fixed destination folder to be always DISPLAY
  Clean-up header file include for BSP Drivers
  External Loaders : Fixed issue with STM32CubeIDE not able to load external loaders

  Updated Component drivers
  ----------------------------------------------------------
  ILI9341 LCD Controller's Driver
  ST7789V LCD Controller's Driver
  MX25L6433F QuadSPI Memory Driver

  Updated HAL and CMSIS Drivers
  ----------------------------------------------------------
  Updated CMSIS ST Devices
  Updated STM32G0xx HAL Drivers
  Updated STM32L4xx HAL Drivers
  Updated STM32U5xx HAL Drivers

  New Middlewares
  ----------------------------------------------------------
  FreeRTOS (CMSIS V1 and V2)
  AzureRTOS ThreadX

  Updated Applications
  ----------------------------------------------------------
  GFX01M1_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M1_HelloWorld Application example for the NUCLEO-L476RG board
  GFX01M2_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M2_HelloWorld Application example for the NUCLEO-WB55RG board
  GFX02Z1_HelloWorld Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_HelloWorld Application example for the NUCLEO-U575ZI-Q board

  New Applications
  ----------------------------------------------------------
  GFX02Z1_FreeRTOS Application example for the NUCLEO-L4R5ZI board
  GFX01M2_FreeRTOS Application example for the NUCLEO-L476RG board
  GFX02Z1_ThreadX Application example for the NUCLEO-U575ZI-Q board

## Contents

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

Components

  Name                                                        Version                                           Release note
  ----------------------------------------------------------- ------------------------------------------------- -------------------------------------------------------------------------------------------------------------------------
  STM32G0xx HAL                                               V1.4.2                                            [release note](Drivers/STM32G0xx_HAL_Driver/Release_Notes.html)
  STM32L4xx HAL                                               V1.13.2   []{.icon-st-update}                     [release note](Drivers/STM32L4xx_HAL_Driver/Release_Notes.html)
  STM32U5xx HAL                                               V1.1.0    []{.icon-st-update}                     [release note](Drivers/STM32U5xx_HAL_Driver/Release_Notes.html)
  STM32WBxx HAL                                               V1.10.0                                           [release note](Drivers/STM32WBxx_HAL_Driver/Release_Notes.html)
  BSP Common                                                  V2.1.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/common/Release_Notes.html)
  BSP IL9341                                                  V2.1.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/ili9341/Release_Notes.html)
  BSP ST7789V                                                 V2.1.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/st7789v/Release_Notes.html)
  BSP MX25L6433F                                              V1.0.1    []{.icon-st-update}                     [release note](Drivers/BSP/Components/mx25l6433f/Release_Notes.html)

## Known limitations


## Development toolchains and compilers

- IAR Embedded Workbench for ARM (EWARM)toolchain 8.50.9
- [STM32CubeIDE V1.9.0](https://www.st.com/en/development-tools/stm32cubeide.html)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.35
- [STM32CubeProgrammer V2.10.0](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Supported STM32 devices and boards

- [NUCLEO-G071RB](https://www.st.com/en/evaluation-tools/nucleo-g071rb.html)
- [NUCLEO-L4R5ZI](https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html)
- [NUCLEO-L476RG](https://www.st.com/en/evaluation-tools/nucleo-l476rg.html)
- [NUCLEO-U575ZI-Q](https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html)
- [NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)

## Supported GFX boards

- [X-NUCLEO-GFX01M1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m1.html)
- [X-NUCLEO-GFX01M2](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html)
- [X-NUCLEO-GFX02Z1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx02z1.html)

## Backward compatibility

- This is a minor release which should be compatible with former releases
- Please consider replacing deprecated APIs from your application code before next major release

## Dependencies

This software release is compatible with:

- This release is compatible with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html#get-software) version **6.5.0** or higher

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section_2_0_1" checked aria-hidden="true">
<label for="collapse-section_2_0_1" aria-hidden="true">__2.0.1 / 13-December-2021__</label>
<div>

## Main changes

### New Patch release with minor changes and fixes

  New features
  ----------------------------------------------------------
  Add Support TE Modes 1 and 2

  Bugfixes
  ----------------------------------------------------------
  Fix line counting on TE events
  Fix reading device id issue for the X-NUCLEO-GFX01M2 expansion board
  Check for operation status before calling apis
  Add PACK_SELF_CONTEXTUALIZATION keyword
  Return Error when DMA was not configured by user for BSP SPI
  NUCLEO-WB55RG - HelloWorld Example : Update system clock to 64MHz

  Updated STM32CubeMX files
  ----------------------------------------------------------
  Config and Modes : Updated dependencies for SPI, FMC and OCTOSPI
  Modes : Added new parameter **p_display_te_mode** for TE Mode
  Modes : Added new parameter **p_display_te_scanline** for TE Scanline
  Modes : Exported **SEMDISPLAY***Cc***TE***Oo***Mode***Jj***1** for LCD TE Mode 1
  Modes : Exported **SEMDISPLAY***Cc***TE***Oo***Mode***Jj***2** for LCD TE Mode 2

  Updated Component drivers
  ----------------------------------------------------------
  ILI9341 LCD Controller's Driver
  ST7789V LCD Controller's Driver

  Updated HAL and CMSIS Drivers
  ----------------------------------------------------------
  Updated CMSIS ST Devices
  Updated STM32WBxx HAL Drivers

  Updated Applications
  ----------------------------------------------------------
  GFX01M1_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M1_HelloWorld Application example for the NUCLEO-L476RG board
  GFX01M2_HelloWorld Application example for the NUCLEO-G071RB board
  GFX01M2_HelloWorld Application example for the NUCLEO-WB55RG board
  GFX02Z1_HelloWorld Application example for the NUCLEO-L4R5ZI board
  GFX02Z1_HelloWorld Application example for the NUCLEO-U575ZI board

## Contents

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

Components

  Name                                                        Version                                           Release note
  ----------------------------------------------------------- ------------------------------------------------- -------------------------------------------------------------------------------------------------------------------------
  STM32G0xx HAL                                               V1.4.2                                            [release note](Drivers/STM32G0xx_HAL_Driver/Release_Notes.html)
  STM32L4xx HAL                                               V1.13.0                                           [release note](Drivers/STM32L4xx_HAL_Driver/Release_Notes.html)
  STM32U5xx HAL                                               V1.0.0                                            [release note](Drivers/STM32U5xx_HAL_Driver/Release_Notes.html)
  STM32WBxx HAL                                               V1.10.0   []{.icon-st-update}                     [release note](Drivers/STM32WBxx_HAL_Driver/Release_Notes.html)
  BSP Common                                                  V2.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/common/Release_Notes.html)
  BSP IL9341                                                  V2.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/ili9341/Release_Notes.html)
  BSP ST7789V                                                 V2.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/st7789v/Release_Notes.html)
  BSP MX25L6433F                                              V1.0.0                                            [release note](Drivers/BSP/Components/mx25l6433f/Release_Notes.html)

## Known limitations


## Development toolchains and compilers

- IAR Embedded Workbench for ARM (EWARM)toolchain 8.50.9
- [STM32CubeIDE V1.8.0](https://www.st.com/en/development-tools/stm32cubeide.html)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.35
- [STM32CubeProgrammer V2.9.0](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Supported STM32 devices and boards

- [NUCLEO-G071RB](https://www.st.com/en/evaluation-tools/nucleo-g071rb.html)
- [NUCLEO-L4R5ZI](https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html)
- [NUCLEO-L476RG](https://www.st.com/en/evaluation-tools/nucleo-l476rg.html)
- [NUCLEO-U575ZI-Q](https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html)
- [NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)

## Supported GFX boards

- [X-NUCLEO-GFX01M1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m1.html)
- [X-NUCLEO-GFX01M2](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html)
- [X-NUCLEO-GFX02Z1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx02z1.html)

## Backward compatibility

- This is a major release which could be not compatible with former releases

## Dependencies

This software release is compatible with:

- This release is compatible with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html#get-software) version **6.4.0** or higher

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section_2_0_0" checked aria-hidden="true">
<label for="collapse-section_2_0_0" aria-hidden="true">__2.0.0 / 25-October-2021__</label>
<div>

## Main changes

### New Major release with more supported Devices and Boards

New features

  New supported STM32 devices
  ----------------------------------------------------------
  Add support for cortex-M4 core
  Add support for cortex-M33 core

  New supported STM32 boards
  ----------------------------------------------------------
  Add support for NUCLEO-L476RG STM32 board
  Add support for NUCLEO-WB55RG STM32 board
  Add support for NUCLEO-U575ZI STM32 board

  New supported GFX boards
  ----------------------------------------------------------
  Add support for X-NUCLEO-GFX01M2 Expansion board
  Add support for X-NUCLEO-GFX02Z1 Expansion board

  New supported Component drivers
  ----------------------------------------------------------
  Add support for MX25L6433F QuadSPI Memory Driver
  Add support for ST7789V LCD Controller's Driver

  New Applications
  ----------------------------------------------------------
  Add GFX01M1_HelloWorld Application example for the NUCLEO-L476RG board
  Add GFX01M2_HelloWorld Application example for the NUCLEO-G071RB board
  Add GFX01M2_HelloWorld Application example for the NUCLEO-WB55RG board
  Add GFX02Z1_HelloWorld Application example for the NUCLEO-U575ZI board

## Contents

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

Components

  Name                                                        Version                                           Release note
  ----------------------------------------------------------- ------------------------------------------------- -------------------------------------------------------------------------------------------------------------------------
  STM32G0xx HAL                                               V1.4.2    []{.icon-st-update}                     [release note](Drivers/STM32G0xx_HAL_Driver/Release_Notes.html)
  STM32L4xx HAL                                               V1.13.0   []{.icon-st-add}                        [release note](Drivers/STM32L4xx_HAL_Driver/Release_Notes.html)
  STM32U5xx HAL                                               V1.0.0    []{.icon-st-add}                        [release note](Drivers/STM32U5xx_HAL_Driver/Release_Notes.html)
  STM32WBxx HAL                                               V1.9.0    []{.icon-st-add}                        [release note](Drivers/STM32WBxx_HAL_Driver/Release_Notes.html)
  BSP Common                                                  V1.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/common/Release_Notes.html)
  BSP IL9341                                                  V1.0.0    []{.icon-st-update}                     [release note](Drivers/BSP/Components/ili9341/Release_Notes.html)
  BSP ST7789V                                                 V1.0.0    []{.icon-st-add}                        [release note](Drivers/BSP/Components/st7789v/Release_Notes.html)
  BSP MX25L6433F                                              V1.0.0    []{.icon-st-add}                        [release note](Drivers/BSP/Components/mx25l6433f/Release_Notes.html)

## Known limitations


## Development toolchains and compilers

- IAR Embedded Workbench for ARM (EWARM)toolchain 8.50.9
- [STM32CubeIDE V1.7.0](https://www.st.com/en/development-tools/stm32cubeide.html)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.35
- [STM32CubeProgrammer V2.8.0](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Supported STM32 devices and boards

- [NUCLEO-G071RB](https://www.st.com/en/evaluation-tools/nucleo-g071rb.html)
- [NUCLEO-L4R5ZI](https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html)
- [NUCLEO-L476RG](https://www.st.com/en/evaluation-tools/nucleo-l476rg.html)
- [NUCLEO-U575ZI-Q](https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html)
- [NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)

## Supported GFX boards

- [X-NUCLEO-GFX01M1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m1.html)
- [X-NUCLEO-GFX01M2](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html)
- [X-NUCLEO-GFX02Z1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx02z1.html)

## Backward compatibility

- This is a major release which could be not compatible with former releases

## Dependencies

This software release is compatible with:

- This release is compatible with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html#get-software) version **6.3.0** or higher

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section_1_0_0" checked aria-hidden="true">
<label for="collapse-section_1_0_0" aria-hidden="true">__1.0.0 / 08-October-2020__</label>
<div>

## Main changes

### First official release of firmware for X-NUCLEO-DISPLAY Software Expansion Pack

New features

  New supported STM32 devices
  ----------------------------------------------------------
  Add support for cortex-M0+ core

  New supported STM32 boards
  ----------------------------------------------------------
  Add support for NUCLEO-G071RB STM32 board

  New supported GFX boards
  ----------------------------------------------------------
  Add support for X-NUCLEO-GFX01M1 Expansion board

  New supported Component drivers
  ----------------------------------------------------------
  Add support for ILI9341 LCD Controller's Driver

  New Applications
  ----------------------------------------------------------
  Add GFX01M1_HelloWorld Application example for the NUCLEO-G071RB board

## Contents

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

Components

  Name                                                        Version                                           Release note
  ----------------------------------------------------------- ------------------------------------------------- -------------------------------------------------------------------------------------------------------------------------
  STM32G0xx HAL                                               V1.3.0    []{.icon-st-add}                        [release note](Drivers/STM32G0xx_HAL_Driver/Release_Notes.html)
  BSP Common                                                  V1.0.0    []{.icon-st-add}                        [release note](Drivers/BSP/Components/common/Release_Notes.html)
  BSP IL9341                                                  V1.0.0    []{.icon-st-add}                        [release note](Drivers/BSP/Components/ili9341/Release_Notes.html)

## Known limitations


## Development toolchains and compilers

- IAR Embedded Workbench for ARM (EWARM)toolchain 8.50.9
- [STM32CubeIDE V1.7.0](https://www.st.com/en/development-tools/stm32cubeide.html)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.35
- [STM32CubeProgrammer V2.5.0](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Supported STM32 devices and boards

- [NUCLEO-G071RB](https://www.st.com/en/evaluation-tools/nucleo-g071rb.html)

## Supported GFX boards

- [X-NUCLEO-GFX01M1](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m1.html)

## Backward compatibility


## Dependencies

This software release is compatible with:

- This release is compatible with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html#get-software) version **6.0.0** or higher

</div>
:::


:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on **X-CUBE-DISPLAY** ,
visit: [www.st.com/x-cube-display.html](https://www.st.com/en/embedded-software/x-cube-display.html)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.1">Info</abbr>
:::
:::
</footer>
