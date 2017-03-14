#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame() {

	new CMap();
	new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	new CPlayer();
}

CGame::~CGame() {
}
void CGame::Update() {
	


}
void CGame::Draw() {


}