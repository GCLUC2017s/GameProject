#include "CCharaBase.h"
static T_CharacterData g_characterData[eCharacterMax] = {
<<<<<<< HEAD
	//ID,���x���A�ő�HP,����HP,�ő�SP,����SP,�U����,�h���,�擾�o���l,�K�v�o���l,�ړ����x,�W�����v�� (11)
	{ "LittlePlayerM" },
	{ "LittlePlayerM" },
	{ "CarrotLeft",5,5,0,0,0,0,0,0,0,1,0,},
	
=======
	//ID,���x���A�ő�HP,����HP,�ő�SP,����SP,�U����,�h���,�擾�o���l,�K�v�o���l,�ړ����x,�W�����v��,X�T�C�Y,Y�T�C�Y(13)
	{ "LittlePlayerM",0,5,0,0,0,0,0,0,0,1,0, },
	{ "LittlePlayerW",1,5,0,0,0,0,0,0,0,1,0, },
	{ "Carrot",2,5,0,0,0,0,0,0,0,1,0,0,0 },
	{ "Chick",3,5,0,0,0,0,0,0,0,1,0,0,0 },
	{ "Fish",4,5,0,0,0,0,0,0,0,1,0,0,0 },
	{ "Rice",5,5,0,0,0,0,0,0,0,1,0,0,0 },
>>>>>>> origin/master
	

};
CCharaBase::CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio) : CCharaBase(type, eUDP_Null, eDWP_Null)
{
	m_state = eState_Idle;
<<<<<<< HEAD
	mp_eData = &g_characterData[type];
=======
>>>>>>> origin/master
	m_chara = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(mp_eData->imageName));
	mp_eData = &g_characterData[type];
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
	m_xsize=mp_eData->xsize;
	m_ysize=mp_eData->ysize;
	m_charaDirection = false;
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
}
CCharaBase::~CCharaBase() 
{

}
void CCharaBase::Animation()
{

}
void CCharaBase::_key() {
	m_right = false;
	m_left = false;
	m_up = false;
	m_down = false;
}
void CCharaBase::_idle(){

	//��L�[(W)����͂������̏���
	if (m_up)
	{
		m_pos.z += 4;
	}
	//���L�[(S)����͂������̏���
	if (m_down)
	{
		m_pos.z += -4;
	}
	//���L�[(A)����͂������̏���
	if (m_left)
	{
		//�L������X���W�Ƀ}�C�i�X�l(�������̒l)�����Z���Ă�������
		m_pos.x += -4;
		//�L�����̕����t���O���������̏�Ԃɂ���
		m_charaDirection = true;
	}
	//�E�L�[(D)����͂������̏���
	if (m_right)
	{
		//�L������X���W�Ƀv���X�l(�E�����̒l)�����Z���Ă�������
		m_pos.x += 4;
		//�L�����̕����t���O���E�����̏�Ԃɂ���
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

