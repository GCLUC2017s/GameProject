#include "CBase.h"
#include "CGame.h"

/* setPos(int row, int col, CVector2 fwd)
row:行の指定
col:列の指定
fwd:移動方向（正規化されたベクトル）
行と列から座標上の座標を設定し、移動方向を設定する
*/
void CBase::setPos(int row, int col) {
	setPos(row, col, CVector2(0.0f, 1.0f));
}
/* setPos(int row, int col, CVector2 fwd)
row:行の指定
col:列の指定
fwd:移動方向（正規化されたベクトル）
行と列から座標上の座標を設定し、移動方向を設定する
*/
void CBase::setPos(int row, int col, CVector2 fwd) {
	//行と列から座標上の位置を設定する
	mPos = CGame::getPosition(row, col);
	//移動方向設定
	mForward = fwd;
}
