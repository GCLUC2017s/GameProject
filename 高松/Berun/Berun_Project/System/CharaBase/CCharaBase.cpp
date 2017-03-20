#include "CCharaBase.h"
T_AnimData _carrotAnimData[] = {
	{ 1,5 },
	{ 6,5 },
	{ 5,3 },
	{ 5,10 },
};
 static const T_CharacterData g_characterData[] =
{
	//ID,レベル、最大HP,現在HP,最大SP,現在SP,攻撃力,防御力,取得経験値,必要経験値,移動速度,ジャンプ力,キャラクターの表示サイズ,キャラクターのアニメデータ,キャラクターの元画像での1サイズ,
	{ "LittlePlayerM",0,5,0,0,0,0,0,0,0,1,1,0, {120,160} ,_carrotAnimData,{ 550,900 },{ 60,160 },CRect(-60,-160,60,0),eItemMax },
	{ "LittlePlayerW",1,5,0,0,0,0,0,0,0,1,1,0, {256,256},_carrotAnimData,{ 500,900 },{ 60,160 },CRect(-60,-160,60,0),eItemMax },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,{160,160} ,_carrotAnimData,{ 500,900 },{ 60,160 },CRect(-60,-160,60,0),eCarrotItem },
	//{ "Chick",3,5,0,0,0,0,0,0,0,1,0,0,0 },
	//{ "Fish",4,5,0,0,0,0,0,0,0,1,0,0,0 },
	//{ "Rice",5,5,0,0,0,0,0,0,0,1,0,0,0 },
};

//static_assert (ARRAY_SIZE(g_characterData) == eCharacterMax,"g_characterDataSizeError");
CCharaBase::CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio) : CBase(updatePrio, drawPrio)
{
	m_state = eState_Move;
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
	m_animPaternX = 0;
	m_animPaternY = eAnim_Attack;
	m_animLoop = false;
	m_animCounter = 0;
	m_dashSpeed = 1;
	m_anim = 0;
	m_charaDirection = false;
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
	m_dash = false;
	m_jumpFlag = false;
}
CCharaBase::~CCharaBase() 
{

}
void CCharaBase::Animation()
{
	m_animCounter++;

	if (m_animCounter >= mp_eData->animData[m_animPaternY].speed)
	{
		m_animPaternX++;
		m_animCounter = 0;
	}
	if (m_animPaternX >= mp_eData->animData[m_animPaternY].pattrn)
	{
		if(m_animLoop) m_animPaternX = 0;
		else m_animPaternX = mp_eData->animData[m_animPaternY].pattrn - 1;
	}
	m_chara->SetRect(mp_eData->texSize.x * m_animPaternX, mp_eData->texSize.y * m_animPaternY, mp_eData->texSize.x * (m_animPaternX + ANIM_REVISION), mp_eData->texSize.y * (m_animPaternY + ANIM_REVISION));
}

void CCharaBase::ChangeAnimation(EANIM type, bool loop)
{
	//もし呼び出された瞬間にそのアニメーションが選ばれていたら、何もせずに関数を抜ける処理
	if (type == m_animPaternY) return;
	m_animPaternY = type;
	m_animPaternX = 0;
	m_animLoop = loop;
}


void CCharaBase::Key()
{
	m_up = false;
	m_down = false;
	m_left = false;
	m_right = false; 
	m_jump = false;
}
void CCharaBase::Move()
{
	
	if (m_dash) m_dashSpeed = mp_eData->speed*2;
	else m_dashSpeed = mp_eData->speed;
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
	if (m_jump) {
		m_gravitySpeed += 20;
 		m_jumpFlag = true;
		m_state = eState_Jump;
	}
	if (m_up || m_down || m_left || m_right)
	{
		if (!m_dash)	ChangeAnimation(eAnim_Walk, true);
		else ChangeAnimation(eAnim_Dash, true);
	}
	else
	{
		ChangeAnimation(eAnim_Idle, true);
	}
}
void CCharaBase::Jump()
{
	ChangeAnimation(eAnim_Jump, true);
	if (m_left)
	{
		m_pos.x += -CHARA_MOVE * m_dashSpeed;
		m_charaDirection = true;
	}
	if (m_right)
	{
		m_pos.x += CHARA_MOVE * m_dashSpeed;
		m_charaDirection = false;
	}
	if (m_pos.y <= 0 && m_gravitySpeed < 20)
	{
		m_jumpFlag = false;
		m_state = eState_Move;
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
	//当たり判定用の矩形を取得
	rect = CRect(m_pos.x + mp_eData->rect.m_left, m_pos.y + mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right, m_pos.y + mp_eData->rect.m_bottom);
}
void CCharaBase::Draw()
{
		m_chara->SetCenter(mp_eData->senter.x, mp_eData->senter.y);
		Animation();
		m_chara->SetSize(mp_eData->size.x, mp_eData->size.y);
		m_chara->SetPos(GetScreenPos());
		m_chara->SetFlipH(m_charaDirection);

		m_chara->Draw();
}


