#include "CPlayer.h"

CPlayer::CPlayer(int type) : CCharaBase(type, eUDP_Player,eDWP_Player)

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
	//�W�����v���ȊO�ɉ��炩�̈ړ��L�[����͂��Ă���΁A��Ԃ�����ɐݒ肷�鏈��
	
	//�V�t�g�L�[����͂��Ă���΁A��Ԃ��_�b�V���ɐݒ肷�鏈��
	if (HOLD_KEY_SHIFT)	m_dash = true;
	else m_dash = false;
	//�W�����v���Ă��Ȃ����ɃX�y�[�X�L�[����͂�����A��Ԃ��W�����v�ɂ��鏈��
	if (PUSH_KEY_SPASE)
	{
		m_jump = true;
	}
}
