#include "CLogo.h"

CLogo::CLogo()
{
	m_black = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Black"));
	m_blackSecond = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BlackSecond"));
	m_logo = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Logo"));
	m_charaM = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerM"));
	m_charaW = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerW"));

	m_blackPosX = 0;
	m_xSpeed = 15;
	m_logoX = 170;
	m_logoY = 280;
	m_logoWidth = 900;
	m_logoHeight = 150;
	m_logoPoint = CVector2D(m_logoX,m_logoY);
	m_logoSize = CVector2D(m_logoWidth,m_logoHeight);

	flag = false;
}
CLogo::~CLogo()
{

}
void CLogo::Update()
{

}
void CLogo::Draw()
{
	//黒味を表示
	m_black->Draw();
	//ロゴの位置と大きさを指定し、描写する。
	m_logo->SetPos(m_logoPoint);
	m_logo->SetSize(m_logoSize);
	m_logo->Draw();
	//上に被せた黒味をずらす処理(文字が表示されていく)
	m_blackPosX += m_xSpeed;
	m_blackSecond->SetPos(m_blackPosX, 0);
	m_blackSecond->Draw();

	if (CInput::GetState(0, CInput::ePush, CInput::eButton10)) flag = true;
}