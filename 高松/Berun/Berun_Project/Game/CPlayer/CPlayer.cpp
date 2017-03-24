#include "CPlayer.h"

CPlayer* CPlayer::mp_player=nullptr;
CPlayer::CPlayer(int type) : CCharaBase(type, ePlayer, eUDP_Player,eDWP_Player)

{
	m_pos = CVector3D(100, 0, 400);
	mp_hpBar = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("HPBar"));
	mp_hp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("HP"));
	mp_wordHp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("WordHP"));
	mp_halfHp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("HalfHP"));
	mp_noHp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("NoHP"));
	mp_sp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("SP"));
	mp_shadow = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("SHADOW"));
	mp_player = this;
}
CPlayer::~CPlayer()
{

}

void CPlayer::Draw()
{
	mp_hpBar->SetColor(0,0,1,0.7f);
	mp_hpBar->SetSize(600,110);
	mp_hpBar->Draw();
	//HPを表示するための繰り返し文(条件式はiの値がHPの半分(実際に表示する数)を超える、残りのHPが)
	for (int i = 0; i < m_hp / 2 || (m_hp == 1 && i < m_hp) || (!m_hp && i == m_hp); i++)
	{
		//HPの表示処理
		if (m_hp > 1)
		{
			mp_hp->SetPos(i * 75 + 150, 25);
			mp_hp->SetSize(75, 75);
			mp_hp->Draw();
		}
		if (m_hp % 2 || m_hp == 1)
		{
			mp_halfHp->SetPos(m_hp / 2 * 75 + 150, 25);
			if(m_hp == 1)	mp_halfHp->SetPos((m_hp - 1) * 75 + 150, 25);
			mp_halfHp->SetSize(75, 75);
			mp_halfHp->Draw();
		}
		for (int j = m_maxHp - m_hp / 2; j > 0; j--)
		{
			if (m_hp != m_maxHp)
			{
				for (int k = j - m_maxHp / 2; k > 0; k--)
				{
					mp_noHp->SetPos((m_hp / 2 + (k - 1)) * 75 + 150, 25);
					mp_noHp->SetSize(75, 75);
					mp_noHp->Draw();
				}
			}
		}
		mp_wordHp->SetPos(-30, -5);
		mp_wordHp->SetSize(200,130);
		mp_wordHp->Draw();
	}
	if (m_state != eState_Down)
	{
		mp_shadow->SetPos(GetScreenPos(CVector3D(m_pos.x, 0, m_pos.z)));
		mp_shadow->SetCenter(35, 15);
		mp_shadow->Draw();
	}
	CCharaBase::Draw();
}

void CPlayer::Contlol() {
	CCharaBase::ResetKey();
	if (!m_death)
	{
		//以下、上下左右のキーを入力すればそれに応じてフラグが切り替わる
		if (HOLD_KEY_UP)	m_up = true;
		if (HOLD_KEY_DOWN)	m_down = true;
		if (HOLD_KEY_LEFT)	m_left = true;
		if (HOLD_KEY_RIGHT)	m_right = true;
		//ジャンプ中、ダメージ中以外に何らかの移動キーを入力していれば、状態を歩きに設定する処理
		if (m_state != eState_Jump && m_state != eState_Damage)
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
		if (PUSH_KEY_ENTER)		m_attack = true;
	}
}

void CPlayer::HitCallBack(CCollisionA * p)
{
	CCharaBase* tt = dynamic_cast<CCharaBase*>(p);

	if (m_state != eState_Attack && tt)
	{
		if (!m_damage)
		{
			if (tt->CheckState() != eState_Attack)
			{
				//HPを減らす処理
				m_hp--;
				//もしこの瞬間にキャラクターのHPが0ならキャラクターの死亡フラグを真にする処理
				if (!m_hp)	m_death = true;
				if (m_pos.x < tt->GetPos().x)	m_damageDirection = true;
				if (m_pos.x > tt->GetPos().x)	m_damageDirection = false;
			}
			else if (m_state != eState_Attack)
			{
				//HPを減らす処理
				m_hp -= tt->GetAttack();
				//もしこの瞬間にキャラクターのHPが0ならキャラクターの死亡フラグを真にする処理
				if (!m_hp)	m_death = true;
				if (m_pos.x < tt->GetPos().x)	m_damageDirection = true;
				if (m_pos.x > tt->GetPos().x)	m_damageDirection = false;
			}
		}
		m_damage = true;
	}
}