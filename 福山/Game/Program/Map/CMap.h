/**/
#ifndef MAP_HPP
#define MAP_HPP
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <stdio.h>
#include "../Base/CBase.h"
#define TREE_MAX  10
#define BEFORE_AND_AFTER 2 
class CMap :public CTask{
private:
	CRectangle mGround;			//�w�i�̒n��
	CRectangle mSky;		//��
	CRectangle mTree[BEFORE_AND_AFTER][TREE_MAX];		//��
	enum MyTree
	{
		E_BEFORE,E_AFTER
	};
	CTexture *mGroundTex; //�w�i�̃e�N�X�`��
	CTexture *mSkyTex;
	CTexture *mTreeTex;

	float	mLeftSc;		//���X�N���[���p
	float	mRightSc;	//�E�X�N���[���p
	bool	mFlagSc;	//���������t���O

public:
	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};
#endif