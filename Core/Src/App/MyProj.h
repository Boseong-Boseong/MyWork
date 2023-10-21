/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    MyProj.h
  * @brief   My project header file
  * @author  bskim
  * @date    23-09-17
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_PROJ_H__
#define __MY_PROJ_H__


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
/** @addtogroup My_Project
 *  @brief My project class.
  * @{
  */


typedef enum
{
    eMyProjState_IDLE = 0,
    eMyProjState_ENABLED,
    eMyProjState_DISABLED
} enumMyProjState_t;
/* USER CODE END PTD */


/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
  ******************************************************************************
  * @class   MyProj

  * @brief   My project class.
  ******************************************************************************
  */
class MyProj
{
private:
/* Private member variables */
    enumMyProjState_t  _eMyProjState = eMyProjState_DISABLED;
    uint32_t           _taskTickMs = getTick();

    SSD1322 &          _hSsd1322;

/* Private member functions */
    bool               isStateUpdated(void);

    inline uint32_t    getTick(void) {return HAL_GetTick();}

public:
/* Public member variables */

/* Public member functions */
    void               initialize(void);
    void               loop(void);
/* Constructor, Destructor */
                       MyProj(SSD1322 & hSsd1322);
                       ~MyProj();
};
/* USER CODE END 0 */


/* Extern variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */


/**
  * @}
  */


#endif /* __MY_PROJ_H__ */