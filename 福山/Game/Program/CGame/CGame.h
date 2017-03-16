#ifndef GAME_HPP
#define GAME_HPP
#include "../Define/define.h"
#include "../Vector/CVector2.h"
#include "../Graphic/CRectangle.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"


class CGame {
public:
	static int *mpMapData;	//マップデータ
	static int mMapRows;	//マップの行数
	static int mMapCols;	//マップの列数
	static int mDispRows;	//表示する行数
	static int mDispCols;	//表示する列数
	static CRectangle *mpMap; //Mapの四角形データ
	static CRectangle *mEnemy; //
	static CPlayer *mPlayer;   //
	static int status;

	/* getIndex
	v:座標上の位置
	return:マップデータ配列の添え字
	座標上の位置からマップデータの添え字を返す
	*/
	static int getIndex(const CVector2 &v);
	/* getPosition
	index:マップデータ配列の添え字
	return:座標上の位置
	*/
	static CVector2 getPosition(const CVector2 &v);
	static CEnemy00 getEnemy(CEnemy00 &ene00);
	static CPlayer getPlayer(CTask &t);
};

#endif