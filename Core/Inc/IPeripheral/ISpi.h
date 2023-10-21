/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    : Core\Src\App\peripheral_interface\ISpi.h
  * @brief   : SPI interface class.
  * @author  : bskim
  * @date    : 2023-10-16
  * @version :
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ISPI_H__
#define __ISPI_H__


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
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
 *  @brief Peripheral interface classes.
  * @{
  */
/**
  ******************************************************************************
  * @class   ISpi
  * @ingroup Peripheral

  * @brief   SPI Interface class.
  ******************************************************************************
  */
class ISpi
{
private:
/* Private member variables */

/* Private member functions */

public:
/* Public member variables */

/* Public member functions */
    virtual void initialize(void) = 0;

    virtual void writeByteSPI(uint8_t iByte) = 0;
    virtual void writeArraySPI(uint8_t * pArray, uint16_t iSize) = 0;
    virtual void readByteSPI(uint8_t * pBuffer) = 0;
    virtual void readArraySPI(uint8_t * pBuffer, uint16_t iSize) = 0;
};
/* USER CODE END 0 */


/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */
/**
  * @}
  */


#endif /* __ISPI_H__ */