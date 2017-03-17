/**/
#ifndef MAP_HPP
#define MAP_HPP
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <stdio.h>
#include "../Base/CBase.h"

class CMap :public CBase{
private:
	CRectangle mGround;			//背景の地面
	CRectangle mSky;		//空
	CRectangle mTree;		//木

	CTexture *mGroundTex; //背景のテクスチャ
	CTexture *mSkyTex;
	CTexture *mTreeTex;

public:
	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};
#endif