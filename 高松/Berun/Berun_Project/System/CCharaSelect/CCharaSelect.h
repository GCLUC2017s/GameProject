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

class CCharaSelect
{
	CImage *m_black;
	CImage *m_charaSelectBackGround;
	CImage *m_charaSelectLogo;
	CImage *m_playerMLogo;
	CImage *m_playerWLogo;
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
	//�ȉ��A�j��l�����S�̍��W�̏����l���i�[����ϐ�
	int m_beforePlayerMLogoX;
	int m_beforePlayerMLogoY;
	//�ȉ��A�j��l�����S�̍��W�̖ړI�n���i�[����ϐ�
	int m_afterPlayerMLogoX;
	int m_afterPlayerMLogoY;
	//�ȉ��A�j��l�����S�̑傫�����i�[����ϐ�
	int m_playerMLogoWidth;
	int m_playerMLogoHeight;
	//�ȉ��A����l�����S�̍��W�̏����l���i�[����ϐ�
	int m_beforePlayerWLogoX;
	int m_beforePlayerWLogoY;
	//�ȉ��A����l�����S�̍��W�̖ړI�n���i�[����ϐ�
	int m_afterPlayerWLogoX;
	int m_afterPlayerWLogoY;
	//�ȉ��A����l�����S�̑傫�����i�[����ϐ�
	int m_playerWLogoWidth;
	int m_playerWLogoHeight;
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
	//�j��l�����S�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMLogoPos;
	//�j��l�����S�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMLogoPos;
	//�j��l�����S�̑傫����Z�߂�ϐ�
	CVector2D m_playerMLogoSize;
	//����l�����S�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerWLogoPos;
	//����l�����S�̖ړI�n�̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerWLogoPos;
	//����l�����S�̑傫����Z�߂�ϐ�
	CVector2D m_playerWLogoSize;
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
	void Render();
};

#endif
