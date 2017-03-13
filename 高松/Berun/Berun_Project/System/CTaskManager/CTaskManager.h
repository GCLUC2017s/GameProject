/**
* @file		CTaskManager.h
* @brief	タスクシステム管理クラス
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

#include <stdio.h>
#include "../CTask/CTask.h"

class CTaskManager
{
private:
	static CTaskManager* mp_instance;	//シングルトン化のためのポインタ
protected:
	CTask *mp_head;		//先頭要素を指すポインタ
	CTask *mp_tail;		//末尾要素を指すポインタ
public:
	CTaskManager();
	~CTaskManager();
	//リスト追加関数
	void Add(CTask *p);
	//リスト内削除関数
	CTask* Destroy(CTask *p);
	//リスト内全削除関数
	void AllDestroy();
	//リスト更新関数
	void AllUpdate();
	//リスト描画関数
	void AllRender();
	//更新停止関数
	void Pause();
	//CTaskManagerを生成して変数に格納
	static CTaskManager* GetInstance();
	//格納されているものを削除
	static void ClearInstance();
};

#endif