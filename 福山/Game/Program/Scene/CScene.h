//�V�[���̃v���O���~���O�i�V�[���}�l�[�W���[�j
//�S���� �����O��
#ifndef CSCENE_HPP
#define CSCENE_HPP
#include "../Define/define.h"
#include "glut.h"
#include <stdio.h>

class CScene{
private:
	static CScene *mScene;
public:
	//�V�[�����ɐݒ�@���т͗���̏���
		enum eSceneNo{
			E_TITLE,
			E_SELECT,
			E_GAMEMAIN,
			E_GAMECLEAR,
			E_GAMEOVER
		};
	static CScene *GetInstance(); //GetInstance
			void ChangeScene(eSceneNo no);	//�V�[���؂�ւ�
			void DeleteScene();			//KILL
	virtual	void Update(){};	//virtual�@
	virtual	void Render(){};
};

#endif