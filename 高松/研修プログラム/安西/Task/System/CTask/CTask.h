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
	bool m_kill;
	CTask *m_prev;					//前のアドレスを格納するポインター
	CTask *m_next;					//次のアドレスを格納するポインター
public:
	CTask();						//CTaskクラスのコンストラクタ
	virtual ~CTask();						//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Render();			//派生先クラスでの描写を行う関数
	friend class CTaskManager;
};

class CTaskManager
{
protected:
	CTask *m_head;				
	CTask *m_tail;				
public:
	CTaskManager();
	~CTaskManager();
	void Add(CTask *p);
	void Kill(CTask *p);
	void KillCheck();
	void AllUpdate();
	void AllRender();
};

#endif // !TASK_GUARD