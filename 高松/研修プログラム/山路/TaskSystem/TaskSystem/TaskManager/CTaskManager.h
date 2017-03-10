/**
*@file
*@brief  タスク管理クラス
*@author 山路
*/

#ifndef  TASKMANAGER_HPP
#define  TASKMANAGER_HPP
#include "../Task/CTask.h"

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
	//リスト全削除関数
	void ListDestroy();
	//更新一時停止関数
	void Pause();
};

#endif