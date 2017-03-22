#include "CCharaBase.h"
#include "../Game/CollisionManager/CollisionManager.h"
#define HitCheck
T_AnimData _playerMAnimData[] = {
	{ 1,5 },
	{ 6,5 },
	{ 6,3 },
	{ 6,10 },
	{ 6,2 },
};
T_AnimData _playerWAnimData[] = {
	{ 1,5 },
	{ 6,5 },
	{ 6,3 },
	{ 6,10 },
	{ 6,2 },
};
T_AnimData _carrotAnimData[] = {
	{ 1,5 },
	{ 6,5 },
	{ 5,3 },
	{ 5,10 },
	
};
 static const T_CharacterData g_characterData[] =
{
{ "LittlePlayerM",0,5,5,5,3,3,0,0,0,1,1,0,0,{ 120,160 } ,_playerMAnimData,{ 550,900 },{ 70,160 },CRect(-50,-160,30,0),eItemMax },
	{ "LittlePlayerW",1,5,0,0,0,0,0,0,0,1,1,0,0,{ 360,180 },_playerWAnimData,{ 600,300 },{ 135,160 },CRect(-35,-160,45,0),eItemMax },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,1,{160,160} ,_carrotAnimData,{ 160,160 },{ 60,160 },CRect(-60,-160,60,0),eCarrotItem },
	{ "Chick",3,5,0,0,0,0,0,0,0,1,0,0,1,{ 160,160 } ,_carrotAnimData,{ 225,225 },{ 60,160 },CRect(-60,-160,60,0),eCarrotItem },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,1,{ 160,160 } ,_carrotAnimData,{ 160,160 },{ 60,160 },CRect(-60,-160,60,0),eCarrotItem },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,1,{ 160,160 } ,_carrotAnimData,{ 160,160 },{ 60,160 },CRect(-60,-160,60,0),eCarrotItem },
	//{ "Pig",4,5,0,0,0,0,0,0,0,1,0,0,{ 160,160 } ,_chicntAnimData,{ 225,225 },{ 60,160 },CRect(-60,-160,60,0),eCarrotItem },
	//{ "Fish",4,5,0,0,0,0,0,0,0,1,0,0,0 },
	//{ "Rice",5,5,0,0,0,0,0,0,0,1,0,0,0 },
};

//static_assert (ARRAY_SIZE(g_characterData) == eCharacterMax,"g_characterDataSizeError");
CCharaBase::CCharaBase(int type, int id, unsigned int updatePrio, unsigned int drawPrio) : CBase(id,updatePrio, drawPrio)
{
	m_state = eState_Move;
	mp_eData = &g_characterData[type];
	m_chara = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(mp_eData->imageName));
	m_red = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RED"));
	
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
	SetType(mp_eData->charaType);
	m_animPaternX = 0;
	m_animPaternY = eAnim_Attack;
	m_animLoop = false;
	m_animCounter = 0;
	m_dashSpeed = 1;
	m_anim = 0;
	m_damage = false;
	m_damageFirst = false;
	m_damageDirection = false;
	m_damageTime = 0;
	m_charaDirection = false;
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
	m_dash = false;
	m_jumpFlag = false;
	m_attack = false;
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
		if (m_state == eState_Attack)	m_state = eState_Move;
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


