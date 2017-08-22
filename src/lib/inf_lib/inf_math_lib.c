#include "inf_math_lib.h"

//function:	1/(number)^(0.5)
float invSqrt(float number)
{
	volatile long i;
	volatile float x,y;
	volatile const float f = 1.5f;
	x = number * 0.5F;
	y = number;
	i = * (( long * ) &y);
	i = 0x5f375a86 - ( i >> 1 );
	y = * (( float * ) & i);
	y = y * ( f - ( x * y * y ) );
	return y;
}

double SlidingWindow_Flitter(unsigned int flitter_length,unsigned int *flitter_cnt,double buf[],double input)
{
	unsigned int cnt;
	double temp = 0,output = 0;
	
	buf[*flitter_cnt] = input;

	*flitter_cnt += 1;
	if(*flitter_cnt >= flitter_length) *flitter_cnt = 0;
	
	for(cnt = 0;cnt < flitter_length;cnt++)
	{
		temp += buf[cnt];
	}

	output = temp / flitter_length;
	
	return output;
}

void Limiting(volatile float *src,volatile float min,volatile float max)
{
	if(*src < min) *src = min;
	else if(*src > max)	*src = max;
}

