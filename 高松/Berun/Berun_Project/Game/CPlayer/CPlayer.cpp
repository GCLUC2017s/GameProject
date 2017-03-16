#include "CPlayer.h"

CPlayer::CPlayer(int type) : CCharaBase(type, eUDP_Player, eDWP_Player)
{
	m_pos = CVector3D(0, 0, 0);
}
CPlayer::~CPlayer()
{

}

void CPlayer::Key() {
	CCharaBase::Key();
	//�ȉ��A�㉺���E�̃L�[����͂���΂���ɉ����ăt���O���؂�ւ��
	if (HOLD_KEY_UP)	m_up = true;
	if (HOLD_KEY_DOWN)	m_down = true;
	if (HOLD_KEY_LEFT)	m_left = true;
	if (HOLD_KEY_RIGHT)	m_right = true;
	//���炩�̈ړ��L�[����͂��Ă���΁A��Ԃ�����ɐݒ肷�鏈��
	if (HOLD_KEY_UP || HOLD_KEY_DOWN || HOLD_KEY_LEFT || HOLD_KEY_RIGHT)	m_state = eState_Move;
	else m_state = eState_Idle;
	//�V�t�g�L�[����͂��Ă���΁A��Ԃ��_�b�V���ɐݒ肷�鏈��
	if (HOLD_KEY_SHIFT)	m_dash = true;
	else m_dash = false;
	if (m_dash) m_dashSpeed = 2;
	else m_dashSpeed = 1;
}
