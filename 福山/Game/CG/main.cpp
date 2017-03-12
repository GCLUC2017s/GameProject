#include "CGameMain.h"
#include "define.h"
#include <Windows.h>
#define JUMP_FIRST_SPEED 0.2
#define ENEMYE_ARRAY_SIZE 10 //�G�l�~�[��
#define PLAYER_ARRAY_SIZE 10 //�v���C���[��

CGameMain gamemain;

/* display�֐�
1�b�Ԃ�60����s�����
*/
void display() {
	//��ʂ̃N���A
	glClear(GL_COLOR_BUFFER_BIT);
	gamemain.Update();
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
	glutCreateWindow("�͂�؂��̃x��");	//�E�B���h�E�쐬
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
