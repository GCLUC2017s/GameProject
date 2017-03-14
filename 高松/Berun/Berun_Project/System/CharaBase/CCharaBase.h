/*
* @file		CCharaBase.h
* @brief	�L�����N�^�[(�G�E����)�̊�{�@�\
*
* @author	Ryoji Anzai
*/

#ifndef CHARABASE_INCLUDE_GUARD
#define CHARABASE_INCLUDE_GUARD
#include "../Base/CBase.h"

#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

//�L�����N�^�[�̊�b�\����
struct T_CharacterData {
	char imageName[64];
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
//�v���C���[�̍\����
struct T_PlayerData
{
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
};
//�G�̍\����
struct T_EnemyData
{
	int m_id;		//ID
	int maxHp;		//�ő�HP
	int hp;			//����HP
	int power;		//�U����
	int defense;	//�h���
	int xp;			//�o���l
	float speed;	//�ړ����x
};
class CCharaBase : public CBase
{
protected:
	enum ESTATE{
		eState_Idle,
		eState_Jump,
	};
	ESTATE m_state;
	CImage *m_chara;

	T_CharacterData  *mp_eData;

	//�L�����N�^�[�̃T�C�Y���i�[����ϐ�
	int m_charaWidth;
	int m_charaHeight;
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
	//�L�����N�^�[�̌������i�[����t���O
	bool m_charaDirection;

	bool m_right;
	virtual void _key();
	void _idle();
public:
	CCharaBase(int type);
	~CCharaBase();
	void Animation();
	void Update();
	void Draw();
	void HitCheck();
};
extern T_PlayerData g_playerData[];
extern T_EnemyData g_enemyData[];
#endif