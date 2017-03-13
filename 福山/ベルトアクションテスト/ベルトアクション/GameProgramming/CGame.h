#pragma once
#include "define.h"
#include "CVector2.h"
#include "CRectangle.h"

class CGame {
public:
	static int *mpMapData;	//マップデータ
	static int mMapRows;	//マップの行数
	static int mMapCols;	//マップの列数
	static int mDispRows;	//表示する行数
	static int mDispCols;	//表示する列数
	static CRectangle *mpMap;	//Mapの四角形データ
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
	マップデータの添え字から、座標上の位置を返す
	*/
	static CVector2 getPosition(int index);
	/* getPosition
	row:マップデータでの行(0～)
	col:マップデータでの列(0～)
	return:座標上の位置
	マップデータ上での行と列から、座標上の位置を返す
	*/
	static CVector2 getPosition(int row, int col);

	static bool collision(CRectangle &rec, CVector2 &forward, CVector2 *rtn);
};