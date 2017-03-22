/*
X,Y���W���܂Ƃ߂��N���X

�S���� �y�c���l
*/

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

/* 2�����̃x�N�g���N���X���쐬���� */
class CVector2 {
public:
	float x;	//X���ւ̑傫��
	float y;	//Y���ւ̑傫��

	CVector2();	//�f�t�H���g�R���X�g���N�^
	CVector2(float x, float y);	//�R���X�g���N�^

	/*�@+=���Z�q�̃I�[�o�[���C�h
	CVector2 += CVector2�@�̐錾
	*/
	void operator+=(const CVector2 &v);

	/*�@*���Z�q�̃I�[�o�[���C�h
	CVector2 + CVector2�@�̐錾
	*/
	const CVector2 operator+(const CVector2 &v) const;
	const CVector2 operator-(const CVector2 &v) const;

	/*�@*���Z�q�̃I�[�o�[���C�h
	CVector2 * float�@�̐錾
	*/
	const CVector2 operator*(float f) const;

	/*�@*=���Z�q�̃I�[�o�[���C�h
	CVector2 *= CVector2�@�̐錾
	*/
	void operator*=(const CVector2 &v);

};

#endif