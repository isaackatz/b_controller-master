#include "main.h"
#include "esc.h"

esc_settings esc_struct;

void update_esc_settings(esc_settings *esc_struct)
{
	if (esc_struct->PWM_duty > 0) {
		TIM3->CCR1  =  SERVO_STOP_DUTY + esc_struct->PWM_duty*PWM_RESIZE_COEF;
	} else {
		TIM3->CCR1  =  SERVO_STOP_DUTY - (~esc_struct->PWM_duty + 1)*PWM_RESIZE_COEF;
	}
}

