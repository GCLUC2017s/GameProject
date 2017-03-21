#include "CRectangle.h"


CRectangle::CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a)
:	//三角形クラスのコンストラクタを呼ぶ
triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
triangle2(left, top, right, bottom, right, top, r, g, b, a), ptexture(0), degree(0)
{}



CRectangle::CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a, CVector2 pos)
:	//三角形クラスのコンストラクタを呼ぶ
triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
triangle2(left, top, right, bottom, right, top, r, g, b, a), position(pos), ptexture(0), degree(0)
{};


CRectangle::CRectangle() {}

//描画する
void CRectangle::Render() {

	if (ptexture == 0) {
		triangle1.Render(position);	//三角形１を描画する
		triangle2.Render(position);	//三角形２を描画する
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
		triangle1.Render(position, uv[0]);
		//三角形2の描画
		triangle2.Render(position, uv[1]);
		//テクスチャを解放
		glBindTexture(GL_TEXTURE_2D, 0);
		//アルファブレンドを無効
		glDisable(GL_BLEND);
		//テクスチャを無効
		glDisable(GL_TEXTURE_2D);
	}
}

//更新処理の宣言
void Update();
/*
left	画像の左上端を原点(0,0)とし、貼り付けたい領域の左の座標値
top		画像の左上端を原点(0,0)とし、貼り付けたい領域の上の座標値
right	画像の左上端を原点(0,0)とし、貼り付けたい領域の右の座標値
bottom	画像の左上端を原点(0,0)とし、貼り付けたい領域の下の座標値
*/

void CRectangle::SetUv(CTexture *t, int left, int top, int right, int bottom) {
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

void CRectangle::SetVertex(float left, float top, float right, float bottom) {
	degree = 0;
	deg_enabled = false;
	triangle1.x1 = left; triangle1.y1 = top;
	triangle1.x2 = left; triangle1.y2 = bottom;
	triangle1.x3 = right; triangle1.y3 = bottom;
	triangle2.x1 = left; triangle2.y1 = top;
	triangle2.x2 = right; triangle2.y2 = bottom;
	triangle2.x3 = right; triangle2.y3 = top;
	triangle1.v1 = CVector2(left, top); triangle1.v2 = CVector2(left, bottom); triangle1.v3 = CVector2(right, bottom);
	triangle2.v1 = CVector2(left, top); triangle2.v2 = CVector2(right, bottom); triangle2.v3 = CVector2(right, top);
	mRLeft = &triangle1.x1;
	mRRight = &triangle1.x3;
	mRBottom = &triangle1.y3;
	mRTop = &triangle2.y1;

}


void CRectangle::SetColor(float r, float g, float b, float a) {
	deg_enabled = false;
	degree = 0;
	triangle1.r = r;
	triangle1.g = g;
	triangle1.b = b;
	triangle1.a = a;
	triangle2.r = r;
	triangle2.g = g;
	triangle2.b = b;
	triangle2.a = a;
}