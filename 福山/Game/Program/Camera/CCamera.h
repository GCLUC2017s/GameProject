/*
カメラのプログラム
担当者　冨田健斗
*/
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#include "../Camera/CCamera.h"
#include "../MyNumber/CMyNumber.h"

#define CAMERA_R_NO 100 //カメラのレンダーのナンバー
#define CAMERA_U_NO 100 //カメラのアップデータのナンバー

class  CCamera : public CTask {
private:


	CPlayer *mPlayer;

public:
 	static int mCamerax;

	CCamera();

	void Update();

};

#endif