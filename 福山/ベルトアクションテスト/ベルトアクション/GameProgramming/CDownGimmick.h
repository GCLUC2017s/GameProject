#ifndef CDOWNGIMMICK_HPP
#define CDOWNGIMMICK_HPP

#include "CRectangle.h"
#include "define.h"
#include "CBase.h"

class CDownGimmick : public CBase{
public:
	CRectangle mRect_left;
	CRectangle mRect_right;
	CVector2 leftpos, rightpos, middlepos,hozleftpos,hozrightpos;

	bool enabled; //閉まっているかどうか
	bool go_enabld;//Let's_goするかしないか

	float speed, plusx; //速度の変数　Xに足すとき用の変数
	static int rowsuu; //何個目か判断用

	CTexture	*mpTexture;
	~CDownGimmick();

	CDownGimmick();

	void init();
	void update();
	void render();
	void setPos(int row, int col);

};
#endif