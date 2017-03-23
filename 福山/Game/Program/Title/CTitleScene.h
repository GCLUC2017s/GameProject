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
	
	float count;	//スクロール演出のため

	int status = E_TITLE_SCENE;		//ステータス

	float FirstX;	//画面スクロール時の移動に使います。

	float Save;		//保存用です。

	float alpha;	//アルファチャンネルに使います 

	enum MyEnum
	{
		E_TITLE_SCENE,
		E_EXPLAIN_SCENE

	};


	//void FadeDisp(); //フェードインで読み込みを綺麗にする為に使用　alphaを徐々に下げる。

	void Init();
	void Update();
};
#endif