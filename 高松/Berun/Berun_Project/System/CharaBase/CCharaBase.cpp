#include "CCharaBase.h"

CCharaBase::CCharaBase(int type):m_state(eState_Idle)
{
	m_chara = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("LittlePlayerM"));
}
CCharaBase::~CCharaBase() 
{

}
void CCharaBase::Animation()
{

}
void CCharaBase::_idle(){

	//��L�[(W)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eUp))
	{
		m_pos.z += 4;
	}
	//���L�[(S)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eDown))
	{
		m_pos.z += -4;
	}
	//���L�[(A)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft))
	{
		//�L������X���W�Ƀ}�C�i�X�l(�������̒l)�����Z���Ă�������
		m_pos.x += -4;
		//�L�����̕����t���O���������̏�Ԃɂ���
		m_charaDirection = true;
	}
	//�E�L�[(D)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eRight))
	{
		//�L������X���W�Ƀv���X�l(�E�����̒l)�����Z���Ă�������
		m_pos.x += 4;
		//�L�����̕����t���O���E�����̏�Ԃɂ���
		m_charaDirection = false;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1))
	{
		m_gravitySpeed += 20;
		m_state = eState_Jump;
	}
}
void CCharaBase::Update()
{
	switch (m_state)
	{
	case eState_Idle:
		_idle();
		break;
	case eState_Jump:
		if (m_pos.y <= 0) m_state = eState_Idle;
		break;
	}
	m_gravitySpeed += GRAVITY;
	m_pos.y += m_gravitySpeed;
	if (m_pos.y < 0)
	{
		m_pos.y = 0;
		m_gravitySpeed = 0;
	}

}
void CCharaBase::Draw()
{
	m_chara->SetCenter(64,128);
	m_chara->SetSize(128,128);
	m_chara->SetPos(GetScreenPos());
	m_chara->SetFlipH(m_charaDirection);
	m_chara->Draw();
}
void CCharaBase::HitCheck()
{

}

#define P_ARRAY_SIZE(g_playerData);

T_EnemyData g_enemyData[] =
{
	//ID,�ő�HP,����HP,�U����,�h���,�o���l,�ړ����x
	{ 0,0,0,0,0,0,0.0f },
};
#define E_ARRAY_SIZE(g_enemyData);