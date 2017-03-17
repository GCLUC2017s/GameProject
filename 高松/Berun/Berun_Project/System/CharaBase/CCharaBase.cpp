#include "CCharaBase.h"
T_AnimData _carrotAnimData[] = {
	{2,5},
	{9,10},
	{5,1},
};
static T_CharacterData g_characterData[] = 
{
	//ID,レベル、最大HP,現在HP,最大SP,現在SP,攻撃力,防御力,取得経験値,必要経験値,移動速度,ジャンプ力,Xサイズ,Yサイズ(13)
	{ "LittlePlayerM",0,5,0,0,0,0,0,0,0,1,0,0,100,140 ,_carrotAnimData,eNone },
	{ "LittlePlayerW",1,5,0,0,0,0,0,0,0,1,0,0, 256,256,_carrotAnimData,eNone },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,160,160 ,_carrotAnimData,eCarrotItem },
	//{ "Chick",3,5,0,0,0,0,0,0,0,1,0,0,0 },
	//{ "Fish",4,5,0,0,0,0,0,0,0,1,0,0,0 },
	//{ "Rice",5,5,0,0,0,0,0,0,0,1,0,0,0 },
};

//static_assert (ARRAY_SIZE(g_characterData) == eCharacterMax,"g_characterDataSizeError");
CCharaBase::CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio) : CBase(updatePrio, drawPrio)
{
	m_state = eState_Idle;
	mp_eData = &g_characterData[type];
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
	m_xSize=mp_eData->xSize;
	m_ySize=mp_eData->ySize;
	m_animPaternX = 0;
	m_animPaternY = eAnim_Attack;
	m_animCounter = 0;
	m_dashSpeed = 1;
	m_charaDirection = false;
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
	m_dash = false;
	m_jumpInDash = false;
	m_jumpFlag = false;
}
CCharaBase::~CCharaBase() 
{

}
void CCharaBase::Animation()
{
	m_animCounter++;
	if (m_animCounter >= mp_eData->animData[m_animPaternY].speed) {
		m_animPaternX++;
		m_animCounter = 0;
	}
	if (m_animPaternX >= mp_eData->animData[m_animPaternY].pattrn) m_animPaternX = 0;
	m_chara->SetRect(m_xSize * m_animPaternX, m_ySize * m_animPaternY, m_xSize * (m_animPaternX + ANIM_REVISION), m_ySize * (m_animPaternY + ANIM_REVISION));
}

void CCharaBase::Key()
{
	m_up = false;
	m_down = false;
	m_left = false;
	m_right = false;
}
void CCharaBase::Idle(){
//	Animation();


}
void CCharaBase::Move()
{
	if (m_up)	m_pos.z += CHARA_MOVE * m_dashSpeed;
	if (m_down)	m_pos.z += -CHARA_MOVE * m_dashSpeed;
	if (m_left)
	{
		m_pos.x += -CHARA_MOVE * m_dashSpeed;
		//キャラの方向フラグを左向きの状態にする
		m_charaDirection = true;
	}
	if (m_right)
	{
		m_pos.x += CHARA_MOVE * m_dashSpeed;
		//キャラの方向フラグを右向きの状態にする
		m_charaDirection = false;
	}
}
void CCharaBase::Jump()
{
	if (!m_jumpFlag) m_gravitySpeed += 20;
	m_jumpFlag = true;
	if (m_left)
	{
		m_pos.x += -CHARA_MOVE;
		m_charaDirection = true;
	}
	if (m_right)
	{
		m_pos.x += CHARA_MOVE;
		m_charaDirection = false;
	}
	if (m_pos.y <= 0 && m_gravitySpeed < 20)
	{
		m_jumpFlag = false;
		m_state = eState_Idle;
	}
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
	case eState_Move:
		Move();
		break;
	case eState_Jump:
		Jump();
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
		m_chara->SetCenter(64, 128);
		m_chara->SetSize(m_xSize, m_ySize);
		m_chara->SetPos(GetScreenPos());
		m_chara->SetFlipH(m_charaDirection);
		Animation();
		m_chara->Draw();
}
void CCharaBase::HitCheck()
{

}

