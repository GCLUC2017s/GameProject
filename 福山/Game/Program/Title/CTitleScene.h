//�^�C�g���̃v���O���~���O
//�S���ҁ@�����O��

#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include "../Map/CMap.h"
#include "../Scene/CScene.h"
#include "../SceneManager/CSceneManager.h"
#include "../Explain/CExplain.h"

class CTitleScene :public CScene{
private:
	CMap mMap;
	CTitle mTitle;
	CExplain mExplain;
	CRectangle mRectFilter;
	CTexture *mFilterTex;

	float mCount;	//�X�N���[�����o�̂���

	int status = E_TITLE_SCENE;		//�X�e�[�^�X

	float mFirstX;	//��ʃX�N���[�����̈ړ��Ɏg���܂��B

	float mSave;		//�ۑ��p�ł��B


	float	mLeftSc;		//���X�N���[���p
	float	mRightSc;	//�E�X�N���[���p

	/*�t�F�[�h,�t�F�[�h�A�E�g,���Ȃ��ȈՃV�[���Ǘ�����*/
	enum MyFade
	{
		E_FADE,E_FADEOUT,E_NOFADE
	};
	MyFade mStarusFade = E_NOFADE;
	enum MyEnum
	{
		E_TITLE_SCENE,
		E_EXPLAIN_SCENE

	};


	void Init();
	void Update();
};
#endif