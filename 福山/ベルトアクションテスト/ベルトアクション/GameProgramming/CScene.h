//�ӂ����
//�����O��
#ifndef CSCENE_HPP
#define CSCENE_HPP

#include "define.h"
#include "glut.h"
#define _USE_MATH_DEFINES	//���w���C�u������M_PI��L���ɂ���
#include <math.h>	//���w���C�u�����̃C���N���[�h
#include <stdio.h>
#include "CStage.h"
#include "CKey.h"
#include "CGame.h"
#include "CGameclear.h"
#include "CGameover.h"
#include "Title.h"
#include "TitleScene.h"



class CScene{
public:

	CStage stage;
	CGameclear clear;
	Title title;
	TitleScene titlescene;
	CGameover out;


	//	int state;

	//	CScene() : state(0) {}
	CScene() {}
};
#endif