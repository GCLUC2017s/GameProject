#include "CTitle.h"
#include "../CSceneManager.h"

CTitle::CTitle()
{
	m_black = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Black"));
	m_titleImage = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Title"));
	m_pushEnter = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PleaseEnter"));
	m_logo = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("TitleLogo"));
	m_logoKnife = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Knife"));
	m_logoFork = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Fork")); 
	m_logoBerun = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Berun")); 
	m_start = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Start")); 
	m_exit = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Exit")); 
	m_playerM = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerM"));
	m_playerW = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerW"));

	m_titleLogoX = 370;
	m_beforeTitleLogoY = -500;
	m_afterTitleLogoY = -50;
	m_titleLogoWidth = 550;
	m_titleLogoHeight = 550;
	m_titleLogoVolume = 5;
	m_titleLogoSpeed = 4;
	m_beforeKnifeX = 1500;
	m_beforeKnifeY = 1000;
	m_afterKnifeX = 410;
	m_afterKnifeY = -20;
	m_knifeWidth = 500;
	m_knifeHeight = 500;
	m_beforeForkX = -280;
	m_beforeForkY = 1000;
	m_afterForkX = 410;
	m_afterForkY = -20;
	m_forkWidth = 500;
	m_forkHeight = 500;
	m_berunX = 370;
	m_berunY = -50;
	m_berunWidth = 550;
	m_berunHeight = 550;
	m_pushEnterX = 400;
	m_pushEnterY = 620;
	m_pushEnterWidth = 500;
	m_pushEnterHeight = 70;
	m_startX = 150;
	m_startY = 605;
	m_startWidth = 400;
	m_startHeight = 85;
	m_exitX = 800;
	m_exitY = 605;
	m_exitWidth = 280;
	m_exitHeight = 85;
	m_beforePlayerMX = 1500;
	m_beforePlayerMY = 0;
	m_afterPlayerMX = 50;
	m_afterPlayerMY = 0;
	m_playerMWidth = 330;
	m_playerMHeight = 610;
	m_beforePlayerWX = -280;
	m_beforePlayerWY = 0;
	m_afterPlayerWX = 900;
	m_afterPlayerWY = 0;
	m_playerWWidth = 330;
	m_playerWHeight = 610;
	m_alphaTitleImage = 0.0f;
	m_alphaWord = 0.0f;
	m_alphaBerun = 0.0f;
	m_alphaStart = 0.0f;
	m_alphaExit = 0.0f;
	m_titleLogoMoveTime = 0.5f;
	m_knifeMoveTime = 0.5f;
	m_forkMoveTime = 0.5f;
	m_playerMMoveTime = 0.3f;
	m_playerWMoveTime = 0.3f;
	m_beforeTitleLogoPos = CVector2D(m_titleLogoX, m_beforeTitleLogoY);
	m_afterTitleLogoPos = CVector2D(m_titleLogoX, m_afterTitleLogoY);
	m_titleLogoSize = CVector2D(m_titleLogoWidth, m_titleLogoHeight);
	m_beforeKnifePos = CVector2D(m_beforeKnifeX, m_beforeKnifeY);
	m_afterKnifePos = CVector2D(m_afterKnifeX, m_afterKnifeY);
	m_knifeSize = CVector2D(m_knifeWidth, m_knifeHeight);
	m_beforeForkPos = CVector2D(m_beforeForkX, m_beforeForkY);
	m_afterForkPos = CVector2D(m_afterForkX, m_afterForkY);
	m_forkSize = CVector2D(m_forkWidth, m_forkHeight);
	m_berunPos = CVector2D(m_berunX, m_berunY);
	m_berunSize = CVector2D(m_berunWidth, m_berunHeight);
	m_enterWordPos = CVector2D(m_pushEnterX,m_pushEnterY);
	m_enterWordSize = CVector2D(m_pushEnterWidth, m_pushEnterHeight);
	m_startPos = CVector2D(m_startX, m_startY);
	m_startSize = CVector2D(m_startWidth, m_startHeight);
	m_exitPos = CVector2D(m_exitX, m_exitY);
	m_exitSize = CVector2D(m_exitWidth, m_exitHeight);
	m_beforePlayerMPos = CVector2D(m_beforePlayerMX, m_beforePlayerMY);
	m_afterPlayerMPos = CVector2D(m_afterPlayerMX, m_afterPlayerMY);
	m_playerMSize = CVector2D(m_playerMWidth, m_playerMHeight);
	m_beforePlayerWPos = CVector2D(m_beforePlayerWX, m_beforePlayerWY);
	m_afterPlayerWPos = CVector2D(m_afterPlayerWX, m_afterPlayerWY);
	m_playerWSize = CVector2D(m_playerWWidth, m_playerWHeight);
	m_moveTitleLogo = false;
	m_moveKnife = false;
	m_moveFork = false;
	m_movePlayerM = false;
	m_movePlayerW = false;
	m_drawBerun = false;
	m_drawTitle = false;
	m_enterTapFlag = false;
	m_alphaEnterTapSwich = false;
	m_titleState = false;
	m_firstMenu = false;
	m_firstChara = false;
	m_titleMenu = false;
}
CTitle::~CTitle()
{

}
void CTitle::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1))
	{
	//	CSceneManager::GetInstance()->ChangeScene();
	//	CSceneManager::GetInstance()->Quit(0, eTest);
	}
}
void CTitle::Draw()
{
	//�����̕\��
	m_black->Draw();
	//�^�C�g���w�i�̐F�ݒ�
	m_titleImage->SetColor(1,1,1,m_alphaTitleImage);
	m_titleImage->Draw();
	if (!m_titleState)
	{
		//�^�C�g���w�i�̓����x(�����l0)��1�ȉ��Ȃ�΁A���t���[��0.02f�����Z���Ă�������
		if (m_alphaTitleImage < 1.0f)
		{
			m_alphaTitleImage += 0.02f;
			//�ȉ��A�o����(�摜)�̈ʒu�A�傫���A�����x�̏�����
			m_logoBerun->SetPos(m_berunPos);
			m_logoBerun->SetSize(m_berunSize);
			m_logoBerun->SetColor(1, 1, 1, m_alphaBerun);
		}
		else
		{
			//�����A�^�C�g���̕\�����������Ă��Ȃ���΁A�\��������������B
			if (!m_drawTitle)
			{
				//������x�ł����j���[��ʂɓ����Ă���΁A�ȉ��̕\���������s��Ȃ��悤�ɂ���������B
				if (!m_firstMenu)
				{
					m_logoBerun->Draw();
					//MoveImage�֐��ŁA�i�C�t�ƃt�H�[�N�̉摜�������ʒu���珊��̈ʒu�܂ňړ�������B
					m_moveKnife = m_logoKnife->MoveImage(m_beforeKnifePos, m_afterKnifePos, m_knifeSize, m_knifeMoveTime);
					m_moveFork = m_logoFork->MoveImage(m_beforeForkPos, m_afterForkPos, m_forkSize, m_forkMoveTime);
					//�����A�o�����̓����x��1�ȉ��ŁA�Ȃ����i�C�t�ƃt�H�[�N�̕\�����I����Ă���΁A���̏����ɓ���B
					if (m_alphaBerun < 1.0f && m_moveKnife && m_moveFork)
					{
						//�i�C�t�ƃt�H�[�N�̈ړ���A���̊Ԋu���J���邽�߁A�ȈՓI�ɏ������Ń��O����鏈���B
						if (m_alphaBerun < 0.006f)	m_alphaBerun += 0.0005f;
						else m_alphaBerun += 0.02f;
						//�ȉ��A�o�����̈ʒu�A�傫���A�����x��ݒ肷�鏈���B
						m_logoBerun->SetPos(m_berunPos);
						m_logoBerun->SetSize(m_berunSize);
						m_logoBerun->SetColor(1, 1, 1, m_alphaBerun);
					}
					else if (m_alphaBerun >= 1.0f)
					{
						m_moveTitleLogo = m_logo->MoveStamp(m_afterTitleLogoPos, m_titleLogoSize, m_titleLogoVolume, m_titleLogoSpeed);
						if (m_moveTitleLogo) m_drawTitle = true;
					}
				}
			}
			else
			{
				if (!m_firstChara)
				{
					//�ȉ��A�j�E����l���̉摜��\�����鏈��
					m_movePlayerM = m_playerM->MoveImage(m_beforePlayerMPos, m_afterPlayerMPos, m_playerMSize, m_playerMMoveTime);
					m_movePlayerW = m_playerW->MoveImage(m_beforePlayerWPos, m_afterPlayerWPos, m_playerWSize, m_playerWMoveTime);
				}
				//�ŏ��̕\�������ʏ��葁������
				if (!m_enterTapFlag && m_alphaWord <= 1.0f)	m_alphaWord += 0.05f;
				else m_enterTapFlag = true;
				if (m_enterTapFlag)
				{
					//ENTERKEY TAP�̓_�ŏ���
					if (m_alphaWord < 1.0f && !m_alphaEnterTapSwich)	m_alphaWord += 0.02f;
					else m_alphaEnterTapSwich = true;
					if (m_alphaWord > 0.5f && m_alphaEnterTapSwich)	m_alphaWord -= 0.02f;
					else m_alphaEnterTapSwich = false;
				}
				//�ȉ��AENTERKEY TAP�̐F�A�ʒu�A�T�C�Y�̐ݒ�ƕ`��
				m_pushEnter->SetColor(1, 1, 1, m_alphaWord);
				m_pushEnter->SetPos(m_enterWordPos);
				m_pushEnter->SetSize(m_enterWordSize);
				m_pushEnter->Draw();
				//�ȉ��A�^�C�g���̕\������
				m_playerM->Draw();
				m_playerW->Draw();
				m_logoKnife->Draw();
				m_logoFork->Draw();
				m_logoBerun->Draw();
				m_logo->Draw();
			}
		}
	}
	else
	{
		if (!m_titleMenu)
		{
			m_start->SetPos(m_startPos.x,m_startPos.y + 10);
			m_start->SetSize(m_startSize);
			m_exit->SetPos(m_exitPos);
			m_exit->SetSize(m_exitSize);

			if (CInput::GetState(0, CInput::ePush, CInput::eButton10))   CSceneManager::GetInstance()->Quit(0,eCharaSelect);
		}
		else
		{
			m_start->SetPos(m_startPos);
			m_start->SetSize(m_startSize);
			m_exit->SetPos(m_exitPos.x,m_exitPos.y + 10);
			m_exit->SetSize(m_exitSize);
			if (CInput::GetState(0, CInput::ePush, CInput::eButton10))	exit(0);
		}
		m_start->Draw();
		m_exit->Draw();
		//�ȉ��A�^�C�g���̕\������
		m_logoKnife->Draw();
		m_logoFork->Draw();
		m_logoBerun->Draw();
		m_logo->Draw();
		m_playerM->Draw();
		m_playerW->Draw();

		//���j���[��ʂ̃J�[�\���ړ�����
		if (!m_titleMenu)
		{
			if (CInput::GetState(0, CInput::ePush, CInput::eRight) || CInput::GetState(0, CInput::ePush, CInput::eLeft))		m_titleMenu = true;
		}
		else
		{
			if (CInput::GetState(0, CInput::ePush, CInput::eRight) || CInput::GetState(0, CInput::ePush, CInput::eLeft))		m_titleMenu = false;
		}
		//���j���[�𔲂��đ��^�C�g����ʂɖ߂鏈��
		if (CInput::GetState(0, CInput::ePush, CInput::eButton1))		m_titleState = false;
	}
	//�G���^�[�L�[���͔���
	if (!m_titleState)	if (CInput::GetState(0, CInput::ePush, CInput::eButton10))
	{
		//�ȉ��A�^�C�g����ʂ̑S�Ă̒l���ŏI�l�ɏ��������鏈��(�\�����o�X�L�b�v)�B
		m_alphaTitleImage = 1.0f;
		m_alphaWord = 1.0f;
		m_logoKnife->SetPos(m_afterKnifePos);
		m_logoKnife->SetSize(m_knifeSize);
		m_logoFork->SetPos(m_afterForkPos);
		m_logoFork->SetSize(m_forkSize);
		m_alphaBerun = 1.0f;
		m_logoBerun->SetColor(1, 1, 1, m_alphaBerun);
		m_logoBerun->SetPos(m_berunPos);
		m_logoBerun->SetSize(m_berunSize);
		m_logo->SetPos(m_afterTitleLogoPos);
		m_logo->SetSize(m_titleLogoSize);
		m_playerM->SetPos(m_afterPlayerMPos);
		m_playerM->SetSize(m_playerMSize);
		m_playerW->SetPos(m_afterPlayerWPos);
		m_playerW->SetSize(m_playerWSize);
		//�^�C�g����ʂ̏�Ԃ����j���[��ʂֈڍs�����鏈��
		m_titleState = true;
		//���j���[��ʂɓ����������L�^���鏈��
		m_firstMenu = true;
		//�L�����N�^�[��\�����������L�^���鏈��
		m_firstChara = true;
		//�^�C�g�����S�̕`�ʊ������L�^���鏈��
		m_drawTitle = true;
	}
}