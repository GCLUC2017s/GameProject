#include "CCharaBase.h"
<<<<<<< HEAD
<<<<<<< HEAD
static T_CharacterData g_characterData[eCharacterMax] = {
=======
static T_CharacterData g_characterData[eCharacterMax] = 
{
>>>>>>> 8fa733087e86287f408b565c59a7cbfe1fdf32e0
=======
const static T_CharacterData g_characterData[eCharacterMax] = 
{
>>>>>>> 8e40ae93fa263e291e501221197bd4f145d23183
	//ID,レベル、最大HP,現在HP,最大SP,現在SP,攻撃力,防御力,取得経験値,必要経験値,移動速度,ジャンプ力,Xサイズ,Yサイズ(13)
	{ "LittlePlayerM",0,5,0,0,0,0,0,0,0,1,0, },
	{ "LittlePlayerW",1,5,0,0,0,0,0,0,0,1,0, },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,0 },
	{ "Chick",3,5,0,0,0,0,0,0,0,1,0,0,0 },
	{ "Fish",4,5,0,0,0,0,0,0,0,1,0,0,0 },
	{ "Rice",5,5,0,0,0,0,0,0,0,1,0,0,0 },
<<<<<<< HEAD
<<<<<<< HEAD
	

=======
>>>>>>> 8fa733087e86287f408b565c59a7cbfe1fdf32e0
=======
>>>>>>> 8e40ae93fa263e291e501221197bd4f145d23183
};
CCharaBase::CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio) : CBase(updatePrio, drawPrio)
{
	m_state = eState_Idle;
<<<<<<< HEAD
<<<<<<< HEAD
=======
	mp_eData = &g_characterData[type];
>>>>>>> 8fa733087e86287f408b565c59a7cbfe1fdf32e0
=======
	mp_eData = &g_characterData[type];
>>>>>>> 8e40ae93fa263e291e501221197bd4f145d23183
	m_chara = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(mp_eData->imageName));
	m_imgPtn = 0;
	m_level= mp_eData->level;
	m_maxHp = mp_eData->maxHp;
	m_hp=mp_eData->hp;
	m_maxSp = mp_eData->maxSp;
	m_sp=mp_eData->sp;
	m_power=mp_eData->power;
	m_defence=mp_eData->defense;
	m_xp=mp_eData->xp;
	m_exp=mp_eData->exp;
	m_speed=mp_eData->speed;
	m_jump=mp_eData->jump;
<<<<<<< HEAD
<<<<<<< HEAD
	m_xsize=mp_eData->xsize;
	m_ysize=mp_eData->ysize;
=======
	m_xSize=mp_eData->xSize;
	m_ySize=mp_eData->ySize;
>>>>>>> 8fa733087e86287f408b565c59a7cbfe1fdf32e0
=======
	m_xSize=mp_eData->xSize;
	m_ySize=mp_eData->ySize;
>>>>>>> 8e40ae93fa263e291e501221197bd4f145d23183
	m_charaDirection = false;
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
}
CCharaBase::~CCharaBase() 
{
	CResourceManager::GetInstance()->Delete(mp_eData->imageName);
	CResourceManager::ClearInstance();
}
void CCharaBase::Animation()
{

}
<<<<<<< HEAD
<<<<<<< HEAD
void CCharaBase::_key() {
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
=======
void CCharaBase::Key()
{
	m_left = false;
	m_up = false;
	m_down = false;
=======
void CCharaBase::Key()
{
<<<<<<< HEAD
	m_left = false;
	m_up = false;
	m_down = false;
>>>>>>> 8e40ae93fa263e291e501221197bd4f145d23183

=======
>>>>>>> ce39bbbcd3e70e8aca0ce261ae5601c6457c7971
	if (CInput::GetState(0, CInput::ePush, CInput::eUp)) m_up = true; 
	if (CInput::GetState(0, CInput::ePush, CInput::eDown)) m_down = true;
	if (CInput::GetState(0, CInput::ePush, CInput::eLeft)) m_left = true;
	if (CInput::GetState(0, CInput::ePush, CInput::eRight)) m_right = true;
	if (CInput::GetState(0, CInput::ePush, CInput::eUp) || CInput::GetState(0, CInput::ePush, CInput::eDown)
		|| CInput::GetState(0, CInput::ePush, CInput::eLeft) || CInput::GetState(0, CInput::ePush, CInput::eRight)) m_state = eState_Walk;

<<<<<<< HEAD
>>>>>>> 8fa733087e86287f408b565c59a7cbfe1fdf32e0
=======
>>>>>>> 8e40ae93fa263e291e501221197bd4f145d23183
}
void CCharaBase::Idle(){
	Animation();


}
void CCharaBase::Walk()
{
	//上キー(W)を入力した時の処理
	if (m_up)
	{
		m_pos.z += CHARA_MOVE;
	}
	//下キー(S)を入力した時の処理
	if (m_down)
	{
		m_pos.z += CHARA_MOVE;
	}
	//左キー(A)を入力した時の処理
	if (m_left)
	{
		//キャラのX座標にマイナス値(左方向の値)を加算していく処理
		m_pos.x += -CHARA_MOVE;
		//キャラの方向フラグを左向きの状態にする
		m_charaDirection = true;
	}
	//右キー(D)を入力した時の処理
	if (m_right)
	{
		//キャラのX座標にプラス値(右方向の値)を加算していく処理
		m_pos.x += CHARA_MOVE;
		//キャラの方向フラグを右向きの状態にする
		m_charaDirection = false;
	}
}
void CCharaBase::Dash()
{

}
void CCharaBase::Jump()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1))
	{
		m_gravitySpeed += 20;
		m_state = eState_Jump;
	}
	if (m_pos.y <= 0) m_state = eState_Idle;
}
void CCharaBase::HpBar()
{

}
void CCharaBase::Update()
{
	Key();
	switch (m_state)
	{
	case eState_Idle:
		Idle();
		break;
	case eState_Walk:
		Walk();
		break;
	case eState_Dash:
		Dash();
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

