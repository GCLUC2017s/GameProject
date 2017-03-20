#include "CCollisionA.h"

bool CCollisionA::CheckHit(CBase *p, CBase *t)
{
	CRect p_rect=p->GetRect();
	CRect t_rect=t->GetRect();	
	if (p_rect.m_right > t_rect.m_left && p_rect.m_left < t_rect.m_right && p_rect.m_top < t_rect.m_bottom && p_rect.m_bottom > t_rect.m_top) {
		printf("“–‚½‚è‚Ü‚µ‚½B\n");
		return true;
	}
	else return false;
}