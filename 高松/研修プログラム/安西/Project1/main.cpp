#include <stdio.h>
#include <math.h>

#define GRAVITY -9.8
#define ARRAY_MAX 10	//最大値

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
	printf("問1.ボールの速度は%fm/s \n",g_velocity1 + g_gravity * g_time1);
	printf("問2.ボールが落下し始めるのは%f秒後 \n", -g_velocity2 / g_gravity);
	printf("問3.異世界の重力は%f \n", (g_speed - g_velocity3) / g_time3);
	printf("問4.ボールが地上に到達するのは%f秒後 \n", (float)sqrt(-g_height4 / g_gravity * 2.0f));
	printf("問5.3、5秒後のボールの高さは%fm \n", g_height5 + g_velocity5 * g_time5 + g_gravity * pow(g_time5,2) / 2);
	printf("問6.初速度%fm/sで放り投げた \n", g_gravity * g_time6 / -2);
/*問７
３次元空間での問題です。
位置P0 = ( 2.0, 3.0, 4.0 )
位置P1 = ( 10.0, 5.0, -8.5 )
P0からボールを打ち上げて5.0秒後にP1に到達するための
ボールの初速度を求めよ。*/
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
	printf("P0[%d,%d,%d]から打ち上げたボールがP1[%d,%d,%f]まで%d秒で到達するために必要な初速度は(X方向に%fm/s,Y方向に%fm/s,Z方向に%fm/s)\n", (int)spos.x, (int)spos.y, (int)spos.z, (int)epos.x, (int)epos.y, epos.z, (int)time,oneSecondSpeed.x, oneSecondSpeed.y, oneSecondSpeed.z);
}