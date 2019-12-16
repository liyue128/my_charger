#include <iostream>
#include "charger.h"

#define NUM 4
using namespace std;

/*calculate voltages of cells
double calcute(data)
{
	int VCOUT = ADC_Count/Full_Scale_Count*VREF_NOMINAL;

	int GC_VCOUT=[(VCn_GC_4<<4)+VCn_GAIN_CORR]*0.001;
	int OC_VCOUT=[(VCn_OC_4<<4)+VCn_OFFSET_CORR]*0.001;
	int GC_VREF=(1+[(VREF_GC_4<<4)+VREF_GAIN_CORR]*0.001)+\
	[(VREF_OC_5<<5)+(VREF_OC_4<<4)+VREF_OFFSET_CORR]*0.001/VREF_NOMINAL;

	VCn=(VCOUT*GC_VREF+OC_VCOUT)/G_VCOUT*(1+GC_VCOUT);
	return VCn;
}*/

//ʹ�ܼ�ʱ��
void EnableTimer(void)
{
	printf("start timer.\n");
	//	TIM_Cmd(TIM1, ENABLE);
//	TIMER_SWITCH_FLAG = 1;
}

//���ü�ʱ��
void DisableTimer(void)
{
	printf("end timer.\n");
	//	TIM_Cmd(TIM1, DISABLE);
//	TIMER_SWITCH_FLAG = 0;
}

//���ѹ���ֵ
double MaxOfCell(double cell[])
{
	int max = cell[0];
	for (int i = 0; i < NUM; i++)
		if (cell[i] > max) max = cell[i];
	return max;
}

//���ѹ��Сֵ
double MinOfCell(double cell[])
{
	int min = cell[0];
	for (int i = 0; i < NUM; i++)
		if (cell[i] < min) min = cell[i];
	return min;
}

//���ܵ�ѹ
double SumOfCell(double cell[])
{
	int sum = 0;
	for (int i = 0; i < NUM; i++) sum += cell[i];
	return sum;
}

//�պϿ���
void SwStart(void)
{
	cout << "SW = 1" << endl;
}

//�Ͽ�����
void SwEnd(void)
{
	cout << "SW = 0" << endl;
}
