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
	//以下、上下左右のキーを入力すればそれに応じてフラグが切り替わる
	if (HOLD_KEY_UP)	m_up = true;
	if (HOLD_KEY_DOWN)	m_down = true;
	if (HOLD_KEY_LEFT)	m_left = true;
	if (HOLD_KEY_RIGHT)	m_right = true;
	//ジャンプ中以外に何らかの移動キーを入力していれば、状態を歩きに設定する処理
	if (m_state != eState_Jump)
	{
		if (HOLD_KEY_UP || HOLD_KEY_DOWN || HOLD_KEY_LEFT || HOLD_KEY_RIGHT)	m_state = eState_Move;
	}
	//シフトキーを入力していれば、状態をダッシュに設定する処理
	if (HOLD_KEY_SHIFT)	m_dash = true;
	else m_dash = false;
	if (m_dash) m_dashSpeed = DASH_SPEED;
	else m_dashSpeed = WALK_SPEED;
	//スペースキーを入力したら、状態をジャンプにする処理
	if (PUSH_KEY_SPASE)		m_jump = true;

}
