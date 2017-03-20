#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#define FULL_SCREEN 0
#define GAME_MODE	1

#include "stdafx.h"
#include "Global.h"
#include "../System/TaskSystem/CTaskManager.h"
#include "../Scene/CSceneManager.h"

void display(void) {
	//各バッファーをクリア
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//行列の初期化
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//カメラ行列を反映
	glLoadMatrixf(CCamera::GetCamera()->GetMatrix().f);
	//---------------------------------------
	// 表示
	//---------------------------------------

	CSceneManager::GetInstance()->Update();
	CSceneManager::GetInstance()->Draw();

	//----------------------------------

	glutSwapBuffers();

}
void init(void)
{
	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'R');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton6, VK_SHIFT);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);


//	CInput::SetMouseInside(true); 
	CInput::UpDate();
	CInput::UpDate();


	//ライト設定
	CLight::SetType(0, CLight::eLight_Direction);
	CLight::SetPos(0, CVector3D(0, 200, 200));
	CLight::SetDir(0, CVector3D(-2, -2, 1).GetNormalize());
	CLight::SetColor(0, CVector3D(0.8f, 0.8f, 0.8f), CVector3D(0.8f, 0.8f, 0.8f));

//	CLight::SetType(1, CLight::eLight_Point);
	CLight::SetColor(1, CVector3D(0.0f, 0.0f, 0.0f), CVector3D(1.0f, 1.0f, 1.0f));
	CLight::SetAttenuation(1,0.10f);
