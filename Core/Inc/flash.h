
#ifndef FLASH_H_
#define FLASH_H_

#include "esc.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_flash_ex.h"

#define  CONFIG_PAGE_ADDR 0x08007C00

#pragma pack(push,  1)

typedef struct  {
	uint8_t  adress;
	uint8_t  reserved_slot1;  // In order for
	uint8_t  reserved_slot2;  // the structure to be
	uint8_t  reserved_slot3;  // a multiple of 32 bytes
}  esc_config;

#pragma pack(pop)

#define AMOUNT_OF_32B_WORDS  sizeof(esc_config)/4

void  FLASH_ReadSettings  (esc_settings *esc_struct);
void  FLASH_WriteSettings (esc_settings *esc_struct);

#endif /* FLASH_H_ */
