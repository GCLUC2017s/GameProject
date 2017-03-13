#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP


#include "CRectangle.h"
#include "CStringtexture.h"
#include "define.h"
#include "CBase.h"
#define MAX_COUNT 10


class UserInterface : public CBase{
public:
	CRectangle mRect_moji;
	CRectangle mRect_gauge;
	CRectangle mRect_window;
	CRectangle mRect_push;

	/*文字*/
	CStringtexture strtex;
	CTexture *tex_push;
	CTexture *tex_suuzi;
	CTexture *tex_moji;
	CTexture *tex_window;

	char str[8];
	static float gaugex;//ゲージの消費
	int seisuu;
	int syousuu;
	float size;
	bool ena_push; //プッシュスタートのenabled
	/*文字終了*/
	CTexture	*mpTexture;
	~UserInterface();

	UserInterface();
	void init();
	void update();

	void render(CVector2 pos);
	void setPos(int row, int col);

};
#endif