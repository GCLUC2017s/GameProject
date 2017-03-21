#include "CBase.h"



CVector2D CBase::m_scroal(0,0);
CBase::CBase() :CTask(0,0), m_gravitySpeed(0), m_pos(0, 0, 0) {

}
CBase::CBase(unsigned int updatePrio, unsigned int drawPrio) : CTask(updatePrio,drawPrio)
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
void CBase::HitCallBack(CCollisionA * p)
{
	SetDestroyFlag(true);
}

bool CBase::CheckHit(CCollisionA *t)
{
	CBase* tt = dynamic_cast<CBase*>(t);
	assert(tt);
	CRect p_rect = GetRect();
	CRect t_rect = tt->GetRect();
	if (abs(m_pos.z - tt->m_pos.z) < 50 && p_rect.m_right > t_rect.m_left && p_rect.m_left < t_rect.m_right && p_rect.m_top < t_rect.m_bottom && p_rect.m_bottom > t_rect.m_top) {
		HitCallBack(t);
		t->HitCallBack(this);
	}
	else return false;
}