//�V�[���̃v���O���~���O�i�V�[���}�l�[�W���[�j
//�S���� �����O��
#ifndef CSCENE_HPP
#define CSCENE_HPP
#include "../Define/define.h"
#include "glut.h"
#include <stdio.h>

class CScene{
public:
	//�V�[�����ɐݒ�@���т͗���̏���
		enum eSceneNo{
			E_TITLE,
			E_SELECT,
			E_GAMEMAIN,
			E_GAMECLEAR,
			E_GAMEOVER
		};


		friend class CSceneManager;
		friend class CTitleScene;
		friend class CScene2;

};

#endif