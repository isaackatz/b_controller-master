/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f1xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
int k;
struct keys_struct keys;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart2;
/* USER CODE BEGIN EV */
extern uint8_t rx_array[];
extern uint8_t rx_flag;
extern esc_settings esc_struct;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	k++;

	if (k == 10) {

			keys.button1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
			keys.button2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
			keys.button3 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
			keys.button4 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);

			keys.sensor1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
			keys.sensor2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);

			k = 0;
	}
  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles RCC global interrupt.
  */
void RCC_IRQHandler(void)
{
  /* USER CODE BEGIN RCC_IRQn 0 */

  /* USER CODE END RCC_IRQn 0 */
  /* USER CODE BEGIN RCC_IRQn 1 */

  /* USER CODE END RCC_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	switch (rx_flag) {
	case (0): {
		if (rx_array[0] == START_BYTE) {
			rx_flag = 1;
			HAL_UART_Receive_IT(&huart2, rx_array + 1, 1);
		} else {
			HAL_UART_Receive_IT(&huart2, rx_array, 1);
		}
	}
		break;

	case (1): {
		switch (rx_array[1]) {
		case (NORMAL_REQUEST_TYPE): {
			rx_flag = 2;
			HAL_UART_Receive_IT(&huart2, rx_array + 2,
					NORMAL_REQUEST_LENGTH - 2);
		}
			break;
		case (CONFIG_REQUEST_TYPE): {
			rx_flag = 2;
			HAL_UART_Receive_IT(&huart2, rx_array + 2,
				CONFIG_REQUEST_LENGTH - 2);
		}
			break;
		case (DEVICE_REQUEST_TYPE): {
			rx_flag = 2;
			HAL_UART_Receive_IT(&huart2, rx_array + 2, DEVICES_REQUEST_LENGTH - 2);
		}
			break;
		default: {
			rx_flag = 0;
			HAL_UART_Receive_IT(&huart2, rx_array, 1);
		}
			break;
		};
	}
		break;

	case (2): {
		switch (rx_array[1]) {
		case (NORMAL_REQUEST_TYPE): {
			if (parse_normal_package(&esc_struct, rx_array)) {
				normal_response(&huart2, &esc_struct);
			}
		}
			break;
		case (CONFIG_REQUEST_TYPE): {
			uint8_t current_adress = esc_struct.device_adress;
			if (parse_config_package(&esc_struct, rx_array)) {
				if (esc_struct.device_adress != current_adress) {
					FLASH_WriteSettings(&esc_struct);
				}
			}
		}
			break;
		case (DEVICE_REQUEST_TYPE): {
			if(parse_device_package(&esc_struct, rx_array))
			{
				device_response(&huart2, &esc_struct);
			}
		}
		};
		rx_flag = 0;
		HAL_UART_Receive_IT(&huart2, rx_array, 1);
	}
		break;
	};
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	HAL_GPIO_WritePin(RS_485_DIR_GPIO_Port, RS_485_DIR_Pin, RESET);
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
