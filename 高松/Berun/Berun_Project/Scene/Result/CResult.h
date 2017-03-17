/**
* @file		CResult.h
* @brief	リザルトシーンクラス
* @author	yuki yamaji
*/

#ifndef RESULT_GUARD
#define RESULT_GUARD

#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"
#include "../Game/Item/CItem.h"

#define IMAGE_MAX 6

class CResult : public CScene
{
private:
	CImage *mp_img[IMAGE_MAX];
	int m_step;
	//int m_corsol;
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
};

#endif