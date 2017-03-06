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
	printf("問1.ボールの速度は%fm/s \n",g_velocity1 + g_gravity * g_time1);
	printf("問2.ボールが落下し始めるのは%f秒後 \n", -g_velocity2 / g_gravity);
	printf("問3.異世界の重力は%f \n", (g_speed - g_velocity3) / g_time3);
	printf("問4.ボールが地上に到達するのは%f秒後 \n", (float)sqrt(-g_height4 / g_gravity * 2.0f));
	printf("問5.3、5秒後のボールの高さは%fm \n", g_height5 + g_velocity5 * g_time5 + g_gravity * pow(g_time5,2) / 2);
	printf("問6.%fm \n", );
	getchar();
}