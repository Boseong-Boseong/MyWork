/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Gpio.cpp
  * @brief   SSD1322 GPIO support file.
  * @author  bskim
  * @date    2023-09-22
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SSD1322_Gpio.h"
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
  * @{
  */
/**
  ******************************************************************************
  * @brief   : Initialize HAL GPIO.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-10-17
  * @version :
  * 
  * @param[in]
  * 
  * @retval
  ******************************************************************************
  */
void SSD1322_Gpio::initialize(void)
{
    MX_GPIO_Init();
}
/**
  * @}
  */
/* USER CODE END 0 */