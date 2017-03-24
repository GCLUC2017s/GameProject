#include "CCharaSelect.h"
#include "../CSceneManager.h"
#include "../System/TaskSystem/CTaskManager.h"
CCharaSelect::CCharaSelect()
{
	m_black = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Black"));
	m_charaSelectBackGround = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("CharaSelectBackGround"));
	m_charaSelectLogo = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("CharaSelectLogo"));
	m_playerMLogoWord1 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMLogoWord1"));
	m_playerMLogoWord2 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMLogoWord2"));
	m_playerMLogoWord3 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMLogoWord3"));
	m_playerMLogoWord4 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMLogoWord4"));
	m_playerWLogoWord1 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerWLogoWord1"));
	m_playerWLogoWord2 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerWLogoWord2"));
	m_playerWLogoWord3 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerWLogoWord3"));
	m_playerM = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerM"));
	m_playerW = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerW"));
	m_playerMShadow = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerMShadow"));
	m_playerWShadow = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerWShadow"));

	enum
	{

	};
	struct T_WordData
	{
		int id;
		int beforeX;
		int beforeY;
		int afterX;
		int afterY;
		int width;
		int height;
	};

	T_WordData wordData[] = 
	{
		{},
	};

	m_charaSelectLogoX = 170;
	m_charaSelectLogoY = 0;
	m_charaSelectLogoWidth = 940;
	m_charaSelectLogoHeight = m_charaSelectLogoWidth * 0.13f;
	m_beforePlayerMLogoWord1X = 10;
	m_beforePlayerMLogoWord1Y = -200;
	m_afterPlayerMLogoWord1X = 10;
	m_afterPlayerMLogoWord1Y = 500;
	m_beforePlayerMLogoWord2X = 120;
	m_beforePlayerMLogoWord2Y = -300;
	m_afterPlayerMLogoWord2X  = 120;
	m_afterPlayerMLogoWord2Y = 520;
	m_beforePlayerMLogoWord3X = 230;
	m_beforePlayerMLogoWord3Y  = -150;
	m_afterPlayerMLogoWord3X = 230;
	m_afterPlayerMLogoWord3Y = 510;
	m_beforePlayerMLogoWord4X = -1000;
	m_beforePlayerMLogoWord4Y = 630;
	m_afterPlayerMLogoWord4X = 0;
	m_afterPlayerMLogoWord4Y = 630;
	m_beforePlayerWLogoWord1X = 1000;
	m_beforePlayerWLogoWord1Y = -200;
	m_afterPlayerWLogoWord1X = 1000;
	m_afterPlayerWLogoWord1Y = 520;
	m_beforePlayerWLogoWord2X = 1110;
	m_beforePlayerWLogoWord2Y = -300;
	m_afterPlayerWLogoWord2X = 1110;
	m_afterPlayerWLogoWord2Y = 510;
	m_beforePlayerWLogoWord3X = 1400;
	m_beforePlayerWLogoWord3Y = 630;
	m_afterPlayerWLogoWord3X = 970;
	m_afterPlayerWLogoWord3Y = 630;
	m_playerLogoWordWidth = 100;
	m_playerLogoWordHeight = 100;
	m_playerLogoWord2Width = 350;
	m_playerLogoWord2Height = m_playerLogoWord2Width * 0.12;
	m_playerLogoWord3Width = 300;
	m_playerLogoWord3Height = m_playerLogoWord3Width * 0.18;
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
	m_playerMLogoMoveTime = 0.3f;
	m_playerWLogoMoveTime = 0.3f;
	m_playerMMoveTime = 0.3f;
	m_playerWMoveTime = 0.3f;
	m_charaSelectLogoPos = CVector2D(m_charaSelectLogoX, m_charaSelectLogoY);
	m_charaSelectLogoSize = CVector2D(m_charaSelectLogoWidth, m_charaSelectLogoHeight);
	m_beforePlayerMLogoWord1Pos = CVector2D(m_beforePlayerMLogoWord1X, m_beforePlayerMLogoWord1Y);
	m_afterPlayerMLogoWord1Pos = CVector2D(m_afterPlayerMLogoWord1X, m_afterPlayerMLogoWord1Y);
	m_beforePlayerMLogoWord2Pos = CVector2D(m_beforePlayerMLogoWord2X, m_beforePlayerMLogoWord2Y);
	m_afterPlayerMLogoWord2Pos = CVector2D(m_afterPlayerMLogoWord2X, m_afterPlayerMLogoWord2Y);
	m_beforePlayerMLogoWord3Pos = CVector2D(m_beforePlayerMLogoWord3X, m_beforePlayerMLogoWord3Y);
	m_afterPlayerMLogoWord3Pos = CVector2D(m_afterPlayerMLogoWord3X, m_afterPlayerMLogoWord3Y);
	m_beforePlayerMLogoWord4Pos = CVector2D(m_beforePlayerMLogoWord4X, m_beforePlayerMLogoWord4Y);
	m_afterPlayerMLogoWord4Pos = CVector2D(m_afterPlayerMLogoWord4X, m_afterPlayerMLogoWord4Y);
	m_beforePlayerWLogoWord1Pos = CVector2D(m_beforePlayerWLogoWord1X, m_beforePlayerWLogoWord1Y);
	m_afterPlayerWLogoWord1Pos = CVector2D(m_afterPlayerWLogoWord1X, m_afterPlayerMLogoWord1Y);
	m_beforePlayerWLogoWord2Pos = CVector2D(m_beforePlayerWLogoWord2X, m_beforePlayerWLogoWord2Y);
	m_afterPlayerWLogoWord2Pos = CVector2D(m_afterPlayerWLogoWord2X, m_afterPlayerMLogoWord2Y);
	m_beforePlayerWLogoWord3Pos = CVector2D(m_beforePlayerWLogoWord3X, m_beforePlayerWLogoWord3Y);
	m_afterPlayerWLogoWord3Pos = CVector2D(m_afterPlayerWLogoWord3X, m_afterPlayerWLogoWord3Y);
	m_playerLogoWord1Size = CVector2D(m_playerLogoWordWidth, m_playerLogoWordHeight);
	m_playerLogoWord2Size = CVector2D(m_playerLogoWord2Width, m_playerLogoWord2Height);
	m_playerLogoWord3Size = CVector2D(m_playerLogoWord3Width, m_playerLogoWord3Height);
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

	CSound::GetInstance()->GetSound("CHARASELECT_BGM")->Play();

}
CCharaSelect::~CCharaSelect()
{
	CSound::GetInstance()->GetSound("CHARASELECT_BGM")->Stop();
	CTaskManager::GetInstance()->KillAll();
}
void CCharaSelect::Update()
{

}
void CCharaSelect::Draw()
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
		m_playerM->SetPos(m_afterPlayerMPos.x + 80, m_afterPlayerMPos.y);
		m_playerW->SetPos(m_afterPlayerWPos.x + 50, m_afterPlayerWPos.y);
		//以下、各キャラクターサイズの初期化
		m_playerM->SetSize(m_playerMSize);
		m_playerW->SetSize(m_playerWSize);
		if (CInput::GetState(0, CInput::ePush, CInput::eRight) || CInput::GetState(0, CInput::ePush, CInput::eLeft) || CInput::GetState(0, CInput::ePush, CInput::eButton10))
		{
			m_playerMLogoWord1->SetMove(1.0f);
			m_playerMLogoWord2->SetMove(1.0f);
			m_playerMLogoWord3->SetMove(1.0f);
			m_playerMLogoWord4->SetMove(1.0f);
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
				m_movePlayerM = m_playerMShadow->MoveImage(m_beforePlayerMPos, CVector2D(m_afterPlayerMPos.x + 100, m_afterPlayerMPos.y), m_playerMSize * 0.9f, m_playerMMoveTime);
				m_movePlayerW = m_playerWShadow->MoveImage(m_beforePlayerWPos, CVector2D(m_afterPlayerWPos.x + 25, m_afterPlayerWPos.y), m_playerWSize * 0.9f, m_playerWMoveTime);
			}
			else m_drawCharaSelectBackGround = true;
			{
				//引き続き、キャラクターの表示
				m_playerMShadow->Draw();
				m_playerWShadow->Draw();
				//キャラクターロゴの表示

			}
		}
		else
		{
			//キャラ選択の処理
			if (!m_chara)
			{
				//以下、非選択時のPlayerWの設定
				m_playerWShadow->SetPos(m_afterPlayerWPos.x + 70, m_afterPlayerWPos.y);
				m_playerWShadow->SetSize(m_playerWSize * 0.9f);
				//以下、キャラクターの表示処理
				m_playerM->Draw();
				m_playerWShadow->Draw();
				//以下、キャラクターWのロゴ座標を初期化する処理
				m_playerWLogoWord1->SetPos(m_beforePlayerWLogoWord1Pos);
				m_playerWLogoWord2->SetPos(m_beforePlayerWLogoWord2Pos);
				m_playerWLogoWord3->SetPos(m_beforePlayerWLogoWord3Pos);
				m_playerWLogoWord1->ResetMove();
				m_playerWLogoWord2->ResetMove();
				m_playerWLogoWord3->ResetMove();
				//以下、キャラクターMのロゴを表示する処理
				m_playerMLogoWord1->MoveImage(m_beforePlayerMLogoWord1Pos, m_afterPlayerMLogoWord1Pos, m_playerLogoWord1Size, m_playerMLogoMoveTime);
				m_playerMLogoWord2->MoveImage(m_beforePlayerMLogoWord2Pos, m_afterPlayerMLogoWord2Pos, m_playerLogoWord1Size, m_playerMLogoMoveTime);
				m_playerMLogoWord3->MoveImage(m_beforePlayerMLogoWord3Pos, m_afterPlayerMLogoWord3Pos, m_playerLogoWord1Size, m_playerMLogoMoveTime);
				m_playerMLogoWord4->MoveImage(m_beforePlayerMLogoWord4Pos, m_afterPlayerMLogoWord4Pos, m_playerLogoWord2Size, m_playerMLogoMoveTime);
				g_tutorialNo = 0;
			}
			else
			{
				//以下、非選択時のPlayerMの設定
				m_playerMShadow->SetPos(m_afterPlayerMPos.x + 80, m_afterPlayerMPos.y);
				m_playerMShadow->SetSize(m_playerMSize * 0.9f);
				//以下、キャラクターの表示処理
				m_playerMShadow->Draw();
				m_playerW->Draw();
				//以下、キャラクターMのロゴ座標を初期化する処理
				m_playerMLogoWord1->SetPos(m_beforePlayerMLogoWord1Pos);
				m_playerMLogoWord2->SetPos(m_beforePlayerMLogoWord2Pos);
				m_playerMLogoWord3->SetPos(m_beforePlayerMLogoWord3Pos);
				m_playerMLogoWord4->SetPos(m_beforePlayerMLogoWord4Pos);
				m_playerMLogoWord1->ResetMove();
				m_playerMLogoWord2->ResetMove();
				m_playerMLogoWord3->ResetMove();
				m_playerMLogoWord4->ResetMove();
				//以下、キャラクターWのロゴを表示する処理
				m_playerWLogoWord1->MoveImage(m_beforePlayerWLogoWord1Pos, m_afterPlayerWLogoWord1Pos, m_playerLogoWord1Size, m_playerWLogoMoveTime);
				m_playerWLogoWord2->MoveImage(m_beforePlayerWLogoWord2Pos, m_afterPlayerWLogoWord2Pos, m_playerLogoWord1Size, m_playerWLogoMoveTime);
				m_playerWLogoWord3->MoveImage(m_beforePlayerWLogoWord3Pos, m_afterPlayerWLogoWord3Pos, m_playerLogoWord3Size, m_playerWLogoMoveTime);
				g_tutorialNo = 1;

			}
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
		if (CInput::GetState(0, CInput::ePush, CInput::eButton10)) CSceneManager::GetInstance()->Quit(0, eGame);
	}
}
