#include"CMap.h"


CMap::CMap() : CTask(0){
	m_background = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Back"));
	m_wood= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Wood"));

}
CMap::~CMap() {


}
void CMap::Update() {

	m_background->SetRect(0,0,1280,768);

	m_wood->SetRect(0,0,230,280);

}

void  CMap::Draw() {

	m_background->Draw();

	m_wood->Draw();
}