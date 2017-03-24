#include "CCharaBase.h"
#include "../Game/CollisionManager/CollisionManager.h"
#include "../TaskSystem/CTaskManager.h"
#define HitCheck
T_AnimData _playerMAnimData[] = {
	{ 1,5 },
	{ 6,5 },
	{ 6,3 },
	{ 6,10 },
	{ 6,2 },
	{ 1,5 },
};
T_AnimData _playerWAnimData[] = {
	{ 1,5 },
	{ 6,5 },
	{ 6,3 },
	{ 6,10 },
	{ 6,2 },
	{ 1,5 },
};
T_AnimData _carrotAnimData[] = {
	{ 9,5 },
	{ 2,5 },
	{ 2,5 },
	{ 2,5 },
	{ 5,10 },
	{ 2,5 },
	
};
T_AnimData _chickAnimData[] = {
	{ 2,10 },
	{ 2,15 },
	{ 2,15 },
	{ 0,0 },
	{ 2,5 },
	{ 2,5 },
};
T_AnimData _fishAnimData[] = {
	{ 2,8 },
	{ 2,8 },
	{ 2,8 },
	{ 2,8 },
	{ 4,5 },
	{ 4,5 },

};
T_AnimData _pigAnimData[] = {
	{ 2,5 },
	{ 2,5 },
	{ 2,5 },
	{ 0,0 },
	{ 3,8 },
	{ 6,10 },

};
T_AnimData _bossAnimData[] = {
	{ 10,10 },
	{ 2,8 },
	{ 2,8 },
	{ 2,8 },
	{ 6,8 },
	{ 2,8 },

};
T_AnimData _bosscarrotAnimData[] = {
	{ 9,5 },
	{ 2,5 },
	{ 2,5 },
	{ 2,5 },
	{ 5,10 },
	{ 2,5 },



};
T_AnimData _riceAnimData[] = {
	{ 3,8 },
	{ 2,8 },
	
};
T_AnimData _squidAnimData[] = {
	{ 3,8 },
	{ 2,8 },
};
T_AnimData _papurikaAnimData[] = {
	{ 4,8 },
	{ 3,8 },

};
 static const T_CharacterData g_characterData[] =
{
	{ "LittlePlayerM",0,5,10,10,3,3,0,0,0,1,5,0,4,0,{ 300,240 } ,_playerMAnimData,{ 500,400 },{ 135,230 },CRect(-40,-160,40,0) },
	{ "LittlePlayerW",1,5,10,10,3,3,0,0,0,1,4,0,4,0,{ 360,180 },_playerWAnimData,{ 600,300 },{ 135,160 },CRect(-35,-160,45,0) },
	{ "Carrot",2,5,3,3,0,0,5,0,0,1,3,0,1,1,{160,160} ,_carrotAnimData,{ 160,160 },{ 60,160 },CRect(-60,-160,60,0) },
	{ "Chick",3,5,3,3,0,0,1,0,0,1,2,0,2,1,{ 160,160 } ,_chickAnimData,{ 220,220 },{ 60,160 },CRect(-60,-160,60,0) },
	{ "Fish",4,5,3,3,0,0,1,0,0,1,1,0,2,1,{ 160,160 } ,_fishAnimData,{ 200,200 },{ 60,160 },CRect(-60,-160,60,0)},
	{ "Pig",5,5,3,3,0,0,1,0,0,1,4,0,3,1,{ 160,160 } ,_pigAnimData,{ 220,220 },{ 60,160 },CRect(-60,-130,60,0)},
	{ "Rice",6,5,1,1,0,0,5,0,0,1,3,0,2,1,{ 160,160 } ,_riceAnimData,{ 145,145 },{ 60,160 },CRect(-60,-160,60,0) },
	{ "Squid",7,5,1,1,0,0,5,0,0,1,3,0,2,1,{ 160,160 } ,_squidAnimData,{ 250,250 },{ 60,160 },CRect(-60,-160,60,0) },
	{ "Paprika",8,5,1,1,0,0,5,0,0,1,3,0,2,1,{ 160,160 } ,_papurikaAnimData,{ 160,160 },{ 60,160 },CRect(-60,-160,60,0) },
	{ "Boss",9,5,20,20,0,0,1,0,0,1,4,0,2,1,{ 240,240 } ,_bossAnimData,{ 500,500 },{ 120,200 },CRect(-60,-160,60,0) },
	{ "Carrottwo",10,5,5,5,0,0,5,0,0,1,3,0,2,1,{ 160,160 } ,_bosscarrotAnimData,{ 160,160 },{ 60,160 },CRect(-60,-160,60,0) },
	
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
	m_type = mp_eData->charaType;
	m_animPaternX = 0;
	m_animPaternY = eAnim_Attack;
	m_animLoop = false;
	m_animCounter = 0;
	m_dashSpeed = 1;
	m_anim = 0;
	m_noDamageTime = 0;
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
	m_death = false;
	m_jumpFlag = false;
	m_attack = false;
	m_attackCollision = false;
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

	if (m_dash) m_dashSpeed = DASH_SPEED;
	else m_dashSpeed = NORMAL_SPEED;

		m_oldPos = m_pos;
		if (m_up)	m_pos.z += mp_eData->speed * m_dashSpeed;
		if (m_down)	m_pos.z += -mp_eData->speed * m_dashSpeed;
		if (m_left)
		{
			m_pos.x += -mp_eData->speed * m_dashSpeed;
			//キャラの方向フラグを左向きの状態にする
			m_charaDirection = true;
		}
		if (m_right)
		{
			m_pos.x += mp_eData->speed * m_dashSpeed;
			//キャラの方向フラグを右向きの状態にする
			m_charaDirection = false;

		}
		if (m_pos.z > WINDOW_UP_LIMIT || m_pos.z < WINDOW_DOWN_LIMIT)	m_pos.z = m_oldPos.z;
		if (m_pos.x < WINDOW_LEFT_LIMIT)	m_pos.x = m_oldPos.x;
	if (m_jump) {
		m_gravitySpeed += 20;
		if(!m_damage) m_state = eState_Jump;
	}
	if (m_attack && !m_damage)	m_state = eState_Attack;
	if (m_damage)	m_state = eState_Damage;
	if ((m_up || m_down || m_left || m_right) && !m_damage)
	{
		if (!m_dash)	ChangeAnimation(eAnim_Walk, true);
		else ChangeAnimation(eAnim_Dash, true);
	}
	else
	{
		if (!m_damage)ChangeAnimation(eAnim_Idle, true);
	}

}
void CCharaBase::Jump()
{
	ChangeAnimation(eAnim_Jump, true);
	if (m_left)
	{
		m_pos.x += -mp_eData->speed * m_dashSpeed;
		m_charaDirection = true;
	}
	if (m_right)
	{
		m_pos.x += mp_eData->speed * m_dashSpeed;
		m_charaDirection = false;
	}
	if (m_pos.y <= 0 && m_gravitySpeed < 20 && !m_damage)
	{
		m_state = eState_Move;
	}
}
void CCharaBase::Attack()
{
	ChangeAnimation(eAnim_Attack, false);
	if (m_animPaternX == mp_eData->m_attackFlame)	m_attackCollision = true;
	if (CheckEndAnim())
		m_state = eState_Move;
}
void CCharaBase::Update()
{
	float zPos = m_pos.z;
	Contlol();
	m_attackCollision = false;
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
	case eState_Down:
		Down();
		break;
	}
	//当たり判定用の矩形を計算
	if(!m_attackCollision)rect = CRect(m_pos.x + mp_eData->rect.m_left, m_pos.y - mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right, m_pos.y - mp_eData->rect.m_bottom);
	else
	{
		if (m_charaDirection)	rect = CRect(m_pos.x + mp_eData->rect.m_left - 60, m_pos.y - mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right, m_pos.y - mp_eData->rect.m_bottom);
		else rect = CRect(m_pos.x + mp_eData->rect.m_left, m_pos.y - mp_eData->rect.m_top, m_pos.x + mp_eData->rect.m_right + 60, m_pos.y - mp_eData->rect.m_bottom);

	}
	m_gravitySpeed += GRAVITY;
	m_pos.y += m_gravitySpeed;
	if (m_pos.y < 0)
	{
		m_pos.y = 0;
		m_gravitySpeed = 0;
	}
	CCollisionManager::GetInstance()->Regist(this);
	if (m_pos.z >= zPos) CTaskManager::GetInstance()->ChangeDrawPrio(this, 600 - m_pos.z);
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
		m_red->SetSize(rect.m_right - rect.m_left, -rect.m_top);
		m_red->Draw();
