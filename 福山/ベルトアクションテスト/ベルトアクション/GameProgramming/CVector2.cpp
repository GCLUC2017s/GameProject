#include "CVector2.h"
#include <math.h>

CVector2::CVector2() : x(0.0f), y(0.0f) {}
CVector2::CVector2(float x, float y) : x(x), y(y) {}

void CVector2::operator+=(const CVector2 &v) { x += v.x; y += v.y; }
void CVector2::operator*=(const CVector2 &v) { x *= v.x; y *= v.y; }

const CVector2 CVector2::operator+(const CVector2 &v) const { return CVector2(x + v.x, y + v.y); }
const CVector2 CVector2::operator-(const CVector2 &v) const { return CVector2(x - v.x, y - v.y); }
const CVector2 CVector2::operator*(float f) const { return CVector2(x * f, y * f); }

float CVector2::dot(const CVector2 &v) {
	return x * v.x + y * v.y;
}

const CVector2 CVector2::normalize() {
	float len = length();
	return CVector2(x /= len, y /= len);
}

float CVector2::length() {
	return sqrtf(x*x + y*y);
}