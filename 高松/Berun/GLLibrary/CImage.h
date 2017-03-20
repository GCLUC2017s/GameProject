/*!
 *	@brief		�摜�Ǘ��N���X
 *	
 */

#pragma once

#include "CRect.h"
#include "CMatrix.h"
#include "CShader.h"
#include "CTexture.h"

class CImage : public CTexture {
public:
	CVector2D	m_vCenter;	//���S�ʒu(pixel)
	CVector2D	m_vSize;	//�T�C�Y(pixel)
	CRect		srcRect;	//�\������`
	float		m_ang;		//��]�l
	bool		m_flipH;	//���E���]
	CColorRGBA	m_color;	//�F
	float r;

public:
	CVector2D	m_vPos;		//�ʒu(pixel)
	CImage();
	virtual ~CImage();
	/*!
		@brief	�t�@�C������摜��ǂݍ��ށi24bitbmp,png�Ή��j
		@param	path		[in] �t�@�C����
		@retval	����:true�ڐG false��ڐG
	**/
	bool Load(char* path);
	static CImage* LoadImage(char* path);
	

	/*!
		@brief	�\���ʒu��ݒ肷��
		@param	x		[in] ���ʒu
		@param	y		[in] �c�ʒu
		@retval	����
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
		@brief	��]�̒��S�ʒu��ݒ肷��
		@param	x		[in] ���ʒu
		@param	y		[in] �c�ʒu
		@retval	����
	**/
	void SetCenter(float x,float y) {
		m_vCenter.x = x; m_vCenter.y = y;
	}
	void SetCenter(CVector2D p) {
		m_vCenter = p;
	}

	/*!
		@brief	�\���T�C�Y��ݒ肷��
		@param	w		[in] ��
		@param	h		[in] ����
		@retval	����
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
		@brief	�\������`��ݒ�
		@param	left	[in] ���ʒu
		@param	top		[in] ��ʒu
		@param	right	[in] �E�ʒu
		@param	bottom	[in] ���ʒu
		@retval	����
	**/
	void SetRect(float left,float top,float right,float bottom){
		srcRect.m_left = left;srcRect.m_right = right;
		srcRect.m_top = top;srcRect.m_bottom = bottom;
	}

	/*!
		@brief	��]�l��ݒ�
		@param	ang		[in] ��]�l
		@retval	����
	**/
	void SetAng(float ang){
		m_ang = ang;
	}

	/*!
		@brief	���E���]�t���O��ݒ�
		@param	f		[in] true:�������] false:�ʏ�
		@retval	����
	**/
	void SetFlipH(bool f) {
		m_flipH = f;
	}

	/*!
		@brief	�F��ݒ�
		@param	r		[in] �Ԑ���
		@param	g		[in] �ΐ���
		@param	b		[in] ����
		@param	a		[in] �s�����x
		@retval	����
	**/
	void SetColor(float r, float g, float b,float a){

		m_color.r = r;
		m_color.g = g;
		m_color.b = b;
		m_color.a = a;
	}
	/*!
		@brief	�`����s��
		@retval	����
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
		//�䗦���i�[����ϐ�
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
		//�����̉�������
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