/**
*@file
*@brief  ���N���X
*@author �R�H
*/

#ifndef CBASE_GUARD
#define CBASE_GUARD

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

class CBase
{
private:
	T_PlayerData *mp_pData;
	T_EnemyData  *mp_eData;
	int   m_id;
	int   m_level;
	int   m_maxHp;
	int   m_hp;
	int   m_maxSp;
	int   m_sp;
	int   m_power;
	int   m_defence;
	int   m_xp;
	int   m_exp;
	float m_speed;
	float m_jump;
public:
	CBase();
	~CBase();
};

extern T_PlayerData g_playerData[];
extern T_EnemyData g_enemyData[];

#endif