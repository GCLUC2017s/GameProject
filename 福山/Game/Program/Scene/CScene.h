//�V�[���̃v���O���~���O�i�V�[���}�l�[�W���[�j
//�S���� �����O��
#ifndef CSCENE_HPP
#define CSCENE_HPP
<<<<<<< HEAD

#include "../Define/define.h"
=======
>>>>>>> 86b196553959a77e4bd3a019ed2d013854cfcbcd
#include "glut.h"
#include <stdio.h>

class CScene{
public:
	CScene(void) {}
	static CScene *mScene;
	static CScene* mGetInstance(void){ //�V���O���g���ɂ��܂��B
		return mScene;
	}

	//�V�[�����ɐݒ�@���т͗���̏���
		enum eSceneNo{
			E_TITLE,
			E_SELECT,
			E_GAMEMAIN,
			E_GAMECLEAR,
			E_GAMEOVER
		};


		eSceneNo mNextStatus;

			void ChangeScene(eSceneNo no);
	virtual	void Update();	//virtual�@�H
	virtual	void Render(){};
};

#endif