#include"CPlayer.h"


CPlayerTask::CPlayerTask() {
	printf("CPlayerのコンストラクト\n");
}
CPlayerTask::~CPlayerTask() {
	printf("CTaskのデストラクタ\n");
}
void CPlayerTask::Update() {

}
void CPlayerTask::Draw() {
	printf("CPlayer書いてます");
}