void CCharaBase::ResetKey()
{
	m_up = false;
	m_down = false;
	m_left = false;
	m_right = false; 
	m_jump = false;
	m_attack = false;
}
void CCharaBase::Contlol()
{
	//派生先で定義
}
void CCharaBase::Move()
{

	if (m_dash) m_dashSpeed = mp_eData->speed*2;
	else m_dashSpeed = mp_eData->speed;

		m_oldPos = m_pos;
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
		if (m_pos.z > 600 || m_pos.z < 100)
		{
			m_pos.z = m_oldPos.z;
		}
	if (m_jump) {
		m_gravitySpeed += 20;
		m_state = eState_Jump;
	}
	if (m_attack)	m_state = eState_Attack;
	if (m_damage)	m_state = eState_Damage;
	if (m_up || m_down || m_left || m_right)
	{
		if (!m_dash)	ChangeAnimation(eAnim_Walk, true);
		else ChangeAnimation(eAnim_Dash, true);
	}
	else
	{
		ChangeAnimation(eAnim_Idle, true);
	}
	//当たり判定用の矩形を計算
	rect = CRect(m_pos.x + mp_eData->rect.m_left, m_pos.y + mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right, m_pos.y + mp_eData->rect.m_bottom);
}
void CCharaBase::Jump()
{
	ChangeAnimation(eAnim_Jump, true);
//	if (m_damage)	m_state = eState_Damage;
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
		m_state = eState_Move;
	}
}
void CCharaBase::Attack()
{
	ChangeAnimation(eAnim_Attack, true);
	if (m_charaDirection)	rect = CRect(m_pos.x + mp_eData->rect.m_left - 60, m_pos.y + mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right, m_pos.y + mp_eData->rect.m_bottom);
	else rect = CRect(m_pos.x + mp_eData->rect.m_left, m_pos.y + mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right + 60, m_pos.y + mp_eData->rect.m_bottom);
}
void CCharaBase::Update()
{
	
	Contlol();
	switch (m_state)
	{
	case eState_Move:
		Move();
		break;
	case eState_Jump:
		Jump();
		break;
	case eState_Attack:
		Attack();
		break;
	case eState_Damage:
		Damage();
		break;
	}
	m_gravitySpeed += GRAVITY;
	m_pos.y += m_gravitySpeed;
	if (m_pos.y < 0)
	{
		m_pos.y = 0;
		m_gravitySpeed = 0;
	}
	CCollisionManager::GetInstance()->Regist(this);
}
void CCharaBase::Draw()
{
	
		m_chara->SetCenter(mp_eData->senter.x, mp_eData->senter.y);
		Animation();
		m_chara->SetSize(mp_eData->size.x, mp_eData->size.y);
		m_chara->SetPos(GetScreenPos());
		m_chara->SetFlipH(m_charaDirection);
		if (!m_charaDirection)	m_chara->SetCenter(mp_eData->senter.x, mp_eData->senter.y);
		else	m_chara->SetCenter(mp_eData->size.x - mp_eData->senter.x, mp_eData->senter.y);

		m_chara->Draw();
#ifdef HitCheck 
		m_red->SetPos(GetScreenPos(CVector3D(rect.m_left, rect.m_bottom, m_pos.z)));
		m_red->SetCenter(0,0);
		m_red->SetSize(rect.m_right - rect.m_left, -g_characterData[g_tutorialNo].size.y);
		if (m_state == eState_Attack)
		{
			if (m_charaDirection)
			{
				m_red->SetPos(GetScreenPos(CVector3D(rect.m_left - 60, rect.m_bottom, m_pos.z)));
				m_red->SetSize(rect.m_right - rect.m_left + 60, -g_characterData[g_tutorialNo].size.y);
			}
			else m_red->SetSize(rect.m_right - rect.m_left + 60, -g_characterData[g_tutorialNo].size.y);
		}
		m_red->Draw();
#endif
	//	m_enemyHp->Draw();
}


bool CCharaBase::CheckHit(CCollisionA *t)
{
	CCharaBase* tt = dynamic_cast<CCharaBase*>(t);
	assert(tt);
	CRect p_rect = GetRect();
	CRect t_rect = tt->GetRect();
	if (abs(m_pos.z - tt->m_pos.z) < 50 && p_rect.m_right > t_rect.m_left && p_rect.m_left < t_rect.m_right && p_rect.m_top < t_rect.m_bottom && p_rect.m_bottom > t_rect.m_top) {
		HitCallBack(t);
		t->HitCallBack(this);
	}
	else return false;
}

void CCharaBase::HitCallBack(CCollisionA * p)
{
	CCharaBase* tt = dynamic_cast<CCharaBase*>(p);
	if (!m_type)
	{
		if (m_state != eState_Attack)
		{
			if (!m_damage)
			{
				if (m_pos.x < tt->m_pos.x)	m_damageDirection = true;
				if (m_pos.x > tt->m_pos.x)	m_damageDirection = false;
			}
			m_damage = true;
		}
	}
	if(tt->m_state==eState_Attack)	SetDestroyFlag(true);
}

void CCharaBase::Damage()
{
	if (!m_damageFirst)
	{
		m_pos.y++;
		m_gravitySpeed += 15;
		m_damageFirst = true;
	}
	if (m_pos.y > 0)
	{
		if(m_damageDirection)	m_pos.x -= 5;
		else m_pos.x += 5;
		m_damageTime += CHANGE_TIME(MILLI_SECOUND(DAMAGE_TIME));
		if (m_damageTime % (int)FLASH_INTERBAL < 100)		m_chara->SetColor(RED_COLOR);
		else m_chara->SetColor(NORMAL_COLOR);
	}
	else
	{
		m_damageTime = 0;
		m_chara->SetColor(NORMAL_COLOR);
		m_damage = false;
		m_damageFirst = false;
		m_state = eState_Move;
	}
	rect = CRect(m_pos.x + mp_eData->rect.m_left, m_pos.y + mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right, m_pos.y + mp_eData->rect.m_bottom);
}
