/*
* @file		CLogo.h
* @brief	ƒƒS‰æ–Ê
*
* @author	Ryoji Anzai
*/

#ifndef CLOGO_INCLUDE_GUARD
#define CLOGO_INCLUDE_GUARD
#include "../Global.h"
#include "../CScene.h"

class CLogo : public CScene
{
	CImage *m_black;
	CImage *m_blackSecond;
	CImage *m_logo;
	CImage *m_charaM;
	CImage *m_charaW;

	//‚¸‚ç‚·—p•–¡‚ÌXÀ•W‚ğŠi”[‚·‚é•Ï”
	int m_blackPosX;
	//•–¡‚ğ‚¸‚ç‚·‘¬“x‚ğŠi”[‚·‚é•Ï”
	int m_xSpeed;
	//ˆÈ‰ºAƒƒS‚ÌÀ•W‚ğŠi”[‚·‚é•Ï”
	int m_logoX;
	int m_logoY;
	//ˆÈ‰ºAƒƒS‚Ì‘å‚«‚³‚ğŠi”[‚·‚é•Ï”
	int m_logoWidth;
	int m_logoHeight;
	//ƒƒS‚ÌÀ•W‚ğ“Z‚ß‚é•Ï”
	CVector2D m_logoPoint;
	//ƒƒS‚Ì‘å‚«‚³‚ğ“Z‚ß‚é•Ï”
	CVector2D m_logoSize;
public:
	//ŠÈˆÕ“I‚ÉÚ‘±‚·‚é‚½‚ß‚Ìƒtƒ‰ƒO
	bool flag;
	CLogo();
	~CLogo();
	void Update();
	void Draw();
};

#endif