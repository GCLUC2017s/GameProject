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
	CVector2D p;
	p.x = m_pos.x;
	p.y = 720 - m_pos.z*0.5f;
	p.y -= m_pos.y;
	return p - m_scroal;
}