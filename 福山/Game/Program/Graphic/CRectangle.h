
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "CTriangle.h"	//三角形クラスのヘッダをインクルードする
#include "../Vector/CVector2.h"	//2次元ベクトルのヘッダをインクルードする
#include "CTexture.h"

/* 長方形クラス */
class  CRectangle {
public:
	CTriangle	triangle1;	//三角形クラスの三角形１
	CTriangle	triangle2;	//三角形クラスの三角形２

	CVector2	position;	//基準位置

	CTexture	*ptexture;
	float		uv[2][6];
	int degree;
	bool deg_enabled;


	/* 頂点１～３のX座標、Y座標と描画色の値を初期設定する
	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a)
	[in] left	左端の値
	[in] top	上部の値
	[in] right	右端の値
	[in] bottom	下部の値
	[in] ir 赤の値（0.0f～1.0f）
	[in] ig 緑の値（0.0f～1.0f）
	[in] ib 青の値（0.0f～1.0f）
	[in] ia 透明度の値（0.0f：透明～1.0f：不透明）
	*/
	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a);

	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a, CVector2 pos);
	CRectangle();

	//描画する
	void Render();

	/*
	left	画像の左上端を原点(0,0)とし、貼り付けたい領域の左の座標値
	top		画像の左上端を原点(0,0)とし、貼り付けたい領域の上の座標値
	right	画像の左上端を原点(0,0)とし、貼り付けたい領域の右の座標値
	bottom	画像の左上端を原点(0,0)とし、貼り付けたい領域の下の座標値
	*/
	void SetUv(CTexture *t, int left, int top, int right, int bottom);
	/* setVertex
	left:左のx座標
	top:上のy座標
	right:右のx座標
	bottom:下のy座標
	四角形の各頂点の座標を設定する
	*/
	void SetVertex(float left, float top, float right, float bottom);
	/* setColor
	r:赤(0.0～1.0)
	g:緑(0.0～1.0)
	b:青(0.0～1.0)
	a:アルファ(0.0透明～1.0不透明)
	四角形の色を設定する
	*/
	void SetColor(float r, float g, float b, float a);
};

#endif