/**
* @file		CTask.h
* @brief	TaskManagerSystem
*
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

#include <stdio.h>
#include "../CTask/CTask.h"

class CTaskManager
{
protected:
	CTask *m_head;		//先頭要素を指すポインタ
	CTask *m_tail;		//末尾要素を指すポインタ
public:
	CTaskManager();
	~CTaskManager();
	//リスト追加関数
	void Add(CTask *p);
	//リスト内削除関数
	void Kill(CTask *p);
	//リスト内全削除関数
	void AllKill(CTask *p);
	void KillCheck();
	//リスト更新関数
	void AllUpdate();
	//リスト描画関数
	void AllRender();
	//更新停止関数
	void Pause();
};

#endif