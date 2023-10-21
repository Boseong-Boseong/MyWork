/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    : Core\Inc\IScreen\IScreen.h
  * @brief   : Screen interface source file.
  * @author  : bskim
  * @date    : 2023-10-16
  * @version :
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ISCREEN_H__
#define __ISCREEN_H__


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */


/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
    eScreenRet_SUCCESS = 0x00,
    eScreenRet_ERROR   = 0x01
} enumScreenRet_t;

typedef enum
{
    eMsgStatus_MSG0 = 0x00,
    eMsgStatus_MSG1,
    eMsgStatus_MSG2,
    eMsgStatus_MSG3
} enumMsgStatus_t;
/* USER CODE END PTD */


/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/** @addtogroup Screen_Interfaces
 *  @brief Screen interface classes.
  * @{
  */


/**
  ******************************************************************************
  * @class IScreen
  * @ingroup
  * 
  * @brief Screen interface class.
  ******************************************************************************
  */
class IScreen
{
private:
/* Private member variables */

/* Private member functions */
        virtual enumScreenRet_t showMessages(void) = 0;
        virtual enumScreenRet_t showImages(void) = 0;
        virtual enumScreenRet_t clearScreen(void) = 0;
        

public:
/* Public member variables */
        virtual void            initialize(void) = 0;
        virtual void            loop(void) = 0;

/* Public member functions */
};
/* USER CODE END 0 */


/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */


/**
  * @}
  */


#endif /* __ISCREEN_H__ */