//タイトルのプログラミング
//担当者　高橋弘樹

#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include "../Map/CMap.h"
#include "../Scene/CScene.h"
#include "../SceneManager/CSceneManager.h"
#include "../Explain/CExplain.h"

class CTitleScene :public CScene{
private:
	CMap mMap;
	CTitle mTitle;
	CExplain mExplain;
	CRectangle mRectFilter;
	CTexture *mFilterTex;

	float mCount;	//スクロール演出のため

	int status = E_TITLE_SCENE;		//ステータス

	float mFirstX;	//画面スクロール時の移動に使います。

	float mSave;		//保存用です。


	float	mLeftSc;		//左スクロール用
	float	mRightSc;	//右スクロール用

	/*フェード,フェードアウト,しない簡易シーン管理する*/
	enum MyFade
	{
		E_FADE,E_FADEOUT,E_NOFADE
	};
	MyFade mStarusFade = E_NOFADE;
	enum MyEnum
	{
		E_TITLE_SCENE,
		E_EXPLAIN_SCENE

	};


	void Init();
	void Update();
};
#endif