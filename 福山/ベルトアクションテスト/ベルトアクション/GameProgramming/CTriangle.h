#pragma once

#include "glut.h"	//OpenGL���[�e�B���e�B�̃C���N���[�h
#include "CVector2.h"	//2�����x�N�g���̃w�b�_���C���N���[�h����

/* �O�p�`�N���X */
class CTriangle {
public:
	//���_�P����R�܂ł̕ϐ����쐬
	float x1;	//���_�P��X���W
	float y1;	//���_�P��Y���W
	float x2;	//���_�Q��X���W
	float y2;	//���_�Q��Y���W
	float x3;	//���_�R��X���W
	float y3;	//���_�R��Y���W

	float r, g, b, a;	//r:�� g:�� b:�� a:�A���t�@�i�����x�j
	CVector2 v1, v2, v3;
	int degree;
	

	/* �f�t�H���g�R���X�g���N�^
	x1 �` y3�܂ł�0.0f��������
	*/
	CTriangle() {
		x1 = y1 = x2 = y2 = x3 = y3 = 0.0f;
	}

	/* ���_�P�`�R��X���W�AY���W�̒l�������ݒ肵�A�`��F��Ԃɂ���
	CTriangle(float ix1, float iy1, float ix2, float iy2, float ix3, float iy3)
	[in] ix1 ���_�P��X���W
	[in] iy1 ���_�P��Y���W
	[in] ix2 ���_�Q��X���W
	[in] iy2 ���_�Q��Y���W
	[in] ix3 ���_�R��X���W
	[in] iy3 ���_�R��Y���W
	*/
	CTriangle(float ix1, float iy1, float ix2, float iy2, float ix3, float iy3)
		: CTriangle(ix1, iy1, ix2, iy2, ix3, iy3, 1.0f, 1.0f, 1.0f, 1.0f) {
		//		x1 = ix1; y1 = iy1; x2 = ix2; y2 = iy2; x3 = ix3; y3 = iy3;
	}

	/* ���_�P�`�R��X���W�AY���W�ƕ`��F�̒l�������ݒ肷��
	CTriangle(float ix1, float iy1, float ix2, float iy2, float ix3, float iy3 float ir, float ig, float ib, float ia)
	[in] ix1 ���_�P��X���W
	[in] iy1 ���_�P��Y���W
	[in] ix2 ���_�Q��X���W
	[in] iy2 ���_�Q��Y���W
	[in] ix3 ���_�R��X���W
	[in] iy3 ���_�R��Y���W
	[in] ir �Ԃ̒l�i0.0f�`1.0f�j
	[in] ig �΂̒l�i0.0f�`1.0f�j
	[in] ib �̒l�i0.0f�`1.0f�j
	[in] ia �����x�̒l�i0.0f�F�����`1.0f�F�s�����j
	*/
	CTriangle(float ix1, float iy1, float ix2, float iy2, float ix3, float iy3, float ir, float ig, float ib, float ia)
		: x1(ix1), y1(iy1), x2(ix2), y2(iy2), x3(ix3), y3(iy3), r(ir), g(ig), b(ib), a(ia) {
	}

	/* render�֐�
	�O�p�`��`�悷��
	*/
	void render() {
		//�`��F��ݒ�
		glColor4f(r, g, b, a);
		//�O�p�`�̕`��
		glBegin(GL_TRIANGLES);	//�O�p�`�̒��_�w��J�n
		glVertex2f(x1, y1);	//���_�P�̎w��
		glVertex2f(x2, y2);	//���_�Q�̎w��
		glVertex2f(x3, y3);	//���_�R�̎w��
		glEnd();	//���_�w��I��
	}

	/* �w�肳�ꂽ�ʒu�ɕ`�悷��
	render(CVector2 pos)
	[in] pos	�ʒu
	*/
	void render(CVector2 pos);
	/* 
	�w�肳�ꂽ�ʒu�Ƀe�N�X�`���t���ŕ`�悷��
	render(CVector2 pos, float uv[])
	[in] pos	�ʒu
	[in] uv[]	�e�N�X�`���}�b�s���O�f�[�^�i�z��j
	*/
	void render(CVector2 pos, float uv[]);


	void CTriangle::render(CVector2 pos, float degree);
	void CTriangle::render(CVector2 pos, float degree,float uv[]);

};
