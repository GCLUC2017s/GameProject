#include "CGame.h"


CGame::CGame() {

	new CMap();
	new CTutorial(g_tutorialDataPath[g_tutorialNo]);
}

CGame::~CGame() {
}
void CGame::Update() {
	


}
void CGame::Draw() {


}