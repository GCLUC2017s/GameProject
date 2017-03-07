/**
* @file
* @brief ���C�p�v���O����
* @author �����Z �R�H
*/

#include "stdio.h"
#include "math.h"
#include <vector>

#define GRAVITY -9.8		//�d��

#define VELOCITY_Q1  5.0	//�����x
#define VELOCITY_Q2 12.0	
#define VELOCITY_Q3 16.0
#define VELOCITY_Q5 20.0

#define SPEED_Q3 6.0		//���x

#define TIME_Q1 2.5			//����
#define TIME_Q3 5.0
#define TIME_Q5 3.5
#define TIME_Q6 4.0
#define TIME_Q7 5.0

#define START_POSQ4 100		//�����ʒu
#define START_POSQ5  10

#define ARRAY_MAX 10			//�z��ő�l

float g_gravity    = GRAVITY;
float g_gravityQ3  = 0.0;

float g_velocityQ1 = VELOCITY_Q1;
float g_velocityQ2 = VELOCITY_Q2;
float g_velocityQ3 = VELOCITY_Q3;
float g_velocityQ4 = 0.0;
float g_velocityQ5 = VELOCITY_Q5;
float g_velocityQ6 = 0.0;
float g_velocityQ7_Q8 = 0.0;

float g_speedQ1 = 0.0;
float g_speedQ3 = SPEED_Q3;

float g_timeQ1 = TIME_Q1;
float g_timeQ2 = 0.0;
float g_timeQ3 = TIME_Q3;
float g_timeQ4 = 0.0;
float g_timeQ5 = TIME_Q5;
float g_timeQ6 = TIME_Q6; 

int g_startPosQ4 = START_POSQ4;
int g_startPosQ5 = START_POSQ5;

float g_endPosQ5 = 0.0;		//���B�ʒu

//���W�ʒu�̃����o�����\����
struct T_Vector3
{
	float x;
	float y;
	float z;
};

//�֐��̃v���g�^�C�v�錾
void RenderVelocity(struct T_Vector3 spos, struct T_Vector3 epos, float time);

void main()
{
	//��1
	g_speedQ1    = g_velocityQ1 + g_gravity * g_timeQ1;
	//��2
	g_timeQ2     = -g_velocityQ2 / g_gravity;
	//��3
	g_gravityQ3  = (g_speedQ3 - g_velocityQ3) / g_timeQ3;
	//��4          //�����������߂�֐�
	g_timeQ4     = sqrt((-g_startPosQ4) / (g_gravity / 2));
	//��5                                                              //�ݏ�����߂�֐�(���߂����ϐ�, �ݏ搔)                
	g_endPosQ5   = g_startPosQ5 + g_velocityQ5 * g_timeQ5 + (g_gravity) / 2 * pow(g_timeQ5, 2);
	//��6
	g_velocityQ6 = -g_gravity / (g_timeQ6 / 2);
	//��7.8
	//�\���̃����o�̒��g��ݒ�
	struct T_Vector3 startPosArray[ARRAY_MAX] =
	{
		{ 2.0, 3.0, 4.0 },
		{ 0.0, 5.0, 5.0 },
		{ 3.0, 4.0, 5.0 },
		{ 2.0, 3.0, 4.0 },
		{ 1.0, 3.0, 5.0 },
		{ 0.0, 5.0, 5.0 },
		{ 5.0, 8.0, 9.5 },
		{ 0.5, 4.5, 7.5 },
		{ 1.0, 5.0, 5.0 },
		{ 1.0, 3.0, 7.0 },
	};

	struct T_Vector3 endPosArray[ARRAY_MAX] =
	{
		{ 10.0, 5.0, -8.5 },
		{  8.0, 7.0, -5.0 },
		{  7.0, 9.0, -4.0 },
		{  6.0, 9.0, -7.5 },
		{  5.0, 8.0, -3.5 },
		{  9.5, 8.5, -5.5 },
		{ 15.0, 9.5, -3.0 },
		{  8.0, 7.5, -3.0 },
		{  5.0, 8.0, -3.0 },
		{ 12.0, 8.0, -3.0 },
	};

	float timeArray[ARRAY_MAX] =
	{
		{ 5.0 },
		{ 3.0 },
		{ 7.5 },
		{ 4.5 },
		{ 3.5 },
		{ 2.0 },
		{ 7.0 },
		{ 9.0 },
		{ 8.0 },
		{ 6.5 },
	};
	//�z��̒��g����������J��Ԃ��擾
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		RenderVelocity(startPosArray[i], endPosArray[i], timeArray[i]);
	}
	//�𓚂̕\��
	printf("A1 %f\n", g_speedQ1);
	printf("A2 %f\n", g_timeQ2);
	printf("A3 %f\n", g_gravityQ3);
	printf("A4 %f\n", g_timeQ4);
	printf("A5 %f\n", g_endPosQ5);
	printf("A6 %f\n", g_velocityQ6);

	getchar();
}
//Q7.8�̉𓚂��J��Ԃ��\������֐�
void RenderVelocity(struct T_Vector3 spos, struct T_Vector3 epos, float time)
{
	//�����ʒu���瓞�B�ʒu�ւ̒�������
	float length = (epos.x - spos.x, epos.y - spos.y, epos.z - spos.z);
	//1�b���Ƃɐi�ޑ��x
	float  speed = length / time;

	printf("A7.8 %f\n");
}