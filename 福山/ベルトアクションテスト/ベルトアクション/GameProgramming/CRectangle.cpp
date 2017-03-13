#include "CRectangle.h"

/* updateä÷êî
positionÇÃílÇçXêVÇ∑ÇÈ
*/
void CRectangle::update() {
}

void CRectangle::setVertex(float left, float top, float right, float bottom) {
	degree = 0;
	deg_enabled = false;
	triangle1.x1 = left; triangle1.y1 = top;
	triangle1.x2 = left; triangle1.y2 = bottom;
	triangle1.x3 = right; triangle1.y3 = bottom;
	triangle2.x1 = left; triangle2.y1 = top;
	triangle2.x2 = right; triangle2.y2 = bottom;
	triangle2.x3 = right; triangle2.y3 = top;
	triangle1.v1 = CVector2(left, top); triangle1.v2 = CVector2(left, bottom); triangle1.v3 = CVector2(right, bottom);
	triangle2.v1 = CVector2(left, top); triangle2.v2 = CVector2(right, bottom); triangle2.v3 = CVector2(right, top);

}


void CRectangle::setColor(float r, float g, float b, float a) {
	deg_enabled = false;
	degree = 0;
	triangle1.r = r;
	triangle1.g = g;
	triangle1.b = b;
	triangle1.a = a;
	triangle2.r = r;
	triangle2.g = g;
	triangle2.b = b;
	triangle2.a = a;
}