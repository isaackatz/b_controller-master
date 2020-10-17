#ifndef DEVICE_H_
#define DEVICE_H_

#define MAX_SERVO_DUTY 1900
#define MIN_SERVO_DUTY 1100
#define SERVO_STOP_DUTY 1500
#define SERVO_RANGE 400

#define PWM_FREQUENCY (72000000/(MAX_PWM_DUTY+1))
#define PWM_RESIZE_COEF (SERVO_RANGE/128)
#define MAX_BASE_VECTORS_NUMB 8

#include <stdint.h>

typedef struct {
	uint8_t device_adress;
	int8_t PWM_duty;
} esc_settings;

struct keys_struct {
	unsigned int button1 :1;
	unsigned int button2 :1;
	unsigned int button3 :1;
	unsigned int button4 :1;
	unsigned int sensor1 :1;
	unsigned int sensor2 :1;
	unsigned int even :2;
};

void update_esc_settings(esc_settings *esc_struct);

#endif /* DEVICE_H_ */
