
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "CTriangle.h"	//�O�p�`�N���X�̃w�b�_���C���N���[�h����
#include "../Vector/CVector2.h"	//2�����x�N�g���̃w�b�_���C���N���[�h����
#include "CTexture.h"

/* �����`�N���X */
class  CRectangle {
public:
	CTriangle	triangle1;	//�O�p�`�N���X�̎O�p�`�P
	CTriangle	triangle2;	//�O�p�`�N���X�̎O�p�`�Q

	CVector2	position;	//��ʒu

	CTexture	*ptexture;
	float		uv[2][6];
	int degree;
	bool deg_enabled;


	/* ���_�P�`�R��X���W�AY���W�ƕ`��F�̒l�������ݒ肷��
	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a)
	[in] left	���[�̒l
	[in] top	�㕔�̒l
	[in] right	�E�[�̒l
	[in] bottom	�����̒l
	[in] ir �Ԃ̒l�i0.0f�`1.0f�j
	[in] ig �΂̒l�i0.0f�`1.0f�j
	[in] ib �̒l�i0.0f�`1.0f�j
	[in] ia �����x�̒l�i0.0f�F�����`1.0f�F�s�����j
	*/
	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a);

	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a, CVector2 pos);
	CRectangle();

	//�`�悷��
	void Render();

	/*
	left	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̍��̍��W�l
	top		�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̏�̍��W�l
	right	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̉E�̍��W�l
	bottom	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̉��̍��W�l
	*/
	void SetUv(CTexture *t, int left, int top, int right, int bottom);
	/* setVertex
	left:����x���W
	top:���y���W
	right:�E��x���W
	bottom:����y���W
	�l�p�`�̊e���_�̍��W��ݒ肷��
	*/
	void SetVertex(float left, float top, float right, float bottom);
	/* setColor
	r:��(0.0�`1.0)
	g:��(0.0�`1.0)
	b:��(0.0�`1.0)
	a:�A���t�@(0.0�����`1.0�s����)
	�l�p�`�̐F��ݒ肷��
	*/
	void SetColor(float r, float g, float b, float a);
};

#endif