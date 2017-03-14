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

	//上キー(W)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eUp))
	{
		m_pos.z += 4;
	}
	//下キー(S)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eDown))
	{
		m_pos.z += -4;
	}
	//左キー(A)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft))
	{
		//キャラのX座標にマイナス値(左方向の値)を加算していく処理
		m_pos.x += -4;
		//キャラの方向フラグを左向きの状態にする
		m_charaDirection = true;
	}
	//右キー(D)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eRight))
	{
		//キャラのX座標にプラス値(右方向の値)を加算していく処理
		m_pos.x += 4;
		//キャラの方向フラグを右向きの状態にする
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
	//ID,最大HP,現在HP,攻撃力,防御力,経験値,移動速度
	{ 0,0,0,0,0,0,0.0f },
};
#define E_ARRAY_SIZE(g_enemyData);