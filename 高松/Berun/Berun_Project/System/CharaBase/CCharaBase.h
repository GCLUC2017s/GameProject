/*
* @file		CCharaBase.h
* @brief	�L�����N�^�[(�G�E����)�̊�{�@�\
*
* @author	Ryoji Anzai
*/

#ifndef CHARABASE_INCLUDE_GUARD
#define CHARABASE_INCLUDE_GUARD
#include "../Base/CBase.h"

#define CHARA_MOVE 4

//�L�����N�^�[�̊�b�\����
struct T_CharacterData {
	char imageName[64];
	int id;			//ID
	int level;		//���x��
	int maxHp;		//�ő�HP
	int hp;			//����HP
	int maxSp;		//�ő�SP
	int sp;			//����SP
	int power;		//�U����
	int defense;	//�h���
	int xp;			//�擾�o���l
	int exp;		//�K�v�o���l
	float speed;	//�ړ����x
	float jump;		//�W�����v��
	float xSize;	//X�T�C�Y
	float ySize;	//Y�T�C�Y
};
enum {
	ePlayerMan,	//�v���C���[�j
	ePlayerWoman,//�v���C���[��
	eCarrot,//�j���W��
	ePapurika,//�s�[�}��
	eBerry,//�C�`�S�T���O���X��
	eStrawberry,//�C�`�S�n��
	eVegetavelboss,//��؃{�X�i�E�T�M�j
	ePig,//��
	eBird,//��
	eMeatboss,//���{�X�i�{�j
	eSquid,//�C�J
	eFish,//��
	eFishboss,//����{�X�i�L�j
	eRice,//��
	eBread,//�p��
	eGrainboss,//�����{�X�i���q���m�j
	eCharacterMax
};

class CCharaBase : public CBase
{
protected:
	enum ESTATE{
		eState_Idle,
		eState_Walk,
		eState_Dash,
		eState_Jump,
		eState_Attack,
		
	};
	ESTATE m_state;
	CImage *m_chara;
	CImage *m_enemyHp;

	T_CharacterData  *mp_eData;

	
	int m_imgPtn;
	//�L�����N�^�[�̃��x��
	int   m_level;
	//�L�����N�^�[�̍ő�̗�
	int   m_maxHp;
	//�L�����N�^�[�̗̑�
	int   m_hp;
	//�L�����N�^�[�̍ő�X�L���|�C���g
	int   m_maxSp;
	//�L�����N�^�[�̃X�L���|�C���g
	int   m_sp;
	//�L�����N�^�[�̍U����
	int   m_power;
	//�L�����N�^�[�̖h���
	int   m_defence;
	//�L�����N�^�[�̌��݌o���l
	int   m_xp;
	//�L�����N�^�[�̕K�v�o���l
	int   m_exp;
	//�L�����N�^�[�̃X�s�[�h
	float m_speed;
	//�L�����N�^�[�̃W�����v��
	float m_jump;
	float m_xSize;//�L�����N�^�[��X�T�C�Y
	float m_ySize;//�L�����N�^�[��Y�T�C�Y
	//�L�����N�^�[�̌������i�[����t���O
	bool m_charaDirection;
	bool m_right;
	bool m_left;
	bool m_up;
	bool m_down;
	virtual void Key();
	void Idle();
	void Walk();
	void Dash();
	void Jump();
	void HpBar();
public:
	CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio);
	~CCharaBase();
	void Animation();
	void Update();
	void Draw();
	void HitCheck();
};

#endif