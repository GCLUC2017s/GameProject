
#ifndef CPLAYER_GAURD
#define CPLAYER_GAURD
#include<stdio.h>
#include"CTask.h"

class CPlayerTask  {
public:

	CPlayerTask(){
		printf("CPlayer�̃R���X�g���N�g");
	}
	~CPlayerTask() {
		printf("CPlayer�̃f�X�g���N�g");
	
	}

	void Update(){
	
	
	}



};
#endif // !INCLUDEGAURD