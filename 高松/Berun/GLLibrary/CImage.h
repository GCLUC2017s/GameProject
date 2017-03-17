/*!
 *	@brief		画像管理クラス
 *	
 */

#pragma once

#include "CRect.h"
#include "CMatrix.h"
#include "CShader.h"
#include "CTexture.h"

class CImage : public CTexture {
public:
	CVector2D	m_vCenter;	//中心位置(pixel)
	CVector2D	m_vSize;	//サイズ(pixel)
	CRect		srcRect;	//表示元矩形
	float		m_ang;		//回転値
	bool		m_flipH;	//左右反転
	CColorRGBA	m_color;	//色
	float r;

public:
	CVector2D	m_vPos;		//位置(pixel)
	CImage();
	virtual ~CImage();
	/*!
		@brief	ファイルから画像を読み込む（24bitbmp,png対応）
		@param	path		[in] ファイル名
		@retval	結果:true接触 false非接触
	**/
	bool Load(char* path);
	static CImage* LoadImage(char* path);
	

	/*!
		@brief	表示位置を設定する
		@param	x		[in] 横位置
		@param	y		[in] 縦位置
		@retval	無し
	**/
	void SetPos(float x,float y) {
		m_vPos.x = x; m_vPos.y = y;
	}
	void SetPos(CVector2D p) {
		m_vPos = p;
	}
	CVector2D GetPos() {
		return m_vPos;
	}

	CVector2D* GetPosPointer()
	{
		return &m_vPos;
	}

	/*!
		@brief	回転の中心位置を設定する
		@param	x		[in] 横位置
		@param	y		[in] 縦位置
		@retval	無し
	**/
	void SetCenter(float x,float y) {
		m_vCenter.x = x; m_vCenter.y = y;
	}
	void SetCenter(CVector2D p) {
		m_vCenter = p;
	}

	/*!
		@brief	表示サイズを設定する
		@param	w		[in] 幅
		@param	h		[in] 高さ
		@retval	無し
	**/
	void SetSize(float w,float h) {
		m_vSize.x = w; m_vSize.y = h;
	}
	void SetSize(CVector2D s) {
		m_vSize = s;
	}
	CVector2D GetSize() {
		return m_vSize;
	}
	/*!
		@brief	表示元矩形を設定
		@param	left	[in] 左位置
		@param	top		[in] 上位置
		@param	right	[in] 右位置
		@param	bottom	[in] 下位置
		@retval	無し
	**/
	void SetRect(float left,float top,float right,float bottom){
		srcRect.m_left = left;srcRect.m_right = right;
		srcRect.m_top = top;srcRect.m_bottom = bottom;
	}

	/*!
		@brief	回転値を設定
		@param	ang		[in] 回転値
		@retval	無し
	**/
	void SetAng(float ang){
		m_ang = ang;
	}

	/*!
		@brief	左右反転フラグを設定
		@param	f		[in] true:水平反転 false:通常
		@retval	無し
	**/
	void SetFlipH(bool f) {
		m_flipH = f;
	}

	/*!
		@brief	色を設定
		@param	r		[in] 赤成分
		@param	g		[in] 緑成分
		@param	b		[in] 青成分
		@param	a		[in] 不透明度
		@retval	無し
	**/
	void SetColor(float r, float g, float b,float a){

		m_color.r = r;
		m_color.g = g;
		m_color.b = b;
		m_color.a = a;
	}
	/*!
		@brief	描画を行う
		@retval	無し
	**/
	void Draw();
	bool MoveImage(CVector2D bPos, CVector2D aPos,CVector2D size, float m_moveTime)
	{
		CVector2D remnant;
		CVector2D pos;


		remnant = CVector2D(aPos - bPos);
		pos = bPos + remnant * r;
		r += 1 / m_moveTime / 60;
		if (r >= 1)	r = 1;
		SetPos(pos);
		SetSize(size);
		Draw();
		if (r >= 1)
		{
			return	true;
		}
		else return	false;
	}

	void ResetMove()
	{
		r = 0;
	}
	void SetMove(float l)
	{
		r = l;
	}

	bool MoveStamp(CVector2D pos, CVector2D size, int volume, int speed) 
	{
		static int m_wordSizeMinus = 0;
		//比率を格納する変数
		static float ratio = 0;
		static CVector2D volumeSize = size * volume;
		static CVector2D volumePos;
		bool m_firstFlag;
		bool m_se;

		volumePos = (pos)-(volumeSize - size) / 2;
		SetPos(volumePos);
		SetSize(volumeSize);
		Draw();

		ratio = size.y / size.x;
		//文字の加速処理
		m_wordSizeMinus += speed;
		if (volumeSize.x > size.x)
		{
			if (volumeSize.x - m_wordSizeMinus > size.x)
			{
				volumeSize.x -= m_wordSizeMinus;
				volumeSize.y = volumeSize.x * ratio;
			}
			else
			{
				volumeSize.x -= volumeSize.x - size.x;
				volumeSize.y = volumeSize.x * ratio;
			}
			return false;
		}
		else
		{
			return true;
		}
	}
};