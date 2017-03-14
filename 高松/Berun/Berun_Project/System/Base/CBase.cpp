#include "CBase.h"

CBase::CBase() :CTask(0,0), m_gravitySpeed(0), m_pos(0, 0, 0) {

}
CBase::~CBase()
{
}

CVector2D CBase::GetScreenPos()
{
	CVector2D p;
	p.x = m_pos.x;
	p.y = 720 - m_pos.z*0.5;
	p.y -= m_pos.y;
	return p;
}