#endif
	//	m_enemyHp->Draw();
}




void CCharaBase::Damage()
{
	if (m_death)	ChangeAnimation(eAnim_Down, true);
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
		m_noDamageTime += CHANGE_TIME(DAMAGE_TIME);
		if (m_noDamageTime >= DAMAGE_TIME || m_type == ENEMY_TYPE)
		{
			m_damageTime = 0;
			m_noDamageTime = 0;
			m_chara->SetColor(NORMAL_COLOR);
			m_damage = false;
			m_damageFirst = false;
			if (!m_death) m_state = eState_Move;
			else m_state = eState_Down;
		}
		else
		{
			Move();
			m_damageTime += CHANGE_TIME(MILLI_SECOUND(DAMAGE_TIME));
			if (m_damageTime % (int)FLASH_INTERBAL < 100)		m_chara->SetColor(RED_COLOR);
			else m_chara->SetColor(NORMAL_COLOR);
		}
	}
}
bool CCharaBase::CheckEndAnim()
{
	if(m_animPaternX >= mp_eData->animData[m_animPaternY].pattrn - 1) return true;
	else return false;
}

void CCharaBase::Down()
{
	//派生先で定義する。
}

bool CCharaBase::CheckHit(CCollisionA *t)
{
	//自分が死んでいれば、何も値を返さない処理
	if (m_death)	return false;
	CCharaBase* tt = dynamic_cast<CCharaBase*>(t);
	assert(tt);
	if (tt->m_death)	return false;
	if (tt->m_damage) 	return false;
	if (m_damage) 	return false;
	CRect p_rect = GetRect();
	CRect t_rect = tt->GetRect();
	if (abs(m_pos.z - tt->m_pos.z) < 100 && p_rect.m_right > t_rect.m_left && p_rect.m_left < t_rect.m_right && p_rect.m_top > t_rect.m_bottom && p_rect.m_bottom < t_rect.m_top) {
		HitCallBack(t);
		t->HitCallBack(this);
	}
	else return false;
}

void CCharaBase::HitCallBack(CCollisionA * p)
{
	//派生先で定義する。
}