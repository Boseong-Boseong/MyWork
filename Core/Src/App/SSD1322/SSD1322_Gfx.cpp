/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Gfx.cpp
  * @brief   SSD1322 GFX file to draw some basic shapes on OLED display.
  * @author  bskim
  * @date    23-09-17
  * @version 
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
#include "SSD1322_Gfx.h"
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

/* USER CODE END PV */


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/** @ingroup SSD1322_Module
 *  @brief OLED module classes.
  * @{
  */
SSD1322_Gfx::SSD1322_Gfx(SSD1322_Api & hSsd1322Api)
: _hSsd1322Api(hSsd1322Api)
{
}

SSD1322_Gfx::~SSD1322_Gfx(void)
{
}

void SSD1322_Gfx::initialize(void)
{
}

/**
  ******************************************************************************
  * @brief   : Draw a pixel on the OLED panel.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] iPosX       X axis position of top left on the OLED panel.
  * @param[in] iPosY       Y axis position of top left on the OLED panel.
  * @param[in] iBrightness Brightness of the pixel.
  * 
  * @see enumSSD1322Brightness_t
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::drawPixel(uint16_t iPosX, uint16_t iPosY, enumSSD1322Brightness_t iBrightness)
{
    if (iPosX > (_hSsd1322Api._iBufferWidth - 1) || iPosY > (_hSsd1322Api._iBufferHeight - 1))
    {
      return;
    }

    if ((iPosY * _hSsd1322Api._iBufferWidth + iPosX) % 2 == 1)
    {
      _hSsd1322Api._siTxBuffer[((iPosY * _hSsd1322Api._iBufferWidth) + iPosX) / 2] = (_hSsd1322Api._siTxBuffer[((iPosY * _hSsd1322Api._iBufferWidth) + iPosX) / 2] & 0xF0) | iBrightness;
    }
    else
    {
      _hSsd1322Api._siTxBuffer[((iPosY * _hSsd1322Api._iBufferWidth) + iPosX) / 2] = (_hSsd1322Api._siTxBuffer[((iPosY * _hSsd1322Api._iBufferWidth) + iPosX) / 2] & 0x0F) | (iBrightness << 4);
    }
}

/**
  ******************************************************************************
  * @brief   : Draw a character on the OLED panel.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in]  iChar       A character you draw.
  * @param[in]  iPosX       X axis position of top left on the OLED panel.
  * @param[in]  iPosY       Y axis position of top left on the OLED panel.
  * @param[in]  iBrightness Brightness of the character.
  * 
  * @see enumSSD1322Brightness_t
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::drawChar(utf16_t iChar, uint16_t iStartX, uint16_t iStartY, enumSSD1322Brightness_t iBrightness)
{
    if (_pFont != NULL)
    {
      iChar -= (uint16_t)_pFont->iFirst;              //convert input char to corresponding byte from font array
      GFXglyph_t * pGlyph = _pFont->pGlyph + iChar;  //get pointer of pGlyph corresponding to char
      uint8_t * pBitmap = _pFont->pBitmap;           //get pointer of char pBitmap

      uint32_t bitmapOffset = pGlyph->iBitmapOffset;
      uint8_t iWidth = pGlyph->iWidth;
      uint8_t iHeight = pGlyph->iHeight;
  
      int8_t iOffsetX = pGlyph->iOffsetX;
      int8_t iOffsetY = pGlyph->iOffsetY;
  
      //decide for background iBrightness or font iBrightness
      uint8_t iBit = 0;
      uint8_t iBits = 0;
      uint8_t iPosY = 0;
      uint8_t iPosX = 0;
  
        for (iPosY = 0; iPosY < iHeight; iPosY++)
        {
            for (iPosX = 0; iPosX < iWidth; iPosX++) 
            {
                if (!(iBit & 0x07))
                {
                    iBits = (*(const unsigned char *)(&pBitmap[bitmapOffset++]));
                }
                else
                {
                    /*Error handler here.*/
                    __NOP();
                }

                if (iBits & 0x80)
                {
                    drawPixel(iStartX + iOffsetX + iPosX, iStartY + iOffsetY + iPosY, iBrightness);
                }
                else
                {
                    /*Error handler here.*/    
                    __NOP();
                }
                iBit++;
                iBits <<= 1;
            }
        }
    }
}

