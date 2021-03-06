/**
* @file
* @brief 研修用プログラム
* @author 高松校 山路
*/

#include "stdio.h"
#include "math.h"
#include <vector>

#define GRAVITY -9.8		//重力
#define FPS 60.0
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))	//配列数を追加に応じて合わせる

float g_gravity    = GRAVITY;
float g_gravityQ3 = 0.0;
//初速度
float g_velocityQ1 = 5.0;
float g_velocityQ2 = 12.0;
float g_velocityQ3 = 16.0;
float g_velocityQ4 = 0.0;
float g_velocityQ5 = 20.0;
float g_velocityQ6 = 0.0;
//速度
float g_speedQ1 = 0.0;
float g_speedQ3 = 6.0;
//時間
float g_timeQ1 = 2.5;
float g_timeQ2 = 0.0;
float g_timeQ3 = 5.0;
float g_timeQ4 = 0.0;
float g_timeQ5 = 3.5;
float g_timeQ6 = 4.0;
float g_timeQ9 = 5.0;
//初期位置
int g_startPosQ4 = 100;
int g_startPosQ5 = 10;
//到達位置
float g_endPosQ5 = 0.0;

//座標のメンバを持つ構造体
struct T_Vector3
{
	float x, y, z;	
};
//初期位置、到達位置、時間のメンバを持つ構造体
struct T_Data
{
	T_Vector3 p0;	//初期位置
	T_Vector3 p1;	//到達位置
	float time;		//時間
};
//関数のプロトタイプ宣言 書き換え不可 参照渡し
T_Vector3 RenderVelocity(const T_Data &data);

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
	//構造体データの中身を設定
	T_Data dataArray[] =
	{
		{ { 2.0, 3.0, 4.0 },{ 10.0, 5.0, -8.5 }, 5.0 },
		{ { 0.0, 5.0, 5.0 },{  8.0, 7.0, -5.0 }, 3.5 },
		{ { 3.0, 4.0, 5.0 },{  7.0, 9.0, -4.0 }, 4.5 },
		{ { 2.0, 3.0, 4.0 },{  6.0, 9.0, -7.5 }, 4.0 },
		{ { 1.0, 3.0, 5.0 },{  5.0, 8.0, -3.5 }, 3.0 },
		{ { 0.0, 5.0, 5.0 },{  9.5, 8.5, -5.5 }, 5.5 },
		{ { 5.0, 8.0, 9.5 },{ 15.0, 9.5, -3.0 }, 6.0 },
		{ { 0.5, 4.5, 7.5 },{  8.0, 7.5, -3.0 }, 2.0 },
		{ { 1.0, 5.0, 5.0 },{  5.0, 8.0, -3.0 }, 1.5 },
		{ { 1.0, 3.0, 7.0 },{ 12.0, 8.0, -3.0 }, 2.5 },
	};
	ARRAY_SIZE(dataArray);
	
	//解答の表示
	printf("A1 %f\n", g_speedQ1);
	printf("A2 %f\n", g_timeQ2);
	printf("A3 %f\n", g_gravityQ3);
	printf("A4 %f\n", g_timeQ4);
	printf("A5 %f\n", g_endPosQ5);
	printf("A6 %f\n", g_velocityQ6);

	//配列の中身を引数から繰り返し取得
	for (int i = 0; i < ARRAY_SIZE(dataArray); i++)
	{  
		T_Vector3 answer = RenderVelocity(dataArray[i]);
		printf("A7&8 X=%f,Y=%f,Z=%f\n", answer.x, answer.y, answer.z);
	}

	//配列0番目のp0座標を格納
	T_Vector3 pos = dataArray[0].p0;
	//配列0番目の速度を関数で受け取り格納
	T_Vector3 speed = RenderVelocity(dataArray[0]);

	//FPSに応じて
	for (float t = 0.0f; t <= g_timeQ9; t += 1.0f / FPS)
	{
		pos.x += speed.x / FPS;
		pos.y += speed.y / FPS;
		pos.z += speed.z / FPS;
		speed.y += g_gravity / FPS;
	}

	printf("A9 x=%f,y=%f,z=%f\n", pos.x, pos.y, pos.z);
	
	getchar();
}
//それぞれの初速度を返す関数
T_Vector3 RenderVelocity(const T_Data &data)
{
	T_Vector3 ret_ans;

	ret_ans.x = (data.p1.x - data.p0.x) / data.time;
	//y軸にのみ重力がかかる
	ret_ans.y = (data.p1.y - data.p0.y + g_gravity * pow(data.time, 2) / -2) / data.time;
	ret_ans.z = (data.p1.z - data.p0.z) / data.time;

	return ret_ans;
}

/*
#define ARRAY_MAX
//型の大きさ（バイト数）
sizeof(dataArray);
*/
/*
char     1
short    2
long     4
int      4
longlong 8

float  4
double 8

sizeof(int)   4
sizeof(float) 4

struct AAA
{
short a1;
short a2;
};

AAA aaa_array[] =
{
{ 1, 2 },{ 2, 3 }
};

sizeof(aaa_array);
sizeof(aaa_array[0]);

sizeof(AAA);
*/