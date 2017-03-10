#include "CMap.h"
#include "../CImageManager.h"
#include "Global.h"
#include"CEnemy.h"

//マップデータ（仮）
static int State1Data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
//クラス変数の定義
CMap* CMap::mainMap;
CMap::CMap() {
	

	  m_backkumo = 1000;
	  m_backkumo2 = 1300;
	  m_backkumo3 = 1600;
	  m_kumopatarnA = 0;
	  m_kumopatarnB = 0;
	  m_kumopatarnC = 0;
	  kumo = 0;
	  kumo2 = 0;
	  kumo3= 0;
	//他のソースファイルで使うマップオブジェクトを自身に設定
	mainMap = this;
	FILE* fp;
	//ファイルを読み込みモードで開く
	fopen_s(&fp, stageDataPath[stageNo], "r");
	if (fp) {
		char tag[32];
		while (!feof(fp)) {
			//ファイルからの読み込み
			fscanf_s(fp, "%s", tag,32);
			//読み込んだ文字がMapDataなら
			if (strcmp(tag, "MapData") == 0) {
				//幅と高さを読み込む
				fscanf_s(fp, "%d %d", &m_width,&m_height);
				for (int i = 0; i < m_height; i++) {
					for (int j = 0; j < m_width; j++) {
						//幅と高さ分マップデータを読み込む
						fscanf_s(fp, "%d", &m_mapData[i][j]);
					}
				}
			}
		}
	}
	fclose(fp);
	m_img = CImageManager::Get("MapTip");

	/*
	//仮データ
	for (int i = 0; i < MAP_HEIGHT;i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_mapData[i][j] = State1Data[i][j];
		}
	}
	*/

	

}
void CMap::Draw() {
	if (stageNo == 1) {
		 
	
		
		m_imghaikei = CImageManager::Get("Haikei2");
		m_imghaikei->setRect(0, 0, 1280, 768);
		m_imghaikei->setSize(1280, 768);
		m_imghaikei->Draw();

		m_imghaikei = CImageManager::Get("Kumo");
		m_imghaikei->setRect(30, 45, 135, 130);
		m_imghaikei->setSize(128, 128);
		if (m_kumopatarnA==0) {
			srand(time(nullptr));
			kumo = rand() % 4;
			m_kumopatarnA++;
		}
		if (m_kumopatarnB == 0) {
			srand(time(nullptr));
			kumo2 = rand() % 6;
			m_kumopatarnB++;
		}
		if (m_kumopatarnC == 0) {
			srand(time(nullptr));
			kumo3 = rand() % 2;
			m_kumopatarnC++;
		}
		m_imghaikei->setPos(m_backkumo, 50*kumo);
		m_imghaikei->Draw();
		m_imghaikei->setPos(m_backkumo2, 30*kumo2);
		m_imghaikei->Draw();
		m_imghaikei->setPos(m_backkumo3, 10*kumo3);
		m_imghaikei->Draw();
		
		if (m_backkumo >= -100) {
			m_backkumo -= 3;
		}
		if (m_backkumo <= -100) {
			m_backkumo = 1200;
			m_kumopatarnA--;
		}

		if (m_backkumo2 >= -100) {
			m_backkumo2 -= 2;
			}
		if (m_backkumo2 <= -100) {
			m_backkumo2 = 1200;
			m_kumopatarnB--;
		}

		if (m_backkumo3 >= -100) {
			m_backkumo3 -= 1;
		}
		if (m_backkumo3 <= -100) {
			m_backkumo3 = 1200;
			m_kumopatarnC--;
		}

		
		
		
		
	}
		if (f ==true) {
			//幅と高さ分繰り返したマップチップを配置・表示する
			for (int i = 0; i < MAP_HEIGHT; i++) {
				for (int j = 0; j < MAP_WIDTH; j++) {
					if (m_mapData[i][j] == 0) continue;
					//マップチップの種類を取得
					int t = m_mapData[i][j];
					//座標設定
					m_img->setPos(j * 32, i * 32);
					//表示サイズ設定
					m_img->setSize(32, 32);
					//表示領域設定
					m_img->setRect(t * 32, 0, t * 32 + 32, 32);
					//描画
					m_img->Draw();
				}
			}
		}
	
	

}
int CMap::GetTipData(CVector2D pos) {
	int x = pos.x / 32;	//座標→チップ単位の場所に変換
	int y = pos.y / 32;
	//はみ出しを防ぐ
	if (x < 0) x = 0;
	if (x >= MAP_WIDTH) x = MAP_WIDTH-1;
	if (y < 0) y = 0;
	if (y >= MAP_HEIGHT) y = MAP_HEIGHT - 1;
	//posの場所のチップの種類を返す
	return m_mapData[y][x];
}