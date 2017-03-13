#ifndef CGOAL_HPP
#define CGOAL_HPP

#include "CRectangle.h"
#include "define.h"
#include "CBase.h"

class CGoal : public CBase{
public:
	CRectangle mRect;

	CTexture	*mpTexture;
	~CGoal();

	CGoal();
	void init();
	void update();
	void render();
	void setPos(int row, int col);

};
#endif