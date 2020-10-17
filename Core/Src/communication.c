
#include <communication.h>
#include <string.h>
#include "checksum.h"
#include "main.h"

uint8_t tx_array[NORMAL_RESPONSE_LENGTH] = {0};
extern struct keys_struct keys;

bool parse_normal_package(esc_settings *esc_struct,  uint8_t  *message)
{
	if  (IsChecksumm8bCorrect(message, NORMAL_REQUEST_LENGTH))  {

		struct Request req;

		memcpy((void*)&req,  (void*)message,  NORMAL_REQUEST_LENGTH);

        if  (req.address  ==  esc_struct->device_adress)  {
        	esc_struct->PWM_duty  =  req.velocity;
        	update_esc_settings(esc_struct);
            return true;
        }
	}
    return false;
}

void normal_response(UART_HandleTypeDef *huart, esc_settings *esc_struct)
{
	struct Response resp;

	resp.AA            = 0xAA;
	resp.type          = 1;
	resp.address       = esc_struct->device_adress;
	resp.state         = 0x55;
	resp.current       = 0x55;
	resp.speed_period  = 0x55;



	memcpy((void*)tx_array,  (void*)&resp,  NORMAL_RESPONSE_LENGTH - 1);

	AddChecksumm8b(tx_array,  NORMAL_RESPONSE_LENGTH);

    HAL_GPIO_WritePin(RS_485_DIR_GPIO_Port,  RS_485_DIR_Pin,  SET);

    HAL_UART_Transmit_IT(huart, tx_array, NORMAL_RESPONSE_LENGTH);

    //HAL_UART_Transmit_DMA(huart, tx_array, NORMAL_RESPONSE_LENGTH);

    HAL_GPIO_TogglePin(DEBUG_LED_GPIO_Port, DEBUG_LED_Pin);
}

bool parse_device_package(esc_settings *esc_struct, uint8_t *message)
{
	if  (IsChecksumm8bCorrect(message, DEVICES_REQUEST_LENGTH))  {

		struct DevicesRequest req;

		memcpy((void*)&req,  (void*)message,  DEVICES_REQUEST_LENGTH);

        if  (req.address  ==  esc_struct->device_adress)  {
        	esc_struct->PWM_duty  =  req.velocity1;
        	update_esc_settings(esc_struct);
            return true;
        }
	}
    return false;
}

void device_response(UART_HandleTypeDef *huart, esc_settings  *esc_struct)
{

	struct DevicesResponse resp;

	resp.AA            = 0xAA;
	resp.address       = esc_struct->device_adress;
	resp.errors        = 0x00;
	resp.current1      = 0x0000;
	resp.current2      = 0x0000;
	resp.velocity1     = esc_struct->PWM_duty;
    resp.velocity2     = 0x00;

    memcpy(&resp.velocity2, &keys, 1);
    memcpy((void*)tx_array,  (void*)&resp,  DEVICES_RESPONSE_LENGTH - 1);

	AddChecksumm8b(tx_array,  DEVICES_RESPONSE_LENGTH);

    HAL_GPIO_WritePin(RS_485_DIR_GPIO_Port,  RS_485_DIR_Pin,  SET);

    HAL_UART_Transmit_IT(huart,  tx_array,  DEVICES_RESPONSE_LENGTH);
    HAL_GPIO_TogglePin(DEBUG_LED_GPIO_Port, DEBUG_LED_Pin);
}


bool parse_config_package(esc_settings *esc_struct,  uint8_t  *message)
{
	if  (IsChecksumm8bCorrect(message, CONFIG_REQUEST_LENGTH)) {

        struct ConfigRequest req;

        memcpy((void*)&req,  (void*)message,  CONFIG_REQUEST_LENGTH);

        if  (req.old_address  ==  esc_struct->device_adress)  {
        	esc_struct->device_adress  =  req.new_address;
        	return true;
        }
	}
	return false;
}

