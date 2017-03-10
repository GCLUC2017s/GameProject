#pragma once
#include "stdafx.h"
#define MAP_WIDTH 80
#define MAP_HEIGHT 24

/*!
*	@brief		マップクラス
*/
class CMap {
private:
	int m_mapData[MAP_HEIGHT][MAP_WIDTH];	//!<マップチップデータ
	int m_width;							//!<幅
	int m_height;							//!<高さ
	CImage* m_img;							//!<画像
	CImage* m_imghaikei;
	int back_haikei1;
	int back_haikei2;
	 
	 float m_backkumo;
	 float m_backkumo2;
	 float m_backkumo3;
	 int m_kumopatarnA;
	 int m_kumopatarnB;
	 int m_kumopatarnC;
	 int kumo;
	 int kumo2;
	 int kumo3;
	
	 float y2;
public:
	static CMap* mainMap;					//!<外部アクセス用
	int f;
	int M;
	int B;
	int F;
	/*!
	@brief	コンストラクタ
	**/
	CMap();
	/*!
	@brief	描画処理
	@retval 無し
	**/
	void Draw();
	/*!
	@brief	チップの種類を取得
	@param	pos	[in]位置（スクリーン座標）
	@retval 無し
	**/
	int GetTipData(CVector2D pos);
	/*!
	@brief	使用中のマップオブジェクトを取得
	@retval マップオブジェクトのアドレス
	**/
	static CMap* Get() {
		return mainMap;
	}

};