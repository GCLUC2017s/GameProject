/**
*@file
*@brief  タスクシステム元クラス
*@author 山路
*/

#ifndef  TASK_HPP
#define  TASK_HPP
#include <string.h>
#include <stdio.h>

class CTask 
{
private:
	CTask *mp_head;			//先頭要素を指すポインタ
	CTask *mp_tail;			//末尾要素を指すポインタ
	CTask *mp_prev;			//手前の要素を指すポインタ
	CTask *mp_next;			//次の要素を指すポインタ
public:
	CTask();
	~CTask();
	//仮想関数 継承先の更新処理を優先
	virtual void Update();
	friend class CTaskManager;
};

class CTaskManager : public CTask
{
public:
	//オブジェクト追加関数
	void Add(CTask *p);
	//オブジェクト削除関数
	void Destroy(CTask *p);
};

#endif