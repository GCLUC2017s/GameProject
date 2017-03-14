/*
�J�����̃v���O����
�S���ҁ@�y�c���l
*/
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#define CAMERA_R_NO 100 //�J�����̃����_�[�̃i���o�[
#define CAMERA_U_NO 100 //�J�����̃A�b�v�f�[�^�̃i���o�[
class  CCamera : public CTask {
private:


	CPlayer *mPlayer;

	int save_player_x;
public:

	CCamera(){
		mPriorityR = CAMERA_R_NO;
		mPriorityU = CAMERA_U_NO;
		save_player_x = first_pos.x;
	};

	void Render();

};

#endif