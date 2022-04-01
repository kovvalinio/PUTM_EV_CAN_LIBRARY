//Generated on Sat Apr  2 17:35:25 2022
#ifndef APPS
#define APPS

#include <cstdint>
#include "hal_can.hpp"
#include "message_abstraction.hpp"

enum struct Apps_states: uint8_t {
	Normal_operation,
	Power_up,
	Sensor_Implausiblity,
	Left_sensor_out_of_range___lower_bound,
	Left_sensor_out_of_range___upper_bound,
	Right_sensor_out_of_range___lower_bound,
	Right_sensor_out_of_range___upper_bound,
};

struct __attribute__ ((packed)) Apps_main{
	uint16_t pedal_position; // pedal position form 0 – 1000 where 0 means pedal not pressed
	uint8_t counter; // counts from 0-255 to ensure all frames are recived
	int8_t position_diff; // pedal position derivative in [count / second]
	Apps_states device_state; // -----------------------------------------------------------------
};

const uint16_t APPS_MAIN_CAN_ID = 0;
const uint8_t APPS_MAIN_CAN_DLC = sizeof(Apps_main);
const uint8_t APPS_MAIN_FREQUENCY = 100;

const CAN_TxHeaderTypeDef can_tx_header_apps{
 APPS_CAN_ID, 0xFFF, CAN_ID_STD, CAN_RTR_DATA, APPS_CAN_DLC, DISABLE};

#endif

