#include<stdio.h>

class CTask
{
protected:
	CTask *m_prev;	//前のアドレスを格納するポインター
	CTask *m_next;	//次のアドレスを格納するポインター
public:
	CTask();		//CTaskクラスのコンストラクタ
	~CTask();		//CTaskクラスのデストラクタ
	virtual void Update();	//派生先クラスでの更新を行う関数
	virtual void Render();	//派生先クラスでの描写を行う関数
	friend class CTaskManager;
};

class CTaskManager
{
protected:
public:
	CTaskManager();
	~CTaskManager();
	void Update();
	void Render();
	void Add(CTask *p);
};