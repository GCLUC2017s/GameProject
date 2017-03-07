/**
* @file
* @brief 研修用プログラム
* @author 高松校 山路
*/

#include "stdio.h"
#include "math.h"
#include <vector>

#define GRAVITY -9.8		//重力

#define VELOCITY_Q1  5.0	//初速度
#define VELOCITY_Q2 12.0	
#define VELOCITY_Q3 16.0
#define VELOCITY_Q5 20.0

#define SPEED_Q3 6.0		//速度

#define TIME_Q1 2.5			//時間
#define TIME_Q3 5.0
#define TIME_Q5 3.5
#define TIME_Q6 4.0
#define TIME_Q7 5.0

#define START_POSQ4 100		//初期位置
#define START_POSQ5  10

#define ARRAY_MAX 10			//配列最大値

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

float g_endPosQ5 = 0.0;		//到達位置

//座標位置のメンバを持つ構造体
struct T_Vector3
{
	float x;
	float y;
	float z;
};

//関数のプロトタイプ宣言
void RenderVelocity(struct T_Vector3 spos, struct T_Vector3 epos, float time);

void main()
{
	//問1
	g_speedQ1    = g_velocityQ1 + g_gravity * g_timeQ1;
	//問2
	g_timeQ2     = -g_velocityQ2 / g_gravity;
	//問3
	g_gravityQ3  = (g_speedQ3 - g_velocityQ3) / g_timeQ3;
	//問4          //平方根を求める関数
	g_timeQ4     = sqrt((-g_startPosQ4) / (g_gravity / 2));
	//問5                                                              //累乗を求める関数(求めたい変数, 累乗数)                
	g_endPosQ5   = g_startPosQ5 + g_velocityQ5 * g_timeQ5 + (g_gravity) / 2 * pow(g_timeQ5, 2);
	//問6
	g_velocityQ6 = -g_gravity / (g_timeQ6 / 2);
	//問7.8
	//構造体メンバの中身を設定
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
	//配列の中身を引数から繰り返し取得
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		RenderVelocity(startPosArray[i], endPosArray[i], timeArray[i]);
	}
	//解答の表示
	printf("A1 %f\n", g_speedQ1);
	printf("A2 %f\n", g_timeQ2);
	printf("A3 %f\n", g_gravityQ3);
	printf("A4 %f\n", g_timeQ4);
	printf("A5 %f\n", g_endPosQ5);
	printf("A6 %f\n", g_velocityQ6);

	getchar();
}
//Q7.8の解答を繰り返し表示する関数
void RenderVelocity(struct T_Vector3 spos, struct T_Vector3 epos, float time)
{
	//初期位置から到達位置への直線距離
	float length = (epos.x - spos.x, epos.y - spos.y, epos.z - spos.z);
	//1秒ごとに進む速度
	float  speed = length / time;

	printf("A7.8 %f\n");
}