#include<stdio.h>
#include <math.h>

#define FPS 60.0f

/*
���S�āA�d�͉����x�͉������� 9.8m / s �Ƃ���B
���S�Ă̖��ŋ�C��R�͖�������B

��P
�����x 5.0m / s �Ń{�[�������グ���Ƃ��A2.5 �b��̃{�[���̑��x�́H

��Q
�����x 12.0m / s �Ń{�[�������グ���Ƃ��A���b��Ƀ{�[���͗������n�߂邩�H

��R
����ِ��E�ɂ����āA�����x 16.0 m / s �Ń{�[�������グ�����ɁA
5.0 �b��̃{�[���̑��x�� 6.0 m / s �ł܂��㏸�����Ƃ����B
���ِ̈��E�ł̏d�͂����߂�B

��S
�n��100m�̃r�����炻���ƃ{�[���𗎉��������Ƃ�(�����x 0.0m / s)�A
���b��ɒn��Ƀ{�[�������B���邩�H

��T
�n��10m�̍�������A�����x 20.0m / s �Ń{�[�������グ�����B
3.5�b��̃{�[���̍��������߂�B

��U
�{�[����^��ɕ��蓊�����Ƃ��A4.0 �b��ɓ����ʒu�ɖ߂��Ă����Ƃ����B
�����x������ŕ��蓊�����̂��낤���H

��V
�R������Ԃł̖��ł��B
�ʒuP0 = (2.0, 3.0, 4.0)
�ʒuP1 = (10.0, 5.0, -8.5)
P0����{�[����ł��グ��5.0�b���P1�ɓ��B���邽�߂�
�{�[���̏����x�����߂�B


��X
��V�̖����t���[�����[�g60fps �̃v���O�������[�v�ŃV�~�����[�g���A
���ۂ�P0����P1�ɓ��B���邱�Ƃ��m�F����v���O����

*/


/*
fps


1 �b�Ԃ� 60���[�v


fps = frame per second

�t���[���@�^�@�b


30fps


60fps


position += ( 5.0f, 0.0f, 0.0f )


30fps    �P�b�Ԃɂǂꂾ���ړ����܂����H

1�b��ɂ���150.0f�ړ�����


60fps�̏ꍇ��x��300.0f�ړ�����


1�b�Ԃ�360�������� fps��60 �}�C�t���[�����ɂU�i��ł��邱�ƂɂȂ�


����const float FPS=30;�������ꍇ

1�b�ԂɂR�U�O.0���������̂�1�t���[��������̑��x=360.0f/FPS;


*/



struct AAA
{

	short a1;
	short a2;

};

AAA aaa_aray[] = {
	{ 1, 2 }, {2,3},
};



//���W�̍\����
struct Vector3{	//�^�O���P

	float x, y, z;	//�����o��
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

//�ꎟ���z��̗v�f�������߂�}�N��

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0])) //a�ɔz�񖼂����Ă��

//�����Z�}�N��
#define  TASHIZAN(a,b)   (a+b)

/*
sizeof(dataArray)

�^�̑傫���ibyte���j

�����^
char 1�o�C�g

short 2�o�C�g

long 4�o�C�g

int 4�o�C�g

lomglomg 8�o�C�g


���������_�^

float  4

double 8



sizeof(int)~4
sizeof(short)~2
*/





// �����������߂̊֐�
Vector3 function(const Data &data) //�Q�Ɠn���@const�ɂ��֐����ŏ����������ł��Ȃ��Ȃ�B�@�������쐫
									//private�����o�Ƃ̈Ⴂ			

