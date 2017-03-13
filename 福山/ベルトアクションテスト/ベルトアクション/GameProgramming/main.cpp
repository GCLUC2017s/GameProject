#include "define.h"
#include "glut.h"
#define _USE_MATH_DEFINES	//���w���C�u������M_PI��L���ɂ���
#include <math.h>	//���w���C�u�����̃C���N���[�h
#include <stdio.h>
#include "CStage.h"
#include "CKey.h"
#include "CGame.h"
#include "CGameclear.h"
#include "CGameover.h"
#include "Title.h"
#include "TitleScene.h"

/*

	GameTitle�y��Result���̈����ɂ��āB

	GameTitle��Game��ʂ̔w�i��i�s����Scroll������Ԃŕ`�悷��B
	���̗v�̂ŃQ�[���Z���N�g���`�悷��B
	Result�AGameOver�����l�ɃQ�[����ʂ����ɕ`�悵����Ԃŕ`�悷��B
	�A���h��L��Result�Ǝ����v�́B


	stage�̔w�i�����[�v�����ł����邩�B

*/


class CScene{
public:

	CStage stage;
	CGameclear clear;
	Title title;
	TitleScene titlescene;
	CGameover out;


	//	int state;

	//	CScene() : state(0) {}
	CScene() {}


	//Main Routine

	void loop() {
		switch (CGame::status) {
			//�^�C�g���̌Ăяo�����s��
		case 0:
			titlescene.init();
			CGame::status = 1;
			break;
		case 1:
			titlescene.update();
			if (CKey::push(VK_RETURN)){		//return�L�[�������ƃQ�[���J�n�B
				CGame::status = 2;
			}
			break;

			//�X�e�[�W�̌Ăяo�����s��
		case 2:
			stage.init();
			CGame::status = 3;
			break;
		case 3:
			stage.update();
			break;

			//�Q�[���I�[�o�[��ʂ̌Ăяo�����s��
		case 4:
			out.init();
			CGame::status = 5;
			break;
		case 5:
			out.update();
			if (CKey::once(VK_RETURN)){		//return�L�[�������ƃ^�C�g���ɖ߂�B
				CGame::status = 0;
			}
			break;

			//���U���g��ʂ̌Ăяo���iclear�j���s��
		case 6:
			clear.init();
			CGame::status = 7;
			break;
		case 7:
			clear.update();
			if (CKey::once(VK_RETURN)){		//return�L�[�������Ɩ߂�B
				CGame::status = 8;
			}

			break;
		case 8:
		

			break;
		case 9:
		


			break;

		};

	}

	void init() {
	}

	void update() {


	}
};
CScene Scene;


/* display�֐�
1�b�Ԃ�60����s�����
*/
void display() {
	//��ʂ̃N���A
	glClear(GL_COLOR_BUFFER_BIT);
	Scene.loop();
	//��ʂɕ\��
	glutSwapBuffers();
}

//�֐��̃v���g�^�C�v�錾
void reshape(int, int);
void idle();

void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	//�E�B���h�E�̐ݒ�
	glutInitWindowSize(WINDOW_PIXEL_H, WINDOW_PIXEL_V);	//�E�B���h�E�T�C�Y�ݒ�
	glutInitDisplayMode(GLUT_RGBA | GL_DOUBLE);	//�f�B�X�v���C���[�h�ݒ�
	glutCreateWindow("Hello GameProgramming");	//�E�B���h�E�쐬
	glClearColor(0.5f, 0.5f, 0.5f, 1.f);	//�N���A�F���O���[�ɐݒ�

	//�e��֐��ݒ�
	glutDisplayFunc(display);	//�`�掞�̊֐����w��
	glutReshapeFunc(reshape);	//�E�B���h�E�ό`���̊֐����w��
	glutIdleFunc(idle);			//�ҋ@���̊֐����w��

	//���C�����[�v
	glutMainLoop();

	return;
}

/*�E�B���h�E�T�C�Y�ύX���̏���
void reshape(int width, int height)
width:��ʕ�
height:��ʍ���
*/
void reshape(int width, int height) {
	glViewport(0, 0, width, height);	//��ʂ̕`��G���A�̎w��
//	glMatrixMode(GL_PROJECTION);		//�s����v���W�F�N�V�������[�h�֕ύX
//	gluOrtho2D(-XMAX, XMAX, -YMAX, YMAX);	//��ʂ̍��W�n��ݒ�
//	gluOrtho2D(-5, 5, -5, 5);	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_MODELVIEW);		//�s������f���r���[���[�h�֕ύX
	glLoadIdentity();	//�s���������
}

LARGE_INTEGER last_time;	//�O��̃J�E���^�l
//�P�b�ԂɂU�O��`�悷��悤�ɒ��߂���
void idle() {
	LARGE_INTEGER freq;		//��b������̃J�E���^��
	LARGE_INTEGER time;		//����̃J�E���^�l

	//��b�Ԃ̃J�E���^�����擾
	QueryPerformanceFrequency(&freq);

	if (last_time.QuadPart == 0) {
		QueryPerformanceCounter(&last_time);
	}
	do{
		//���݂̃V�X�e���̃J�E���g�����擾
		QueryPerformanceCounter(&time);

		//���̃J�E���g-�O��̃J�E���g < 1�b������̃J�E���g����60�Ŋ���(1/60�b������̃J�E���g��)
	} while (time.QuadPart - last_time.QuadPart < freq.QuadPart / 60);
	last_time = time;

	//�`�悷��֐����Ă�
	display();
}
