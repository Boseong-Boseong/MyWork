/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    my_proj.cpp
  * @brief   My project file
  * @author  bskim
  * @date    23-09-17
  * @version 
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MyProj.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MY_PROJ_ACTION_PERIOD (2000) //Unit : ms
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
/** @ingroup My_Project
  * @{
  */
MyProj::MyProj(SSD1322 & hSsd1322)
: _hSsd1322(hSsd1322)
{
}

MyProj::~MyProj(void)
{
}

/**
  ******************************************************************************
  * @brief   : Initialize my project.
  * @note    : Initialize SSD1322 handler that my project needs to run.
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
void MyProj::initialize(void)
{
    _hSsd1322.initialize();
}

/**
  ******************************************************************************
  * @brief   : Infinite loop of my project.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
void MyProj::loop(void)
{
    _eMyProjState = (isStateUpdated() == true) ? eMyProjState_ENABLED : eMyProjState_IDLE;

    switch (_eMyProjState)
    {
    case eMyProjState_IDLE:
        __NOP();
        break;

    case eMyProjState_ENABLED:
        _hSsd1322.loop();
        _hSsd1322++; //Change eMsgStatus.
        break;

    default:
        /*Error handler here.*/
        __NOP();
        break;
    }
}

/**
  ******************************************************************************
  * @brief   : Update the state of my project periodically.
  * @note    : 
  * @author  : bskim
  * @date    : 2023-09-22
  * @version :
  * 
  * @param None
  * 
  * @retval None
  ******************************************************************************
  */
bool MyProj::isStateUpdated(void)
{
    bool ret = false;
    uint32_t currTime = getTick();
    uint32_t preTime = _taskTickMs;

    if ( (currTime - preTime) >= MY_PROJ_ACTION_PERIOD )
    {
        _taskTickMs = currTime;
        ret = true;
    }
    else if ( (currTime - preTime) < MY_PROJ_ACTION_PERIOD )
    {
        /*Wait for update period...*/
    }
    else
    {
        __NOP();
    }

    return ret;
}
/**
  * @}
  */
/* USER CODE END 0 */