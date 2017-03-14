/*
* @file		CPlayer.h
* @brief	�v���[���[�@�\
*
* @author	Ryoji Anzai
*/
#ifndef CPLAYER_INCLUDE_GUARD
#define CPLAYER_INCLUDE_GUARD
#include "../Global.h"

#define PLAYER_MOVE 4

class CPlayer
{
	CImage *m_littlePlayerM;
	CImage *m_littlePlayerW;
	CImage *m_stageImage;

	//�ȉ��A�L�����N�^�[�̍��W���i�[����ϐ�
	int m_playerX;
	int m_playerY;
	//�ȉ��A�L�����N�^�[�̑傫�����i�[����ϐ�
	int m_playerWidth;
	int m_playerHeight;
	//�L�����N�^�[�̍��W���i�[����ϐ�
	CVector2D m_playerPos;
	//�L�����N�^�[�̑傫�����i�[����ϐ�
	CVector2D m_playerSize;
	//�L�����N�^�[�̌������i�[����t���O(false = �E,true = ��)
	bool m_charaDirection;
public:
	CPlayer();
	~CPlayer();
	void Update();
	void Draw();
};

#endif // !CPLAYER_INCLUDE_GUARD