#pragma once

#include "CTriangle.h"	//三角形クラスのヘッダをインクルードする
#include "CVector2.h"	//2次元ベクトルのヘッダをインクルードする
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
	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a)
		:	//三角形クラスのコンストラクタを呼ぶ
		triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
		triangle2(left, top, right, bottom, right, top, r, g, b, a), ptexture(0), degree(0)
	{}

	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a, CVector2 pos)
		:	//三角形クラスのコンストラクタを呼ぶ
		triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
		triangle2(left, top, right, bottom, right, top, r, g, b, a), position(pos), ptexture(0), degree(0)
	{};


	CRectangle() {}

	//描画する
	void render() {

		if (degree != 0 || deg_enabled){ //回る四角かどうか
			if (ptexture != 0){ //テクスチャがあるかどうか
				//テクスチャを有効にする
				glEnable(GL_TEXTURE_2D);
				//アルファブレンドを有効にする
				glEnable(GL_BLEND);
				//ブレンド方法を指定
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				//テクスチャを指定
				glBindTexture(GL_TEXTURE_2D, ptexture->id);
				//三角形1の描画
				triangle1.render(position, degree,uv[0]);
				//三角形2の描画
				triangle2.render(position, degree,uv[1]);
				//テクスチャを解放
				glBindTexture(GL_TEXTURE_2D, 0);
				//アルファブレンドを無効
				glDisable(GL_BLEND);
				//テクスチャを無効
				glDisable(GL_TEXTURE_2D);
			}
			else{
				triangle1.render(position, degree);
				triangle2.render(position, degree);
				deg_enabled = true;
			}
		}
		else if (ptexture == 0) {
			triangle1.render(position);	//三角形１を描画する
			triangle2.render(position);	//三角形２を描画する
		}
		else {
			//テクスチャを有効にする
			glEnable(GL_TEXTURE_2D);
			//アルファブレンドを有効にする
			glEnable(GL_BLEND);
			//ブレンド方法を指定
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//テクスチャを指定
			glBindTexture(GL_TEXTURE_2D, ptexture->id);
			//三角形1の描画
			triangle1.render(position, uv[0]);
			//三角形2の描画
			triangle2.render(position, uv[1]);
			//テクスチャを解放
			glBindTexture(GL_TEXTURE_2D, 0);
			//アルファブレンドを無効
			glDisable(GL_BLEND);
			//テクスチャを無効
			glDisable(GL_TEXTURE_2D);
		}
	}

	//更新処理の宣言
	void update();
	/*
	left	画像の左上端を原点(0,0)とし、貼り付けたい領域の左の座標値
	top		画像の左上端を原点(0,0)とし、貼り付けたい領域の上の座標値
	right	画像の左上端を原点(0,0)とし、貼り付けたい領域の右の座標値
	bottom	画像の左上端を原点(0,0)とし、貼り付けたい領域の下の座標値
	*/
	void setuv(CTexture *t, int left, int top, int right, int bottom) {
		ptexture = t;
		uv[0][0] = uv[1][0] = (float)left / ptexture->header.width;
		uv[0][1] = uv[1][1] = (float)(ptexture->header.height - top) / ptexture->header.height;
		uv[0][2] = (float)left / ptexture->header.width;
		uv[0][3] = (float)(ptexture->header.height - bottom) / ptexture->header.height;
		uv[0][4] = uv[1][2] = (float)right / ptexture->header.width;
		uv[0][5] = uv[1][3] = (float)(ptexture->header.height - bottom) / ptexture->header.height;
		uv[1][4] = (float)right / ptexture->header.width;
		uv[1][5] = (float)(ptexture->header.height - top) / ptexture->header.height;
	}
	/* setVertex
	left:左のx座標
	top:上のy座標
	right:右のx座標
	bottom:下のy座標
	四角形の各頂点の座標を設定する
	*/
	void setVertex(float left, float top, float right, float bottom);
	/* setColor
	r:赤(0.0～1.0)
	g:緑(0.0～1.0)
	b:青(0.0～1.0)
	a:アルファ(0.0透明～1.0不透明)
	四角形の色を設定する
	*/
	void setColor(float r, float g, float b, float a);
};
