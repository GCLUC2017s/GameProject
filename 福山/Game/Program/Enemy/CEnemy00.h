/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l&�����O��
*/
#ifndef CENEMY00_HPP
#define CENEMY00_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#include"../Player/CPlayer.h"

#define FLAME_LIMIT 6 //�t���[�����̏��


const	 CVector2 Enemy00_first_pos
= CVector2(character_limit_left*0.55, (character_limit_top + character_limit_bottom) / 2);	//�G�l�~�[�̏����ʒu
//���݂̓}�b�v���̂̍��[�����Ĕz�u���Ă���B

class  CEnemy00 : public CBase
{
private:

	float mVelocity;//�ړ�����Ƃ��Ɏg��

	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/
	enum MyEnum
	{
		E_STAY_L, E_STAY_R,
		E_WALK_L, E_WALK_R,
		E_RUN_L, E_RUN_R,
		E_ATTACK_L, E_ATTACK_R,
		E_DIE_L, E_DIE_R
	};

	//const int mStatus;
	int AnimePattern;				//�S�̂̃A�j���[�V�����p�^�[��
	int mSaveAnime; //���O�̃A�j�����������f�p
	int mFlameCount;		//�t���[�����J�E���g�p
	int mAnime;		//�A�j���[�V�����̃t���[����

	CVector2 mSuvePos;//�������ʒu�̕ۑ�

	int direction;	//���E�̊ȈՔ��f

	float rulerR; //�G�l�~�[�ƃL�����N�^�[�̋���
	float rulerL; //�G�l�~�[�ƃL�����N�^�[�̋���
	
	bool actionflag; //�A�N�V���������Ă��鎞�͗��Ă�

	float delay;	//�s����̍Ē��I�f�B���C
	
	int motion;		
	int pattern;

	void Walk();
	void SetPos();
	void AnimeScene();

public:
	CEnemy00();
	~CEnemy00();
	void Init();
	void Render();
	void Update();

};

#endif