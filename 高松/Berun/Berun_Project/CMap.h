#ifndef CMAP_INCLUDE_GUARD
#define CMAP_INCLUDE_GUARD
#include "../Global.h"

class CMap {
private:
	CImage *m_background;

	/*!
	@brief	コンストラクタ
	**/
	CMap();
	/*!
	@brief	描画処理
	@retval 無し
	**/
	void Draw();
	
}


#endif // CMAP_GURAD
