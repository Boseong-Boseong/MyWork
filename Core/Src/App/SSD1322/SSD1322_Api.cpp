/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    : Core\Src\App\SSD1322\SSD1322_Api.cpp
  * @brief   : SSD1322 API file.
  * @author  : bskim
  * @date    : 2023-09-17
  * @version :
  * 
  * @attention
  * Copyright (C) 2020 Wojciech Klimek
  * MIT license:
  * https://github.com/wjklimek1/SSD1322_OLED_library
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SSD1322_Api.h"
/* USER CODE END Includes */


/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */


/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */


/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */


/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t SSD1322_Api::_siTxBuffer[OLED_TX_BUFFER_SIZE] = {0,};
/* USER CODE END PV */


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
SSD1322_Api::SSD1322_Api(SSD1322_Spi & hSsd1322Spi, SSD1322_Gpio & hSsd1322Gpio)
: _hSsd1322Spi(hSsd1322Spi),
  _hSsd1322Gpio(hSsd1322Gpio)
{
}

SSD1322_Api::~SSD1322_Api(void)
{
}

/**
  ******************************************************************************
  * @brief   : Set initial config to SSD1322 module via SPI.
  * @note    : It must be initialized after SSD1322_Spi handler initialized.
  * @author  : bskim
  * @date    : 2023-09-25
  * @version :
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::initialize(void)
{
  /* Initialize GPIO, SPI3 for SSD1322 */
  _hSsd1322Gpio.initialize();
  _hSsd1322Spi.initialize();

  /* Initialize SSD1322 */
  setRstPinLow();                      //Reset pin low
  delayMs(1);                          //1ms delay
  setRstPinHigh();                     //Reset pin high
  delayMs(50);                         //50ms delay
  sendCmdToSSD1322(0xFD);              //set Command unlock
  sendDataToSSD1322(0x12);
  sendCmdToSSD1322(0xAE);              //set display off
  sendCmdToSSD1322(0xB3);              //set display clock divide ratio
  sendDataToSSD1322(0x91);
  sendCmdToSSD1322(0xCA);              //set multiplex ratio
  sendDataToSSD1322(0x3F);
  sendCmdToSSD1322(0xA2);              //set display offset to 0
  sendDataToSSD1322(0x00);
  sendCmdToSSD1322(0xA1);              //start display start line to 0
  sendDataToSSD1322(0x00);
  sendCmdToSSD1322(0xA0);              //set remap and dual COM Line Mode
  sendDataToSSD1322(0x14);
  sendDataToSSD1322(0x11);
  sendCmdToSSD1322(0xB5);              //disable IO input
  sendDataToSSD1322(0x00);
  sendCmdToSSD1322(0xAB);              //function select
  sendDataToSSD1322(0x01);
  sendCmdToSSD1322(0xB4);              //enable VSL extern
  sendDataToSSD1322(0xA0);
  sendDataToSSD1322(0xFD);
  sendCmdToSSD1322(0xC1);              //set contrast current
  sendDataToSSD1322(0xFF);
  sendCmdToSSD1322(0xC7);              //set master contrast current
  sendDataToSSD1322(0x0F);
  sendCmdToSSD1322(0xB9);              //default grayscale
  sendCmdToSSD1322(0xB1);              //set phase length
  sendDataToSSD1322(0xE2);
  sendCmdToSSD1322(0xD1);              //enhance driving scheme capability
  sendDataToSSD1322(0x82);
  sendDataToSSD1322(0x20);
  sendCmdToSSD1322(0xBB);              //first pre charge voltage
  sendDataToSSD1322(0x1F);
  sendCmdToSSD1322(0xB6);              //second pre charge voltage
  sendDataToSSD1322(0x08);
  sendCmdToSSD1322(0xBE);              //VCOMH
  sendDataToSSD1322(0x07);
  sendCmdToSSD1322(0xA6);              //set normal display mode
  sendCmdToSSD1322(0xA9);              //no partial mode
  delayMs(10);                         //stabilize VDD

  setWindow(SSD1322_WINDOW_COL_START,
            SSD1322_WINDOW_COL_END,
            SSD1322_WINDOW_ROW_START,
            SSD1322_WINDOW_ROW_END);   //set window size

  sendCmdToSSD1322(0xAF);              //display on
  delayMs(50);                         //stabilize VDD
  clearWindow();
}

