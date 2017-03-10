#include "CResource.h"


CResourceManager*	CResourceManager::m_instance = nullptr;

CResourceManager::CResourceManager() {

}
CResourceManager::~CResourceManager() {
	for (std::map<std::string, CResource*>::iterator it = m_list.begin(); it != m_list.end(); it++) {
		if (it->second) {
			it->second->Release();
			delete it->second;
		}
		it->second = nullptr;
	}
	m_list.clear();
}

void CResourceManager::Add(CResource* res) {
	if (!res) return;
	m_list[res->m_name] = res;
}
void CResourceManager::Add(std::string name,CResource* res) {
	if (!res) return;
	res->m_name = name;
	m_list[res->m_name] = res;
}
CResource* CResourceManager::Get(std::string name) {
	return m_list[name];
}
void CResourceManager::Delete(std::string name) {
	CResource* tmp = m_list[name];
	if (tmp) {
		delete tmp;
		m_list[name] = nullptr;
	}
}
