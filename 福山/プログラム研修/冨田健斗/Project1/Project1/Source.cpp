#include <stdio.h>
#include <windows.h>
#include <math.h>
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

	
	/*��1*/
	question[0].v0 = 5.0f;
	question[0].t = 2.5f;

	question[0].v = question[0].v0 + question[0].g * question[0].t;

	printf("��1.���� %f\n\n", question[0].v);
	/*�I��*/


	/*��Q*/
	question[1].v0 = 12.0f;

	question[1].t = -question[1].v0 / question[1].g;

	printf("��2.���� %f\n\n", question[1].t);
	/*�I��*/


	/*��3*/
	question[2].v0 = 16.0f;
	question[2].t = 5.0f;

	question[2].g = (question[2].v - question[2].v0) / question[2].t;

	printf("��3.���� %f\n\n", question[2].g);
	/*�I��*/


	/*��4*/
	question[3].y = 100.0f;

	question[3].t = sqrt(-question[3].y / (question[3].g / 2)); //sprt�����������߂�

	printf("��4.���� %f\n\n", question[3].t);
	/*�I��*/


	/*��T*/
	question[4].y0 = 10;
	question[4].v0 = 20.0f;
	question[4].t = 3.5f;

	question[4].y = question[4].y0 + question[4].v0*question[4].t + (question[4].g / 2) * question[4].t*question[4].t;

	printf("��5.���� %f\n\n", question[4].y);
	/*�I��*/


	/*��6*/
	question[5].t = 4.0f;

	question[5].v0 = (question[5].g / 2 * question[5].t*question[5].t) / -question[5].t;

	printf("��6.���� %f\n\n", question[5].v0);
	/*�I��*/

	/*��7*/
	float p0x = 2.0f, p0y = 3.0f, p0z = 4.0f;
	float p1x = 10.0f, p1y = 5.0f, p1z = -8.5f;
	float v0x, v0y, v0z;

	question[6].t = 5.0f;

	v0x = (p0x + question[6].g / 2 * question[6].t *question[6].t) / p1x;
	v0y = (p0y + question[6].g / 2 * question[6].t * question[6].t) / p1y;
	v0z = (p0z + question[6].g / 2 * question[6].t * question[6].t) / p1z;

	question[6].v0 = v0x + v0y + v0z;
	question[6].v0 = abs(question[6].v0);

	printf("��7.���� %f\n\n", question[6].v0);
	/*�I��*/

	/*��8*/
	const int x = 0, y = 1, z = 2;
	for (int i = 0; i < xyz_kazu; i++)
	{
		question[7].p0[x][i] = rand() % 10;
		question[7].p0[y][i] = rand() % 10;
		question[7].p0[z][i] = rand() % 10;

		question[7].p1[x][i] = rand() % 10;
		question[7].p1[y][i] = rand() % 10;
		question[7].p1[z][i] = rand() % 10;

		printf("��8.\n");
		printf("p0�� x��%f,y��%f,z��%f\n", question[7].p0[x][i], question[7].p0[y][i], question[7].p0[z][i]);
		printf("p1�� x��%f,y��%f,z��%f\n", question[7].p1[x][i], question[7].p1[y][i], question[7].p1[z][i]);

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

		printf("���� %f\n\n", question[7].v0);
	}

	/*�I��*/
	getchar();
}