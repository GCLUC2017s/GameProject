#ifndef CWINDMILL_HPP
#define	CWINDMILL_HPP

#include "CRectangle.h"
#include "define.h"
#include "CBase.h"

class CWindmill : public CBase{
public:
	CRectangle mRect_spin;
	CRectangle mRect_rod;

	CTexture	*mpTexture;
	~CWindmill();

	CWindmill();
	void init();
	void update();
	void render();

	void setPos(int row, int col);

	//I can not speak English
	//	But I was born in America
	//Ç»ÇºÇ»ÇºÅ@Class Cgame{int toi_1[] = {71,78,70,56,63,15,48,90,84,63,62} //ÉqÉìÉgÅ@}
};
#endif