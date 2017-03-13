#include "CPlayer.h"
#include "CGame.h"
#include"CKey.h"
#include"CTexture.h"
#include "define.h"
#define JUMP_FIRST_SPEED 0.2

void CPlayer::init() {
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("plkame.tga");	//テクスチャファイル読み込み
	m_Player.setuv(mpTexture, 0, 0, 49, 50);
	muki = 2;
	mForward = CVector2(1.0f, 0.0f);
	axis = mPos.y;
}


CPlayer::~CPlayer() {
	if (mpTexture) {
		delete mpTexture;
		mpTexture = 0;
	}
}



//プレイヤー描画
CPlayer::CPlayer() : mVelocity(0.07f), mpTexture(0),status(3),speed_jump(JUMP_FIRST_SPEED){
	//四角形の頂点設定
	m_Player.setVertex(-0.5, 0.5f, 0.5f, -0.5f);
	//四角形の色を設定
	m_Player.setColor(1.0f, 1.0f, 1.0f, 1.0f);

}


const float gravity = 0.01;//重力


void CPlayer::MethodJump(){ //ジャンプ処理メソッド

	mPos.y -= gravity; //重力処理
	mPos.y += speed_jump; //飛ぶ処理
	speed_jump -= gravity;//減速処理

	m_Player.setColor(1.0f, 0.0f, 0.2f, 1.0f);

	if (mPos.y < axis){//現在の軸についたとき
		mPos.y = axis; //元いた地面の"Y"に戻す
		m_Player.setColor(1.0f, 1.0f, 1.0f, 1.0f);
		speed_jump = JUMP_FIRST_SPEED; 
		enabled_jump = false; //終了

	}


	
}

const float player_limit_left = -MAP_LIMIT_X / 2;  //ＰＬが進める上限(左)
const float player_limit_top = -0.2;			   //ＰＬが進める上限(上)
const float player_limit_right = MAP_LIMIT_X / 2;  //ＰＬが進める上限(右)
const float player_limit_bottom = -MAP_LIMIT_Y / 2 + 0.2;//ＰＬが進める上限(下)

void CPlayer::update() {

	//四角形の位置を設定
	m_Player.position = mPos;
	
	//上の辺の左端と右端の少し内側の座標を求め、座標に該当する添え字を取得する
	int li = CGame::getIndex(mPos + CVector2(-0.3f, -0.5f));
	int ri = CGame::getIndex(mPos + CVector2(0.3f, -0.5f));
	int li2 = CGame::getIndex(mPos + CVector2(-0.3f, 0.5f));
	int ri2 = CGame::getIndex(mPos + CVector2(0.3f, 0.5f));

	//移動の処理

		//switch (jumps)
		//{
		//case true:

		//	jump += 0.2f;

		//	if (jump <= 1){
		//		player.position.y -= 0.01f; //踏ん張り
		//	}
		//	else if (jump <= 50){ //ジャンプ中
		//		mForward = CVector2(0.0f, 1.0f);
		//		if (jump != 0)mPos.y += 0.1f / jump;
		//	}

		//	if (jump >= 3){ //地上に落ちた時
		//		jump = 1.0f;
		//		jumps = false;
		//	}

		//	break;

		//case false:


		//	break;
		//}
	
	//ジャンプ
	if (CKey::push(' ') || enabled_jump) {
		if (!enabled_jump){ //ジャンプしていないとき
			enabled_jump = true;
		}
		MethodJump();
	}


	//上移動
	if (CKey::push(VK_UP) && axis < player_limit_top) { //軸が上限に達していないとき
		const float speedy = 1.0f;
		mForward = CVector2(0.0f, speedy);
		mPos += mForward * mVelocity;
		axis += mForward.y * mVelocity;

	}

	//下移動
	if (CKey::push(VK_DOWN) && axis > player_limit_bottom) {//軸が上限に達していないとき
		status = 0;
		const float speedy = -1.0f;
		mForward = CVector2(0.0f, speedy);
		mPos += mForward * mVelocity;
		axis += mForward.y * mVelocity;

	}

	//右移動
	if (CKey::push(VK_RIGHT)) {
		muki = 2;
		status = 0;
		const float speedx = 3.0f; 
		mForward = CVector2(speedx, 0.0f);
		mPos += mForward * mVelocity;
	}

	//左移動
	if (CKey::push(VK_LEFT)) {


		muki = 4;
		status = 0;

		const float speedx = -3.0f;
		mForward = CVector2(speedx, 0.0f);
		mPos += mForward * mVelocity;

	}	

	

	/*あたり判定*/
	if (mPos.y > player_limit_top && !enabled_jump){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = player_limit_top;
		axis = mPos.y; //軸をもとに戻す
	}
	if (mPos.y < player_limit_bottom){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = player_limit_bottom;
		axis = mPos.y; //軸をもとに戻す
	}

	if (mPos.x >= player_limit_right || mPos.x <= player_limit_left){ //マップ外に出ると元の位置に戻す(X)
		mPos.x = m_Player.position.x;
	}
	/*あたり判定終了*/




	//スイッチ

	/*向き
		0がデフォルト
		1が上向き
		2が右向き
		3が下向き
		4が左向き
	*/
	switch (muki)
	{
	//通常時
	case 0:
	
		break;
	//上向いてるとき
	case 1:

		break;
	//右向いてるとき
	case 2:
		//アニメーション
		m_Player.setuv(mpTexture, 100, 0, 149, 50);
		framecnt++;
		if (framecnt > 30){
			m_Player.setuv(mpTexture, 100, 50, 149, 100);
			framecnt2++;
			if (framecnt2 > 30){
				framecnt = 0;
				framecnt2 = 0;
			}
		}
		break;

	//下向いてるとき
	case 3:

		break;
	//左向いてるとき
	case 4:
		//アニメーション
		m_Player.setuv(mpTexture, 51, 0, 99, 50);
		framecnt++;
		if (framecnt > 30){
			m_Player.setuv(mpTexture, 51, 50, 99, 100);
			framecnt2++;
			if (framecnt2 > 30){
				framecnt = 0;
				framecnt2 = 0;
			}
		}
		break;


		//透明時の処理　何もしない
	case 5:
		break;

	}
	

	//四角形の位置を設定
	m_Player.position = mPos;


}

void CPlayer::render(){
	//プレイヤーの描画
	m_Player.render();
}

//行と列から座標上の位置を設定する
void CPlayer::setPos(int row, int col) {
	//行と列から座標上の位置を設定する
	
	mPos = CGame::getPosition(row, col);
	mTarget = mPos;
}

void CPlayer::setPos(){
	const CVector2 first_pos = CVector2(player_limit_left+CGame::mDispCols,
										(player_limit_top + player_limit_bottom) / 2); //上限(X)と上限(Y)
	mPos = first_pos;

}
