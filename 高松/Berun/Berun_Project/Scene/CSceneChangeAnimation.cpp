#include "CSceneChangeAnimation.h"

CSceneChangeAnimation::CSceneChangeAnimation() : 
	m_type(eFade)
{
	m_image.Load("Black");
}

void CSceneChangeAnimation::Draw(float t)
{
	CRect rect = CCamera::GetCurrent()->GetScreenRect();
	switch(m_type)
	{
	case eFade:
		//            (R,G,B,“§–¾“x)
		m_image.SetColor(1,1,1,t);
		m_image.SetSize(rect.m_right,rect.m_bottom);
		m_image.Draw();
		break;
	}			
}