/**
* @file
* @brief ���C�p�v���O����
* @author �����Z �R�H
*/

#include "stdio.h"
#include "math.h"

#define GRAVITY -9.8		//�d��

#define VELOCITY_Q1  5.0	//�����x
#define VELOCITY_Q2 12.0	
#define VELOCITY_Q3 16.0
#define VELOCITY_Q5 20.0

#define SPEED_Q3 6.0		//���x

#define TIME_Q1 2.5			//����
#define TIME_Q3 5.0
#define TIME_Q5 3.5

#define START_POSQ4 100		//�����ʒu
#define START_POSQ5  10

float g_gravity    = GRAVITY;
float g_gravityQ3  = 0.0;

float g_velocityQ1 = VELOCITY_Q1;
float g_velocityQ2 = VELOCITY_Q2;
float g_velocityQ3 = VELOCITY_Q3;
float g_velocityQ4 = 0.0;
float g_velocityQ5 = VELOCITY_Q5;

float g_speedQ1 = 0.0;
float g_speedQ3 = SPEED_Q3;

float g_timeQ1 = TIME_Q1;
float g_timeQ2 = 0.0;
float g_timeQ3 = TIME_Q3;
float g_timeQ4 = 0.0;
float g_timeQ5 = TIME_Q5;

int g_startPosQ4 = START_POSQ4;
int g_startPosQ5 = START_POSQ5;

float g_endPosQ5 = 0.0;

void main()
{
	g_speedQ1   = g_velocityQ1 + g_gravity * g_timeQ1;

	g_timeQ2    = -g_velocityQ2 / g_gravity;

	g_gravityQ3 = (g_speedQ3 - g_velocityQ3) / g_timeQ3;
	            //�����������߂�֐�
	g_timeQ4    = sqrt((-g_startPosQ4) / (g_gravity / 2));
	                                                                //�ݏ�����߂�֐�(���߂����ϐ�, �ݏ搔)                
	g_endPosQ5  = g_startPosQ5 + g_velocityQ5 * g_timeQ5 + (g_gravity) / 2 * pow(g_timeQ5, 2);

	printf("A1 %f\n", g_speedQ1);
	printf("A2 %f\n", g_timeQ2);
	printf("A3 %f\n", g_gravityQ3);
	printf("A4 %f\n", g_timeQ4);
	printf("A5 %f\n", g_endPosQ5);

	getchar();
}