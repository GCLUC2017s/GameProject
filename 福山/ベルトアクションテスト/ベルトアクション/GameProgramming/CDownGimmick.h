#ifndef CDOWNGIMMICK_HPP
#define CDOWNGIMMICK_HPP

#include "CRectangle.h"
#include "define.h"
#include "CBase.h"

class CDownGimmick : public CBase{
public:
	CRectangle mRect_left;
	CRectangle mRect_right;
	CVector2 leftpos, rightpos, middlepos,hozleftpos,hozrightpos;

	bool enabled; //�܂��Ă��邩�ǂ���
	bool go_enabld;//Let's_go���邩���Ȃ���

	float speed, plusx; //���x�̕ϐ��@X�ɑ����Ƃ��p�̕ϐ�
	static int rowsuu; //���ڂ����f�p

	CTexture	*mpTexture;
	~CDownGimmick();

	CDownGimmick();

	void init();
	void update();
	void render();
	void setPos(int row, int col);

};
#endif