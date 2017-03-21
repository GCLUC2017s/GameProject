#include "CBase.h"



CVector2D CBase::m_scroal(0,0);
CBase::CBase() :CTask(0,0,0), m_gravitySpeed(0), m_pos(0, 0, 0) {

}
CBase::CBase(int id, unsigned int updatePrio, unsigned int drawPrio) : CTask(id,updatePrio,drawPrio)
{
}
CBase::~CBase()
{
}

CVector2D CBase::GetScreenPos()
{
	CVector2D m_player;
	m_player.x = m_pos.x;
	m_player.y = 720 - m_pos.z*0.5;
	m_player.y -= m_pos.y;
	return m_player - m_scroal;
}

CVector2D CBase::GetScreenPos(CVector3D pos)
{
	CVector2D m_player;
	m_player.x = pos.x;
	m_player.y = 720 - pos.z*0.5;
	m_player.y -= pos.y;
	return m_player - m_scroal;
}