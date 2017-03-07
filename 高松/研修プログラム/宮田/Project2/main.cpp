#include<stdio.h>
#include<math.h>



#define GRAVITY 9.8
#define VECTOR 5.0
#define TIME 2.5
//V=Vo+g*t←重力計算①
//y＝yo+Vo*t+g/2*t2

struct T_point
{
	float x = 2.0;
	float y = 3.0;
	float z = 4.0;
	float P0 = (x, y, z);

	float x1 = 10.0;
	float y1 = 5.0;
	float z1 = -8.5;
	float P1 = (x1, y1, z1);
	float lenght = pow(pow((x - x1), 2) + pow((y - y1), 2) + pow((z - z1), 2),0.5);
		
};

/*struct T_point1
{
	float x1 = 10.0;
	float y1 = 5.0;
	float z1 = -8.5;
	float P1 = (x1, y1, z1);
};*/


void main(){
	float l_grabity = -9.8;//重力
	float l_time = 2.5;//時間
	float l_vector = 5.0;//初速度
	float l_speed;
	float l_haigh = 100.0;

	float x = 2.0;
	float y = 3.0;
	float z = 4.0;
	//float P0 = (x, y, z);

	float x1 = 10.0;
	float y1 = 5.0;
	float z1 = -8.5;
	//float P1 = (x1, y1, z1);
	float l_lenght = pow(pow((x - x1), 2) + pow((y - y1), 2) + pow((z - z1), 2), 0.5);
	

	printf("hellow world\n");
	
	//問１　初速度 5.0m/s でボールを放り上げたとき、2.5 秒後のボールの速度は？
	printf("%f\n",l_vector+l_grabity*l_time);

	//問２　初速度 12.0m/s でボールを放り上げたとき、何秒後にボールは落下し始めるか？
	l_vector = 12.0;
	printf("%f\n",(l_speed-l_vector)/l_grabity);

	//問３ある異世界において、初速度 16.0 m/s でボールを放り上げた時に、5.0 秒後のボールの速度は 6.0 m/s でまだ上昇中だという。この異世界での重力を求めよ。
	l_vector = 16.0;
	l_time = 5.0;
	l_speed = 6.0;
	printf("%f\n", (l_speed - l_vector) / l_time);

	//問４地上100mのビルからそっとボールを落下させたとき(初速度 0.0m/s)、何秒後に地上にボールが到達するか？
	l_vector = 0.0;
	l_grabity = -9.8;
	l_haigh = 100;
	printf("%f\n", (float)sqrt(-l_haigh / l_grabity * 2));

	//問５地上10mの高さから、初速度 20.0m/s でボールを放り上げた時。3.5秒後のボールの高さを求めよ。
	l_haigh = 10;
	l_grabity = -9.8;
	l_vector = 20.0;
	l_time = 3.5;
	printf("%f\n",l_haigh+l_vector*l_time+l_grabity/2*pow(l_time,2) );

	//問６ボールを真上に放り投げたとき、4.0 秒後に同じ位置に戻ってきたという。初速度いくらで放り投げたのだろうか？
	l_grabity = 9.8;
	l_time = 4.0;
	printf("%f\n",(l_grabity*(l_time*l_time))/2/l_time);


	/*問７ ３次元空間での問題です。位置P0 = ( 2.0, 3.0, 4.0 )位置P1 = ( 10.0, 5.0, -8.5 )
	P0からボールを打ち上げて5.0秒後にP1に到達するためのボールの初速度を求めよ。*/
	l_grabity = 9.8;
	l_time = 5.0;
	
	printf("%f\n", (l_lenght+ l_grabity*(l_time*l_time)) / 2 / l_time);
	
	

	//問８は、問７の問題のP0,P1,経過時間を１０種類用意して、それらの答えが次々に表示されるプログラムを書いてください。
	
	getchar();
}