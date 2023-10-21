/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Api.h
  * @brief   SSD1322 API header file.
  * @author  bskim
  * @date    2023-09-17
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SSD1322_API_H__
#define __SSD1322_API_H__


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SSD1322_Spi.h"
#include "SSD1322_Gpio.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SSD1322_ENABLE_GRAYSCALE_TABLE               (0x00)
#define SSD1322_SET_COLUMN_ADDR                      (0x15)
#define SSD1322_ENABLE_RAM_WRITE                     (0x5C)
#define SSD1322_SET_ROW_ADDR                         (0x75)
#define SSD1322_SET_REMAP_AND_DUAL_COM               (0xA0)
#define SSD1322_SET_DISP_START_LINE                  (0xA1)
#define SSD1322_SET_DISP_OFFSET                      (0xA2)

#define SSD1322_SET_DISP_MODE_OFF                    (0xA4)
#define SSD1322_SET_DISP_MODE_ON                     (0xA5)
#define SSD1322_SET_DISP_MODE_NORMAL                 (0xA6)
#define SSD1322_SET_DISP_MODE_INVERTED               (0xA7)

#define SSD1322_ENABLE_PARTIAL_MODE                  (0xA8)
#define SSD1322_DISABLE_PARTIAL_MODE                 (0xA9)

#define SSD1322_SLEEP_MODE_ON                        (0xAE)
#define SSD1322_SLEEP_MODE_OFF                       (0xAF)

#define SSD1322_SET_PHASE_LENGTH                     (0xB1)
#define SSD1322_SET_FRONT_CLOCK_DIV                  (0xB3)
#define SSD1322_DISP_ENCHANCEMENT                    (0xB4)
#define SSD1322_SET_2ND_PRECHARGE_PERIOD             (0xB6)
#define SSD1322_SET_GRAYSCALE_TABLE                  (0xB8)
#define SSD1322_SET_DEFAULT_GRAYSCALE_TAB            (0xB9)
#define SSD1322_SET_PRECHARGE_VOLTAGE                (0xBB)
#define SSD1322_SET_V_COMH                           (0xBE)
#define SSD1322_SET_CONTRAST_CURRENT                 (0xC1)
#define SSD1322_MASTER_CONTRAST_CURRENT              (0xC7)
#define SSD1322_SET_MUX_RATIO                        (0xCA)
#define SSD1322_SET_COMMANDS_LOCK                    (0xFD)

#define SSD1322_ACTIVATE_SCROLL                      (0x2F)
#define SSD1322_DEACTIVATE_SCROLL                    (0x2E)
#define SSD1322_SET_VERTICAL_SCROLL_AREA             (0xA3)
#define SSD1322_RIGHT_HORIZONTAL_SCROLL              (0x26)
#define SSD1322_LEFT_HORIZONTAL_SCROLL               (0x27)
#define SSD1322_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL (0x29)
#define SSD1322_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL  (0x2A)

#define OLED_HEIGHT                                  (64)
#define OLED_WIDTH                                   (256)
#define OLED_TX_BUFFER_SIZE                          (8192) //256 * 64 / 2

#define SSD1322_WINDOW_COL_START                     (0)
#define SSD1322_WINDOW_COL_END                       (63)   
#define SSD1322_WINDOW_ROW_START                     (0)   
#define SSD1322_WINDOW_ROW_END                       (255)

#define SSD1322_COLUMN_OFFSET                        (28)
/* USER CODE END PD */


/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
    eSSD1322Mode_ON = 0,
    eSSD1322Mode_OFF,
    eSSD1322Mode_NORMAL,
    eSSD1322Mode_INVERTED
} enumSSD1322Mode_t;

typedef enum
{
    eSSD1322SleepMode_ON = 0,
    eSSD1322SleepMode_OFF,
} enumSSD1322SleepMode_t;

typedef enum
{
    eSSD1322Brightness_LEVEL_0 = 0,   
    eSSD1322Brightness_LEVEL_1,
    eSSD1322Brightness_LEVEL_2,
    eSSD1322Brightness_LEVEL_3,
    eSSD1322Brightness_LEVEL_4,
    eSSD1322Brightness_LEVEL_5,
    eSSD1322Brightness_LEVEL_6,
    eSSD1322Brightness_LEVEL_7,
    eSSD1322Brightness_LEVEL_8,
    eSSD1322Brightness_LEVEL_9,
    eSSD1322Brightness_LEVEL_10,
    eSSD1322Brightness_LEVEL_11,
    eSSD1322Brightness_LEVEL_12,
    eSSD1322Brightness_LEVEL_13,
    eSSD1322Brightness_LEVEL_14,
    eSSD1322Brightness_LEVEL_15 = 0x0F
} enumSSD1322Brightness_t;
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
 *  @brief OLED module classes.
  * @{
  */


/**
 ******************************************************************************
  * @class   SSD1322_Api
  * @ingroup SSD1322
  *
  * @brief   OLED API class.
  ******************************************************************************
  */
class SSD1322_Api
{
private:
/* Private member variables */
    SSD1322_Spi &  _hSsd1322Spi;
    SSD1322_Gpio & _hSsd1322Gpio;

/* Private member functions */
    void           sendDataToSSD1322(uint8_t iData);
    void           sendCmdToSSD1322(uint8_t iCmd);
public:
/* Public member variables */
    static uint8_t _siTxBuffer[OLED_TX_BUFFER_SIZE];
    uint16_t       _iBufferWidth  = OLED_WIDTH;
    uint16_t       _iBufferHeight = OLED_HEIGHT;

/* Public member functions */
    void           initialize(void);
    void           setScreenBrightness(enumSSD1322Brightness_t iBrightness);
    void           setDisplayMode(enumSSD1322Mode_t eMode);
    void           setSleepMode(uint8_t mode);
    void           setContrast(uint8_t contrast);
    bool           setGrayScale(uint8_t *pTableOrNull);
    void           setWindow(uint8_t startColumn, uint8_t endColumn, uint8_t startRow, uint8_t endRow);
    void           clearWindow(void);
    void           sendBufferToOLED(uint16_t xStart, uint16_t yStart);

    inline void    setRstPinLow(void) {_hSsd1322Gpio.clearGpioPin(GPIO_OLED_RST_GPIO_Port, GPIO_OLED_RST_Pin);}
    inline void    setRstPinHigh(void) {_hSsd1322Gpio.setGpioPin(GPIO_OLED_RST_GPIO_Port, GPIO_OLED_RST_Pin);}
    inline void    setDcPinLow(void) {_hSsd1322Gpio.clearGpioPin(GPIO_OLED_DC_GPIO_Port, GPIO_OLED_DC_Pin);}
    inline void    setDcPinHigh(void) {_hSsd1322Gpio.setGpioPin(GPIO_OLED_DC_GPIO_Port, GPIO_OLED_DC_Pin);}
    inline void    setCsPinLow(void) {_hSsd1322Gpio.clearGpioPin(GPIO_OLED_CS_GPIO_Port, GPIO_OLED_CS_Pin);}
    inline void    setCsPinHigh(void) {_hSsd1322Gpio.setGpioPin(GPIO_OLED_CS_GPIO_Port, GPIO_OLED_CS_Pin);}

    inline void    delayMs(uint32_t ms) {HAL_Delay(ms);}

/* Constructor, Destructor */
                   SSD1322_Api(SSD1322_Spi & hSsd1322Spi, SSD1322_Gpio & hSsd1322Gpio);
                   ~SSD1322_Api();
};
/* USER CODE END 0 */


/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */


/**
  * @}
  */


#endif /* __SSD1322_API_H__ */