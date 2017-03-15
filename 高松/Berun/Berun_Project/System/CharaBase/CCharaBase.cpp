#include "CCharaBase.h"
static T_CharacterData g_characterData[eCharacterMax] = {
	//ID,レベル、最大HP,現在HP,最大SP,現在SP,攻撃力,防御力,取得経験値,必要経験値,移動速度,ジャンプ力 (11)
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
	if (m_right)
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

