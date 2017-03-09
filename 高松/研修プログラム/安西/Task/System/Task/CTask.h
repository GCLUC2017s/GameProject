/**
* @file		CTask.h
* @brief	TaskSystem
*
* @author	ryoji anzai
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include<stdio.h>

class CTask
{
protected:
	CTask *m_prev;					//前のアドレスを格納するポインター
	CTask *m_next;					//次のアドレスを格納するポインター
public:
	CTask();						//CTaskクラスのコンストラクタ
	~CTask();						//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Render();			//派生先クラスでの描写を行う関数
	friend class CTaskManager;
};

class CTaskManager
{
protected:
	CTask *m_head;					//現在のアドレスと前のアドレスを繋ぐためのポインター
	CTask *m_tail;					//現在のアドレスと次のアドレスを繋ぐためのポインター
public:
	CTaskManager();
	~CTaskManager();
	void Add(CTask *p);
	void Kill();
	void AllUpdate();
	void AllRender();
};

#endif // !TASK_GUARD