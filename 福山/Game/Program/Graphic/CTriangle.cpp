#include "CTriangle.h"	//三角形クラスのヘッダをインクルードする

void CTriangle::Render(CVector2 pos) {
	//描画色を設定
	glColor4f(r, g, b, a);
	//三角形の描画
	glBegin(GL_TRIANGLES);	//三角形の頂点指定開始
	glVertex2f(x1 + pos.x, y1 + pos.y);	//頂点１の指定
	glVertex2f(x2 + pos.x, y2 + pos.y);	//頂点２の指定
	glVertex2f(x3 + pos.x, y3 + pos.y);	//頂点３の指定
	glEnd();	//頂点指定終了
}
/*
テクスチャマッピング付きの描画処理
UV[0]:頂点1のU、UV[1]:頂点1のV
UV[2]:頂点2のU、UV[3]:頂点2のV
UV[4]:頂点3のU、UV[5]:頂点3のV
*/
void CTriangle::Render(CVector2 pos, float uv[]) {
	//描画色を設定
	glColor4f(r, g, b, a);
	//三角形の描画
	glBegin(GL_TRIANGLES);	//三角形の頂点指定開始
	glTexCoord2f(uv[0], uv[1]);			//頂点1のテクスチャマッピング
	glVertex2f(x1 + pos.x, y1 + pos.y);	//頂点１の指定
	glTexCoord2f(uv[2], uv[3]);			//頂点2のテクスチャマッピング
	glVertex2f(x2 + pos.x, y2 + pos.y);	//頂点２の指定
	glTexCoord2f(uv[4], uv[5]);			//頂点3のテクスチャマッピング
	glVertex2f(x3 + pos.x, y3 + pos.y);	//頂点３の指定
	glEnd();	//頂点指定終了
}


