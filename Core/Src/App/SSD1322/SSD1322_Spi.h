/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Spi.h
  * @brief   SSD1322 SPI header file.
  * @author  bskim
  * @date    23-09-20
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SSD1322_SPI_H__
#define __SSD1322_SPI_H__


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "spi.h"
/* USER CODE BEGIN Includes */
#include "..\..\Inc\IPeripheral\ISpi.h"
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
  * @class   SSD1322_Spi
  * @ingroup SSD1322
  * 
  * @brief   OLED SPI class.
  ******************************************************************************
  */
class SSD1322_Spi : public ISpi
{
private:
/* Private member variables */
    SPI_HandleTypeDef & _hSsd1322Spi;

/* Private member functions */

public:
/* Public member variables */

/* Public member functions */
    virtual void initialize(void) override;
    virtual void writeByteSPI(uint8_t iByte) override;
    virtual void writeArraySPI(uint8_t * pArray, uint16_t iSize) override;
    virtual void readByteSPI(uint8_t * pBuffer) override;
    virtual void readArraySPI(uint8_t * pBuffer, uint16_t iSize) override;
/* Constructor, Destructor */
    SSD1322_Spi(SPI_HandleTypeDef & hSsd1322Spi);
    ~SSD1322_Spi();
};
/* USER CODE END 0 */


/* Extern variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */


/**
  * @}
  */


#endif /* __SSD1322_SPI_H__ */