/**
  ******************************************************************************
  * @brief   : Set buffer size.
  * @note    : Depending on what OLED module is, you need to set buffer size properly.
  *            ex) iBufferWidth = 256, iBufferHeight = 64 (SSD1322 OLED Module)
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] iBufferWidth  OLED panel's width info.
  * @param[in] iBufferHeight OLED panel's height info.
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::setBufferSize(uint16_t iBufferWidth, uint16_t iBufferHeight)
{
  _hSsd1322Api._iBufferWidth = iBufferWidth;
  _hSsd1322Api._iBufferHeight = iBufferHeight;
}

/**
  ******************************************************************************
  * @brief   : Draw 8 bitmap image on the OLED panel.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] pBitmap Bitmap array that you draw.
  * @param[in] iPosX0  X axis position of top left on the OLED panel.
  * @param[in] iPosY0  Y axis position of top left on the OLED panel.
  * @param[in] xSize   Width of bitmap.
  * @param[in] ySize   Width of bitmap.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::drawBitMap8bpp(const uint8_t * pBitmap, uint16_t iPosX0, uint16_t iPosY0, uint16_t xSize, uint16_t ySize)
{

}

/**
  ******************************************************************************
  * @brief   : Draw 4 bitmap image on the OLED panel.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in]  pBitmap Bitmap array that you draw.
  * @param[in]  iPosX0  X axis position of top left on the OLED panel.
  * @param[in]  iPosY0  Y axis position of top left on the OLED panel.
  * @param[in]  xSize   Width of bitmap.
  * @param[in]  ySize   Width of bitmap.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::drawBitmap4bpp(const uint8_t * pBitmap, uint16_t iPosX0, uint16_t iPosY0, uint16_t xSize, uint16_t ySize)
{

}

/**
  ******************************************************************************
  * @brief   : Draw texts on the OLED panel.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] pText       Pointer var of the texts you draw.
  * @param[in] iPosX       X axis position of top left on the OLED panel.
  * @param[in] iPosY       Y axis position of top left on the OLED panel.
  * @param[in] iBrightness Brightness of the texts.
  * 
  * @see enumSSD1322Brightness_t
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::drawText(const char * pText, uint16_t iPosX, uint16_t iPosY, enumSSD1322Brightness_t iBrightness)
{
    while (*pText != NULL)
    {
        drawChar(*pText, iPosX, iPosY, iBrightness);
        iPosX = iPosX + _pFont->pGlyph[*pText - _pFont->iFirst].iAdvanceX;
        pText++;
    }

    _hSsd1322Api.sendBufferToOLED(0, 0);
}

/**
  ******************************************************************************
  * @brief   : Draw texts on the OLED panel after clear window.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] pText       Pointer var of the texts you draw.
  * @param[in] iPosX       X axis position of top left on the OLED panel.
  * @param[in] iPosY       Y axis position of top left on the OLED panel.
  * @param[in] iBrightness Brightness of the texts.
  * @see enumSSD1322Brightness_t
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::clearAndDrawText(const utf16_t * pText, uint16_t iPosX, uint16_t iPosY, enumSSD1322Brightness_t iBrightness)
{
    _hSsd1322Api.clearWindow();

    while (*pText != NULL)
    {
        /* Check if the text is Korean or not. */
        if (isKoreanText(pText) == true)
        {
          selectFont(&NotoSansKR_Regular16pt8b);     //KOR
          // selectFont(&KBO_Dia_Gothic_light16pt8b);     //KOR
        }
        else if (isKoreanText(pText) == false)
        {
          selectFont(&KBO_Dia_Gothic_light16pt7b_Eng); //ENG
        }
        else
        {
            /*Error handler here.*/
            __NOP();
        }

        drawChar(*pText, iPosX, iPosY, iBrightness);

        iPosX = iPosX + _pFont->pGlyph[*pText - _pFont->iFirst].iAdvanceX;
        pText++;
    }

    _hSsd1322Api.sendBufferToOLED(0, 0);
}

/**
  ******************************************************************************
  * @brief   : Select font used on the OLED panel.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] pNewfont Pointer var of the font you select.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Gfx::selectFont(const GFXfont_t *pNewfont)
{
    _pFont = pNewfont;
}

bool SSD1322_Gfx::isKoreanText(const utf16_t *pText)
{
  bool ret = false;

  if (*pText >= (utf16_t)UNICODE_HANGEUL_FIRST_CHAR && *pText <= (utf16_t)UNICODE_HANGEUL_LAST_CHAR)
  {
      ret = true;
  }
  else
  {
    /* Error handler here. */
    __NOP();
  }

  return ret;
}
    /**
      * @}
      */
/**
  * @}
  */


/* TODO */
void SSD1322_Gfx::drawVline(uint16_t iPosX, uint16_t iPosY0, uint16_t iPosY1, enumSSD1322Brightness_t iBrightness)
{

}

void SSD1322_Gfx::drawHline(uint16_t iPosY, uint16_t iPosX0, uint16_t iPosX1, enumSSD1322Brightness_t iBrightness)
{

}

void SSD1322_Gfx::drawLine(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosY1, enumSSD1322Brightness_t iBrightness)
{

}

void SSD1322_Gfx::drawAALine(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosY1, enumSSD1322Brightness_t iBrightness)
{

}

void SSD1322_Gfx::drawRect(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosX2, enumSSD1322Brightness_t iBrightness)
{

}

void SSD1322_Gfx::drawRectFilled(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosX2, enumSSD1322Brightness_t iBrightness)
{

}

void SSD1322_Gfx::drawCircle(uint16_t iPosX0, uint16_t iPosY0, uint16_t r, enumSSD1322Brightness_t iBrightness)
{

}