#include "CBase.h"

T_PlayerData g_playerData[] =
{
	//ID,���x��,�ő�HP,����HP,�ő�SP,����SP,�U����,�h���,�擾�o���l,�K�v�o���l,�ړ����x,�W�����v��
	{ 0,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
	{ 1,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
};

T_EnemyData g_enemyData[] =
{
	//ID,�ő�HP,����HP,�U����,�h���,�o���l,�ړ����x
	{ 0,0,0,0,0,0,0.0f},
};

CBase::CBase() : mp_pData(nullptr),mp_eData(nullptr),m_id(0),m_level(0),
				 m_maxHp(0),m_hp(0),m_maxSp(0),m_sp(0),m_power(0),
				 m_defence(0),m_xp(0),m_exp(0),m_speed(0.0f),m_jump(0.0f)
{
}

CBase::~CBase()
{
}
