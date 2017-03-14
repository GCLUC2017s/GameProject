#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_littlePlayerM = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("LittlePlayerM"));
	m_littlePlayerW = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("LittlePlayerW"));
	m_stageImage = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Title"));

	m_playerX = 0;
	m_playerY = 0;
	m_playerWidth = 100;
	m_playerHeight = 100;
	m_playerPos = CVector2D(m_playerX,m_playerY);
	m_playerSize = CVector2D(m_playerWidth,m_playerHeight);
	m_charaDirection = false;
}
CPlayer::~CPlayer()
{

}
void CPlayer::Update()
{
	//��L�[(W)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eUp))
	{
		m_playerPos.y += -PLAYER_MOVE;
	}
	//���L�[(S)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eDown))
	{
		m_playerPos.y += PLAYER_MOVE;
	}
	//���L�[(A)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft))
	{
		//�����E�������Ă���Ή摜�𔽓]������(�������ɂ���)����
		if (!m_charaDirection)	m_littlePlayerM->SetFlipH(true);
		//�L������X���W�Ƀ}�C�i�X�l(�������̒l)�����Z���Ă�������
		m_playerPos.x += -PLAYER_MOVE;
		//�L�����̕����t���O���������̏�Ԃɂ���
		m_charaDirection = true;
	}
	//�E�L�[(D)����͂������̏���
	if (CInput::GetState(0, CInput::eHold, CInput::eRight))
	{
		//�����E�������Ă���Ή摜��ʏ�����ɖ߂�(�E�����ɂ���)����
		if (m_charaDirection)	m_littlePlayerM->SetFlipH(false);
		//�L������X���W�Ƀv���X�l(�E�����̒l)�����Z���Ă�������
		m_playerPos.x += PLAYER_MOVE;
		//�L�����̕����t���O���E�����̏�Ԃɂ���
		m_charaDirection = false;
	}
	//�ȉ��ŃL�����N�^�[�̍��W�Ƒ傫����ݒ�
	m_littlePlayerM->SetPos(m_playerPos);
	m_littlePlayerM->SetSize(m_playerSize);
}
void CPlayer::Draw()
{
	m_stageImage->Draw();
	m_littlePlayerM->Draw();

	//440,650
}

