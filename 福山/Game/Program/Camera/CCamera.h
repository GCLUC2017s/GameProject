/*
�J�����̃v���O����
�S���ҁ@�y�c���l
*/
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#include "../Camera/CCamera.h"
#include "../MyNumber/CMyNumber.h"

#define CAMERA_R_NO 100 //�J�����̃����_�[�̃i���o�[
#define CAMERA_U_NO 100 //�J�����̃A�b�v�f�[�^�̃i���o�[

class  CCamera : public CTask {
private:


	CPlayer *mPlayer;

public:
 	static int mCamerax;

	CCamera();

	void Update();

};

#endif