#include <stdio.h>




class Task{
public:
	virtual void Update();

	Task *Prev;
	Task *Next;

	Task() :Prev(0), Next(0){};
	~Task();

};

class Text :public Task{
public:

	void Update(){
		
		printf("testone");

	}
	

};

class Text2 :public Task{
public:

	void Update(){

		printf("testtwo");

	}

};

class Taskmanager:public Task{
public:
	Task *Root;
	Task *Tail;




	void Update(){};
};


int Main(){
	



}