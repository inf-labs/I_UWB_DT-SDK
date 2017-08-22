#include "ilink_get.h"


//void Sensor_Calibration_Data_Frame_Unpack(unsigned char *buf,int length)
//{
//	
//}

//void PIDA_Data_Frame_Unpack(unsigned char *data_frame)
//{
//	static u16 data_frame_length = sizeof(data_frame);//Get data frame length,define static to avoid everytime bliud sizeof() function
//	u8 data_frame_sum = 0;//校验位
//	u8 i = 0;

//	if((data_frame[0] == 0x54) && (data_frame[1] == 0x03))//Frame Header & Function Mark check
//	{
//		for(i = 0;i < (data_frame_length - 1);i++)//最后字节为校验和
//		{
//			data_frame_sum += data_frame[i];
//		}

//		if(data_frame_sum == data_frame[data_frame_length - 1])//检验和 检查
//		{
////			dis[0] = ((float)Byte16(u16, recieve_buf[2],  recieve_buf[3])) / 100;
////			dis[1] = ((float)Byte16(u16, recieve_buf[4],  recieve_buf[5])) / 100;
////			dis[2] = ((float)Byte16(u16, recieve_buf[6],  recieve_buf[7])) / 100;
////			dis[3] = ((float)Byte16(u16, recieve_buf[8],  recieve_buf[9])) / 100;
//		}

//	}
//}


lps_setting_frame_struct lps_setting_frame;

uint8 LPS_Setting_Frame_Unpack(unsigned char *data_frame)
{
	uint8 data_frame_sum = 0;//校验位
	uint8 i = 0;

	if((data_frame[0] == 0x54) && (data_frame[1] == 0x09))//Frame Header & Function Mark check
	{
		for(i = 0;i < (LPS_SETTING_FRAME_LENGTH - 1);i++)//最后字节为校验和
		{
			data_frame_sum += data_frame[i];
		}

		if(data_frame_sum == data_frame[LPS_SETTING_FRAME_LENGTH - 1])//检验和 检查
		{
			lps_setting_frame.is_factory_setting = data_frame[2];
			lps_setting_frame.role = data_frame[3];
			lps_setting_frame.mode = data_frame[4];
			lps_setting_frame.baudrate = data_frame[5];
			lps_setting_frame.channel = data_frame[6];
			lps_setting_frame.anchor_num = data_frame[7];
			lps_setting_frame.tag_num = data_frame[8]; 
			lps_setting_frame.local_add = data_frame[9]; 
			
			lps_setting_frame.antenna_delay = Byte16(sint32,data_frame[11],data_frame[12]);
			
			return 1;
		}
	}
	return 0; 
}


