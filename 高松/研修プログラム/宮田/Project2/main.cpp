#include<stdio.h>
#include<math.h>



#define GRAVITY 9.8
#define VECTOR 5.0
#define TIME 2.5
//V=Vo+g*t���d�͌v�Z�@
//y��yo+Vo*t+g/2*t2


void main(){
	float l_grabity = -9.8;//�d��
	float l_time = 2.5;//����
	float l_vector = 5.0;//�����x
	float l_speed;
	float l_haigh = 100.0;
	


	printf("hellow world\n");
	
	//��P�@�����x 5.0m/s �Ń{�[�������グ���Ƃ��A2.5 �b��̃{�[���̑��x�́H
	printf("%f\n",l_vector+l_grabity*l_time);

	//��Q�@�����x 12.0m/s �Ń{�[�������グ���Ƃ��A���b��Ƀ{�[���͗������n�߂邩�H
	l_vector = 12.0;
	printf("%f\n",(l_speed-l_vector)/l_grabity);

	//��R����ِ��E�ɂ����āA�����x 16.0 m/s �Ń{�[�������グ�����ɁA5.0 �b��̃{�[���̑��x�� 6.0 m/s �ł܂��㏸�����Ƃ����B���ِ̈��E�ł̏d�͂����߂�B
	l_vector = 16.0;
	l_time = 5.0;
	l_speed = 6.0;
	printf("%f\n", (l_speed - l_vector) / l_time);

	//��S�n��100m�̃r�����炻���ƃ{�[���𗎉��������Ƃ�(�����x 0.0m/s)�A���b��ɒn��Ƀ{�[�������B���邩�H
	l_vector = 0.0;
	l_grabity = -9.8;
	l_haigh = 100;
	printf("%f\n", (float)sqrt(-l_haigh / l_grabity * 2));

	//��T�n��10m�̍�������A�����x 20.0m/s �Ń{�[�������グ�����B3.5�b��̃{�[���̍��������߂�B
	l_haigh = 10;
	l_grabity = -9.8;
	l_vector = 20.0;
	l_time = 3.5;
	printf("%f\n",l_haigh+l_vector*l_time+l_grabity/2*pow(l_time,2) );

	//��U�{�[����^��ɕ��蓊�����Ƃ��A4.0 �b��ɓ����ʒu�ɖ߂��Ă����Ƃ����B�����x������ŕ��蓊�����̂��낤���H
	l_grabity = 9.8;
	l_time = 4.0;
	printf("%f\n", (l_));


	//��V �R������Ԃł̖��ł��B�ʒuP0 = ( 2.0, 3.0, 4.0 )�ʒuP1 = ( 10.0, 5.0, -8.5 )P0����{�[����ł��グ��5.0�b���P1�ɓ��B���邽�߂̃{�[���̏����x�����߂�B
	getchar();
}