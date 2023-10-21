/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Gpio.h
  * @brief   SSD1322 GPIO header file.
  * @author  bskim
  * @date    2023-09-22
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SSD1322_GPIO_H__  
#define __SSD1322_GPIO_H__


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN Includes */
#include "..\..\Inc\IPeripheral\IGpio_STM32.h"
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
  * @class   SSD1322_Gpio
  * @ingroup SSD1322
  *
  * @brief   OLED GPIO class.
  ******************************************************************************
  */
class SSD1322_Gpio : public IGpio_STM32
{
private:
/* Private member variables */
    GPIO_TypeDef * _pGpioPortRst = GPIO_OLED_RST_GPIO_Port;
    GPIO_TypeDef * _pGpioPortDc  = GPIO_OLED_DC_GPIO_Port;
    GPIO_TypeDef * _pGpioPortCs  = GPIO_OLED_CS_GPIO_Port;

    uint16_t       _iGpioPinRst  = GPIO_OLED_RST_Pin;
    uint16_t       _iGpioPinDc   = GPIO_OLED_DC_Pin;
    uint16_t       _iGpioPinCs   = GPIO_OLED_CS_Pin;
/* Private member functions */

public:
/* Public member variables */

/* Public member functions */
    virtual void   initialize(void) override;
};
/* USER CODE END 0 */


/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */



/**
  * @}
  */
 

#endif /* __SSD1322_GPIO_H__ */