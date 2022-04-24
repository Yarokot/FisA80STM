/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* vim: set ai et ts=4 sw=4: */
#include <string.h>
#include "st7735.h"
#include "fonts.h"
#include "testimg.h"
#include "blackimg.h"




/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int x=1;
int y=1;
int z=1;
int p=1;


int door=0;
int door2=0;
void init() {
    ST7735_Init();

    const char ready[] = "Ready!\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)ready, sizeof(ready)-1, HAL_MAX_DELAY);
}
void caricon(uint16_t x, uint16_t y, uint16_t color)
{
	int tab[96][43]={	{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
						{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
						{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
						{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
						{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
						{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
						{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
						{1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1},
						{1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
						{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
						{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
						{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
						{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
						{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
						{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1},
						{1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1},
						{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
						{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
						{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
						{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
						{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
						{1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
						{1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
						{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
						{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
						{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
						{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
						{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
						{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0}};

	int p=0;
		int i, j;
		for (i=0; i<96; i++)
		{
			for(j=0; j<43; j++)
			{
				p=tab[i][j];
				if (p==1)
				{
					ST7735_DrawPixel(x+j, y+i, color);
				}
			}
		}
}
void Rcardooricon(uint16_t x, uint16_t y, uint16_t color)
{
	int tab[14][13]={	{1,0,0,0,0,0,0,0,0,0,0,0,0},
						{1,1,0,0,0,0,0,0,0,0,0,0,0},
						{0,1,1,0,0,0,0,0,0,0,0,0,0},
						{0,0,1,1,0,0,0,0,0,0,0,0,0},
						{0,0,0,1,1,0,0,0,0,0,0,0,0},
						{0,0,0,0,1,1,0,0,0,0,0,0,0},
						{0,0,0,0,0,1,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,1,1,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,1,1,0,0,0},
						{0,0,0,0,0,0,0,0,0,1,1,0,0},
						{0,0,0,0,0,0,0,0,0,0,1,1,0},
						{0,0,0,0,0,0,0,0,0,0,0,1,1},
						{0,0,0,0,0,0,0,0,0,0,0,0,1}};
	int p=0;
			int i, j;
			for (i=0; i<14; i++)
			{
				for(j=0; j<13; j++)
				{
					p=tab[i][j];
					if (p==1)
					{
						ST7735_DrawPixel(x+j, y+i, color);
					}
				}
			}
}
void Lcardooricon(uint16_t x, uint16_t y, uint16_t color)
{
	int tab[14][13]={		{0,0,0,0,0,0,0,0,0,0,0,0,1},
							{0,0,0,0,0,0,0,0,0,0,0,1,1},
							{0,0,0,0,0,0,0,0,0,0,1,1,0},
							{0,0,0,0,0,0,0,0,0,1,1,0,0},
							{0,0,0,0,0,0,0,0,1,1,0,0,0},
							{0,0,0,0,0,0,0,1,1,0,0,0,0},
							{0,0,0,0,0,0,1,1,0,0,0,0,0},
							{0,0,0,0,0,1,1,0,0,0,0,0,0},
							{0,0,0,0,1,1,0,0,0,0,0,0,0},
							{0,0,0,1,1,0,0,0,0,0,0,0,0},
							{0,0,1,1,0,0,0,0,0,0,0,0,0},
							{0,1,1,0,0,0,0,0,0,0,0,0,0},
							{1,1,0,0,0,0,0,0,0,0,0,0,0},
							{1,0,0,0,0,0,0,0,0,0,0,0,0}};
	int p=0;
			int i, j;
			for (i=0; i<14; i++)
			{
				for(j=0; j<13; j++)
				{
					p=tab[i][j];
					if (p==1)
					{
						ST7735_DrawPixel(x+j, y+i, color);
					}
				}
			}
}
void fuelicon(uint16_t x, uint16_t y, uint16_t color)
{
	int tab[16][16]={ {0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0},
					  {0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0},
					  {1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0},
					  {1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1},
					  {1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,1},
					  {1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
					  {1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0}};

	int p=0;
	int i, j;
	for (i=0; i<16; i++)
	{
		for(j=0; j<16; j++)
		{
			p=tab[i][j];
			if (p==1)
			{
				ST7735_DrawPixel(x+j, y+i, color);
			}
		}
	}
}
void frame(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	int i;
	int j;
	for(i = 0; i <= w ; i++)
	{
	     ST7735_DrawPixel(x+i, y, color);
	     ST7735_DrawPixel(x+i, y+h, color);
	}
	for(j = 0; j < h; j++)
	{
	     ST7735_DrawPixel(x, y+j, color);
	     ST7735_DrawPixel(x+w, y+j, color);
	}
}
void box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	int i;
	int j;
	for(i = 0; i <= w ; i++)
	{
		for(j = 0; j < h; j++)
		{
		     ST7735_DrawPixel(x+i, y+j, color);
		}
	}
}
void img()
{
	if(y==1)
	{
		ST7735_FillScreen(ST7735_BLACK);
		ST7735_DrawImage(0, 0, 128, 128, (uint16_t*)test_img_128x128);
		y=0;
	}
	if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
	    {
	    	if (x==3)
	    	{
	    		x=2;
	    	}
	    	y=1;
	    	HAL_Delay(20);
	    }
}

void MainScreen()
{
	int i;
	int d;
	int f;
	int c=1;

	char a[7];
	if(y==1)
	{
		ST7735_FillScreen(ST7735_BLACK);
		ST7735_FillRectangle(0, 20, 128, 2, ST7735_RED);
		ST7735_WriteString(2, 2, "10:30", Font_11x18, ST7735_RED, ST7735_BLACK);
		ST7735_WriteString(80, 2, "15*C", Font_11x18, ST7735_RED, ST7735_BLACK);
		ST7735_FillRectangle(0, 135, 128, 2, ST7735_RED);
		fuelicon(2, 140, ST7735_RED);
		frame(20, 140, 102, 15, ST7735_RED);
		for (i=0; i<4; i++)
			{
				d=i*20;
				ST7735_WriteString(2, 25+d, "test", Font_11x18, ST7735_RED, ST7735_BLACK);
			}
		//f=10*z;
		//frame(60, 50, f, f, ST7735_RED);
		y=0;
	}
	if (p<10)
	{
		ST7735_FillRectangle(70, 26, 12, 14, ST7735_BLACK);
	}
	if (p<100)
		{
			ST7735_FillRectangle(82, 26, 12, 14, ST7735_BLACK);
		}
	itoa(p, a, 10);
	ST7735_WriteString(60, 25, a, Font_11x18, ST7735_RED, ST7735_BLACK);


	if (HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin) == GPIO_PIN_RESET && p<10)
		{
			c=1;
			p++;
			while(HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin) == GPIO_PIN_RESET);
			HAL_Delay(20);
		}

	if (HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin) == GPIO_PIN_RESET && p>1)
		{
			c=1;
			p--;
			while(HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin) == GPIO_PIN_RESET);
			HAL_Delay(20);
		}
	if (c==1) //Poziom paliwa
	{
		f=10*p;
		box(21+f, 141, 100-f, 14, ST7735_BLACK);
		box(21, 141, f, 14, ST7735_RED);

		c=0;
	}
	if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
	    {
	    	if (x==1)
	    	{
	    		x=2;
	    	}
	    	y=1;
	    	HAL_Delay(20);
	    }
}
void Menu()
{

	int m;

	if(y==1)
		{
			ST7735_FillScreen(ST7735_BLACK);
			ST7735_FillRectangle(0, 20, 128, 2, ST7735_RED);
			ST7735_WriteString(2, 2, "Menu", Font_11x18, ST7735_RED, ST7735_BLACK);
			ST7735_WriteString(5, 25, "Diagnostyka", Font_11x18, ST7735_RED, ST7735_BLACK);
			ST7735_WriteString(5, 45, "Ustawienia", Font_11x18, ST7735_RED, ST7735_BLACK);
			ST7735_WriteString(5, 65, "Obrazek", Font_11x18, ST7735_RED, ST7735_BLACK);
			ST7735_WriteString(5, 85, "Ekran gl.", Font_11x18, ST7735_RED, ST7735_BLACK);
			y=0;
			m=1;
		}
	/*if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
		{
		   	if (x==2)
		   	{
		   		x=1;
		   	}
		   	y=1;
		   	HAL_Delay(20);
		}*/

	if (HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin) == GPIO_PIN_RESET)
		{
			HAL_Delay(20);
			z++;
			m=1;
			while(HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin) == GPIO_PIN_RESET);
		}

	if (HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin) == GPIO_PIN_RESET)
		{
			HAL_Delay(20);
			z--;
			m=1;
			while(HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin) == GPIO_PIN_RESET);
		}
	switch (z)
	    {
	    	case 1:			//Diagnostyka
	    	{
	    		if (m==1)
	    		{
	    			ST7735_WriteString(5, 45, "Ustawienia", Font_11x18, ST7735_RED, ST7735_BLACK);
	    			ST7735_WriteString(5, 25, "Diagnostyka", Font_11x18, ST7735_BLACK, ST7735_RED);
	    			m=0;
	    		}

	    		break;
	    	}
	    	case 2:			//Ustawienia
	    	{
	    		if (m==1)
	    		{
	    			ST7735_WriteString(5, 25, "Diagnostyka", Font_11x18, ST7735_RED, ST7735_BLACK);
	    			ST7735_WriteString(5, 65, "Obrazek", Font_11x18, ST7735_RED, ST7735_BLACK);
	    			ST7735_WriteString(5, 45, "Ustawienia", Font_11x18, ST7735_BLACK, ST7735_RED);
	    			m=0;
	    			    		}
	    		break;
	    	}
	    	case 3:			//Obrazek
	    	{
	    		if (m==1)
	    		{
	    			ST7735_WriteString(5, 45, "Ustawienia", Font_11x18, ST7735_RED, ST7735_BLACK);
   					ST7735_WriteString(5, 85, "Ekran gl.", Font_11x18, ST7735_RED, ST7735_BLACK);
	    			ST7735_WriteString(5, 65, "Obrazek", Font_11x18, ST7735_BLACK, ST7735_RED);
	    			m=0;
	    		}
	    	    break;
	    	}
	    	case 4:			//Ekran główny
	    	{
	    		if (m==1)
	    		{
	    			ST7735_WriteString(5, 65, "Obrazek", Font_11x18, ST7735_RED, ST7735_BLACK);
	    			ST7735_WriteString(5, 85, "Ekran gl.", Font_11x18, ST7735_BLACK, ST7735_RED);
	    			m=0;
	    		}
	    	    break;
	    	}

	    }
	if (z==1 && HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
	{
		x=4; //Diagnostyka
		y=1;
		HAL_Delay(20);
	}
	if (z==2 && HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
	{
		x=5; //Ustawienia
		y=1;
		HAL_Delay(20);
	}
	if (z==3 && HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
	{
		x=3; //Obrazek
		y=1;
		HAL_Delay(20);
	}
	if (z==4 && HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
	{
		x=1; //Ekran główny
		y=1;
		HAL_Delay(20);
	}
}

void Diagnostyka()
{
	if(y==1)
		{
			ST7735_FillScreen(ST7735_BLACK);
			ST7735_FillRectangle(0, 20, 128, 2, ST7735_RED);
			ST7735_WriteString(2, 2, "Diagnostyka", Font_11x18, ST7735_RED, ST7735_BLACK);
			caricon(42, 35, ST7735_RED);
			Rcardooricon(85, 67, ST7735_RED);
			Lcardooricon(29, 67, ST7735_RED);
			fuelicon(2, 140, ST7735_RED);
			y=0;
			}
	if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
			{
			   	x=2;
			   	y=1;
			   	HAL_Delay(20);
			}
}
void Ustawienia()
{
	if(y==1)
			{
				ST7735_FillScreen(ST7735_BLACK);
				ST7735_FillRectangle(0, 20, 128, 2, ST7735_RED);
				ST7735_WriteString(2, 2, "Diagnostyka", Font_11x18, ST7735_RED, ST7735_BLACK);
				y=0;
			}
	if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
			{
			   	x=2;
			   	y=1;
			   	HAL_Delay(20);
			}
}
void Doors()
{
	if(y==1)
	{
		ST7735_DrawImage(0, 22, 128, 113, (uint16_t*)black_img_128x128);
		caricon(42, 31, ST7735_RED);
		y=0;
	}
		if (HAL_GPIO_ReadPin(LFDoor_GPIO_Port, LFDoor_Pin) == GPIO_PIN_RESET) //Drzwi lewy przód
		{
			Lcardooricon(29, 63, ST7735_RED);
			HAL_Delay(20);
		}
		else
		{
			Lcardooricon(29, 63, ST7735_BLACK);
		}
		if (HAL_GPIO_ReadPin(RFDoor_GPIO_Port, RFDoor_Pin) == GPIO_PIN_RESET) //Drzwi prawy przód
		{
			Rcardooricon(85, 63, ST7735_RED);
			HAL_Delay(20);
		}
		else
		{
			Rcardooricon(85, 63, ST7735_BLACK);
		}
		if (HAL_GPIO_ReadPin(LRDoor_GPIO_Port, LRDoor_Pin) == GPIO_PIN_RESET) //Drzwi lewy tył
		{
			Lcardooricon(29, 85, ST7735_RED);
			HAL_Delay(20);
		}
		else
		{
			Lcardooricon(29, 85, ST7735_BLACK);
		}
		if (HAL_GPIO_ReadPin(RRDoor_GPIO_Port, RRDoor_Pin) == GPIO_PIN_RESET) //Drzwi prawy tył
		{
			Rcardooricon(85, 85, ST7735_RED);
			HAL_Delay(20);
		}
		else
		{
			Rcardooricon(85, 85, ST7735_BLACK);
		}


}
void loop() {
    // Check border

	if (HAL_GPIO_ReadPin(LFDoor_GPIO_Port, LFDoor_Pin) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(RFDoor_GPIO_Port, RFDoor_Pin) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(LRDoor_GPIO_Port, LRDoor_Pin) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(RRDoor_GPIO_Port, RRDoor_Pin) == GPIO_PIN_RESET)
	{
		if (door2==0)
		{
			door=x;
			y=1;
		}
	   	x=6;
	   	door2=1;
	   	HAL_Delay(20);
	}
	else
	{
		if (door2==1){
			x=door;
			door2=0;
			y=1;
			HAL_Delay(100);
		}
	}
    switch (x)
    {
    	case 1:
    	{
    		MainScreen();
    		break;
    	}
    	case 2:
    	{
    		Menu();
    		break;
    	}
    	case 3:
    	{
    	    img();
    	    break;
    	}
    	case 4:
    	{
    	    Ustawienia();
    	    break;
    	   	}
    	case 5:
    	{
    	    Diagnostyka();
    	    break;
    	}
    	case 6:
    	{
    		Doors();
    		break;
    	}
    }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  init();
  while (1)
  {
    loop();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DOWN_Pin */
  GPIO_InitStruct.Pin = DOWN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DOWN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RRDoor_Pin LRDoor_Pin LFDoor_Pin RFDoor_Pin */
  GPIO_InitStruct.Pin = RRDoor_Pin|LRDoor_Pin|LFDoor_Pin|RFDoor_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : UP_Pin */
  GPIO_InitStruct.Pin = UP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(UP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

