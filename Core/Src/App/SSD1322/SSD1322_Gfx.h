/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Gfx.h
  * @brief   SSD1322 GFX header file
  * @author  bskim
  * @date    23-09-17
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SSD1322_GFX_H__
#define __SSD1322_GFX_H__


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SSD1322_Api.h"
#include "SSD1322/Fonts/Panel_Font.h"
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


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/** @addtogroup SSD1322_Modules
  * @{
  */


/**
 ******************************************************************************
  * @class   SSD1322_Gfx
  * @ingroup SSD1322
  *
  * @brief   OLED GFX class.
  ******************************************************************************
  */
class SSD1322_Gfx
{
private:
/* Private member variables */
    SSD1322_Api &     _hSsd1322Api;
    const GFXfont_t * _pFont = &NotoSansKR_Regular16pt8b;
    // const GFXfont_t * _pFont = &KBO_Dia_Gothic_light16pt8b;

/* Private member functions */
    void              drawPixel(uint16_t iPosX, uint16_t iPosY, enumSSD1322Brightness_t iBrightness);
    void              drawChar(utf16_t iChar, uint16_t iStartX, uint16_t iStartY, enumSSD1322Brightness_t iBrightness);
    void              drawVline(uint16_t iPosX, uint16_t iPosY0, uint16_t iPosY1, enumSSD1322Brightness_t iBrightness);
    void              drawHline(uint16_t iPosY, uint16_t iPosX0, uint16_t iPosX1, enumSSD1322Brightness_t iBrightness);
    void              drawLine(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosY1, enumSSD1322Brightness_t iBrightness);
    void              drawAALine(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosY1, enumSSD1322Brightness_t iBrightness);
    void              drawRect(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosX2, enumSSD1322Brightness_t iBrightness);
    void              drawRectFilled(uint16_t iPosX0, uint16_t iPosY0, uint16_t iPosX1, uint16_t iPosX2, enumSSD1322Brightness_t iBrightness);
    void              drawCircle(uint16_t iPosX0, uint16_t iPosY0, uint16_t r, enumSSD1322Brightness_t iBrightness);
public:
/* Public member variables */

/* Public member functions */
    void              initialize(void);

    void              setBufferSize(uint16_t iBufferWidth, uint16_t iBufferHeight);

    void              drawBitMap8bpp(const uint8_t * pBitmap, uint16_t iPosX0, uint16_t iPosY0, uint16_t x_size, uint16_t y_size);
    void              drawBitmap4bpp(const uint8_t * pBitmap, uint16_t iPosX0, uint16_t iPosY0, uint16_t x_size, uint16_t y_size);
    void              drawText(const char * text, uint16_t iPosX, uint16_t iPosY, enumSSD1322Brightness_t iBrightness);
    void              clearAndDrawText(const utf16_t * pText, uint16_t iPosX, uint16_t iPosY, enumSSD1322Brightness_t iBrightness);

    void              selectFont(const GFXfont_t *pNewfont);

    bool              isKoreanText(const utf16_t *pText);

/* Constructor, Destructor */
                      SSD1322_Gfx(SSD1322_Api & hSsd1322Api);
                      ~SSD1322_Gfx();
};
/* USER CODE END 0 */


/* Extern variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */



/**
  * @}
  */
 

#endif /* __SSD1322_GFX_H__ */