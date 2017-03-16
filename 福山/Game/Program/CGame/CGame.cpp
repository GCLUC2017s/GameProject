#include "CGame.h"

int *CGame::mpMapData = 0;	//マップのデータ
int CGame::mMapRows = 0;	//マップの行数
int CGame::mMapCols = 0;	//マップの列数
int CGame::mDispRows = 0;	//表示する行数
int CGame::mDispCols = 0;	//表示する列数
int CGame::status = 0;		//ゲーム全体のステータス
CRectangle *CGame::mpMap;

/* getPosition
i:マップデータ配列の添字
return:座標上の位置
マップデータ配列の添字から、座標上の位置を返す
*/
CVector2 CGame::getPosition(CVector2 &v) {
	return v;
}
