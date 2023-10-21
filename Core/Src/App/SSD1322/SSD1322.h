/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Core\Src\App\SSD1322\SSD1322.h
  * @brief   SSD1322 header file.
  * @author  bskim
  * @date    2023-09-21
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SSD1322_H__
#define __SSD1322_H__


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "..\..\Inc\IScreen\IScreen.h"

#include "SSD1322_Spi.h"
#include "SSD1322_Api.h"
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
  * @class   SSD1322
  * @ingroup SSD1322
  * 
  * @brief   OLED class.
  ******************************************************************************
  */
class SSD1322 : public IScreen
{
private:
/* Private member variables */
    SSD1322_Api             _hSsd1322Api;
    SSD1322_Gfx             _hSsd1322Gfx;

    enumMsgStatus_t         _eMsgStatus = eMsgStatus_MSG0;

/* Private member functions */
    virtual enumScreenRet_t showMessages(void) override;
    virtual enumScreenRet_t showImages(void) override;
    virtual enumScreenRet_t clearScreen(void) override;

public:
/* Public member variables */

/* Public member functions */
    virtual void            initialize(void) override;
    virtual void            loop(void) override;

public:
/* Operator overloading */
    void operator++(int)
    {
        switch (_eMsgStatus)
        {
        case eMsgStatus_MSG0:
            _eMsgStatus = eMsgStatus_MSG1;
            break;

        case eMsgStatus_MSG1:
            _eMsgStatus = eMsgStatus_MSG2;
            break;

        case eMsgStatus_MSG2:
            _eMsgStatus = eMsgStatus_MSG3;
            break;

        case eMsgStatus_MSG3:
            _eMsgStatus = eMsgStatus_MSG0;
            break;
        
        default:
            /*Error handler here.*/
            __NOP();
            break;
        }
    }

/* Constructor, Destructor */
                            SSD1322(SSD1322_Api & hSsd1322Api, SSD1322_Gfx & hSsd1322Gfx);
                            ~SSD1322();
};
/* USER CODE END 0 */


/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */


/**
  * @}
  */
 

#endif /* __SSD1322_H__ */