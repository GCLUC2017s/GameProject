#include "CPlayer.h"

T_PlayerData g_playerData[] =
{
	//ID,���x��,�ő�HP,����HP,�ő�SP,����SP,�U����,�h���,�擾�o���l,�K�v�o���l,�ړ����x,�W�����v��
	{ 0,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
	{ 1,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
};
CPlayer::CPlayer(int type):CCharaBase(0)
{
	mp_pData = &g_playerData[type];
	
	m_hp = mp_pData->hp;
	
}
CPlayer::~CPlayer()
{

}


