/*
カメラのプログラム
担当者　冨田健斗
*/
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#define CAMERA_R_NO 100 //カメラのレンダーのナンバー
#define CAMERA_U_NO 100 //カメラのアップデータのナンバー
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