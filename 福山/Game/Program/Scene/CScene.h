//シーンのプログラミング（シーンマネージャー）
//担当者 高橋弘樹
#ifndef CSCENE_HPP
#define CSCENE_HPP
#include "../Define/define.h"
#include "glut.h"
#include <stdio.h>

class CScene{
public:
	CScene(void) {}
	static CScene *mScene;
	static CScene* mGetInstance(void){ //シングルトンにします。
		return mScene;
	}

	//シーン毎に設定　並びは流れの順番
		enum eSceneNo{
			E_TITLE,
			E_SELECT,
			E_GAMEMAIN,
			E_GAMECLEAR,
			E_GAMEOVER
		};


		eSceneNo mNextStatus;

			void ChangeScene(eSceneNo no);
	virtual	void Update();	//virtual　？
	virtual	void Render(){};
};

#endif