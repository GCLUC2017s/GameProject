#ifndef CSCENEMANAGER_HPP
#define CSCENEMANAGER_HPP
#include "../Scene/CScene.h"

class CSceneManager :public CScene{
private:
	static CSceneManager *mSceneManager;

public:
	int NextNo;

	static CSceneManager *GetInstance(); //GetInstance

	void ChangeScene(eSceneNo no);	//ƒV[ƒ“Ø‚è‘Ö‚¦
	void DeleteScene();			//KILL
	
	void SceneMain();

	virtual	void Update(){};	//virtual@
	virtual	void Render(){};

};
#endif