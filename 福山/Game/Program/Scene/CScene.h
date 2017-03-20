//シーンのプログラミング（シーンマネージャー）
//担当者 高橋弘樹
#ifndef CSCENE_HPP
#define CSCENE_HPP
#include "../Define/define.h"
#include "glut.h"
#include <stdio.h>

enum eSceneNo{
	E_TITLE,
	E_SELECT,
	E_GAMEMAIN,
	E_GAMECLEAR,
	E_GAMEOVER
};

class CScene{
public:
	//シーン毎に設定　並びは流れの順番
	


		virtual	void Update(){};	//virtual　
		virtual	void Render(){};
		virtual	void Init(){};


		friend class CSceneManager;
		friend class CTitleScene;
		friend class CScene2;
};

#endif