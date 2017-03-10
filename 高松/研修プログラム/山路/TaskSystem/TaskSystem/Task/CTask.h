/**
*@file
*@brief  タスクシステム元クラス
*@author 山路
*/

#ifndef  TASK_HPP
#define  TASK_HPP
#include <stdio.h>

class CTask 
{
private:
	CTask *mp_prev;				//手前の要素を指すポインタ
	CTask *mp_next;				//次の要素を指すポインタ
	//符号無しの整数型
	unsigned int m_udPriority;  //更新優先順位格納
	unsigned int m_rdPriority;  //描画優先順位格納
public:
	CTask();
	~CTask();
	//仮想関数 継承先の更新処理を優先
	virtual void Update();
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

class CTaskManager
{
private:
	CTask *mp_head;			//先頭要素を指すポインタ
	CTask *mp_tail;			//末尾要素を指すポインタ
public:
	CTaskManager();
	//リスト更新関数
	void ListUpdate();
	//リスト描画関数
	void ListRender();
	//リスト追加関数
	void Add(CTask *p);
	//リスト削除関数
	void Destroy();
};

#endif