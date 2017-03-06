#include <stdio.h>
#include <windows.h>
#include <math.h>
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

	void toi8(){
	

		const int question_kazu = 10;
		for (int i = 0; i < question_kazu; i++)
		{

		}
		printf("");

	}

};



int main(){
	CQuestion question[8];

	printf("Hello world\n\n");

	
	/*問1*/
	question[0].v0 = 5.0f;
	question[0].t = 2.5f;

	question[0].v = question[0].v0 + question[0].g * question[0].t;

	printf("問1.答え %f\n\n", question[0].v);
	/*終了*/


	/*問２*/
	question[1].v0 = 12.0f;

	question[1].t = -question[1].v0 / question[1].g;

	printf("問2.答え %f\n\n", question[1].t);
	/*終了*/


	/*問3*/
	question[2].v0 = 16.0f;
	question[2].t = 5.0f;

	question[2].g = (question[2].v - question[2].v0) / question[2].t;

	printf("問3.答え %f\n\n", question[2].g);
	/*終了*/


	/*問4*/
	question[3].y = 100.0f;

	question[3].t = sqrt(-question[3].y / (question[3].g / 2)); //sprt平方根を求める

	printf("問4.答え %f\n\n", question[3].t);
	/*終了*/


	/*問５*/
	question[4].y0 = 10;
	question[4].v0 = 20.0f;
	question[4].t = 3.5f;

	question[4].y = question[4].y0 + question[4].v0*question[4].t + (question[4].g / 2) * question[4].t*question[4].t;

	printf("問5.答え %f\n\n", question[4].y);
	/*終了*/


	/*問6*/
	question[5].t = 4.0f;

	question[5].v0 = (question[5].g / 2 * question[5].t*question[5].t) / -question[5].t;

	printf("問6.答え %f\n\n", question[5].v0);
	/*終了*/

	/*問7*/
	float p0x = 2.0f, p0y = 3.0f, p0z = 4.0f;
	float p1x = 10.0f, p1y = 5.0f, p1z = -8.5f;
	float v0x, v0y, v0z;

	question[6].t = 5.0f;

	v0x = (p0x + question[6].g / 2 * question[6].t *question[6].t) / p1x;
	v0y = (p0y + question[6].g / 2 * question[6].t * question[6].t) / p1y;
	v0z = (p0z + question[6].g / 2 * question[6].t * question[6].t) / p1z;

	question[6].v0 = v0x + v0y + v0z;
	question[6].v0 = abs(question[6].v0);

	printf("問7.答え %f\n\n", question[6].v0);
	/*終了*/

	/*問8*/
	const int x = 0, y = 1, z = 2;
	for (int i = 0; i < xyz_kazu; i++)
	{
		question[7].p0[x][i] = rand() % 10;
		question[7].p0[y][i] = rand() % 10;
		question[7].p0[z][i] = rand() % 10;

		question[7].p1[x][i] = rand() % 10;
		question[7].p1[y][i] = rand() % 10;
		question[7].p1[z][i] = rand() % 10;

		printf("問8.\n");
		printf("p0の xは%f,yは%f,zは%f\n", question[7].p0[x][i], question[7].p0[y][i], question[7].p0[z][i]);
		printf("p1の xは%f,yは%f,zは%f\n", question[7].p1[x][i], question[7].p1[y][i], question[7].p1[z][i]);

		if (question[7].p1[x][i] != 0){
			v0x = (question[7].p0[x][i] + question[7].g / 2 * question[7].t *question[7].t) / question[7].p1[x][i];
		}
		else{
			v0x = 0;
		}
		if (question[7].p1[y][i] != 0){
			v0y = (question[7].p0[y][i] + question[7].g / 2 * question[7].t *question[7].t) / question[7].p1[y][i];
		}
		else{
			v0y = 0;
		}
		if (question[7].p1[z][i] != 0){

			v0z = (question[7].p0[z][i] + question[7].g / 2 * question[7].t *question[7].t) / question[7].p1[z][i];
		}
		else{
			v0z = 0;
		}


		question[7].v0 = v0x + v0y + v0z;
		question[7].v0 = abs(question[7].v0);

		printf("答え %f\n\n", question[7].v0);
	}

	/*終了*/
	getchar();
}