/**
  ******************************************************************************
  * @brief   : Send the data to SSD1322 module via SPI.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-25
  * @version :
  * 
  * @param[in] iData Data that you send to SSD1322.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::sendDataToSSD1322(uint8_t iData)
{
  setCsPinLow();
  setDcPinHigh();
  _hSsd1322Spi.writeByteSPI(iData);
  setCsPinHigh();
}

/**
  ******************************************************************************
  * @brief   : Send the command to SSD1322 module via SPI.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-25
  * @version :
  * 
  * @param[in] iCmd Command that you send to SSD1322.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::sendCmdToSSD1322(uint8_t iCmd)
{
  setCsPinLow();
  setDcPinLow();
  _hSsd1322Spi.writeByteSPI(iCmd);
  setCsPinHigh();
}

/**
  ******************************************************************************
  * @brief   : Set display mode of OLED Module.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-25
  * @version :
  * 
  * @param[in] eMode enum var to set display mode of SSD1322.
  * 
  * @see enumSSD1322Mode_t
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::setDisplayMode(enumSSD1322Mode_t eMode)
{
  switch (eMode)
	{
	case eSSD1322Mode_NORMAL:
		sendCmdToSSD1322(SSD1322_SET_DISP_MODE_NORMAL);
		break;
	case eSSD1322Mode_INVERTED:
		sendCmdToSSD1322(SSD1322_SET_DISP_MODE_INVERTED);
		break;
	case eSSD1322Mode_ON:
		sendCmdToSSD1322(SSD1322_SET_DISP_MODE_ON);
		break;
	case eSSD1322Mode_OFF:
		sendCmdToSSD1322(SSD1322_SET_DISP_MODE_OFF);
		break;
	}
}

/**
  ******************************************************************************
  * @brief   : Set OLED window size. (range of pixels)
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-25
  * @version :
  * 
  * @param[in] iStartColumn Start of the column on the screen.
  * @param[in] iEndColumn   End of the column on the screen.
  * @param[in] iStartRow    Start of the row on the screen.
  * @param[in] iEndRow      End of the row on the screen.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::setWindow(uint8_t iStartColumn, uint8_t iEndColumn, uint8_t iStartRow, uint8_t iEndRow)
{
  sendCmdToSSD1322(SSD1322_SET_COLUMN_ADDR); //set columns range
  sendDataToSSD1322(SSD1322_COLUMN_OFFSET + iStartColumn);
  sendDataToSSD1322(SSD1322_COLUMN_OFFSET + iEndColumn);
  sendCmdToSSD1322(SSD1322_SET_ROW_ADDR);    //set rows range
  sendDataToSSD1322(iStartRow);
  sendDataToSSD1322(iEndRow);
}

/**
  ******************************************************************************
  * @brief   : Clear the OLED window.
  * @note    : Fill 0 to all pixels on OLED panel.
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::clearWindow(void)
{
    setScreenBrightness(eSSD1322Brightness_LEVEL_0);
    sendBufferToOLED(0, 0);
}

/**
  ******************************************************************************
  * @brief   : Set brightness of the background.
  * @note    :
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] iBrightness Brightness of all pixels.
  * 
  * @see enumSSD1322Brightness_t
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::setScreenBrightness(enumSSD1322Brightness_t iBrightness)
{
  	uint8_t value = (iBrightness << 4) | iBrightness;
    uint32_t bufferSize = _iBufferHeight * _iBufferWidth / 2;
    uint32_t bufferIndex = 0;

    while (bufferSize--)
    {
        _siTxBuffer[bufferIndex++] = value;
    }
}

/**
  ******************************************************************************
  * @brief   : Send buffer that has pixel position to the OLED module.
  * @note    : This function is needed to be called after all GFX function in SSD1322_Gfx.c file.
  *            ex) drawText(), clearAndDrawText(), drawBitMap8bpp())
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] xStart Horizontal position on the OLED panel for scrolling.
  * @param[in] yStart Vertical position on the OLED panel for scrolling.
  *
  * @retval None
  ******************************************************************************
  */
void SSD1322_Api::sendBufferToOLED(uint16_t xStart, uint16_t yStart)
{
    sendCmdToSSD1322(SSD1322_ENABLE_RAM_WRITE);
    setCsPinLow();
    setDcPinHigh();
    _hSsd1322Spi.writeArraySPI(_siTxBuffer + (yStart * OLED_WIDTH / 2) + xStart, OLED_TX_BUFFER_SIZE);
    setCsPinHigh();
}

/* TODO */
void SSD1322_Api::setSleepMode(uint8_t mode)
{

}

void SSD1322_Api::setContrast(uint8_t contrast)
{

}

bool SSD1322_Api::setGrayScale(uint8_t *pTableOrNull)
{
  return true;
}
/* USER CODE END 0 */