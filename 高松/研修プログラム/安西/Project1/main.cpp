#include <stdio.h>
#include <math.h>

#define GRAVITY -9.8

float g_gravity = GRAVITY;
float g_velocity1 = 5.0f;
float g_velocity2 = 12.0f;
float g_velocity3 = 16.0f;
float g_velocity5 = 20.0f;
float g_time1 = 2.5f;
float g_time3 = 5.0f;
float g_time5 = 3.5f;
float g_time6 = 4.0f;
float g_speed = 6.0f;
float g_height4 = 100.0f;
float g_height5 = 10.0f;

void main()
{
	printf("HelloWorld!\n");
	printf("��1.�{�[���̑��x��%fm/s \n",g_velocity1 + g_gravity * g_time1);
	printf("��2.�{�[�����������n�߂�̂�%f�b�� \n", -g_velocity2 / g_gravity);
	printf("��3.�ِ��E�̏d�͂�%f \n", (g_speed - g_velocity3) / g_time3);
	printf("��4.�{�[�����n��ɓ��B����̂�%f�b�� \n", (float)sqrt(-g_height4 / g_gravity * 2.0f));
	printf("��5.3�A5�b��̃{�[���̍�����%fm \n", g_height5 + g_velocity5 * g_time5 + g_gravity * pow(g_time5,2) / 2);
	printf("��6.%fm \n", );
	getchar();
}