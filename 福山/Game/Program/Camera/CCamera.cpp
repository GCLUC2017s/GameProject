#include "CCamera.h"
#include "glut.h"
#include "../Define/define.h"
#include "../Player/CPlayer.h"  

int CCamera::mCamerax;

CCamera::CCamera(){
	mPriorityR = E_CAMERA;
	mPriorityU = E_CAMERA;
	mMyNumber = E_CAMERA;
	mCamerax = first_pos.x;
};

void CCamera::Update(){
	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	const float area_x = MAP_LIMIT_X / 2;
	//�\������G���A���w��
	if (-area_x <= -DISP_X + CPlayer::camera_x + SIZE_PLAYER_X &&
		area_x >= DISP_X + CPlayer::camera_x + SIZE_PLAYER_X){
		mCamerax = CPlayer::camera_x + SIZE_PLAYER_X;

		gluOrtho2D(
			-DISP_X + CPlayer::camera_x + SIZE_PLAYER_X,
			DISP_X + CPlayer::camera_x + SIZE_PLAYER_X,
			-DISP_Y,
			DISP_Y);
	}
	else{
		gluOrtho2D(
			-DISP_X + mCamerax,
			DISP_X + mCamerax,
			-DISP_Y,
			DISP_Y);
	}

}