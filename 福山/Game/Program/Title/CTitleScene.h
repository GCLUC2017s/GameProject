//タイトルのプログラミング
//担当者　高橋弘樹

#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include "../Map/CMap.h"
#include "../Scene/CScene.h"
#include "../SceneManager/CSceneManager.h"
class CTitleScene :public CSceneManager{
private:
	CMap mMap;
	CTitle mTitle;
	CRectangle mFade;	//アラート表示四角形
	
	float count;	//スクロール演出のため

	int status;		//ステータス

	float FirstX;	//画面スクロール時の移動に使います。

	float Save;		//保存用です。

	float alpha;	//アルファチャンネルに使います 

	//void FadeDisp(); //フェードインで読み込みを綺麗にする為に使用　alphaを徐々に下げる。

	void Init();
	void Update();
};
#endif