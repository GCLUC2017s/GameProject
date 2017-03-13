#include "CCharaSelect.h"

CCharaSelect::CCharaSelect()
{
	m_black = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Black"));
	m_charaSelectBackGround = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("CharaSelectBackGround"));
	m_charaSelectLogo = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("CharaSelectLogo"));
	m_playerMLogo = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMLogo"));
	m_playerWLogo = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerWLogo"));
	m_playerM = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerM"));
	m_playerW = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerW"));
	m_playerMShadow = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMShadow"));
	m_playerWShadow = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerWShadow"));

	m_charaSelectLogoX = 170;
	m_charaSelectLogoY = 0;
	m_charaSelectLogoWidth = 940;
	m_charaSelectLogoHeight = m_charaSelectLogoWidth * 0.13;
	m_beforePlayerMLogoX = 150;
	m_beforePlayerMLogoY = 900;
	m_afterPlayerMLogoX = 150;
	m_afterPlayerMLogoY = 300;
	m_playerMLogoWidth = 150;
	m_playerMLogoHeight = 300;
	m_beforePlayerWLogoX = 970;
	m_beforePlayerWLogoY = 900;
	m_afterPlayerWLogoX = 970;
	m_afterPlayerWLogoY = 300;
	m_playerWLogoWidth = 150;
	m_playerWLogoHeight = 300;
	m_beforePlayerMX = -250;
	m_beforePlayerMY = 100;
	m_afterPlayerMX = 250;
	m_afterPlayerMY = 100;
	m_playerMWidth = 330;
	m_playerMHeight = 610;
	m_beforePlayerWX = 1500;
	m_beforePlayerWY = 100;
	m_afterPlayerWX = 665;
	m_afterPlayerWY = 100;
	m_playerWWidth = 330;
	m_playerWHeight = 610;
	m_alphaCharaSelect = 0;
	m_alphaMax = 1.0f;
	m_normalRGB = 1.0f;
	m_shadowRGB = 0.3f;
	m_playerMLogoMoveTime = 0.4f;
	m_playerWLogoMoveTime = 0.4f;
	m_playerMMoveTime = 0.3f;
	m_playerWMoveTime = 0.3f;
	m_charaSelectLogoPos = CVector2D(m_charaSelectLogoX, m_charaSelectLogoY);
	m_charaSelectLogoSize = CVector2D(m_charaSelectLogoWidth, m_charaSelectLogoHeight);
	m_beforePlayerMLogoPos = CVector2D(m_beforePlayerMLogoX, m_beforePlayerMLogoY);
	m_afterPlayerMLogoPos = CVector2D(m_afterPlayerMLogoX, m_afterPlayerMLogoY);
	m_playerMLogoSize = CVector2D(m_playerMLogoWidth, m_playerMLogoHeight);
	m_beforePlayerWLogoPos = CVector2D(m_beforePlayerWLogoX, m_beforePlayerWLogoY);
	m_afterPlayerWLogoPos = CVector2D(m_afterPlayerWLogoX, m_afterPlayerWLogoY);
	m_playerWLogoSize = CVector2D(m_playerWLogoWidth, m_playerWLogoHeight);
	m_beforePlayerMPos = CVector2D(m_beforePlayerMX, m_beforePlayerMY);
	m_afterPlayerMPos = CVector2D(m_afterPlayerMX, m_afterPlayerMY);
	m_playerMSize = CVector2D(m_playerMWidth, m_playerMHeight);
	m_beforePlayerWPos = CVector2D(m_beforePlayerWX, m_beforePlayerWY);
	m_afterPlayerWPos = CVector2D(m_afterPlayerWX, m_afterPlayerWY);
	m_playerWSize = CVector2D(m_playerWWidth, m_playerWHeight);
	m_movePlayerMLogo = false;
	m_movePlayerWLogo = false;
	m_movePlayerM = false;
	m_movePlayerW = false;
	m_drawCharaSelectBackGround = false;
	m_chara = false;



}
CCharaSelect::~CCharaSelect()
{

}
void CCharaSelect::Update()
{

}
void CCharaSelect::Render()
{
	//黒味の表示
	m_black->Draw();

	//タイトル画面背景、ロゴの表示処理
	m_charaSelectBackGround->SetColor(1,1,1,m_alphaCharaSelect);
	m_charaSelectBackGround->SetSize(SCREEN_SIZE);
	m_charaSelectLogo->SetColor(1, 1, 1, m_alphaCharaSelect);
	m_charaSelectLogo->SetPos(m_charaSelectLogoPos);
	m_charaSelectLogo->SetSize(m_charaSelectLogoSize);
	m_charaSelectBackGround->Draw();
	m_charaSelectLogo->Draw();

	if (m_alphaCharaSelect < 1.0f)
	{
		m_alphaCharaSelect += 0.02f;
		//以下、各キャラクター位置の初期化
		m_playerM->SetPos(m_afterPlayerMPos.x - 30, m_afterPlayerMPos.y);
		m_playerW->SetPos(m_afterPlayerWPos.x + 50, m_afterPlayerWPos.y);
		//以下、各キャラクターサイズの初期化
		m_playerM->SetSize(m_playerMSize);
		m_playerW->SetSize(m_playerWSize);
		if (CInput::GetState(0, CInput::ePush, CInput::eRight) || CInput::GetState(0, CInput::ePush, CInput::eLeft) || CInput::GetState(0, CInput::ePush, CInput::eButton10))
		{
			m_alphaCharaSelect = 1.0f;
			m_drawCharaSelectBackGround = true;
		}
	}
	else
	{
		if (!m_drawCharaSelectBackGround)
		{
			if (!m_movePlayerM && !m_movePlayerW)
			{
				//キャラクターの表示処理
				m_movePlayerM = m_playerMShadow->MoveImage(m_beforePlayerMPos, m_afterPlayerMPos, m_playerMSize * 0.9f, m_playerMMoveTime);
				m_movePlayerW = m_playerWShadow->MoveImage(m_beforePlayerWPos, CVector2D(m_afterPlayerWPos.x + 25, m_afterPlayerWPos.y), m_playerWSize * 0.9f, m_playerWMoveTime);
			}
			else if (!m_movePlayerMLogo && !m_movePlayerWLogo)
			{
				//引き続き、キャラクターの表示
				m_playerMShadow->Draw();
				m_playerWShadow->Draw();
				//キャラクターロゴの表示
				m_playerMLogo->SetColor(m_shadowRGB, m_shadowRGB, m_shadowRGB, m_alphaMax);
				m_playerWLogo->SetColor(m_shadowRGB, m_shadowRGB, m_shadowRGB, m_alphaMax);
				m_movePlayerMLogo = m_playerMLogo->MoveImage(m_beforePlayerMLogoPos, m_afterPlayerMLogoPos, m_playerMLogoSize * 0.8f, m_playerMLogoMoveTime);
				m_movePlayerWLogo = m_playerWLogo->MoveImage(m_beforePlayerWLogoPos, m_afterPlayerWLogoPos, m_playerWLogoSize * 0.8f, m_playerWLogoMoveTime);
				if (m_movePlayerMLogo && m_movePlayerWLogo)	m_drawCharaSelectBackGround = true;
			}
		}
		else
		{
			//キャラ選択の処理
			if (!m_chara)
			{
				//以下、各キャラクターロゴのRGBの設定
				m_playerMLogo->SetColor(m_normalRGB, m_normalRGB, m_normalRGB, m_alphaMax);
				m_playerWLogo->SetColor(m_shadowRGB, m_shadowRGB, m_shadowRGB,m_alphaMax);
				//以下、PlayerMLogoの初期化
				m_playerMLogo->SetPos(m_afterPlayerMLogoPos);
				m_playerMLogo->SetSize(m_playerMLogoSize);
				//以下、非選択時のPlayerWLogoの設定
				m_playerWLogo->SetPos(m_afterPlayerWLogoPos);
				m_playerWLogo->SetSize(m_playerWLogoSize * 0.8f);
				//以下、非選択時のPlayerWの設定
				m_playerWShadow->SetPos(m_afterPlayerWPos.x + 70, m_afterPlayerWPos.y);
				m_playerWShadow->SetSize(m_playerWSize * 0.9f);
				//以下、キャラクターの表示処理
				m_playerM->Draw();
				m_playerWShadow->Draw();
			}
			else
			{
				//以下、各キャラクターロゴのRGBの設定
				m_playerMLogo->SetColor(m_shadowRGB, m_shadowRGB, m_shadowRGB, m_alphaMax);
				m_playerWLogo->SetColor(m_normalRGB, m_normalRGB, m_normalRGB, m_alphaMax);
				//以下、非選択時のPlayerMLogoの設定
				m_playerMLogo->SetPos(m_afterPlayerMLogoPos.x + 20, m_afterPlayerMLogoPos.y);
				m_playerMLogo->SetSize(m_playerMLogoSize * 0.8f);
				//以下、PlayerWLogoの初期化
				m_playerWLogo->SetPos(m_afterPlayerWLogoPos);
				m_playerWLogo->SetSize(m_playerWLogoSize);
				//以下、非選択時のPlayerMの設定
				m_playerMShadow->SetPos(m_afterPlayerMPos.x - 30, m_afterPlayerMPos.y);
				m_playerMShadow->SetSize(m_playerMSize * 0.9f);
				//以下、キャラクターの表示処理
				m_playerMShadow->Draw();
				m_playerW->Draw();
			}
			//キャラクターロゴの表示処理
			m_playerMLogo->Draw();
			m_playerWLogo->Draw();
			//メニュー画面のカーソル移動処理
			if (!m_chara)
			{
				if (CInput::GetState(0, CInput::ePush, CInput::eRight) || CInput::GetState(0, CInput::ePush, CInput::eLeft))		m_chara = true;
			}
			else
			{
				if (CInput::GetState(0, CInput::ePush, CInput::eRight) || CInput::GetState(0, CInput::ePush, CInput::eLeft))		m_chara = false;
			}
		}
	}
}