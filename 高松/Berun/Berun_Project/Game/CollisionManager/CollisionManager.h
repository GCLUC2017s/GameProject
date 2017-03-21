#ifndef COLLISIONMANAGER_INCLUDE_GUARD
#define COLLISIONMANAGER_INCLUDE_GUARD
#include "../CollisionA/CCollisionA.h"

class CCollisionManager
{
private:
	static CCollisionManager* mp_instance;	//シングルトン化のためのポインタ
protected:
	CCollisionA *mp_head;		//先頭要素を指すポインタ
	CCollisionA *mp_tail;		//末尾要素を指すポインタ
public:
	CCollisionManager();
	~CCollisionManager();
	void Regist(CCollisionA *p);
	CCollisionA *UnRegist(CCollisionA *p);
	void UnRegistAll();
	void CheckHitAll();
	//CCollisionManagerを生成して変数に格納
	static CCollisionManager* GetInstance();
	//格納されているものを削除
	static void ClearInstance();
};

#endif