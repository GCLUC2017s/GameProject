#include"CMap.h"

CMap::CMap() {
	m_background = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Background"));
}
void CMap::Draw() {

}