/*
class CA {
 private:


int  m_a;

};

new messages
Function( CA &a )

a.m_a = 111
 
������Ȃ�
						
Function �֐��̗p�r

m_a ��������������Ȃ�
	

	const ���Ǝg���������ł���
	FunctionXXX(  CA & a)

	FunctionYYY( const CA &a )

	�֐����p�r


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

	g = 9.8f; //�d��

	Vector3 ret_val;
		ret_val.x = (data.P1.x - data.P0.x) / data.time;

		ret_val.y = (data.P0.y + (-g / 2 * data.time*data.time) - data.P1.y) / data.time;
		
		ret_val.z = (data.P1.z - data.P0.z) / data.time;
		
		return ret_val;
};


void main(){

	printf("5+3 = %d\n", TASHIZAN(5, 3));

	printf("aaa_aray = %d\n", ARRAY_SIZE(aaa_aray));

	float v;//���x
	float g;//�d�͉����x
	float t;//����
	float v0;//����
	float y0;//�͂��߂̍���
	float y;//����



	printf("��1\n�����x 5.0m / s �Ń{�[�������グ���Ƃ��A2.5 �b��̃{�[���̑��x�́H\n");

	//��1
	g = 9.8f;
	v0 = 5.0f;
	t = 2.5f;

	v = v0 + (-g*t);
	printf("��1:%f\n", v);

	printf("��2\n�����x 12.0m / s �Ń{�[�������グ���Ƃ��A���b��Ƀ{�[���͗������n�߂邩�H\n");
	//��2
	v0 = 12.0f;

	t = v0 / g;
	printf("��2:%f\n", t);


	printf("��3\n����ِ��E�ɂ����āA�����x 16.0 m / s �Ń{�[�������グ�����ɁA5.0 �b��̃{�[���̑��x�� 6.0 m / s �ł܂��㏸�����Ƃ����B���ِ̈��E�ł̏d�͂����߂�B\n");
	//��3
	v0 = 16.0f;
	t = 5.0f;
	v = 6.0f;
	g = (v0 - v) / -t;

	printf("��3:%f\n", g);

	g = 9.8f;//�\����ɏd�͂̒l�����Ƃɖ߂�


	printf("��4\n�n��100m�̃r�����炻���ƃ{�[���𗎉��������Ƃ�(�����x 0.0m / s)�A���b��ɒn��Ƀ{�[�������B���邩�H\n");
	//��4
	y0 = 100.0f;

	t = sqrt(y0 / (g / 2.0f));


	printf("��4:%f\n", t);


	printf("��5\n�n��10m�̍�������A�����x 20.0m / s �Ń{�[�������グ�����B3.5�b��̃{�[���̍��������߂�B\n");

	//��5
	y0 = 10.0f;
	v0 = 20.0f;
	t = 3.5f;

	y = y0 + (v0*t) + (-g / 2 * t*t);

	printf("��5:%f\n", y);


	printf("��6\n�{�[����^��ɕ��蓊�����Ƃ��A4.0 �b��ɓ����ʒu�ɖ߂��Ă����Ƃ����B�����x������ŕ��蓊�����̂��낤���H\n");
	//��6
	t = 4.0f;

	v0 = (g/2*t*t)/t;

	printf("����6:%f\n", v0);


	printf("��7\n�R������Ԃł̖��ł��B�ʒuP0 = (2.0, 3.0, 4.0)�ʒuP1 = (10.0, 5.0, -8.5)P0����{�[����ł��グ��5.0�b���P1�ɓ��B���邽�߂̃{�[���̏����x�����߂�B\n");
	//��7

	float p0x = 2.0f, p0y = 3.0f, p0z = 4.0f;
	float p1x = 10.0f, p1y = 5.0f, p1z = -8.5f;
	float v0x, v0y, v0z;
	t = 5;

	v0x = (p1x - p0x)/5;
	v0z = (p1z - p0z)/5;
	
	v0y = (p0y + (-g / 2 * t*t) - p1y) / t;


	printf("��7x:%f", v0x);
	printf(" y:%f", v0y);
	printf(" z:%f\n", v0z);

	printf("��8\n��V�̖���P0, P1, �o�ߎ��Ԃ��P�O��ޗp�ӂ��āA�����̓��������X�ɕ\�������v���O�����������Ă��������B\n");


	//��8
	for (int i = 0; i < 10; ++i) {

		Vector3 answer = function(question_data[i]);

		printf("�� x=%f y=%f z=%f\n" ,answer.x,answer.y,answer.z);
	}

	printf("aaa_aray = %d\n", ARRAY_SIZE(question_data));



	//��9
	float posx,posy,posz;

	posx = 2.0f;
	posy = 3.0f;
	posz = 4.0f;

	t = 5;


	float speedx, speedy, speedz;


	speedx = v0x;		//����
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
	
	printf("�T�b��̈ʒu = x=%f y=%f z=%f" ,posx,posy,posz);

	getchar();
};

