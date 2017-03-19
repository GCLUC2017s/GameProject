/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l&�����O��
*/
#ifndef CENEMY01_HPP
#define CENEMY01_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#define FLAME_LIMIT 6 //�t���[�����̏��

const	 CVector2 Enemy01_first_pos
= CVector2(character_limit_left*0.85, (character_limit_top + character_limit_bottom) / 2);	//�G�l�~�[�̏����ʒu

class  CEnemy01 : public CBase
{
private:

	float mVelocity;//�ړ�����Ƃ��Ɏg��
	CRectangle	mEnemy01;
	CRectangle  mShadow;

	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/
	enum MyEnum
	{
		E_STAY_L, E_STAY_R,
		E_FLY_L, E_FLY_R,
		E_RUN_L, E_RUN_R,
		E_ATTACK_L, E_ATTACK_R,
		E_DIE_L, E_DIE_R
	};
	//const int mStatus;
	MyEnum eAnime = E_STAY_R;
	int AnimePattern;				//�S�̂̃A�j���[�V�����p�^�[��
	int mSaveAnime;					 //���O�̃A�j�����������f�p
	int mFlameCount;				//�t���[�����J�E���g�p
	int mAnime;						//�A�j���[�V�����̃t���[����
	CVector2 mTarget;	
	CVector2 mSuvePos;				//�������ʒu�̕ۑ�
	int direction;

	/*�A�j���[�V�����̒l������,�����ŉE���𔻒f R��*/
	void DecisionRL(int R, int L){};

	void Walk(){};
	void AnimeFlame();
	void SetPos();

public:
	CEnemy01();
	~CEnemy01();
	void Init();
	void Render();
	void Update();

};

#endif