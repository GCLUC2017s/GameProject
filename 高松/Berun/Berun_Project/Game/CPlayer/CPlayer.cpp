#include "CPlayer.h"

CPlayer::CPlayer(int type) : CCharaBase(type, eUDP_Player,eDWP_Player)
{
}
CPlayer::~CPlayer()
{

}

void CPlayer::Key() {
	CCharaBase::Key();
	
	
	if (CInput::GetState(0, CInput::eHold, CInput::eRight))
	{
		m_pos = CVector3D(0, 0, 0);
		m_right = true;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft))
	{
		m_left = true;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eUp))
	{
		m_up = true;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown))
	{
		m_down = true;
	}
}

