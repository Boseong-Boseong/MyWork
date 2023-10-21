/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    : Core\Src\App\peripheral_interface\IGpio.h
  * @brief   : STM32 GPIO interface class.
  * @author  : bskim
  * @date    : 2023-10-16
  * @version :
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IGPIO_STM32_H__
#define __IGPIO_STM32_H__


/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
/** @addtogroup Peripheral_Interfaces
  * @{
  */
/**
 ******************************************************************************
  * @class   IGpio_STM32
  * @ingroup Peripheral

  * @brief   GPIO Interface class.
  ******************************************************************************
  */
class IGpio_STM32
{
private:
/* Private member variables */

/* Private member functions */

public:
/* Public member variables */

/* Public member functions */
    virtual void   initialize(void) = 0;

    inline void    setGpioPin(GPIO_TypeDef * pGpioPort, uint16_t iGpioPin){HAL_GPIO_WritePin(pGpioPort, iGpioPin, GPIO_PIN_SET);}
    inline void    clearGpioPin(GPIO_TypeDef * pGpioPort, uint16_t iGpioPin){HAL_GPIO_WritePin(pGpioPort, iGpioPin, GPIO_PIN_RESET);}
};


/* USER CODE END 0 */


/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */
/**
  * @}
  */


#endif /* __IGPIO_STM32_H__ */