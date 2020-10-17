#ifndef __COMMUNICATION_H
#define __COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>
#include "messages.h"
#include "esc.h"

bool parse_normal_package(esc_settings *esc_struct,  uint8_t  *message);
bool parse_device_package(esc_settings *esc_struct,  uint8_t  *message);
bool parse_config_package(esc_settings *esc_struct,  uint8_t  *message);

void normal_response();
void device_response();


#endif //__COMMUNICATION_H
