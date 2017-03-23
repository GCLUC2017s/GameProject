#include "CCamera.h"
#include "glut.h"
#include "../Define/define.h"
#include "../Player/CPlayer.h"  
#include "../SceneManager/CSceneManager.h"
#include "../CGame/CGame.h"
#include "../MyNumber/CMyNumber.h"


CCamera::CCamera(){
	mPriorityR = E_CAMERA;
	mPriorityU = E_CAMERA;
	mMyNumber = E_CAMERA;
	mCamerax = first_pos.x;
};
void Search(){
	CTask *t;

	t = CTaskManager::GetInstance()->mRoot;

	while (t != 0)
	{
		if (t->mCharaFlag){
			switch (t->mMyNumber){
			case E_ENEMY00:
			case E_ENEMY01:
			case E_BOSS:
				break;
			};

		}
	}
}



void CCamera::Update(){
	//画面の座標系を設定
	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	const float arealeft_x = character_limit_left+SIZE_PLAYER_X*2;
	const float arearifgt_x = character_limit_right-(DISP_X/2)-SIZE_PLAYER_X*4;
	//表示するエリアを指定
	if (arealeft_x <= CPlayer::camera_x&& arearifgt_x >= CPlayer::camera_x){

		mCamerax = CPlayer::camera_x ;
		gluOrtho2D(
			-DISP_X + CPlayer::camera_x ,
			DISP_X  + CPlayer::camera_x ,
			-DISP_Y,
			DISP_Y);
	}
	else if (arealeft_x > CPlayer::camera_x){
		gluOrtho2D(
			-DISP_X + arealeft_x,
			DISP_X + arealeft_x,
			-DISP_Y,
			DISP_Y);
	}
	else{
		gluOrtho2D(
			-DISP_X + arearifgt_x,
			DISP_X + arearifgt_x,
			-DISP_Y,
			DISP_Y);
	}

}
