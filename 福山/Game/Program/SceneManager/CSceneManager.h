#ifndef CSCENEMANAGER_HPP
#define CSCENEMANAGER_HPP
#include "../Scene/CScene.h"
class CSceneManager{
private:
	static CSceneManager *mSceneManager;
public:
	int NextNo;

	int status;

	static CSceneManager *GetInstance(); //GetInstance

	void ChangeScene(eSceneNo no);	//シーン切り替え
	void DeleteScene();			//KILL
	void SceneMain();
	CSceneManager();
	~CSceneManager();

};
#endif