
#ifndef CPLAYER_GAURD
#define CPLAYER_GAURD
#include<stdio.h>
#include"CTask.h"

class CPlayerTask : public CTask {
public:

	CPlayerTask();
	~CPlayerTask();

	virtual	void Update();
	virtual void Draw();
	
};
#endif // !INCLUDEGAURD