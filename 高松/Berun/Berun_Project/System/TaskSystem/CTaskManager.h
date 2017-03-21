/**
* @file		CTaskManager.h
* @brief	タスクシステム管理クラス
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

#include "CTask.h"

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
	//リスト内指定削除関数
	void DestroyAppoint();
	//リスト内全削除関数
	void DestroyAll();
	//リスト更新関数
	void UpdateAll();
	//リスト描画関数
	void DrawAll();
	CTask GetTask();
	//CTaskManagerを生成して変数に格納
	static CTaskManager* GetInstance();
	//格納されているものを削除
	static void ClearInstance();

	void Number(int i);
};

#endif