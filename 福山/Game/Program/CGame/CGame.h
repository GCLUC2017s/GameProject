/*
メソッド一覧
冨田健斗
*/
#ifndef GAME_HPP
#define GAME_HPP
#include "../Define/define.h"
#include "../Vector/CVector2.h"
#include "../Graphic/CRectangle.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"


class CGame {
private:
public:

	/* getPosition
	return:座標上の位置
	*/
	static CVector2 mGetPlayerPos();
	static CVector2 getPosition(const CVector2 &v);
	static CEnemy00 getEnemy(CEnemy00 &ene00);
	static CVector2 CameraPos();
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
	 /*テクスチャをデリートするときに使う*/
	static void Delete(CTexture **t);
	 /*フェード関数 speed = フェードの速さ a = ALPHA*/
	static void Fade(float speed, CRectangle *rect,float a);
	static void FadeOut(float speed, CRectangle *rect);
	/*拡大縮小関数
	true 拡大, false 縮小
	x,y 上限
	speed 速さ
	rect 四角
	*/
	static void RectScaling(bool flag, float x, float y,float speed,CRectangle *rect);
	/*時間経過でTRUEにする timeにかかる時間を書く saveは保存用 使うところ路各自管理する <-　使いにくいので直したいやり方がわからず*/
	static bool FlagTime(float time,float fps,float *save);
	/*ステージエネミー判断*/
 


};

#endif