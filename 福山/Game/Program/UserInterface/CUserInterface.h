/*
UIのプログラム

担当者　冨田健斗
*/
#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include "../Graphic/CRectangle.h"
#include "../Graphic/CTexture.h"
#include "../Task/CTask.h"
#include "../Define/define.h"
#include "../Player/CPlayer.h"
#define HP_ST 2 //HPとST
#define HUNG_HLN	3//おなかの減り具合	hungry_high_low_normalの略

class  CUserinterface : public CTask
{
private:
	/*PLAYERのgaugeのRect*/
	CRectangle  mGaugePlayer[HP_ST];
	CRectangle  mFramePlayer[HP_ST];
	/*エネミーのgaugeのRect*/
	CRectangle mGaugeEne;
	CRectangle mFrameEne;
	/*PLAYERのテクスチャ*/
	CTexture  *mPlayerGageTex[HP_ST];
	CTexture  *mPlayerFrameHpTex;
	CTexture  *mPlayerFrameStTex[HUNG_HLN];
	/*エネミーのテクスチャ*/
	CTexture  *mEnemyGageTex;
	CTexture  *mEnemyFrameTex;
	

	CVector2 mPos;			//四角のポジジョン
	float savex;			//PLAYERのgauge調整用
	CTask *task;				
	bool mFlagColar;			//カラー演出用
	bool mFlagHP;				//レンダー未表示フラグ（HP ）
	bool mFlagST;				//レンダー未表示フラグ（ST）
	float mHungryC;				//hungry状態色計算用

	/*hungry状態演出関数*/
	void SetHungC(const CPlayer *player);
	
public:
	/*
	自分がどのアニメーションか判断用
	enum文
	*/
	 CUserinterface();
	~ CUserinterface();
	void Init();
	void Update();
	void Render();
};


#endif