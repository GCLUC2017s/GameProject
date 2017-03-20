#ifndef GAME_HPP
#define GAME_HPP
#include "../Define/define.h"
#include "../Vector/CVector2.h"
#include "../Graphic/CRectangle.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"


class CGame {
public:
	/* getPosition
	return:座標上の位置
	*/
	static CVector2 mGetPlayerPos();
	static CVector2 getPosition(const CVector2 &v);
	static CEnemy00 getEnemy(CEnemy00 &ene00);
	static float	GetPlayerAxis();
	static CPlayer getPlayer(CTask &t);
	/*タスク属性がほしいときに使う
	　number　ほしいもののナンバー
	 キャストをして使う 
	 (例)
	 CPlyer *pl;

	 pl = (CPlayer*)getStatus(E_PLAYER);

	 */
	static CTask *getStatus(int number);
	static void Delete(CTexture **t);
};

#endif