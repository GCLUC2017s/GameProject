/*
�J�����̃v���O����
�S���ҁ@�y�c���l
*/
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"

class  CCamera : public CTask {
public:

	CPlayer *mPlayer;

	int save_player_x;

	CCamera(){
		
	};

	void Render();

};

#endif