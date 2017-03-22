#include "CPlayer.h"

CPlayer* CPlayer::mp_player=nullptr;
CPlayer::CPlayer(int type) : CCharaBase(type, ePlayer, eUDP_Player,eDWP_Player)

{
	m_pos = CVector3D(100, 0, 400);
	mp_hp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("HP"));
	mp_sp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("SP"));
	mp_shadow = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("SHADOW"));
	mp_player = this;
}
CPlayer::~CPlayer()
{

}

void CPlayer::Draw()
{
	for (int i = 0; i < m_hp; i++)
	{
		mp_hp->SetPos(i * 75 + 10, 25);
		mp_hp->SetSize(75, 75);
		mp_hp->Draw();
	}
	for (int j = 0; j < m_sp; j++)
	{
		mp_sp->SetPos(j * 75 + 400, 25);
		mp_sp->SetSize(75, 75);
		mp_sp->Draw();
	}
	mp_shadow->SetPos(GetScreenPos(CVector3D(m_pos.x, 0, m_pos.z)));
	mp_shadow->SetCenter(35,15);
	mp_shadow->Draw();
	CCharaBase::Draw();
}

void CPlayer::Contlol() {
	CCharaBase::ResetKey();
	//�ȉ��A�㉺���E�̃L�[����͂���΂���ɉ����ăt���O���؂�ւ��
	if (HOLD_KEY_UP)	m_up = true;
	if (HOLD_KEY_DOWN)	m_down = true;
	if (HOLD_KEY_LEFT)	m_left = true;
	if (HOLD_KEY_RIGHT)	m_right = true;
	//�W�����v���A�_���[�W���ȊO�ɉ��炩�̈ړ��L�[����͂��Ă���΁A��Ԃ�����ɐݒ肷�鏈��
	if (m_state != eState_Jump && m_state != eState_Damage)
	{
		if (HOLD_KEY_UP || HOLD_KEY_DOWN || HOLD_KEY_LEFT || HOLD_KEY_RIGHT)	m_state = eState_Move;
	}
	//�V�t�g�L�[����͂��Ă���΁A��Ԃ��_�b�V���ɐݒ肷�鏈��
	if (HOLD_KEY_SHIFT)	m_dash = true;
	else m_dash = false;
	if (m_dash) m_dashSpeed = DASH_SPEED;
	else m_dashSpeed = WALK_SPEED;
	//�X�y�[�X�L�[����͂�����A��Ԃ��W�����v�ɂ��鏈��
	if (PUSH_KEY_SPASE)		m_jump = true;
	if (PUSH_KEY_ENTER)		m_attack = true;
}

void CPlayer::HitCallBack(CCollisionA * p)
{
	CCharaBase::HitCallBack(p);
	CCharaBase* tt = dynamic_cast<CCharaBase*>(p);

	if (m_state != eState_Attack && tt)
	{
		if (!m_damage)
		{
			m_hp--;
			if (!m_hp);
			if (m_pos.x < tt->GetPos().x)	m_damageDirection = true;
			if (m_pos.x > tt->GetPos().x)	m_damageDirection = false;
		}
		m_damage = true;
	}
}