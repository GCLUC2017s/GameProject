#ifndef INCLUDE_GUARD
#define INCLUDE_GUARD

#include "../System/CTask.h"

#endif // !INCLUDE_GUARD

class CEnemy : CTask
{
public:
	CEnemy();
	~CEnemy();
	void Update();
	void Render();
};