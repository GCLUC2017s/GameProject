//�ӂ����
//�����O��
#ifndef CSCENE_HPP
#define CSCENE_HPP

#include "define.h"
#include "glut.h"
#define _USE_MATH_DEFINES	//���w���C�u������M_PI��L���ɂ���
#include <math.h>	//���w���C�u�����̃C���N���[�h
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