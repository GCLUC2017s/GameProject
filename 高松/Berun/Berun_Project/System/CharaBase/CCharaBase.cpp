#include "CCharaBase.h"
static T_CharacterData g_characterData[eCharacterMax] = {
	//ID,���x���A�ő�HP,����HP,�ő�SP,����SP,�U����,�h���,�擾�o���l,�K�v�o���l,�ړ����x,�W�����v�� (11)
	{ "LittlePlayerM" },
	{ "LittlePlayerM" },
	{ "CarrotLeft",5,5,0,0,0,0,0,0,0,1,0,},
	
	

};
CCharaBase::CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio) : CCharaBase(type, eUDP_Null, eDWP_Null)
{
	m_state = eState_Idle;
	mp_eData = &g_characterData[type];
	m_chara = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(mp_eData->imageName));
}
CCharaBase::~CCharaBase() 
{

}
void CCharaBase::Animation()
{

}
void CCharaBase::_key() {
	m_right = false;
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
	if (m_right)
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
	_key();
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

