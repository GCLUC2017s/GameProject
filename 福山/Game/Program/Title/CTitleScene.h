//�^�C�g���̃v���O���~���O
//�S���ҁ@�����O��

#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include "../Map/CMap.h"
#include "../Scene/CScene.h"
#include "../SceneManager/CSceneManager.h"
class CTitleScene :public CSceneManager{
private:
	CMap mMap;
	CTitle mTitle;
	CRectangle mFade;	//�A���[�g�\���l�p�`
	
	float count;	//�X�N���[�����o�̂���

	int status;		//�X�e�[�^�X

	float FirstX;	//��ʃX�N���[�����̈ړ��Ɏg���܂��B

	float Save;		//�ۑ��p�ł��B

	float alpha;	//�A���t�@�`�����l���Ɏg���܂� 

	//void FadeDisp(); //�t�F�[�h�C���œǂݍ��݂��Y��ɂ���ׂɎg�p�@alpha�����X�ɉ�����B

	void Init();
	void Update();
};
#endif