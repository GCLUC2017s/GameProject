/**
* @file		CEnemy.h
* @brief	“G‚Ì‹@”\
*
* @author	ryoji anzai
*/

#ifndef ENEMY_GUARD
#define ENEMY_GUARD

#include "../System/CTask.h"


class CEnemy : CTask
{
public:
	CEnemy();
	~CEnemy();
	void Update();
	void Render();
};

#endif // !ENEMY_GUARD