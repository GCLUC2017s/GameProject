#include "CCamera.h"
#include "glut.h"
#include "../Define/define.h"
#include "../Player/CPlayer.h"  

void CCamera::Render(){
	//画面の座標系を設定
	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	const float area_x = MAP_LIMIT_X / 2;
	//表示するエリアを指定
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