/**
* @file		CTask.h
* @brief	タスクシステム元クラス
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

enum E_UdPriority
{
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};

enum E_DwPriority
{
	eDWP_Map,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_destroyFlg;				//削除フラグ
	bool m_pauseFlg;				//更新停止フラグ
	//符号無しの整数型	
	unsigned int m_udPriority;	    //更新優先順位格納
	unsigned int m_dwPriority;		//描画優先順位格納
	CTask *mp_prev;					//前のアドレスを格納するポインタ
	CTask *mp_next;					//次のアドレスを格納するポインタ
public:
	CTask();						//CTaskクラスのコンストラクタ
	CTask(unsigned int udpriority, unsigned int rdPriority);
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Draw();			//派生先クラスでの描写を行う関数
	//更新順位設定関数
	void SetUDPriority(int udPriority)
	{
		m_udPriority = udPriority;
	}
	//描画順位設定関数
	void SetDWPriority(int dwPriority)
	{
		m_dwPriority = dwPriority;
	}
	//更新順位取得関数
	int GetUDPriority()
	{
		return m_udPriority;
	}
	//描画順位取得関数
	int GetDWPriority()
	{
		return m_udPriority;
	}
	//更新順位変更
	void ChangeUpdatePriority(int udPriority)
	{
		m_udPriority = udPriority;
	}
	//描画順位変更
	void ChangeDrawPriority(int dwPriority)
	{
		m_dwPriority = dwPriority;
	}
	friend class CTaskManager;
};

#endif