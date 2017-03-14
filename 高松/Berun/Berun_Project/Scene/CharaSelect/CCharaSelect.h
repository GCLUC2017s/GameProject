/*
* @file		CCharaSelect.h
* @brief	�L�����Z���N�g���
*
* @author	Ryoji Anzai
*/

#ifndef CCHARASELECT_INCLUDE_GUARD
#define CCHARASELECT_INCLUDE_GUARD
#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"

class CCharaSelect : public CScene
{
	CImage *m_black;
	CImage *m_charaSelectBackGround;
	CImage *m_charaSelectLogo;
	CImage *m_playerMLogoWord1;
	CImage *m_playerMLogoWord2;
	CImage *m_playerMLogoWord3;
	CImage *m_playerMLogoWord4;
	CImage *m_playerWLogoWord1;
	CImage *m_playerWLogoWord2;
	CImage *m_playerWLogoWord3;
	CImage *m_playerM;
	CImage *m_playerW;
	CImage *m_playerMShadow;
	CImage *m_playerWShadow;

	//�ȉ��A�L�����Z���N�g��ʂ̃��S���W���i�[����ϐ�
	int m_charaSelectLogoX;
	int m_charaSelectLogoY;
	//�ȉ��A�L�����Z���N�g��ʂ̃��S�T�C�Y���i�[����ϐ�
	int m_charaSelectLogoWidth;
	int m_charaSelectLogoHeight;
	//�ȉ��A�L�����N�^�[M��Word1�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerMLogoWord1X;
	int m_beforePlayerMLogoWord1Y;
	//�ȉ��A�L�����N�^�[M��Word1�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerMLogoWord1X;
	int m_afterPlayerMLogoWord1Y;
	//�ȉ��A�L�����N�^�[M��Word2�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerMLogoWord2X;
	int m_beforePlayerMLogoWord2Y;
	//�ȉ��A�L�����N�^�[M��Word2�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerMLogoWord2X;
	int m_afterPlayerMLogoWord2Y;
	//�ȉ��A�L�����N�^�[M��Word3�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerMLogoWord3X;
	int m_beforePlayerMLogoWord3Y;
	//�ȉ��A�L�����N�^�[M��Word3�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerMLogoWord3X;
	int m_afterPlayerMLogoWord3Y;
	//�ȉ��A�L�����N�^�[M��Word4�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerMLogoWord4X;
	int m_beforePlayerMLogoWord4Y;
	//�ȉ��A�L�����N�^�[M��Word4�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerMLogoWord4X;
	int m_afterPlayerMLogoWord4Y;
	//�ȉ��A�L�����N�^�[W��Word1�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerWLogoWord1X;
	int m_beforePlayerWLogoWord1Y;
	//�ȉ��A�L�����N�^�[W��Word1�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerWLogoWord1X;
	int m_afterPlayerWLogoWord1Y;
	//�ȉ��A�L�����N�^�[W��Word2�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerWLogoWord2X;
	int m_beforePlayerWLogoWord2Y;
	//�ȉ��A�L�����N�^�[W��Word2�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerWLogoWord2X;
	int m_afterPlayerWLogoWord2Y;
	//�ȉ��A�L�����N�^�[W��Word3�̈ړ��O�̍��W���i�[����ϐ�
	int m_beforePlayerWLogoWord3X;
	int m_beforePlayerWLogoWord3Y;
	//�ȉ��A�L�����N�^�[W��Word3�̖ړI�n�̍��W���i�[����ϐ�
	int m_afterPlayerWLogoWord3X;
	int m_afterPlayerWLogoWord3Y;
	//�ȉ��A�L�����N�^�[���S�̑傫�����i�[����ϐ�
	int m_playerLogoWordWidth;
	int m_playerLogoWordHeight;
	//�ȉ��A�L�����N�^�[���S2�̑傫�����i�[����ϐ�
	int m_playerLogoWord2Width;
	int m_playerLogoWord2Height;
	//�ȉ��A�L�����N�^�[���S3�̑傫�����i�[����ϐ�
	int m_playerLogoWord3Width;
	int m_playerLogoWord3Height;
	//�ȉ��A�j��l���̍��W�̏����l���i�[����ϐ�
	int m_beforePlayerMX;
	int m_beforePlayerMY;
	//�ȉ��A�j��l���̍��W�̖ړI�n���i�[����ϐ�
	int m_afterPlayerMX;
	int m_afterPlayerMY;
	//�ȉ��A�j��l���̑傫�����i�[����ϐ�
	int m_playerMWidth;
	int m_playerMHeight;
	//�ȉ��A�j��l���̍��W�̏����l���i�[����ϐ�
	int m_beforePlayerWX;
	int m_beforePlayerWY;
	//�ȉ��A�j��l���̍��W�̖ړI�n���i�[����ϐ�
	int m_afterPlayerWX;
	int m_afterPlayerWY;
	//�ȉ��A����l���̑傫�����i�[����ϐ�
	int m_playerWWidth;
	int m_playerWHeight;
	//�L�����Z���N�g��ʔw�i�A���S�̓����x���i�[����ϐ�
	float m_alphaCharaSelect;
	//���S�\�����̓����x���i�[����ϐ�
	float m_alphaMax;
	//�L�����Z���N�g�őI������RGB�l���i�[����ϐ�
	float m_normalRGB;
	//�L�����Z���N�g�Ŕ�I������RGB�l���i�[����ϐ�
	float m_shadowRGB;
	//�j��l�����S�ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_playerMLogoMoveTime;
	//����l�����S�ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_playerWLogoMoveTime;
	//�j��l���ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_playerMMoveTime;
	//����l���ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_playerWMoveTime;
	//�L�����Z���N�g��ʂ̃��S���W��Z�߂�ϐ�
	CVector2D m_charaSelectLogoPos;
	//�L�����Z���N�g��ʂ̃��S�T�C�Y��Z�߂�ϐ�
	CVector2D m_charaSelectLogoSize;
	//�j��l�����S����1�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMLogoWord1Pos;
	//�j��l�����S����1�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMLogoWord1Pos;
	//�j��l�����S����2�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMLogoWord2Pos;
	//�j��l�����S����2�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMLogoWord2Pos;
	//�j��l�����S����3�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMLogoWord3Pos;
	//�j��l�����S����3�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMLogoWord3Pos;
	//�j��l�����S����4�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMLogoWord4Pos;
	//�j��l�����S����4�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMLogoWord4Pos;
	//����l�����S����1�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerWLogoWord1Pos;
	//����l�����S����1�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerWLogoWord1Pos;
	//����l�����S����2�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerWLogoWord2Pos;
	//����l�����S����2�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerWLogoWord2Pos;
	//����l�����S����3�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerWLogoWord3Pos;
	//����l�����S����3�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerWLogoWord3Pos;
	//��l�����S�����̑傫����Z�߂�ϐ�
	CVector2D m_playerLogoWord1Size;
	//��l�����S����2�̑傫����Z�߂�ϐ�
	CVector2D m_playerLogoWord2Size;
	//��l�����S����3�̑傫����Z�߂�ϐ�
	CVector2D m_playerLogoWord3Size;
	//�j��l���̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMPos;
	//�j��l���̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMPos;
	//�j��l���̑傫����Z�߂�ϐ�
	CVector2D m_playerMSize;
	//����l���̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerWPos;
	//����l���̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerWPos;
	//����l���̑傫����Z�߂�ϐ�
	CVector2D m_playerWSize;
	//�j��l�����S�̈ړ��������������ǂ����𔻒肷��t���O
	bool m_movePlayerMLogo;
	//����l�����S�̈ړ��������������ǂ����𔻒肷��t���O
	bool m_movePlayerWLogo;
	//�j��l���̈ړ��������������ǂ����𔻒肷��t���O
	bool m_movePlayerM;
	//����l���̈ړ��������������ǂ����𔻒肷��t���O
	bool m_movePlayerW;
	//�L�����Z���N�g��ʂ̕\���������������ǂ����𔻒肷��t���O
	bool m_drawCharaSelectBackGround;
	//�ǂ���̃L������I�����Ă��邩���i�[����t���O(false = M,true = W)
	bool m_chara;

public:
	CCharaSelect();
	~CCharaSelect();
	void Update();
	void Draw();
};

#endif
