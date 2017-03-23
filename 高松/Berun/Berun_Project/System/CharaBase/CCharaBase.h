/*
* @file		CCharaBase.h
* @brief	�L�����N�^�[(�G�E����)�̊�{�@�\
*
* @author	Ryoji Anzai
*/

#ifndef CHARABASE_INCLUDE_GUARD
#define CHARABASE_INCLUDE_GUARD
#include "../Base/CBase.h"
#include "../Game/Item/CItem.h"

#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))
#define NORMAL_SPEED 1
#define DASH_SPEED 2
#define ANIM_REVISION 1
#define DAMAGE_TIME 2
#define WINDOW_UP_LIMIT	600
#define WINDOW_DOWN_LIMIT 100
#define WINDOW_LEFT_LIMIT 50
#define FLASH_INTERBAL MILLI_SECOUND(0.2f)


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
	int charaType;	//�L�����̃^�C�v
	SVector2D size;
	T_AnimData *animData;
	SVector2D texSize;
	SVector2D senter;	//�L�����N�^�[�̒��S�_
	CRect rect;			//�L�����N�^�[�̋�`
};
enum {
	ePlayerMan,	//�v���C���[�j
	ePlayerWoman,//�v���C���[��
	eCarrot,//�j���W��
	eChick,//��
	eFish,//��
	ePig,//��
	eVegetavelboss,//��؃{�X�i�E�T�M�j
	eBerry,//�C�`�S�T���O���X��
	ePapurika,//�s�[�}��
	eStrawberry,//�C�`�S�n��
	eMeatboss,//���{�X�i�{�j
	eSquid,//�C�J
	eFishboss,//����{�X�i�L�j
	eRice,//��
	eBread,//�p��
	eGrainboss,//�����{�X�i���q���m�j
	eCharacterMax
};

class CCharaBase : public CBase, public CCollisionA
{
protected:
	enum ESTATE{
		eState_Jump,
		eState_Move,
		eState_Attack,
		eState_Damage,
		eState_Down
	};
	enum EANIM {
		eAnim_Idle,
		eAnim_Walk,
		eAnim_Dash,
		eAnim_Jump,
		eAnim_Attack,
		eAnim_Down,
	};
	ESTATE m_state;
	CImage *m_chara;
	CImage *m_enemyHp;
	CImage *m_red;
	
	const T_CharacterData  *mp_eData;
	
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
	//�A�j���[�V���������[�v�����邩�ǂ������i�[����ϐ�(false = No,true = Yes)
	int m_animLoop;
	//�A�j���[�V�����̐؂�ւ��J�E���^�[
	int m_animCounter;
	//�_�b�V�����鎞�̃X�s�[�h
	int m_dashSpeed;
	int m_flashTyming;
	//�_���[�W���󂯂Ă��邩�ǂ������i�[����ϐ�
	bool m_damage;
	//�_���[�W���֐��̒ʉ߂����߂Ă��ǂ������i�[����ϐ�
	bool m_damageFirst;
	//�_���[�W�����ǂ��瑤����󂯂������i�[����֐�(false = ��,true = �E)
	bool m_damageDirection;
	//�_���[�W���󂯂���̖��G���Ԃ��i�[����ϐ�
	int m_damageTime;
	int m_type;
	CVector3D m_oldPos;

	unsigned int m_anim;
	//�L�����N�^�[�̌������i�[����t���O
	bool m_charaDirection;
	bool m_right;
	bool m_left;
	bool m_up;
	bool m_down;
	bool m_jump;
	//�_�b�V�������ǂ������i�[����ϐ�(false = No,true = Yes)
	bool m_dash;
	//�W�����v�����ǂ������i�[����ϐ�(false = No,true = Yes)
	bool m_jumpFlag;
	bool m_attack;
	bool m_death;
	void ResetKey();
	virtual void Contlol();
	void Move();
	void Jump();
	void Attack();
public:
	CCharaBase(int type, int id, unsigned int updatePrio, unsigned int drawPrio);
	~CCharaBase();
	void Animation();
	void ChangeAnimation(EANIM type,bool loop);
	void Update();
	virtual void Draw(); 
	virtual void HitCallBack(CCollisionA * p);
	bool CheckHit(CCollisionA *t);
	void Damage();
	virtual void Down();
	CVector3D GetPos()
	{
		return m_pos;
	}
	int GetAttack()
	{
		return m_power;
	}
	int CheckType()
	{
		return m_type;
	}
	int CheckState()
	{
		return m_state;
	}
	bool GetDeath()
	{
		return m_death;
	}

};
#endif