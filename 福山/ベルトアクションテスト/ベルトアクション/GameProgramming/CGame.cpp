#include "CGame.h"
#include "CCollision.h"

int *CGame::mpMapData = 0;	//マップのデータ
int CGame::mMapRows = 0;	//マップの行数
int CGame::mMapCols = 0;	//マップの列数
int CGame::mDispRows = 0;	//表示する行数
int CGame::mDispCols = 0;	//表示する列数
int CGame::status = 0;		//ゲーム全体のステータス
CRectangle *CGame::mpMap;


/* getIndex
v:座標上の位置
return:マップデータ配列の添字
座標上の位置に該当するマップデータ配列の添字を返す
*/
int CGame::getIndex(const CVector2 &v) {
	int col = v.x + CGame::mMapCols / 2.0f;
	int row = (v.y + 0.5f - CGame::mMapRows / 2.0f) * -1.0f + 0.5f;
	return row * CGame::mMapCols + col;
}
/* getPosition
i:マップデータ配列の添字
return:座標上の位置
マップデータ配列の添字から、座標上の位置を返す
*/
CVector2 CGame::getPosition(int i) {
	return CVector2(
		i % CGame::mMapCols - CGame::mMapCols / 2.0f + 0.5f,
		-i / CGame::mMapCols + CGame::mMapRows / 2.0f - 0.5f);
}
/* getPosition
row:マップデータでの行(0～)
col:マップデータでの列(0～)
return:座標上の位置
マップデータ上での行と列から、座標上の位置を返す
*/
CVector2 CGame::getPosition(int row, int col) {
	return CVector2(
		col - CGame::mMapCols / 2.0f + 0.5f,
		-row + CGame::mMapRows / 2.0f - 0.5f);
}

/*
向き(fwd)へ移動した四角形(rec)が、障害物に衝突している場合、
戻す量(rtn)を設定しtrueを戻す。
*/
bool CGame::collision(CRectangle &rec, CVector2 &fwd, CVector2 *rtn) {
	int index = CGame::getIndex(rec.position);
	//右へ移動
	if (fwd.x > 0.0f) {
		if (CGame::mpMapData[index + 1 - MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index + 1 - MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + 1] != 0 && CCollision::collision(rec, CGame::mpMap[index + 1], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + 1 + MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index + 1 + MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
	}
	//左へ移動
	if (fwd.x < 0.0f) {
		if (CGame::mpMapData[index - 1 - MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index - 1 - MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - 1] != 0 && CCollision::collision(rec, CGame::mpMap[index - 1], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - 1 + MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index - 1 + MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
	}
	//上に移動
	if (fwd.y > 0.0f) {
		if (CGame::mpMapData[index - MAP_COLS - 1] != 0 && CCollision::collision(rec, CGame::mpMap[index - MAP_COLS - 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index - MAP_COLS], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - MAP_COLS + 1] != 0 && CCollision::collision(rec, CGame::mpMap[index - MAP_COLS + 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
	}
	//下へ移動
	if (fwd.y < 0.0f) {
		if (CGame::mpMapData[index + MAP_COLS - 1] != 0 && CCollision::collision(rec, CGame::mpMap[index + MAP_COLS - 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index + MAP_COLS], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + MAP_COLS + 1] != 0 && CCollision::collision(rec, CGame::mpMap[index + MAP_COLS + 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
	}
	return false;
}
