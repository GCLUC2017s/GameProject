#include "CMap.h"
#include  <Windows.h>
#include "../Define/define.h"
#include "../MyNumber/CMyNumber.h"
#define FIRST_R_NO_BG -100 //�w�i�̃����_�[�����ݒ�
#define FIRST_U_NO_BG -100 //�w�i�̃A�b�v�f�[�^�����ݒ�
#define FILE_BG_GROUND		"../CG/background/ground/"
#define FILE_BG_SKY			"../CG/background/sky/"
#define FILE_BG_TREE		"../CG/background/tree/"

void CMap::Init() {
	mGroundTex = new CTexture;
	mSkyTex = new CTexture;
	mTreeTex = new CTexture;

	mGroundTex->load(FILE_BG_GROUND"ground_background.tga");
	mSkyTex->load(FILE_BG_SKY"background\sky.tga");
	mTreeTex->load(FILE_BG_TREE"background_tree.tga");

	const float area_top = MAP_LIMIT_Y / 8;
	const float area_bottom = -MAP_LIMIT_Y / 2;
	const float area_x = MAP_LIMIT_X / 2;

	mGround.SetVertex(-area_x, area_top, area_x, area_bottom);
	mGround.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mGround.SetUv(mGroundTex, 0, 0, 1600, 400);

	mSky.SetVertex(-area_x, area_top, area_x, area_bottom);
	mSky.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mSky.SetUv(mGroundTex, 0, 0, 1600, 400);
	
	mTree.SetVertex(-area_x, area_top, area_x, area_bottom);
	mTree.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mTree.SetUv(mGroundTex, 0, 0, 1600, 400);


}

CMap::~CMap() {
	if (mGroundTex){
		delete mGroundTex;
		mGroundTex = 0;
	}

}
CMap::CMap() :mGroundTex(0) {
	
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
	mGround.Render();
}