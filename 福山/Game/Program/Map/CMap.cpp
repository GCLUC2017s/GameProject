#include "CMap.h"
#include  <Windows.h>
#include "../Define/define.h"
#include "../MyNumber/CMyNumber.h"
#define FIRST_R_NO_BG -100 //�w�i�̃����_�[�����ݒ�
#define FIRST_U_NO_BG -100 //�w�i�̃A�b�v�f�[�^�����ݒ�

void CMap::Init() {
	BackGround = new CTexture;

	BackGround->load("../CG\\background\\ground\\ground_background.tga");

	const float area_top = MAP_LIMIT_Y / 8;
	const float area_bottom = -MAP_LIMIT_Y / 2;
	const float area_x = MAP_LIMIT_X / 2;

	BGrect.SetVertex(-area_x, area_top, area_x, area_bottom);
	BGrect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	BGrect.SetUv(BackGround,0,0,1600,400);



}

CMap::~CMap() {
	if (BackGround){
		delete BackGround;
		BackGround = 0;
	}

}
CMap::CMap() : BackGround(0) {
	
		mPriorityR = E_BACKGROWND;		//�����_�[���Ԃ̏����ݒ�
		mPriorityU = E_BACKGROWND;		//�A�b�v�f�[�^���Ԃ̏����ݒ�
		mMyNumber = E_BACKGROWND;		//�����̐ݒ�
	
}



void CMap::Update() {

}

/* render
�}�b�v�̎l�p�`��`�悷��
*/

void CMap::Render() {
	BGrect.Render();
}