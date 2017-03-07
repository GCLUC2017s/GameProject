#include <stdio.h>
#include <windows.h>
#include <math.h>
const float gravity = -9.8f;
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
*/
double y;

const int xyz = 3;
const int xyz_kazu = 10;
class CQuestion{
public: 

	float v, v0, g, t;
	float y, y0;
	float p0[xyz][xyz_kazu]; //0をx ,1をy, 2をz
	float p1[xyz][xyz_kazu];

	CQuestion() : v(0.0f), v0(0.0f), g(-9.8f), t(0.0f), y(0.0f), y0(0.0f) {
		for (int i = 0; i < xyz_kazu; i++){
			const int px = 0, py = 1, pz = 2;
			p0[px][i] = 0;
			p0[py][i] = 0;
			p0[pz][i] = 0;

			p1[px][i] = 0;
			p1[py][i] = 0;
			p1[pz][i] = 0;
		}
	}

	
	////敵キャラ
	//struct Enemy
	//{
	//	char *name;//名前
	//	float hp;
	//	float atttack;
	//	float defence;
	//};

	//Enemy enemy_data[] = {
	//	{ "Enm1", 5.0f, 1.0f, 1.0f },
	//	{ "Enm2", 5.0f, 3.0f, 1.0f },
	//	{ "Enm3", 5.0f, 5.0f, 1.0f },
	//	{ "Enm4", 0.0f, 2.0f, 1.0f },
	//	{ "Enm5", 2.0f, 2.0f, 1.0f },
	//	{ "Enm6", 5.0f, 3.0f, 10.0f },
	//	{ "BOSS", 50.0f, 10.0f, 10.0f } //ボス
	//};


	

};

//座標構造
struct Vector3
{
	float x, y, z;
};

struct Data
{
	Vector3 P0; //初期位置
	Vector3 P1; //到達位置
	float time; //経過時間

};

Data question_data[] = {
	//     p0                        p1               time
	{ { 2.0f, 3.0f, 4.0f }, { 10.0f, 5.0f, -8.5f }, 5.0f },//1
	{ { -2.0f, 3.0f, 4.0f }, { 10.0f, 5.0f, -8.5f }, 5.0f },//2
	{ { 3.0f, 2.0f, 3.0f }, { 1.0f, 2.0f, 3.0f }, 3.5f },//3
	{ { 4.0f, 2.0f, 3.0f }, { 1.0f, 2.0f, 3.0f }, 3.5f },//4
	{ { 1.0f, 2.0f, 3.0f }, { 1.0f, -2.0f, 3.0f }, 3.5f },//5
	{ { 2.0f, 2.0f, 3.0f }, { 1.0f, -2.0f, 3.0f }, 3.5f },//6
	{ { 3.0f, 2.0f, 3.0f }, { 1.0f, -2.0f, 3.0f }, 3.5f },//7
	{{ 3.0f, 2.0f, 3.0f }, { -1.0f, -2.0f, -3.0f }, 3.5f },//8
	{{ 3.0f, -2.0f, 2.0f }, { -1.0f, -2.0f, 3.0f }, 3.5f },//9
	{{ 3.0f, -2.0f, 1.0f }, { 1.0f, -2.0f, 3.0f }, 3.5f },//10
};



// 問題を解くための関数
Vector3  function(Data data)
{
	Vector3 ret_val;
	ret_val.x = (data.P1.x - data.P0.x) / data.time;
	ret_val.y = (data.P0.y + gravity / 2 * data.time * data.time - data.P1.y) / data.time;
	ret_val.z = (data.P1.z - data.P0.z) / data.time;
	return ret_val;
	
};

void toi8(){
	for (int i = 0; i < 10; ++i) {
		Vector3 answer = function(question_data[i]);
		printf("答え (%f,%f,%f)\n ",answer.x,answer.y,answer.z);
	}
}

int main(){

	CQuestion question[8];

	printf("Hello world\n\n");

	
	/*問1*/
	question[0].v0 = 5.0f;
	question[0].t = 2.5f;

	question[0].v = question[0].v0 + question[0].g * question[0].t;

	printf("問1.\n初速度 5.0m / s でボールを放り上げたとき、2.5 秒後のボールの速度は？\n");
	printf("\n答え %f\n\n", question[0].v);
	/*終了*/


	/*問２*/
	question[1].v0 = 12.0f;

	question[1].t = question[1].v0 / -question[1].g;

	printf("問2.\n初速度 12.0m / s でボールを放り上げたとき、何秒後にボールは落下し始めるか？\n");
	printf("\n答え %f\n\n", question[1].t);
	/*終了*/


	/*問3*/
	question[2].v0 = 16.0f;
	question[2].t = 5.0f;
	question[2].v = 6.0f;

	question[2].g = (question[2].v0 - question[2].v) / -question[2].t;

	printf("問3.\nある異世界において、初速度 16.0 m / s でボールを放り上げた時に,\n5.0 秒後のボールの速度は 6.0 m / sでまだ上昇中だという。\nこの異世界での重力を求めよ。\n");
	printf("\n答え %f\n\n", question[2].g);
	/*終了*/


	/*問4*/
	question[3].y0 = 100.0f;

	question[3].t = sqrt(-question[3].y0 / (question[3].g / 2)); //sprt平方根を求める

	printf("問4.\n地上100mのビルからそっとボールを落下させたとき(初速度 0.0m / s)、\n何秒後に地上にボールが到達するか？\n");
	printf("\n答え %f\n\n", question[3].t);
	/*終了*/


	/*問５*/
	question[4].y0 = 10;
	question[4].v0 = 20.0f;
	question[4].t = 3.5f;

	question[4].y = question[4].y0 + question[4].v0*question[4].t + (question[4].g / 2) * question[4].t*question[4].t;

	printf("問5.\n地上10mの高さから、初速度 20.0m / s でボールを放り上げた時。\n3.5秒後のボールの高さを求めよ．\n");
	printf("\n答え %f\n\n", question[4].y);
	/*終了*/


	/*問6*/
	question[5].t = 4.0f;

	question[5].v0 = (-question[5].g / 2 * question[5].t*question[5].t) / question[5].t;

	printf("問6.\nボールを真上に放り投げたとき、4.0 秒後に同じ位置に戻ってきたという。\n初速度いくらで放り投げたのだろうか？\n");
	printf("\n答え %f\n\n", question[5].v0);
	/*終了*/

	/*問7*/
	float p0x = 2.0f, p0y = 3.0f, p0z = 4.0f;
	float p1x = 10.0f, p1y = 5.0f, p1z = -8.5f;
	float v0x, v0y, v0z;

	question[6].t = 5.0f;

	v0x = (p1x - p0x) / question[6].t; //重力がかからない

	v0y = (p0y + question[6].g / 2 * question[6].t * question[6].t- p1y) / question[6].t; //重力かかる

	v0z = (p1z - p0z) / question[6].t; //重力がかからない


	printf("問7.\n３次元空間での問題です。\n位置P0 = (2.0, 3.0, 4.0)\n位置P1 = (10.0, 5.0, -8.5)\nP0からボールを打ち上げて5.0秒後にP1に到達するための\nボールの初速度を求めよ。\n");
	printf("\n答え (%f,%f,%f)\n\n", v0x,v0y,v0z );
	/*終了*/

	/*問8*/
	printf("問8.\n問7の問題のP0, P1, 経過時間を１０種類用意して、それらの答えが次々に表示されるプログラムを書いてください\n\n");
	
	toi8();

	/*終了*/
	getchar();
}