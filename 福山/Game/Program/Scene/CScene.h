//シーンのプログラミング（シーンマネージャー）
//担当者 高橋弘樹
#ifndef CSCENE_HPP
#define CSCENE_HPP
#include "../Define/define.h"
#include "glut.h"
#include <stdio.h>

class CScene{
private:
	static CScene *mScene;
public:
	//シーン毎に設定　並びは流れの順番
		enum eSceneNo{
			E_TITLE,
			E_SELECT,
			E_GAMEMAIN,
			E_GAMECLEAR,
			E_GAMEOVER
		};
	static CScene *GetInstance(); //GetInstance
			void ChangeScene(eSceneNo no);	//シーン切り替え
			void DeleteScene();			//KILL
	virtual	void Update(){};	//virtual　
	virtual	void Render(){};
};

#endif