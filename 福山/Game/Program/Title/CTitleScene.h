#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include"../Map/CMap.h"

class CTitleScene {

public:
	CMap map;
	CTitle title;
	CRectangle mFade;	//�A���[�g�\���l�p�`




	float count;//�X�N���[�����o�̂���

	int status;

	float FirstX;

	float Save;

	CTitleScene();
	void Init();
	void Update();
	/* �ǐՒ��\��
	*/
	void FadeDisp();
};
#endif