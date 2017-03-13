#include "CCamera.h"
#include "glut.h"
#include "define.h"

void CCamera::Render(){
	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	const float camera_x = DISP_X;
	const float camera_y = DISP_Y;
	const float area_x = MAP_LIMIT_X / 2;
	//�\������G���A���w��
	if (-area_x <= -camera_x + CPlayer::camera_x &&
		area_x >= camera_x + CPlayer::camera_x){

		save_player_x = CPlayer::camera_x;

		gluOrtho2D(
			-camera_x + CPlayer::camera_x,
			camera_x + CPlayer::camera_x,
			-camera_y,
			camera_y);
	}
	else{
		gluOrtho2D(
			-camera_x + save_player_x,
			camera_x + save_player_x,
			-camera_y,
			camera_y);
	}

}