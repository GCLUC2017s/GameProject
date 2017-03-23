#include"../Title/CTitle.h"
#include"../Graphic/CTexture.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h"
#include "CExplain.h"

#define FILE_START	"../CG\\title\\gamestart\\"
#define FILE_TITLE	"../CG\\title\\logo\\"
#define FILE_TEXTBOX	"../CG\\title\\Explain\\"

#define TEXT_X 640
#define TEXT_Y 212
#define TEXTBOX_X 640
#define TEXTBOX_Y 212




//TitleSceneで表示されるテクスチャの設定。

void CExplain::Init(){

	//text1を表示
	mpText1 = new CTexture();	//テクスチャクラスのインスタンス作成
	mpText1->load(FILE_TEXTBOX"setumei0.tga");	//テクスチャファイル読み込み

	mText1.SetUv(mpText1, 0, 0, TEXT_X, TEXT_Y);//TGA上の座標

	//text2を表示
	mpText2 = new CTexture();	//テクスチャクラスのインスタンス作成
	mpText2->load(FILE_TEXTBOX"setumei1.tga");	//テクスチャファイル読み込み

	mText2.SetUv(mpText2, 0, 0, TEXT_X, TEXT_Y);//TGA上の座標

	//text3を表示
	mpText3 = new CTexture();	//テクスチャクラスのインスタンス作成
	mpText3->load(FILE_TEXTBOX"setumei2.tga");	//テクスチャファイル読み込み

	mText3.SetUv(mpText3, 0, 0, TEXT_X, TEXT_Y);//TGA上の座標


	//テキストボックスの表示
	mpTextBox = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTextBox->load(FILE_TEXTBOX"windowW.tga");	//テクスチャファイル読み込み

	mTextBox.SetUv(mpTextBox, 0, 0, TEXTBOX_X, TEXTBOX_Y);//TGA上の座標

}
CExplain::~CExplain(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}
}
CExplain::CExplain() : mpTexture(0),patternflag(false){
	mMyNumber = E_MTITLE;
	mPriorityR = E_MTITLE;
	mPriorityU = E_MTITLE;

	mText1.SetVertex(-7.0f, -1.3f, 7.0f, -7.0f);//表示範囲
	mText1.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	mText2.SetVertex(-7.0f, -1.3f, 7.0f, -7.0f);//表示範囲
	mText2.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	mText3.SetVertex(-7.0f, -1.3f, 7.0f, -7.0f);//表示範囲
	mText3.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	mTextBox.SetVertex(-7.0f, -1.3f, 7.0f, -7.0f);//表示範囲
	mTextBox.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	mBackBlack.SetVertex(-6.0f, -2.3f, 6.0f, -5.8f);//表示範囲
	mBackBlack.SetColor(0.0f, 0.0f, 0.0f, 1.0f);

	
}

void CExplain::Update(){

};
void CExplain::Render(CVector2 pos) {

		mBackBlack.position = pos;
		mBackBlack.position.y = DISP_Y / 20;

		mTextBox.position = pos;
		mTextBox.position.y = DISP_Y / 20;

		mText1.position = pos;
		mText1.position.y = DISP_Y / 20;

		mText2.position = pos;
		mText2.position.y = DISP_Y / 20;

		mText3.position = pos;
		mText3.position.y = DISP_Y / 20;


		mBackBlack.Render();

		mTextBox.Render();

		switch (textpattern)
		{
		case 0 :
			if (CKey::once(VK_RETURN)){
				textpattern = 1;
			}
			break;
		case 1:
			mText1.Render();
			if (CKey::once(VK_RETURN)){
				textpattern = 2;
			}
			break;
		case 2:
			mText2.Render();
			if (CKey::once(VK_RETURN)){
				textpattern = 3;
			}
			break;
		case 3:
			mText3.Render();
			if (CKey::once(VK_RETURN)){
				patternflag = true;
			}
			break;

		}


	}

