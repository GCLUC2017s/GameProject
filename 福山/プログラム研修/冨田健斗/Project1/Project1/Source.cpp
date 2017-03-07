#include <stdio.h>
#include <windows.h>
#include <math.h>
const float gravity = -9.8f;
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
*/
double y;

const int xyz = 3;
const int xyz_kazu = 10;
class CQuestion{
public: 

	float v, v0, g, t;
	float y, y0;
	float p0[xyz][xyz_kazu]; //0��x ,1��y, 2��z
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

	
	////�G�L����
	//struct Enemy
	//{
	//	char *name;//���O
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
	//	{ "BOSS", 50.0f, 10.0f, 10.0f } //�{�X
	//};


	

};

//���W�\��
struct Vector3
{
	float x, y, z;
};

struct Data
{
	Vector3 P0; //�����ʒu
	Vector3 P1; //���B�ʒu
	float time; //�o�ߎ���

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



// �����������߂̊֐�
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
		printf("���� (%f,%f,%f)\n ",answer.x,answer.y,answer.z);
	}
}

int main(){

	CQuestion question[8];

	printf("Hello world\n\n");

	
	/*��1*/
	question[0].v0 = 5.0f;
	question[0].t = 2.5f;

	question[0].v = question[0].v0 + question[0].g * question[0].t;

	printf("��1.\n�����x 5.0m / s �Ń{�[�������グ���Ƃ��A2.5 �b��̃{�[���̑��x�́H\n");
	printf("\n���� %f\n\n", question[0].v);
	/*�I��*/


	/*��Q*/
	question[1].v0 = 12.0f;

	question[1].t = question[1].v0 / -question[1].g;

	printf("��2.\n�����x 12.0m / s �Ń{�[�������グ���Ƃ��A���b��Ƀ{�[���͗������n�߂邩�H\n");
	printf("\n���� %f\n\n", question[1].t);
	/*�I��*/


	/*��3*/
	question[2].v0 = 16.0f;
	question[2].t = 5.0f;
	question[2].v = 6.0f;

	question[2].g = (question[2].v0 - question[2].v) / -question[2].t;

	printf("��3.\n����ِ��E�ɂ����āA�����x 16.0 m / s �Ń{�[�������グ������,\n5.0 �b��̃{�[���̑��x�� 6.0 m / s�ł܂��㏸�����Ƃ����B\n���ِ̈��E�ł̏d�͂����߂�B\n");
	printf("\n���� %f\n\n", question[2].g);
	/*�I��*/


	/*��4*/
	question[3].y0 = 100.0f;

	question[3].t = sqrt(-question[3].y0 / (question[3].g / 2)); //sprt�����������߂�

	printf("��4.\n�n��100m�̃r�����炻���ƃ{�[���𗎉��������Ƃ�(�����x 0.0m / s)�A\n���b��ɒn��Ƀ{�[�������B���邩�H\n");
	printf("\n���� %f\n\n", question[3].t);
	/*�I��*/


	/*��T*/
	question[4].y0 = 10;
	question[4].v0 = 20.0f;
	question[4].t = 3.5f;

	question[4].y = question[4].y0 + question[4].v0*question[4].t + (question[4].g / 2) * question[4].t*question[4].t;

	printf("��5.\n�n��10m�̍�������A�����x 20.0m / s �Ń{�[�������グ�����B\n3.5�b��̃{�[���̍��������߂�D\n");
	printf("\n���� %f\n\n", question[4].y);
	/*�I��*/


	/*��6*/
	question[5].t = 4.0f;

	question[5].v0 = (-question[5].g / 2 * question[5].t*question[5].t) / question[5].t;

	printf("��6.\n�{�[����^��ɕ��蓊�����Ƃ��A4.0 �b��ɓ����ʒu�ɖ߂��Ă����Ƃ����B\n�����x������ŕ��蓊�����̂��낤���H\n");
	printf("\n���� %f\n\n", question[5].v0);
	/*�I��*/

	/*��7*/
	float p0x = 2.0f, p0y = 3.0f, p0z = 4.0f;
	float p1x = 10.0f, p1y = 5.0f, p1z = -8.5f;
	float v0x, v0y, v0z;

	question[6].t = 5.0f;

	v0x = (p1x - p0x) / question[6].t; //�d�͂�������Ȃ�

	v0y = (p0y + question[6].g / 2 * question[6].t * question[6].t- p1y) / question[6].t; //�d�͂�����

	v0z = (p1z - p0z) / question[6].t; //�d�͂�������Ȃ�


	printf("��7.\n�R������Ԃł̖��ł��B\n�ʒuP0 = (2.0, 3.0, 4.0)\n�ʒuP1 = (10.0, 5.0, -8.5)\nP0����{�[����ł��グ��5.0�b���P1�ɓ��B���邽�߂�\n�{�[���̏����x�����߂�B\n");
	printf("\n���� (%f,%f,%f)\n\n", v0x,v0y,v0z );
	/*�I��*/

	/*��8*/
	printf("��8.\n��7�̖���P0, P1, �o�ߎ��Ԃ��P�O��ޗp�ӂ��āA�����̓��������X�ɕ\�������v���O�����������Ă�������\n\n");
	
	toi8();

	/*�I��*/
	getchar();
}