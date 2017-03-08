#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include "CTask.h"

class  CPlayer : public CTask{
public:
	 
	void Update(){
		printf("player%f‚Å‚·\n",next);
	}

};

#endif