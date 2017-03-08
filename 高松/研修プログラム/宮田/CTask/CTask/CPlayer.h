
#ifndef CPLAYER_GAURD
#define CPLAYER_GAURD
#include<stdio.h>
#include"CTask.h"

class CPlayerTask  {
public:

	CPlayerTask(){
		printf("CPlayerのコンストラクト");
	}
	~CPlayerTask() {
		printf("CPlayerのデストラクト");
	
	}

	void Update(){
	
	
	}



};
#endif // !INCLUDEGAURD