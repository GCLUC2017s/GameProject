//ふくやま
//高橋弘樹
#ifndef CSCENE_HPP
#define CSCENE_HPP

#include "define.h"
#include "glut.h"
#define _USE_MATH_DEFINES	//数学ライブラリのM_PIを有効にする
#include <math.h>	//数学ライブラリのインクルード
#include <stdio.h>


class CScene{
public:

	enum Estatus
	{
		E_GAMETITLE,E_GAMEMAIN
	};
	Estatus estatus;

	static int status;

	CScene() {
		status = E_GAMETITLE;
	}

	void Loop();
};
#endif