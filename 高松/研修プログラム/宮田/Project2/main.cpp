#include<stdio.h>
#include<math.h>



#define GRAVITY 9.8
#define VECTOR 5.0
#define TIME 2.5
//V=Vo+g*t←重力計算①
//y＝yo+Vo*t+g/2*t2

/*struct Vector3
{
	float x, y, z;
};
struct  Data
{
	Vector3 P0;
	Vector3 P1;
	float time;
};
Data  question8_data[] = {
	{ { 1.0f,2.0f,3.0f, },{ 2.0f,4.0f,2.0f, },3.5f },
	{ { 2.0f,5.0f,6.0f, },{ 1.0f,3.0f,1.0f, },6.5f },
	{ { 3.0f,1.0f,5.0f, },{ 2.0f,2.0f,4.0f, },2.5f },
	{ { 5.0f,3.0f,6.0f, },{ 1.0f,1.0f,2.0f, },1.5f },
	{ { 4.0f,2.0f,3.0f, },{ 2.0f,1.0f,6.0f, },2.5f },
	{ { 7.0f,1.0f,3.0f, },{ 2.0f,3.0f,4.0f, },3.3f },
	{ { 7.0f,2.0f,1.0f, },{ 1.0f,3.0f,2.0f, },1.3f },
	{ { 3.0f,1.0f,3.0f, },{ 3.0f,3.0f,4.0f, },3.0f },
	{ { 4.0f,1.0f,1.0f, },{ 2.0f,1.0f,2.0f, },2.3f },
	{ { 2.0f,3.0f,1.0f, },{ 2.0f,2.0f,4.0f, },4.0f },

};



Vector3 function(Data data) {
	data.P0.x;
	data.P1.y;
	data.time;

	Vector3 return_value;
	return_value.x=;
	return_value.y;
	return_value.z;
	return return_value;

	
}
void Vector() {
	for (int i = 0; i < 6; ++i) {
		Vector = function(question8_data[i]);
		printf("答え");
	}
}
struct T_point1
{
	float x1 = 10.0;
	float y1 = 5.0;
	float z1 = -8.5;
	float P1 = (x1, y1, z1);
};
*/

struct T_Point
{
	float x, y, z;

};
struct T_Data
{
	T_Point p0;
	T_Point p1;
	float time;
};
T_Point Answer(T_Data data);




/*struct AAA
{
	short a1;
	short a2;
};
sizeof(AAA)
printf("AAA=%d"sizeof(AAA));
*/
T_Data dataArray[]{
	{ { 2.0f,3.0f,4.0f, },{ 10.0f,5.0f,-8.5f, },5.0f },
	{ { 2.0f,5.0f,6.0f, },{ 1.0f,3.0f,1.0f, },6.5f },
	{ { 3.0f,1.0f,5.0f, },{ 2.0f,2.0f,4.0f, },2.5f },
	{ { 5.0f,3.0f,6.0f, },{ 1.0f,1.0f,2.0f, },1.5f },
	{ { 4.0f,2.0f,3.0f, },{ 2.0f,1.0f,6.0f, },2.5f },
	{ { 7.0f,1.0f,3.0f, },{ 2.0f,3.0f,4.0f, },3.3f },
	{ { 7.0f,2.0f,1.0f, },{ 1.0f,3.0f,2.0f, },1.3f },
	{ { 3.0f,1.0f,3.0f, },{ 3.0f,3.0f,4.0f, },3.0f },
	{ { 4.0f,1.0f,1.0f, },{ 2.0f,1.0f,2.0f, },2.3f },
	{ { 2.0f,3.0f,1.0f, },{ 2.0f,2.0f,4.0f, },4.0f },

};
float g_grabity = -9.8;//重力

void main(){
	float l_grabity = -9.8;//重力
	float l_time = 2.5;//時間
	float l_vector = 5.0;//初速度
	float l_speed;
	float l_haigh = 100.0;
	float l_haigh2;




	

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
	float x = 2.0;//３次元のｘ座標
	float y = 3.0;//３次元のｙ座標
	float z = 4.0;//３次元のｚ座標
				  
	float x1 = 10.0;
	float y1 = 5.0;
	float z1 = -8.5;
	l_grabity = -9.8;
	l_time = 5.0;
	

	float x3 = (x1 - x)/5;
	float z3 = (z1 - z) / 5;
	float y3 = ((l_grabity*(l_time*l_time)) / -2 + y1 - y) / l_time;


	T_Point pos =dataArray[0].p0 ;
	T_Point speed = Answer(dataArray[0]);

	for (float t = 0.0f; t <= 5.0; t ++) {
		t += 1.0 / 60;
		pos.x += speed.x/60;
		pos.y += speed.y/60;
		speed.y += l_grabity/60;
		pos.z += speed.z/60;
		


	}
	printf("5秒後の位置=%f,%f,%f\n",pos.x,pos.y,pos.z);


	printf("%f,%f,%f\n",x3,y3,z3);
	




	

	//問８は、問７の問題のP0,P1,経過時間を１０種類用意して、それらの答えが次々に表示されるプログラムを書いてください。
	
	for (int i = 0; i < 10; ++i) {
		T_Point answer = Answer(dataArray[i]);

		printf("答え%f,%f,%f\n",answer.x,answer.y,answer.z);
	}






	getchar();
}

T_Point Answer(T_Data data) {
	T_Point ret_ans;
	ret_ans.x = data.p1.x - data.p0.x / data.time;
	ret_ans.y = data.p1.y - data.p0.y + g_grabity * pow(data.time, 2) / -2 / data.time;
	ret_ans.z = data.p1.z - data.p0.z / data.time;
	return ret_ans;
};

/*
マクロ
#define ARRY_SIZE(a)(size(a)/sizeof(a[0]))
#define TASIZAN(a,b)(a+b)
printf("5+3=",TASIZAN(5,3))



#define ARRY_SIZE(a)(size(a)/sizeof(a[0]))
ARRAY_SIZE(aaa_array)
(sizeof(a)/sizeof(aaa_array[0]))
ARRAY_SIZE(aaa_array)
*/