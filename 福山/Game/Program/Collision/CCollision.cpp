#include "CCollision.h"
#include <math.h>


bool CCollision::Collision(const CRectangle &r1,const CRectangle &r2){

	float w_xl1 = r1.triangle1.x1 + r1.position.x;
	float w_xr1 = r1.triangle1.x3 + r1.position.x;
	float w_yt1 = r1.triangle1.y1 + r1.position.y;
	float w_yb1 = r1.triangle1.y3 + r1.position.y;
	float w_xl2 = r2.triangle1.x1 + r2.position.x;
	float w_xr2 = r2.triangle1.x3 + r2.position.x;
	float w_yt2 = r2.triangle1.y1 + r2.position.y;
	float w_yb2 = r2.triangle1.y3 + r2.position.y;



	if (w_xl1 < w_xr2 && w_xl2 < w_xr1 && w_yt1 > w_yb2 && w_yb1 < w_yt2){
		return true;
	}

	return false;
}