#include "CMap.h"
#include "CGame.h"
#include  <Windows.h>

/*�@init
�}�b�v�f�[�^�z�񂩂�\���ł���l�p�`��ݒ肷��
*/

void CMap::init() {
	BackGround = new CTexture;

	BackGround->load("�w�i.tga");

	const float area_y = CGame::mMapRows / 2;
	const float area_x = CGame::mMapCols / 2;

	BGrect.setVertex(-area_x, area_y, area_x, -area_y);
	BGrect.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	BGrect.setuv(BackGround,0,0,300,30);



}

CMap::~CMap() {
	if (BackGround){
		delete BackGround;
		BackGround = 0;
	}

}
CMap::CMap() : BackGround(0) {
}



void CMap::update() {

}

/* render
�}�b�v�̎l�p�`��`�悷��
*/

void CMap::render() {
	BGrect.render();
}