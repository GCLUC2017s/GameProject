#ifndef INCLUDE_HEADER_HPP_CTask
#define INCLUDE_HEADER_HPP_CTask

#include <stdio.h>


class  CTask
{
public:

	CTask *next;
	CTask *prev;

	CTask() :next(0), prev(0){};
	~CTask(){};

	virtual void Update(){};

};

#endif
