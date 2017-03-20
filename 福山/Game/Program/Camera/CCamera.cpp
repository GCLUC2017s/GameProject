#include "CCamera.h"
#include "glut.h"
#include "../Define/define.h"
#include "../Player/CPlayer.h"  
#include "../SceneManager/CSceneManager.h"



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
	const float arealeft_x = character_limit_left  + (DISP_X/2) -SIZE_PLAYER_X*2;
	const float arearifgt_x = character_limit_right - (DISP_X / 2) - SIZE_PLAYER_X*3;
	//�\������G���A���w��
	if (arealeft_x <= CPlayer::camera_x&& arearifgt_x >= CPlayer::camera_x){

		mCamerax = CPlayer::camera_x ;
		gluOrtho2D(
			-DISP_X + CPlayer::camera_x ,
			DISP_X  + CPlayer::camera_x ,
			-DISP_Y,
			DISP_Y);
	}else{
		gluOrtho2D(
			-DISP_X + mCamerax,
			DISP_X + mCamerax,
			-DISP_Y,
			DISP_Y);
	}

}
