/*
* @file		CTitle.h
* @brief	�^�C�g�����
*
* @author	Ryoji Anzai
*/

#ifndef CTITLE_INCLUDE_GUARD
#define CTITLE_INCLUDE_GUARD
#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"

class CTitle : public CScene
{
	CImage *m_black;
	CImage *m_titleImage;
	CImage *m_pushEnter;
	CImage *m_logo;
	CImage *m_logoKnife;
	CImage *m_logoFork;
	CImage *m_logoBerun;
	CImage *m_start;
	CImage *m_exit;
	CImage *m_playerM;
	CImage *m_playerW;

	//�^�C�g�����S��X���W���i�[����ϐ�
	int m_titleLogoX;
	//�^�C�g�����S��Y���W�̏����l���i�[����ϐ�
	int m_beforeTitleLogoY;
	//�^�C�g�����S��Y���W�̖ړI�n���i�[����ϐ�
	int m_afterTitleLogoY;
	//�ȉ��A�^�C�g�����S�̑傫�����i�[����ϐ�
	int m_titleLogoWidth;
	int m_titleLogoHeight;
	//�^�C�g�����S�̕`�ʉ��o�ŁA�����̑傫�������{�ɂ��邩���i�[����ϐ�
	int m_titleLogoVolume;
	//�^�C�g�����S�̕`�ʉ��o�ŁA�\���̃X�s�[�h�������ɂ��邩���i�[����ϐ�
	int m_titleLogoSpeed;
	//�ȉ��A�i�C�t�̍��W�̏����l���i�[����ϐ�
	int m_beforeKnifeX;
	int m_beforeKnifeY;
	//�ȉ��A�i�C�t�̍��W�̖ړI�n���i�[����ϐ�
	int m_afterKnifeX;
	int m_afterKnifeY;
	//�ȉ��A�i�C�t(�摜)�̑傫�����i�[����ϐ�
	int m_knifeWidth;
	int m_knifeHeight;
	//�ȉ��A�t�H�[�N�̍��W�̏����l���i�[����ϐ�
	int m_beforeForkX;
	int m_beforeForkY;
	//�ȉ��A�t�H�[�N�̍��W�̖ړI�n���i�[����ϐ�
	int m_afterForkX;
	int m_afterForkY;
	//�ȉ��A�t�H�[�N(�摜)�̑傫�����i�[����ϐ�
	int m_forkWidth;
	int m_forkHeight;
	//�ȉ��A�o����(�摜)�̍��W���i�[����ϐ�
	int m_berunX;
	int m_berunY;
	//�ȉ��A�o����(�摜)�̑傫�����i�[����ϐ�
	int m_berunWidth;
	int m_berunHeight;
	//�ȉ��AENTERKEY TAP�̕����̍��W���i�[����ϐ�
	int m_pushEnterX;
	int m_pushEnterY;
	//�ȉ��AENTERKEY TAP�̕����̑傫�����i�[����ϐ�
	int m_pushEnterWidth;
	int m_pushEnterHeight;
	//�ȉ��ASTART�̕����̍��W���i�[����ϐ�
	int m_startX;
	int m_startY;
	//�ȉ��ASTART�̕����̑傫�����i�[����ϐ�
	int m_startWidth;
	int m_startHeight;
	//�ȉ��AEXIT�̕����̍��W���i�[����ϐ�
	int m_exitX;
	int m_exitY;
	//�ȉ��AEXIT�̕����̑傫�����i�[����ϐ�
	int m_exitWidth;
	int m_exitHeight;
	//�ȉ��A�j��l���̍��W�̏����l���i�[����ϐ�
	int m_beforePlayerMX;
	int m_beforePlayerMY;
	//�ȉ��A�j��l���̍��W�̖ړI�n���i�[����ϐ�
	int m_afterPlayerMX;
	int m_afterPlayerMY;
	//�ȉ��A�j��l���̑傫�����i�[����ϐ�
	int m_playerMWidth;
	int m_playerMHeight;
	//�ȉ��A����l���̍��W�̏����l���i�[����ϐ�
	int m_beforePlayerWX;
	int m_beforePlayerWY;
	//�ȉ��A����l���̍��W�̖ړI�n���i�[����ϐ�
	int m_afterPlayerWX;
	int m_afterPlayerWY;
	//�ȉ��A����l���̑傫�����i�[����ϐ�
	int m_playerWWidth;
	int m_playerWHeight;
	//�^�C�g���w�i�̓����x���i�[����ϐ�
	float m_alphaTitleImage;
	//�^�C�g�������̓����x���i�[����ϐ�
	float m_alphaWord;
	//�o����(�摜)�̓����x���i�[����ϐ�
	float m_alphaBerun;
	//START�̓����x���i�[����ϐ�
	float m_alphaStart;
	//EXIT�̓����x���i�[����ϐ�
	float m_alphaExit;
	//�^�C�g�����S�ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_titleLogoMoveTime;
	//�i�C�t(�摜)�̎��Ԃ��i�[����ϐ�
	float m_knifeMoveTime;
	//�t�H�[�N(�摜)�ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_forkMoveTime;
	//�j��l���ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_playerMMoveTime;
	//����l���ړ��̂��߂̎��Ԃ��i�[����ϐ�
	float m_playerWMoveTime;
	//�^�C�g�����S�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforeTitleLogoPos;
	//�^�C�g�����S�̈ړ���̍��W��Z�߂�ϐ�
	CVector2D m_afterTitleLogoPos;
	//�^�C�g�����S�̑傫����Z�߂�ϐ�
	CVector2D m_titleLogoSize;
	//�i�C�t(�摜)�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforeKnifePos;
	//�i�C�t(�摜)�̈ړ���̍��W��Z�߂�ϐ�
	CVector2D m_afterKnifePos;
	//�i�C�t(�摜)�̑傫����Z�߂�ϐ�
	CVector2D m_knifeSize;
	//�t�H�[�N(�摜)�̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforeForkPos;
	//�t�H�[�N(�摜)�̈ړ���̍��W��Z�߂�ϐ�
	CVector2D m_afterForkPos;
	//�t�H�[�N(�摜)�̑傫����Z�߂�ϐ�
	CVector2D m_forkSize;
	//�o����(�摜)�̈ړ���̍��W��Z�߂�ϐ�
	CVector2D m_berunPos;
	//�o����(�摜)�̑傫����Z�߂�ϐ�
	CVector2D m_berunSize;
	//ENTERKEY TAP�̍��W��Z�߂�ϐ�
	CVector2D m_enterWordPos;
	//ENTERKEY TAP�̑傫����Z�߂�ϐ�
	CVector2D m_enterWordSize;
	//START�̍��W��Z�߂�ϐ�
	CVector2D m_startPos;
	//START�̑傫����Z�߂�ϐ�
	CVector2D m_startSize;
	//EXIT�̍��W��Z�߂�ϐ�
	CVector2D m_exitPos;
	//EXIT�̑傫����Z�߂�ϐ�
	CVector2D m_exitSize;
	//�j��l���̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerMPos;
	//�j��l���̈ړ���̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerMPos;
	//�j��l���̑傫����Z�߂�ϐ�
	CVector2D m_playerMSize;
	//����l���̈ړ��O�̍��W��Z�߂�ϐ�
	CVector2D m_beforePlayerWPos;
	//����l���̈ړ���̍��W��Z�߂�ϐ�
	CVector2D m_afterPlayerWPos;
	//����l���̑傫����Z�߂�ϐ�
	CVector2D m_playerWSize;
	//�^�C�g�����S�̈ړ��������������ǂ����𔻒肷��t���O
	bool m_moveTitleLogo;
	//�i�C�t�̈ړ��������������ǂ����𔻒肷��t���O
	bool m_moveKnife;
	//�t�H�[�N�̈ړ��������������ǂ����𔻒肷��t���O
	bool m_moveFork;
	//�j��l���̈ړ��������������ǂ����𔻒肷��t���O
	bool m_movePlayerM;
	//����l���̈ړ��������������ǂ����𔻒肷��t���O
	bool m_movePlayerW;
	//�o�����̕\���������������ǂ����𔻒肷��t���O
	bool m_drawBerun;
	//�^�C�g�����S�ĕ\�����I��������ǂ����𔻒肷��t���O
	bool m_drawTitle;
	//ENTERKEY TAP�̕\�����ŏ��̃^�C�~���O�̂݉��������邽�߂̃t���O
	bool m_enterTapFlag;
	//ENTERKEY TAP�����x�̉��Z���Z��؂�ւ��邽�߂̃t���O
	bool m_alphaEnterTapSwich;
	//�^�C�g���̏�Ԃ��i�[����t���O(false = �����͏��(���S��ENTERKEY TAP�\��),true = ���͏��(���j���[))
	bool m_titleState;
	//��x�ł����j���[��Ԃɓ��������ǂ����̃t���O
	bool m_firstMenu;
	//��x�ł��L������\���������ǂ����̃t���O
	bool m_firstChara;
	//���j���[�̂ǂ��瑤(START/EXIT)��I�����Ă��邩���i�[����t���O(false = START,true = EXIT)
	bool m_titleMenu;
public:

	CTitle();
	~CTitle();
	void Update();
	void Draw();
};

#endif