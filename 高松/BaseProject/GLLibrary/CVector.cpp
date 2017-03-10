#include "CVector.h"


CVector3D::CVector3D(const CVector4D& v) { x = v.x; y = v.y; z = v.z; }
CVector3D CVector3D::operator = (const CVector4D& v) { x = v.x; y = v.y; z = v.z; return *this; }