//	CLight::SetRadiationAngle(1, Utility::DgreeToRadian(5.0f));

	CLight::SetFogParam(CVector4D(1, 1, 1, 1), 300, 400);
	//カメラ初期化
	CCamera::GetCamera()->LookAt(	CVector3D(0,100,-150),
									CVector3D(0,10,0),
									CVector3D(0.0, 1.0, 0.0));


	
	//CResourceManagerで一括管理(前はCImageManagerだったもの)
	//画像読み込み
	CResourceManager::GetInstance()->Add("Black", CImage::LoadImage("Title/Black.png"));
	CResourceManager::GetInstance()->Add("BlackSecond", CImage::LoadImage("Title/Black.png"));
	CResourceManager::GetInstance()->Add("White", CImage::LoadImage("Title/White.png"));
	CResourceManager::GetInstance()->Add("Logo", CImage::LoadImage("Title/Window.png"));
	CResourceManager::GetInstance()->Add("Title", CImage::LoadImage("BackGround/Background_M01.png"));
	CResourceManager::GetInstance()->Add("PleaseEnter", CImage::LoadImage("Title/Enterkey.png"));
	CResourceManager::GetInstance()->Add("TitleLogo", CImage::LoadImage("Title/Titlelogo.png"));
	CResourceManager::GetInstance()->Add("Knife", CImage::LoadImage("Title/Knife.png"));
	CResourceManager::GetInstance()->Add("Fork", CImage::LoadImage("Title/Fork.png"));
	CResourceManager::GetInstance()->Add("Berun", CImage::LoadImage("Title/Baran.png"));
	CResourceManager::GetInstance()->Add("Start", CImage::LoadImage("Title/Start.png"));
	CResourceManager::GetInstance()->Add("Exit", CImage::LoadImage("Title/Exit.png"));
	CResourceManager::GetInstance()->Add("Clear", CImage::LoadImage("Result/Clear.png"));
	CResourceManager::GetInstance()->Add("RankA", CImage::LoadImage("Result/A.png"));
	CResourceManager::GetInstance()->Add("RankB", CImage::LoadImage("Result/B.png"));
	CResourceManager::GetInstance()->Add("RankC", CImage::LoadImage("Result/C.png"));
	CResourceManager::GetInstance()->Add("RankS", CImage::LoadImage("Result/S.png"));
	CResourceManager::GetInstance()->Add("Rank", CImage::LoadImage("Result/Rank.png"));
	CResourceManager::GetInstance()->Add("Select", CImage::LoadImage("Result/Item5.png"));
	CResourceManager::GetInstance()->Add("Item", CImage::LoadImage("Result/Itemhyouji.png"));
	CResourceManager::GetInstance()->Add("Arrow", CImage::LoadImage("Result/Yajirusi.png"));
	CResourceManager::GetInstance()->Add("Craft", CImage::LoadImage("Result/Tsukurulogo.png"));
	CResourceManager::GetInstance()->Add("ItemSelect", CImage::LoadImage("Result/Itemsentaku.png"));
	CResourceManager::GetInstance()->Add("ResultTitle", CImage::LoadImage("Result/Titlegamen.png"));
	CResourceManager::GetInstance()->Add("TutorialM", CImage::LoadImage("TutoText/Serihu.png"));
	CResourceManager::GetInstance()->Add("TutorialW", CImage::LoadImage("Tutotext/Serihu2.png"));
	CResourceManager::GetInstance()->Add("PlayerM", CImage::LoadImage("Player/Player_m.png"));
	CResourceManager::GetInstance()->Add("PlayerW", CImage::LoadImage("Player/Player_w.png"));
	CResourceManager::GetInstance()->Add("LittlePlayerM", CImage::LoadImage("Player/PlayerM.png"));
	CResourceManager::GetInstance()->Add("LittlePlayerW", CImage::LoadImage("Player/LittlePlayerW.png"));
	CResourceManager::GetInstance()->Add("PlayerMShadow", CImage::LoadImage("Player/Player_m2.png"));
	CResourceManager::GetInstance()->Add("PlayerWShadow", CImage::LoadImage("Player/Player_w2.png"));
	CResourceManager::GetInstance()->Add("CharaSelectBackGround", CImage::LoadImage("CharaSelect/Tutorial_background.png"));
	CResourceManager::GetInstance()->Add("CharaSelectLogo", CImage::LoadImage("CharaSelect/Tutorial1.png"));
	CResourceManager::GetInstance()->Add("PlayerMLogoWord1", CImage::LoadImage("CharaSelect/PlayerMWord1.png"));
	CResourceManager::GetInstance()->Add("PlayerMLogoWord2", CImage::LoadImage("CharaSelect/PlayerMWord2.png"));
	CResourceManager::GetInstance()->Add("PlayerMLogoWord3", CImage::LoadImage("CharaSelect/PlayerMWord3.png"));
	CResourceManager::GetInstance()->Add("PlayerMLogoWord4", CImage::LoadImage("CharaSelect/PlayerMWord4.png"));
	CResourceManager::GetInstance()->Add("PlayerWLogoWord1", CImage::LoadImage("CharaSelect/PlayerWWord1.png"));
	CResourceManager::GetInstance()->Add("PlayerWLogoWord2", CImage::LoadImage("CharaSelect/PlayerWWord2.png"));
	CResourceManager::GetInstance()->Add("PlayerWLogoWord3", CImage::LoadImage("CharaSelect/PlayerWWord3.png"));
	CResourceManager::GetInstance()->Add("BackGroundMoning", CImage::LoadImage("BackGround/Background_M01.png"));
	CResourceManager::GetInstance()->Add("BackGroundNoon", CImage::LoadImage("BackGround/Background_N02.png"));
	CResourceManager::GetInstance()->Add("ResultBackGround", CImage::LoadImage("BackGround/Game_Background/Background_Ni02.png"));
	CResourceManager::GetInstance()->Add("BackGroundMoningBack", CImage::LoadImage("BackGround/Back/Background_M_2.png"));
	CResourceManager::GetInstance()->Add("BackGroundNoonBack", CImage::LoadImage("BackGround/Back/Background_ M_2.png"));
	CResourceManager::GetInstance()->Add("BackGroundEveingBack", CImage::LoadImage("BackGround/Back/Background_E_2.png"));
	CResourceManager::GetInstance()->Add("BackGroundNightBack", CImage::LoadImage("BackGround/Back/Back_00.png"));
	CResourceManager::GetInstance()->Add("BackGround", CImage::LoadImage("BackGround/Back/Back_02.png"));
	CResourceManager::GetInstance()->Add("BackGround2", CImage::LoadImage("BackGround/Back/Back_02.png"));
	CResourceManager::GetInstance()->Add("Back_03", CImage::LoadImage("BackGround/Back/Back_03.png"));
	CResourceManager::GetInstance()->Add("Carrot", CImage::LoadImage("Enemy/Carrot.png"));
	CResourceManager::GetInstance()->Add("Meter", CImage::LoadImage("Enemy/Meter_01.png"));
	//サウンド読み込み
	CSound::GetInstance()->GetSound("TITLE_BGM")->Load("BGM/Title.wav", 1);
	CSound::GetInstance()->GetSound("CHARASELECT_BGM")->Load("BGM/CharaSelect.wav", 1);
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Load("BGM/Area_M.wav", 1);
	CSound::GetInstance()->GetSound("AREA_N_BGM")->Load("BGM/Area_N.wav", 1);
	CSound::GetInstance()->GetSound("AREA_E_BGM")->Load("BGM/Area_E.wav", 1);
	CSound::GetInstance()->GetSound("AREA_Ni_BGM")->Load("BGM/Area_Ni.wav", 1);
	CSound::GetInstance()->GetSound("RESULT_BGM")->Load("BGM/Result.wav", 1);
	CSound::GetInstance()->GetSound("GAMEOVER_BGM")->Load("BGM/GameOver.wav", 1);
	
}


