#include <stdio.h>
#include"Test.h"
#include"Main.h"

Test *test;
Test test;


class Task:public Test
{
public:
	virtual void Update();

	Task *Next;
	Task *Prev;

};

Task *Root;
Task *Tail;


void init(){
	Task *t = new Task();

	test.Update;
	
	Root = t;
	Tail = t;

}

void Kill(){
	Task *n;
	n = Root;

}

void Main(){
	Task *n;
	n = Root;



	

}