#include<stdio.h>
#include <math.h>

#define FPS 60.0f

/*
※全て、重力加速度は下方向へ 9.8m / s とする。
※全ての問題で空気抵抗は無視する。

問１
初速度 5.0m / s でボールを放り上げたとき、2.5 秒後のボールの速度は？

問２
初速度 12.0m / s でボールを放り上げたとき、何秒後にボールは落下し始めるか？

問３
ある異世界において、初速度 16.0 m / s でボールを放り上げた時に、
5.0 秒後のボールの速度は 6.0 m / s でまだ上昇中だという。
この異世界での重力を求めよ。

問４
地上100mのビルからそっとボールを落下させたとき(初速度 0.0m / s)、
何秒後に地上にボールが到達するか？

問５
地上10mの高さから、初速度 20.0m / s でボールを放り上げた時。
3.5秒後のボールの高さを求めよ。

問６
ボールを真上に放り投げたとき、4.0 秒後に同じ位置に戻ってきたという。
初速度いくらで放り投げたのだろうか？

問７
３次元空間での問題です。
位置P0 = (2.0, 3.0, 4.0)
位置P1 = (10.0, 5.0, -8.5)
P0からボールを打ち上げて5.0秒後にP1に到達するための
ボールの初速度を求めよ。


問９
問７の問題をフレームレート60fps のプログラムループでシミュレートし、
実際にP0からP1に到達することを確認するプログラム

*/


/*
fps


1 秒間に 60ループ


fps = frame per second

フレーム　／　秒


30fps


60fps


position += ( 5.0f, 0.0f, 0.0f )


30fps    １秒間にどれだけ移動しますか？

1秒後にｘが150.0f移動する


60fpsの場合はxに300.0f移動する


1秒間に360動く物体 fpsは60 マイフレーム毎に６進んでいることになる


もしconst float FPS=30;だった場合

1秒間に３６０.0ｆ動く物体の1フレームあたりの速度=360.0f/FPS;


*/



struct AAA
{

	short a1;
	short a2;

};

AAA aaa_aray[] = {
	{ 1, 2 }, {2,3},
};



//座標の構造体
struct Vector3{	//タグ名１

	float x, y, z;	//メンバ名
};

struct Data
{
	Vector3 P0;
	Vector3 P1;
	float    time;
};
Data    question_data[] = {
	//		P0				P1				 time
	{ { 2.0, 4.0, 4.0 }, { 10.0, 6.0, -8.5 }, 5.0f },
	{ { 2.0, 2.0, 6.0 }, { 9.0, 4.0, -7.5 }, 2.0f },
	{ { 3.0, 7.0, 4.0 }, { 3.0, 3.0, -6.5 }, 1.0f },
	{ { 3.0, 3.0, 8.0 }, { 7.0, 6.0, -4.5 }, 7.0f },
	{ { 2.0, 4.0, 4.0 }, { 18.0, 7.0, -3.5 }, 3.0f },
	{ { 5.0, 3.0, 3.0 }, { 12.0, 8.0, -6.5 }, 4.0f },
	{ { 7.0, 2.0, 2.0 }, { 7.0, 9.0, 8.5 }, 2.0f },
	{ { 3.0, 0.0, 4.0 }, { 9.0, 7.0, -1.5 }, 9.0f },
	{ { 6.0, 9.0, 4.0 }, { 12.0, 9.0, -8.0 }, 8.0f },
	{ { 1.0, 7.0, 4.0 }, { 18.0, 5.0, -2.5 }, 10.0f },

};
#define ARRAY_MAX

//一次元配列の要素数を求めるマクロ

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0])) //aに配列名を入れてやる

//足し算マクロ
#define  TASHIZAN(a,b)   (a+b)

/*
sizeof(dataArray)

型の大きさ（byte数）

整数型
char 1バイト

short 2バイト

long 4バイト

int 4バイト

lomglomg 8バイト


浮動小数点型

float  4

double 8



sizeof(int)~4
sizeof(short)~2
*/





// 問題を解くための関数
Vector3 function(const Data &data) //参照渡し　constにより関数内で書き換えができなくなる。　共同制作性
									//privateメンバとの違い			

/*
class CA {
 private:


int  m_a;

};

new messages
Function( CA &a )

a.m_a = 111
 
入れられない
						
Function 関数の用途

m_a あたいが入れられない
	

	const だと使い分けができる
	FunctionXXX(  CA & a)

	FunctionYYY( const CA &a )

	関数＝用途


*/


