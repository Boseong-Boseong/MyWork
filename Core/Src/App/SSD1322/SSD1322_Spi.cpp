/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322_Spi.cpp
  * @brief   SSD1322 SPI support file.
  * @author  bskim
  * @date    23-09-20
  * @version  
  ******************************************************************************
  */
/* USER CODE END Header */


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SSD1322_Spi.h"
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
SSD1322_Spi::SSD1322_Spi(SPI_HandleTypeDef & hSsd1322Spi)
: _hSsd1322Spi(hSsd1322Spi)
{
}

SSD1322_Spi::~SSD1322_Spi(void)
{
}

/**
  ******************************************************************************
  * @brief   : SSD1322 SPI initialize.
  * @note    : Initialize HAL SPI3 here.
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Spi::initialize(void)
{
    MX_SPI3_Init();
}

/**
  ******************************************************************************
  * @brief   : Wrapping HAL function of sending Byte via SPI.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] iByte A Byte that send via SPI.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Spi::writeByteSPI(uint8_t iByte)
{
    uint8_t iSize = sizeof(uint8_t);
    
    HAL_SPI_Transmit(&_hSsd1322Spi, &iByte, iSize, 10); //Timeout duration is 10ms.
}

/**
  ******************************************************************************
  * @brief   : Wrapping HAL function of sending array via SPI.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in] pArray Array that send via SPI.
  * @param[in] iSize  Size of the array.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Spi::writeArraySPI(uint8_t * pArray, uint16_t iSize)
{
    HAL_SPI_Transmit(&_hSsd1322Spi, pArray, iSize, 100); //Timeout duration is 100ms.
}

/**
  ******************************************************************************
  * @brief   : Wrapping HAL function of receiving a byte via SPI.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in,out] pBuffer Buffer pointer that receive data via SPI.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Spi::readByteSPI(uint8_t * pBuffer)
{
    uint8_t iSize = sizeof(uint8_t);
    
    HAL_SPI_Receive(&_hSsd1322Spi, pBuffer, iSize, 10); //Timeout duration is 10ms.
}

/**
  ******************************************************************************
  * @brief   : Wrapping HAL function of receiving an array via SPI.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param[in,out] pBuffer Buffer pointer that receive data via SPI.
  * @param[in]     iSize   Size of the receiving data.
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322_Spi::readArraySPI(uint8_t * pBuffer, uint16_t iSize)
{
    HAL_SPI_Receive(&_hSsd1322Spi, pBuffer, iSize, 100); //Timeout duration is 100ms.
}
/* USER CODE END 0 */