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
	//上キー(W)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eUp))
	{
		m_playerPos.y += -PLAYER_MOVE;
	}
	//下キー(S)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eDown))
	{
		m_playerPos.y += PLAYER_MOVE;
	}
	//左キー(A)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft))
	{
		//もし右を向いていれば画像を反転させる(左向きにする)処理
		if (!m_charaDirection)	m_littlePlayerM->SetFlipH(true);
		//キャラのX座標にマイナス値(左方向の値)を加算していく処理
		m_playerPos.x += -PLAYER_MOVE;
		//キャラの方向フラグを左向きの状態にする
		m_charaDirection = true;
	}
	//右キー(D)を入力した時の処理
	if (CInput::GetState(0, CInput::eHold, CInput::eRight))
	{
		//もし右を向いていれば画像を通常方向に戻す(右向きにする)処理
		if (m_charaDirection)	m_littlePlayerM->SetFlipH(false);
		//キャラのX座標にプラス値(右方向の値)を加算していく処理
		m_playerPos.x += PLAYER_MOVE;
		//キャラの方向フラグを右向きの状態にする
		m_charaDirection = false;
	}
	//以下でキャラクターの座標と大きさを設定
	m_littlePlayerM->SetPos(m_playerPos);
	m_littlePlayerM->SetSize(m_playerSize);
}
void CPlayer::Draw()
{
	m_stageImage->Draw();
	m_littlePlayerM->Draw();

	//440,650
}

