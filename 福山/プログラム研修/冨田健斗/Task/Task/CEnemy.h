#ifndef INCLUDE_HEADER_HPP_CEnemy
#define INCLUDE_HEADER_HPP_CEnemy
#include "CTask.h"


class  CEnemy : public CTask
{
public:
	CEnemy(){};

	void Update(){
		printf("enemy%f‚Å‚·\n",next);
	};

};

#endif