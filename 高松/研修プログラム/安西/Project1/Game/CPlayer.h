#ifndef INCLUDE_GUARD
#define INCLUDE_GUARD

#include "../System/CTask.h"

#endif // !INCLUDE_GUARD

class CPlayer : CTask 
{

public:
	CPlayer();
	~CPlayer();
	void Update();
	void Render();

};