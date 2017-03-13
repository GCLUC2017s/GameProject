#ifndef WIND_HPP
#define WIND_HPP

#include "CRectangle.h"
#include "define.h"
#include "CBase.h"
#include  "CPlayer.h"
#define WIND_NUM 3

class CWind : public CBase{
public:
	CRectangle mRect[WIND_NUM];
	CVector2 mPos[WIND_NUM],hoz_mPos;
	CVector2 hoz_forward;


	bool enabled; //ïóÇ™ê^Ç©ãUÇ©
	bool ena_mp;
	int count;

	CTexture	*mpTexture;
	~CWind();

	CWind();
	void init();
	void update(CPlayer *pl);
	void render();

	void setPos(CVector2 pos);

};
#endif