{
	
	data.P0.x;
	data.P0.y;
	data.P0.z;

	data.P1.x;
	data.P1.y;
	data.P1.z;
	data.time;

	float g;

	g = 9.8f; //重力

	Vector3 ret_val;
		ret_val.x = (data.P1.x - data.P0.x) / data.time;

		ret_val.y = (data.P0.y + (-g / 2 * data.time*data.time) - data.P1.y) / data.time;
		
		ret_val.z = (data.P1.z - data.P0.z) / data.time;
		
		return ret_val;
};


void main(){

	printf("5+3 = %d\n", TASHIZAN(5, 3));

	printf("aaa_aray = %d\n", ARRAY_SIZE(aaa_aray));

	float v;//速度
	float g;//重力加速度
	float t;//時間
	float v0;//初速
	float y0;//はじめの高さ
	float y;//高さ



	printf("問1\n初速度 5.0m / s でボールを放り上げたとき、2.5 秒後のボールの速度は？\n");

	//問1
	g = 9.8f;
	v0 = 5.0f;
	t = 2.5f;

	v = v0 + (-g*t);
	printf("答1:%f\n", v);

	printf("問2\n初速度 12.0m / s でボールを放り上げたとき、何秒後にボールは落下し始めるか？\n");
	//問2
	v0 = 12.0f;

	t = v0 / g;
	printf("答2:%f\n", t);


	printf("問3\nある異世界において、初速度 16.0 m / s でボールを放り上げた時に、5.0 秒後のボールの速度は 6.0 m / s でまだ上昇中だという。この異世界での重力を求めよ。\n");
	//問3
	v0 = 16.0f;
	t = 5.0f;
	v = 6.0f;
	g = (v0 - v) / -t;

	printf("答3:%f\n", g);

	g = 9.8f;//表示後に重力の値をもとに戻す


	printf("問4\n地上100mのビルからそっとボールを落下させたとき(初速度 0.0m / s)、何秒後に地上にボールが到達するか？\n");
	//問4
	y0 = 100.0f;

	t = sqrt(y0 / (g / 2.0f));


	printf("答4:%f\n", t);


	printf("問5\n地上10mの高さから、初速度 20.0m / s でボールを放り上げた時。3.5秒後のボールの高さを求めよ。\n");

	//問5
	y0 = 10.0f;
	v0 = 20.0f;
	t = 3.5f;

	y = y0 + (v0*t) + (-g / 2 * t*t);

	printf("答5:%f\n", y);


	printf("問6\nボールを真上に放り投げたとき、4.0 秒後に同じ位置に戻ってきたという。初速度いくらで放り投げたのだろうか？\n");
	//問6
	t = 4.0f;

	v0 = (g/2*t*t)/t;

	printf("答え6:%f\n", v0);


	printf("問7\n３次元空間での問題です。位置P0 = (2.0, 3.0, 4.0)位置P1 = (10.0, 5.0, -8.5)P0からボールを打ち上げて5.0秒後にP1に到達するためのボールの初速度を求めよ。\n");
	//問7

	float p0x = 2.0f, p0y = 3.0f, p0z = 4.0f;
	float p1x = 10.0f, p1y = 5.0f, p1z = -8.5f;
	float v0x, v0y, v0z;
	t = 5;

	v0x = (p1x - p0x)/5;
	v0z = (p1z - p0z)/5;
	
	v0y = (p0y + (-g / 2 * t*t) - p1y) / t;


	printf("答7x:%f", v0x);
	printf(" y:%f", v0y);
	printf(" z:%f\n", v0z);

	printf("問8\n問７の問題のP0, P1, 経過時間を１０種類用意して、それらの答えが次々に表示されるプログラムを書いてください。\n");


	//問8
	for (int i = 0; i < 10; ++i) {

		Vector3 answer = function(question_data[i]);

		printf("答 x=%f y=%f z=%f\n" ,answer.x,answer.y,answer.z);
	}

	printf("aaa_aray = %d\n", ARRAY_SIZE(question_data));



	//問9
	float posx,posy,posz;

	posx = 2.0f;
	posy = 3.0f;
	posz = 4.0f;

	t = 5;


	float speedx, speedy, speedz;


	speedx = v0x;		//初速
	speedy = v0y;
	speedz = v0z;

	for (float t = 0.0f; t <= 5.0f; t += 1.0f/FPS )
	{
		posx += speedx/FPS;
	//	speedx += 0.0;
		
		posy += speedy/FPS;
		speedy += g/FPS ;

		posz += speedz/FPS;
	//	speedz += (1.0f/FPS);

	}
	
	printf("５秒後の位置 = x=%f y=%f z=%f" ,posx,posy,posz);

	getchar();
};

