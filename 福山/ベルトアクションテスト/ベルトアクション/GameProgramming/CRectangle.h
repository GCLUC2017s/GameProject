#pragma once

#include "CTriangle.h"	//�O�p�`�N���X�̃w�b�_���C���N���[�h����
#include "CVector2.h"	//2�����x�N�g���̃w�b�_���C���N���[�h����
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
	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a)
		:	//�O�p�`�N���X�̃R���X�g���N�^���Ă�
		triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
		triangle2(left, top, right, bottom, right, top, r, g, b, a), ptexture(0), degree(0)
	{}

	CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a, CVector2 pos)
		:	//�O�p�`�N���X�̃R���X�g���N�^���Ă�
		triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
		triangle2(left, top, right, bottom, right, top, r, g, b, a), position(pos), ptexture(0), degree(0)
	{};


	CRectangle() {}

	//�`�悷��
	void render() {

		if (degree != 0 || deg_enabled){ //���l�p���ǂ���
			if (ptexture != 0){ //�e�N�X�`�������邩�ǂ���
				//�e�N�X�`����L���ɂ���
				glEnable(GL_TEXTURE_2D);
				//�A���t�@�u�����h��L���ɂ���
				glEnable(GL_BLEND);
				//�u�����h���@���w��
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				//�e�N�X�`�����w��
				glBindTexture(GL_TEXTURE_2D, ptexture->id);
				//�O�p�`1�̕`��
				triangle1.render(position, degree,uv[0]);
				//�O�p�`2�̕`��
				triangle2.render(position, degree,uv[1]);
				//�e�N�X�`�������
				glBindTexture(GL_TEXTURE_2D, 0);
				//�A���t�@�u�����h�𖳌�
				glDisable(GL_BLEND);
				//�e�N�X�`���𖳌�
				glDisable(GL_TEXTURE_2D);
			}
			else{
				triangle1.render(position, degree);
				triangle2.render(position, degree);
				deg_enabled = true;
			}
		}
		else if (ptexture == 0) {
			triangle1.render(position);	//�O�p�`�P��`�悷��
			triangle2.render(position);	//�O�p�`�Q��`�悷��
		}
		else {
			//�e�N�X�`����L���ɂ���
			glEnable(GL_TEXTURE_2D);
			//�A���t�@�u�����h��L���ɂ���
			glEnable(GL_BLEND);
			//�u�����h���@���w��
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//�e�N�X�`�����w��
			glBindTexture(GL_TEXTURE_2D, ptexture->id);
			//�O�p�`1�̕`��
			triangle1.render(position, uv[0]);
			//�O�p�`2�̕`��
			triangle2.render(position, uv[1]);
			//�e�N�X�`�������
			glBindTexture(GL_TEXTURE_2D, 0);
			//�A���t�@�u�����h�𖳌�
			glDisable(GL_BLEND);
			//�e�N�X�`���𖳌�
			glDisable(GL_TEXTURE_2D);
		}
	}

	//�X�V�����̐錾
	void update();
	/*
	left	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̍��̍��W�l
	top		�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̏�̍��W�l
	right	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̉E�̍��W�l
	bottom	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̉��̍��W�l
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
	left:����x���W
	top:���y���W
	right:�E��x���W
	bottom:����y���W
	�l�p�`�̊e���_�̍��W��ݒ肷��
	*/
	void setVertex(float left, float top, float right, float bottom);
	/* setColor
	r:��(0.0�`1.0)
	g:��(0.0�`1.0)
	b:��(0.0�`1.0)
	a:�A���t�@(0.0�����`1.0�s����)
	�l�p�`�̐F��ݒ肷��
	*/
	void setColor(float r, float g, float b, float a);
};
