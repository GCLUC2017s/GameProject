/**/
#ifndef MAP_HPP
#define MAP_HPP
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <stdio.h>
#include "../Base/CBase.h"
#define TREE_MAX  10
#define BEFORE_AND_AFTER 2 
class CMap :public CTask{
private:
	CRectangle mGround;			//背景の地面
	CRectangle mSky;		//空
	CRectangle mTree[BEFORE_AND_AFTER][TREE_MAX];		//木
	enum MyTree
	{
		E_BEFORE,E_AFTER
	};
	CTexture *mGroundTex; //背景のテクスチャ
	CTexture *mSkyTex;
	CTexture *mTreeTex;

	float	mLeftSc;		//左スクロール用
	float	mRightSc;	//右スクロール用
	bool	mFlagSc;	//引く足すフラグ

public:
	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};
#endif