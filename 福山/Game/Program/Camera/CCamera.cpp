#include "CCamera.h"
#include "glut.h"
#include "../Define/define.h"
#include "../Player/CPlayer.h"  

void CCamera::Render(){
	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	const float area_x = MAP_LIMIT_X / 2;
	//�\������G���A���w��
	if (-area_x <= -DISP_X + CPlayer::camera_x + SIZE_PLAYER_X &&
		area_x >= DISP_X + CPlayer::camera_x + SIZE_PLAYER_X){
		save_player_x = CPlayer::camera_x + SIZE_PLAYER_X;

		gluOrtho2D(
			-DISP_X + CPlayer::camera_x + SIZE_PLAYER_X,
			DISP_X + CPlayer::camera_x + SIZE_PLAYER_X,
			-DISP_Y,
			DISP_Y);
	}
	else{
		gluOrtho2D(
			-DISP_X + save_player_x,
			DISP_X + save_player_x,
			-DISP_Y,
			DISP_Y);
	}

}