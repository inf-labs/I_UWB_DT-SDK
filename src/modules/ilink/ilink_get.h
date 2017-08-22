#ifndef __ILINK_GET_H
#define __ILINK_GET_H
	
#include "inf_typedef.h"
	
	
#define LPS_SETTING_FRAME_LENGTH 32

typedef struct
{
	uint8 is_factory_setting;
	uint8 role;
	uint8 mode;			//dw1000 system time stamp, 40bit effective
	uint8 baudrate;
	uint8 channel;
	uint8 anchor_num;
	uint8 tag_num;
	uint8 local_add;
	sint16 antenna_delay;
	
} lps_setting_frame_struct;//基站i,j结构体

extern lps_setting_frame_struct lps_setting_frame;

uint8 LPS_Setting_Frame_Unpack(unsigned char *data_frame);

#endif

