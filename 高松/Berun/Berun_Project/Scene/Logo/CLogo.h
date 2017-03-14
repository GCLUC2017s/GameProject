/*
* @file		CLogo.h
* @brief	���S���
*
* @author	Ryoji Anzai
*/

#ifndef CLOGO_INCLUDE_GUARD
#define CLOGO_INCLUDE_GUARD
#include "../Global.h"
#include "../CScene.h"

class CLogo : public CScene
{
	CImage *m_black;
	CImage *m_blackSecond;
	CImage *m_logo;
	CImage *m_charaM;
	CImage *m_charaW;

	//���炷�p������X���W���i�[����ϐ�
	int m_blackPosX;
	//���������炷���x���i�[����ϐ�
	int m_xSpeed;
	//�ȉ��A���S�̍��W���i�[����ϐ�
	int m_logoX;
	int m_logoY;
	//�ȉ��A���S�̑傫�����i�[����ϐ�
	int m_logoWidth;
	int m_logoHeight;
	//���S�̍��W��Z�߂�ϐ�
	CVector2D m_logoPoint;
	//���S�̑傫����Z�߂�ϐ�
	CVector2D m_logoSize;
public:
	//�ȈՓI�ɐڑ����邽�߂̃t���O
	bool flag;
	CLogo();
	~CLogo();
	void Update();
	void Draw();
};

#endif