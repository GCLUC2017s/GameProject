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
#define CHARA_MOVE 4
#define ANIM_REVISION 1

struct T_AnimData {
	int pattrn;
	int speed;
};
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
	T_AnimData *animData;
};
enum {
	ePlayerMan,	//�v���C���[�j
	ePlayerWoman,//�v���C���[��
	eCarrot,//�j���W��
	eBerry,//�C�`�S�T���O���X��
	ePapurika,//�s�[�}��
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
		eState_Jump,
		eState_Move,
		eState_Attack,
		
	};
	enum {
		eAnim_Walk,
		eAnim_Idle,
		eAnim_Attack,
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
	//�A�j���[�V�����p�^�[���̉��s�ڂ����i�[����ϐ�
	int m_animPaternX;
	//�A�j���[�V�����p�^�[���̉���ڂ����i�[����ϐ�
	int m_animPaternY;
	//�A�j���[�V�����̐؂�ւ��J�E���^�[
	int m_animCounter;
	//�_�b�V�����鎞�̃X�s�[�h
	int m_dashSpeed;
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
	//�_�b�V�������ǂ������i�[����ϐ�(false = No,true = Yes)
	bool m_dash;
	//�W�����v���鎞�ɑ����Ă������ǂ������i�[����ϐ�(false = No,true = Yes)
	bool m_jumpInDash;
	//�W�����v�����ǂ������i�[����ϐ�(false = No,true = Yes)
	bool m_jumpFlag;
	virtual void Key();
	void Idle();
	void Move();
	void Jump();
	void HpBar();
public:
	CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio);
	~CCharaBase();
	void Animation();
	void Update();
	virtual void Draw();
	void HitCheck();
};

#endif