#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include "../Graphic/CRectangle.h"
#include "../Graphic/CTexture.h"
#include "../Task/CTask.h"
#include "../Define/define.h"
#define HP_ST 2 //HPとST
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
	CTexture  *mPlayerFrameTex[HP_ST];
	/*エネミーのテクスチャ*/
	CTexture  *mEnemyGageTex;
	CTexture  *mEnemyFrameTex;

	CVector2 mPos;			//四角のポジジョン
	float savex;			//PLAYERのgauge調整用

	const float area_x = MAP_LIMIT_X / 2; //PLAYERの表示エリア
	
public:
	/*
	自分がどのアニメーションか判断用
	enum文
	*/

	 CUserinterface();
	~ CUserinterface();

	void Update();
	void Render();
};


#endif