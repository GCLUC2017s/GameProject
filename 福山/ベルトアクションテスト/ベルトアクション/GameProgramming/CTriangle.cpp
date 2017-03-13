#pragma once

#include "CTriangle.h"	//�O�p�`�N���X�̃w�b�_���C���N���[�h����
#include "CMatricx22.h"

void CTriangle::render(CVector2 pos) {
	//�`��F��ݒ�
	glColor4f(r, g, b, a);
	//�O�p�`�̕`��
	glBegin(GL_TRIANGLES);	//�O�p�`�̒��_�w��J�n
	glVertex2f(x1 + pos.x, y1 + pos.y);	//���_�P�̎w��
	glVertex2f(x2 + pos.x, y2 + pos.y);	//���_�Q�̎w��
	glVertex2f(x3 + pos.x, y3 + pos.y);	//���_�R�̎w��
	glEnd();	//���_�w��I��
}
/*
�e�N�X�`���}�b�s���O�t���̕`�揈��
UV[0]:���_1��U�AUV[1]:���_1��V
UV[2]:���_2��U�AUV[3]:���_2��V
UV[4]:���_3��U�AUV[5]:���_3��V
*/
void CTriangle::render(CVector2 pos, float uv[]) {
	//�`��F��ݒ�
	glColor4f(r, g, b, a);
	//�O�p�`�̕`��
	glBegin(GL_TRIANGLES);	//�O�p�`�̒��_�w��J�n
	glTexCoord2f(uv[0], uv[1]);			//���_1�̃e�N�X�`���}�b�s���O
	glVertex2f(x1 + pos.x, y1 + pos.y);	//���_�P�̎w��
	glTexCoord2f(uv[2], uv[3]);			//���_2�̃e�N�X�`���}�b�s���O
	glVertex2f(x2 + pos.x, y2 + pos.y);	//���_�Q�̎w��
	glTexCoord2f(uv[4], uv[5]);			//���_3�̃e�N�X�`���}�b�s���O
	glVertex2f(x3 + pos.x, y3 + pos.y);	//���_�R�̎w��
	glEnd();	//���_�w��I��
}


void CTriangle::render(CVector2 pos, float degree){
	CMatricx22 scale;
	scale.setscale(sinf(degree * M_PI / 180.0f) * 0.5f + 1.0f,
		sinf(degree * M_PI / 180.0f) * 0.5f + 1.0f);

	CVector2 w1 = scale * v1;
	CVector2 w2 = scale * v2;
	CVector2 w3 = scale * v3;

	CMatricx22 rotation;
	rotation.setrotation(degree);
	w1 = rotation * w1;
	w2 = rotation * w2;
	w3 = rotation * w3;

	glColor4f(r, g, b, a);
	glBegin(GL_TRIANGLES);
	glVertex2f(w1.x + pos.x, w1.y + pos.y);
	glVertex2f(w2.x + pos.x, w2.y + pos.y);
	glVertex2f(w3.x + pos.x, w3.y + pos.y);
	glEnd();
}

void CTriangle::render(CVector2 pos, float degree,float uv[]){
	/*CMatricx22 scale;
	scale.setscale(sinf(degree * M_PI / 180.0f) * 0.5f + 1.0f,
		sinf(degree * M_PI / 180.0f) * 0.5f + 1.0f);*/

	CVector2 w1 = v1;
	CVector2 w2 = v2;
	CVector2 w3 = v3;

	CMatricx22 rotation;
	rotation.setrotation(degree);
	w1 = rotation * w1;
	w2 = rotation * w2;
	w3 = rotation * w3;

	glColor4f(r, g, b, a);
	glBegin(GL_TRIANGLES);

	glTexCoord2f(uv[0], uv[1]);			//���_1�̃e�N�X�`���}�b�s���O
	glVertex2f(w1.x + pos.x, w1.y + pos.y);

	glTexCoord2f(uv[2], uv[3]);			//���_2�̃e�N�X�`���}�b�s���O
	glVertex2f(w2.x + pos.x, w2.y + pos.y);

	glTexCoord2f(uv[4], uv[5]);			//���_3�̃e�N�X�`���}�b�s���O
	glVertex2f(w3.x + pos.x, w3.y + pos.y);

	glEnd();	//���_�w��I��
}