void release()
{
	CResourceManager::ClearInstance();
}
void resize(int w, int h)
{

	glViewport(0, 0, w, h);
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	CCamera::GetCamera()->SetScreenRect(CRect(0, 0, (float)w, (float)h));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	CMatrix mProj;
	mProj.Perspective(Utility::DgreeToRadian(45.0), (float)w / (float)h, 1.0, 10000.0);
	CCamera::GetCurrent()->SetProjectionMatrix(mProj);
	glLoadMatrixf(mProj.f);


}



void idle(void)
{
	static LARGE_INTEGER time;
	static LARGE_INTEGER time_buf;
	static long t_buf=0;
	HDC glDc = wglGetCurrentDC();
	//ウィンドウハンドル取得
	HWND hWnd = WindowFromDC(glDc);
	//ユーザーの操作対象になっているウインドウを取得
	HWND h = GetForegroundWindow();
	while (h && hWnd != h)
	{
		//非アクティブに
		Sleep(10);
		h = GetForegroundWindow();
	}
	//現在のシステムのカウント数を取得
	QueryPerformanceCounter(&time_buf);

	CInput::UpDate();
	display();
	//現在のシステムのカウント数を取得
	QueryPerformanceCounter(&time);
	//現在のシステムのカウント数を取得
	if (t_buf == 0) {
		t_buf = time.QuadPart - time_buf.QuadPart;
	}
	else {
		t_buf = (t_buf + (time.QuadPart - time_buf.QuadPart)) / 2;
	}

	CFPS::Wait();

	char title[32];
	sprintf_s(title, "sample fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
	glutSetWindowTitle(title);

}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '\033':  // '\033' は ESC の ASCII コード
		glutLeaveMainLoop();
	default:
		break;
	}
}
void wheel(int wheel_number, int direction, int x, int y)
{
	CInput::addMouseWheel(direction);
}



int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	glutInit(argcp, argv);



	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("sample");
#if (FULL_SCREEN)
	int nMode = 0;
	DEVMODE devMode;
	while (EnumDisplaySettings(NULL, nMode++, &devMode)) {
		if (devMode.dmPelsWidth != SCREEN_WIDTH || devMode.dmPelsHeight != SCREEN_HEIGHT)continue;
		if (devMode.dmBitsPerPel != 32)continue;
		if (ChangeDisplaySettings(&devMode, CDS_TEST) == DISP_CHANGE_SUCCESSFUL)break;
	}
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
	glutFullScreen();
#else
#endif

	glewInit();

	SetCurrentDirectory(L"data");


	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glEnable(GL_ALPHA_TEST);





	init();


	



	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutReshapeFunc(resize);
	glutMouseWheelFunc(wheel);

	
	

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop();

	release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}

void DrawSphere(CVector3D &p, float radius, CVector4D &color) {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(p.x,p.y,p.z);
	glColor4fv(color.v);
	glutSolidSphere(radius, 8, 8);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}
void DrawLine(CVector3D &s, CVector3D &e, CVector4D &color) {
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor4fv(color.v);
	glVertex3fv(s.v);
	glVertex3fv(e.v);
	glEnd();
	glEnable(GL_LIGHTING);
}
void DrawLine(CVector2D &s, CVector2D &e,CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//各種機能を無効に
	//カリング無効
	glDisable(GL_CULL_FACE);
	//ライティング無効
	glDisable(GL_LIGHTING);
	//デプステスト無効
	glDisable(GL_DEPTH_TEST);
	//
	//正射投影の行列を作成
	//
	CMatrix	mProj = CMatrix(
		2.0f / CCamera::GetCurrent()->GetWhidth(), 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / CCamera::GetCurrent()->GetHeight(), 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	//投影行列を専用の物に設定
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//モデル＆ビュー行列を再設定
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_LINES);
	//カラー設定
	glColor4fv(color.v);
	//描画

	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();


	//元の行列と設定に戻す
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}