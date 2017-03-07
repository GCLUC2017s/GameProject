#include <stdio.h>
#include <math.h>

#define GRAVITY -9.8
#define ARRAY_MAX 10	//�ő�l

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
struct T_Vector3
{
	float x, y, z;
};

void RenderVelocity(struct T_Vector3 spos, struct  T_Vector3 epos, float time);

void main()
{
	printf("HelloWorld!\n");
	printf("��1.�{�[���̑��x��%fm/s \n",g_velocity1 + g_gravity * g_time1);
	printf("��2.�{�[�����������n�߂�̂�%f�b�� \n", -g_velocity2 / g_gravity);
	printf("��3.�ِ��E�̏d�͂�%f \n", (g_speed - g_velocity3) / g_time3);
	printf("��4.�{�[�����n��ɓ��B����̂�%f�b�� \n", (float)sqrt(-g_height4 / g_gravity * 2.0f));
	printf("��5.3�A5�b��̃{�[���̍�����%fm \n", g_height5 + g_velocity5 * g_time5 + g_gravity * pow(g_time5,2) / 2);
	printf("��6.�����x%fm/s�ŕ��蓊���� \n", g_gravity * g_time6 / -2);
/*��V
�R������Ԃł̖��ł��B
�ʒuP0 = ( 2.0, 3.0, 4.0 )
�ʒuP1 = ( 10.0, 5.0, -8.5 )
P0����{�[����ł��グ��5.0�b���P1�ɓ��B���邽�߂�
�{�[���̏����x�����߂�B*/
	struct T_Data
	{
		T_Vector3 P0;
		T_Vector3 P1;
		float time;
	};
	T_Data T_QuestionData[]=
	{
		{ { 2.0, 3.0, 4.0 },{ 10.0, 5.0, -8.5 },5.0 },
		{ { 3.0, 4.0, 5.0 },{ 8.0, 6.0, -10.0 },11.0 },
		{ { 4.0, 5.0, 6.0 },{ 9.0, 7.0, -16.0 }, 7.0 },
		{ { 5.0, 6.0, 7.0 },{ 12.0, 10.0, -13.0 }, 8.0 },
		{ { 6.0, 7.0, 8.0 },{ 16.0, 17.0, -18.0 }, 1.0 },
		{ { 7.0, 8.0, 9.0 },{ 13.0, 14.0, -14.0 }, 4.0 },
		{ { 8.0, 9.0, 10.0 },{ 8.0, 9.0, 10.0 }, 10.0 },
		{ { 9.0, 10.0, 11.0 },{ 15.0, 20.0, -20.0 }, 2.0 },
		{ { 10.0, 11.0, 12.0 },{ 22.0, 21.0, -12.0 }, 3.0 },
		{ { 11.0, 12.0, 13.0 },{ 20.0, 25.0, -22.0 }, 6.0 }
	};
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		RenderVelocity(T_QuestionData[i].P0,T_QuestionData[i].P1,T_QuestionData[i].time);
	}
	getchar();
}

void RenderVelocity(struct T_Vector3 spos, struct  T_Vector3 epos, float time)
{
	T_Vector3 answerArray;
	T_Vector3 oneSecondSpeed;
	answerArray.x = epos.x - spos.x;
	answerArray.z = epos.z - spos.z;

	oneSecondSpeed.x = answerArray.x / time;
	oneSecondSpeed.y = (epos.y - spos.y + g_gravity * pow(time, 2) / -2) / time;
	oneSecondSpeed.z = answerArray.z / time;
	printf("P0[%d,%d,%d]����ł��グ���{�[����P1[%d,%d,%f]�܂�%d�b�œ��B���邽�߂ɕK�v�ȏ����x��(X������%fm/s,Y������%fm/s,Z������%fm/s)\n", (int)spos.x, (int)spos.y, (int)spos.z, (int)epos.x, (int)epos.y, epos.z, (int)time,oneSecondSpeed.x, oneSecondSpeed.y, oneSecondSpeed.z);
}