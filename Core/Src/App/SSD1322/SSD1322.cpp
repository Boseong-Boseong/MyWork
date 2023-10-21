/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322.cpp
  * @brief   SSD1322 file
  * @author  bskim
  * @date    2023-09-21
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SSD1322.h"
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
const utf16_t msg0[] = {0x0053, 0x0053, 0x0044, 0x0031, 0x0033, 0x0032, 0x0032, 0x0020, 0xd14c, 0xc2a4, 0xd2b8, NULL}; //SSD1322 테스트
const utf16_t msg1[] = {0xc548, 0xb155, 0xd558, 0xc138, 0xc694, NULL}; //안녕하세요
const utf16_t msg2[] = {0xbc18, 0xac11, 0xc2b5, 0xb2c8, 0xb2e4, NULL}; //반갑습니다
const utf16_t msg3[] = {0xb8f0, 0xb8e8, 0xb8e8, 0xb784, 0xb77c, 0x007e, NULL}; //룰루루랄라~

const utf16_t *msg[] = {msg0, msg1, msg2, msg3};

/* USER CODE END PV */


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
SSD1322::SSD1322(SSD1322_Api & hSsd1322Api, SSD1322_Gfx & hSsd1322Gfx)
: _hSsd1322Api(hSsd1322Api),
  _hSsd1322Gfx(hSsd1322Gfx)
{
}

SSD1322::~SSD1322(void)
{
}

/**
  ******************************************************************************
  * @brief   SSD1322 initialize.
  * @note    Initialize API handler, GFX handler here.
  * @author  bskim
  * @date    2023-09-21
  * @version 
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322::initialize(void)
{
    _hSsd1322Api.initialize();
    _hSsd1322Gfx.initialize();
}

/**
  ******************************************************************************
  * @brief   : SSD1322 loop task.
  * @note    : Show the messages based on '_eMsgStatus' and change the status to the next status in Myproj.loop()
  * @author  : bskim
  * @date    : 2023-09-21
  * @version :
  * 
  * @param None
  * 
  * @see MyProj.cpp
  * 
  * @retval None
  ******************************************************************************
  */
void SSD1322::loop(void)
{
    showMessages();
}

/**
  ******************************************************************************
  * @brief   : Show messages you set already.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-10-16
  * @version :
  * 
  * @param None
  * 
  * @retval enumScreenRet_t
  ******************************************************************************
  */
enumScreenRet_t SSD1322::showMessages(void)
{
    enumScreenRet_t eRet = eScreenRet_SUCCESS;

    _hSsd1322Gfx.clearAndDrawText(msg[_eMsgStatus], 15, 30, eSSD1322Brightness_LEVEL_15);
    
    return eRet;
}

/**
  ******************************************************************************
  * @brief   : Show bitmap images you set already.
  * @note    : Not implemented yet.
  * @author  : bskim
  * @date    : 2023-10-16
  * @version :
  * 
  * @param None
  * 
  * @retval enumScreenRet_t
  ******************************************************************************
  */
enumScreenRet_t SSD1322::showImages(void)
{
    enumScreenRet_t eRet = eScreenRet_SUCCESS;

    __NOP();

    return eRet;
}

/**
  ******************************************************************************
  * @brief   : Clear the screen all.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-10-16
  * @version :
  * 
  * @param None
  * 
  * @retval enumScreenRet_t
  ******************************************************************************
  */
enumScreenRet_t SSD1322::clearScreen(void)
{
    enumScreenRet_t eRet = eScreenRet_SUCCESS;

    _hSsd1322Api.clearWindow();

    return eRet;
}
/* USER CODE END 0 */