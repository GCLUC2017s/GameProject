#include "CRectangle.h"


CRectangle::CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a)
:	//�O�p�`�N���X�̃R���X�g���N�^���Ă�
triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
triangle2(left, top, right, bottom, right, top, r, g, b, a), ptexture(0), degree(0)
{}



CRectangle::CRectangle(float left, float top, float right, float bottom, float r, float g, float b, float a, CVector2 pos)
:	//�O�p�`�N���X�̃R���X�g���N�^���Ă�
triangle1(left, top, left, bottom, right, bottom, r, g, b, a),
triangle2(left, top, right, bottom, right, top, r, g, b, a), position(pos), ptexture(0), degree(0)
{};


CRectangle::CRectangle() {}

//�`�悷��
void CRectangle::Render() {

	if (ptexture == 0) {
		triangle1.Render(position);	//�O�p�`�P��`�悷��
		triangle2.Render(position);	//�O�p�`�Q��`�悷��
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
		triangle1.Render(position, uv[0]);
		//�O�p�`2�̕`��
		triangle2.Render(position, uv[1]);
		//�e�N�X�`�������
		glBindTexture(GL_TEXTURE_2D, 0);
		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);
		//�e�N�X�`���𖳌�
		glDisable(GL_TEXTURE_2D);
	}
}

//�X�V�����̐錾
void Update();
/*
left	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̍��̍��W�l
top		�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̏�̍��W�l
right	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̉E�̍��W�l
bottom	�摜�̍���[�����_(0,0)�Ƃ��A�\��t�������̈�̉��̍��W�l
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