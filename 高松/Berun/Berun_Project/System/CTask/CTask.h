/**
* @file		CTask.h
* @brief	TaskSystem
*
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include<stdio.h>

class CTask
{
protected:
	bool m_kill;
	bool m_pauseflg;			//更新停止フラグ
	//符号無しの整数型
	unsigned int m_udPriority;  //更新優先順位格納
	unsigned int m_rdPriority;  //描画優先順位格納
	CTask *m_prev;					//前のアドレスを格納するポインター
	CTask *m_next;					//次のアドレスを格納するポインター
public:
	CTask();						//CTaskクラスのコンストラクタ
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Render();			//派生先クラスでの描写を行う関数
	//更新順位設定関数
	void SetUDPriority(int udPriority)
	{
		m_udPriority = udPriority;
	}
	//描画順位設定関数
	void SetRDPriority(int rdPriority)
	{
		m_rdPriority = rdPriority;
	}
	//更新順位取得関数
	int GetUDPriority()
	{
		return m_udPriority;
	}
	//描画順位取得関数
	int GetRDPriority()
	{
		return m_udPriority;
	}
	friend class CTaskManager;
};

#endif // !TASK_GUARD