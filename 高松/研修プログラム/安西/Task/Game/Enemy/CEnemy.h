/**
* @file		CEnemy.h
* @brief	“G‚Ì‹@”\
*
* @author	ryoji anzai
*/

#ifndef ENEMY_GUARD
#define ENEMY_GUARD

#include "../../System/Task/CTask.h"


class CEnemy : public CTask
{
public:
	CEnemy();
	CEnemy(int i);
	~CEnemy();
	void Update();
	void Render();
};

#endif // !ENEMY_GUARD