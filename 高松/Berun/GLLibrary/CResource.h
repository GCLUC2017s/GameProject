#pragma once
#pragma once
/**
* @file		AsSet.h
* @brief	リソース管理クラス
*
* @author	shinya nagakawa
*/


#include <map>

class CResource {
	std::string m_name;
public:
	CResource():m_name(""){}
	/**
	* @fn
	* コンストラク
	* @brief コンストラクタ
	* @param name [in]　名前
	*/
	CResource(std::string name) :m_name(name){}
	/**
	* @fn
	* デストラクタ
	* @brief デストラクタ
	*/
	virtual ~CResource() {};
	/**
	* @fn
	* 名前の取得
	* @brief 名前の取得
	* @return 名前
	*/
	std::string GetName() const {
		return m_name;
	}
	/**
	* @fn
	* リソース開放処理
	* @brief リソース開放処理
	*/
	virtual void Release() {};
	friend class CResourceManager;

};
class CResourceManager {
private:
	std::map<std::string, CResource*> m_list;
	static CResourceManager*	m_instance;
public:
	static CResourceManager* GetInstance() {
		if (!m_instance) m_instance = new CResourceManager;
		return m_instance;
	}
	/**
	* @fn　リソースを全て破棄する
	* @brief リソースを全て破棄する
	*/
	static void ClearInstance() {
		if (!m_instance) return;
		delete m_instance;
		m_instance = nullptr;
	}
	CResourceManager();
	~CResourceManager();
	/**
	* @fn
	* リソースの追加
	* @brief リソースの追加
	*/
	void Add(CResource* res);
	void Add(std::string name, CResource* res);
	/**
	* @fn
	* リソースの取得
	* @brief リソースのの取得
	* @param name [in]　リソースの名前
	* @return リソース
	*/
	CResource* Get(std::string name);
	/**
	* @fn
	* リソースの削除
	* @brief リソースのの削除
	* @param name [in]　リソースの名前
	*/
	void Delete(std::string name);

};