#include "CTriangle.h"	//�O�p�`�N���X�̃w�b�_���C���N���[�h����

void CTriangle::Render(CVector2 pos) {
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
void CTriangle::Render(CVector2 pos, float uv[]) {
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


