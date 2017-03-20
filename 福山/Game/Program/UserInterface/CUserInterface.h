/*
UI�̃v���O����

�S���ҁ@�y�c���l
*/
#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include "../Graphic/CRectangle.h"
#include "../Graphic/CTexture.h"
#include "../Task/CTask.h"
#include "../Define/define.h"
#define HP_ST 2 //HP��ST
#define HUNG_HLN	3//���Ȃ��̌���	hungry_high_low_normal�̗�

class  CUserinterface : public CTask
{
private:
	/*PLAYER��gauge��Rect*/
	CRectangle  mGaugePlayer[HP_ST];
	CRectangle  mFramePlayer[HP_ST];
	/*�G�l�~�[��gauge��Rect*/
	CRectangle mGaugeEne;
	CRectangle mFrameEne;
	/*PLAYER�̃e�N�X�`��*/
	CTexture  *mPlayerGageTex[HP_ST];
	CTexture  *mPlayerFrameHpTex;
	CTexture  *mPlayerFrameStTex[HUNG_HLN];
	/*�G�l�~�[�̃e�N�X�`��*/
	CTexture  *mEnemyGageTex;
	CTexture  *mEnemyFrameTex;

	CVector2 mPos;			//�l�p�̃|�W�W����
	float savex;			//PLAYER��gauge�����p
	CTask *task;
	
public:
	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/
	 CUserinterface();
	~ CUserinterface();
	void Init();
	void Update();
	void Render();
};


#endif