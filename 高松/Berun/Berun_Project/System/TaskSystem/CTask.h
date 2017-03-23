/**
* @file		CTask.h
* @brief	タスクシステム元クラス
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD
//更新順序
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Tutorial,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_destroyFlg;				//削除フラグ
	bool m_pauseFlg;				//更新停止フラグ
	//符号無しの整数型	
	unsigned int m_updatePrio;	    //更新優先順位格納
	unsigned int m_drawPrio;		//描画優先順位格納
	int m_id;
	CTask *mp_prev;					//前のアドレスを格納するポインタ
	CTask *mp_next;					//次のアドレスを格納するポインタ
public:
	CTask();						//CTaskクラスのコンストラクタ
	CTask(int id, unsigned int updateprio, unsigned int drawPrio);
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Draw();			//派生先クラスでの描写を行う関数
	//更新順位設定関数
	void SetUpdatePrio(unsigned int updatePrio)
	{
		m_updatePrio = updatePrio;
	}
	//描画順位設定関数
	void SetDrawPrio(unsigned int drawPrio)
	{
		m_drawPrio = drawPrio;
	}
	//更新順位取得関数
	int GetUpdatePrio()
	{
		return m_updatePrio;
	}
	//描画順位取得関数
	int GetDrawPrio()
	{
		return m_drawPrio;
	}
	//更新順位変更
	void ChangeUpdatePrio(unsigned int updatePrio)
	{
		unsigned int prio = m_updatePrio;
		m_updatePrio = updatePrio;
		updatePrio = prio;
	}
	//描画順位変更
	void ChangeDrawPriority(unsigned int drawPrio)
	{
		unsigned int prio = m_drawPrio;
		m_drawPrio = drawPrio;
		drawPrio = prio;
	}
	void SetKill() 
	{
		m_destroyFlg = true;
	}
	friend class CTaskManager;
};

#endif