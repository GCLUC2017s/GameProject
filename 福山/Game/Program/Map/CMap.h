/**/
#ifndef MAP_HPP
#define MAP_HPP
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <stdio.h>
#include "../Base/CBase.h"


class CMap :public CTask{
private:
	CRectangle mGround;			//�w�i�̒n��
	CRectangle mSky;		//��
	CRectangle mTree;		//��

	CTexture *mGroundTex; //�w�i�̃e�N�X�`��
	CTexture *mSkyTex;
	CTexture *mTreeTex;

public:
	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};
#endif