/*
キャラクターのベースクラス
担当者　冨田健斗
*/
#ifndef BASE_HPP
#define BASE_HPP

#define SIZE_PLAYER_Y 1.0f							//プレイヤーのサイズ_Y
#define SIZE_PLAYER_X 0.8f						//プレイヤーのサイズ_X
#define SIZE_LOWBOSS_X 2.5f
#define SIZE_LOWBOSS_Y 2.5f

#define SIZE_ENEMY00_Y 1  //エネミー00のサイズ_Y
#define SIZE_ENEMY00_X 1 //エネミー00のサイズ_X
#define SIZE_ENEMY01_Y 1 //エネミー01のサイズ_Y
#define SIZE_ENEMY01_X 1 //エネミー01のサイズ_X
#define SIZE_BOSS_Y 3    //エネミー00のサイズ_Y
#define SIZE_BOSS_X 3    //エネミー00のサイズ_X
#define CAL_ENEMY00	0.2f  //エネミーのカロリー
#define CAL_ENEMY01 0.3f
#define CAL_BOSS	10
#define SIZE_SHADOW_X *mRect.mRRight*0.5f						//影のサイズX
#define SIZE_SHADOW_Y *mRect.mRLeft	*0.2f					//影のサイズY
#define SHADOW_TEX_X			70.f				//影のテクスチャのX
#define SHADOW_TEX_Y			20.f				//影のテクスチャのY

#define PL_HP_X 2.0f //ゲージx　 //HPはこちらから使うように(初期値)
#define PL_HP_Y 0.15f//ゲージy
#define PL_ST_X PL_HP_X*1.3	 //ゲージx
#define PL_ST_Y 0.45f//ゲージy
#define PL_ST_FR_Y 0.3f//ゲージy

#define SIZE_PL_FRAME_X PL_HP_X //フレームＸ
#define SIZE_PL_FRAME_Y 0.2f  //フレームY			

#define ENE_HP_X 2.0f			//エネミーgauge　(初期値)
#define ENE_HP_Y 0.2f			//エネミーgauge

#define SIZE_EN_FRAME_X ENE_HP_X*0.9			//エネミーのフレーム
#define SIZE_EN_FRAME_Y 0.15f			//エネミーのフレーム

#define SIZE_BOSS_FRAME_X	2.0f		
#define SIZE_BOSS_FRAME_Y	0.2f			
/*ＰＬＡＹＥＲの攻撃力*/
#define PL_NORMAL_POWER 0.05f
#define PL_JUMP_AT_POWER 0.07f
#define PL_EAT_POWER	0.06f
#define PL_EX01_POWER	0.15f
/*エネミーの攻撃力*/
#define ENE00_POWER		0.0000000005f
#define ENE01_POWER		0.0000000005f
#define BOSS_JAB_POWER	0.001f
#define BOSS_HIGH_POWER	0.002f
/*ＰＯＩＮＴ*/
#define POINT_00		(int)100
#define POINT_01		(int)200
#define POINT_BOSS		(int)1000
#define POINT_PLAYER	(int)-2000
/*エネミー数*/
#define ENE00_LIMIT	3
#define ENE01_LIMIT	3
#define BOSS_LIMIT	1

#define TEX_FILE_SHADOW		"../CG/shadow/"		//影のファイル場所
#include "../Task/CTask.h"
#include "../Vector/CVector2.h"
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <time.h>

/*
使い方

CTaskにある書いてある

int mPriorityR; //Rander()のナンバー
int mPriorityU;//Update()のナンバー

CBase を継承するものには必ず入れること
数字が小さいものほど

*/


class CBase : public CTask{
private:

	float mFrameTime;				//bool 関数	 FrameTie計算用
	int mFrameCount;				//現在のフレーム数
	/*アラート関数用*/
	float mSaveAlertHitoPoint;		//アラート用
	float mAlertCount;				//アラートカウント
	bool FlagAlertSetHp;			//アラートHPの初期設定用

public:
	CTexture	*mShadowTex;		//影テクスチャチャ
	CVector2 mPos;					//位置
	CVector2 mForward;				//向き
	CRectangle  mRect;				//画像用
	CRectangle  mShadow;			//影
	CRectangle mAttackRange;		//攻撃範囲の四角形

	bool mEnabledEat;				//有効フラグ　食べる(プレイヤー)
	bool mEnabledEaten;				//有効フラグ 食べられた(エネミー)
	bool mEnabledAttack;		    //攻撃しているか否か
	bool mEnabledJump;				//ジャンプいている
	bool mEnabledEx01;				//必殺技(消費)
	bool mEnabledPoint;				//ポイント換算された判断

	float mHitPoint;				//ヒットポイント
	float mAttackPoint;				//攻撃力
	float mStamina;					//スタミナ

	int mSaveAnime;                 //前のアニメーションがどれだったか判断用
	float mAttackAxis;				//攻撃の軸範囲
	bool mEnabledUi;			    //UIがついているとき true
	int mAnimeFrame;				//アニメのフレーム数
	float mAxis;					//軸　使い方　mPosの'Y'を代入する(ジャンプの時など，移動以外の'Y'は代入しない)
	int mStatus;					//現在何をしているかステータス
	static int kazu;				//デバッグ用					

	CVector2 mTargetP;  //プレイヤーポジションの取得用
	
	CBase() : mEnabledEat(false),mEnabledEaten(false),mAxis(0), mHitPoint(0), mEnabledAttack(false), mAttackPoint(0.01f), mEnabledPoint(false), FlagAlertSetHp(false){
		mCharaFlag = true;
		mShadow.SetColor(0.5f, 0.5f, 0.5f, 0.4f);
		kazu += 1;
		srand(time(NULL));
	}

	/*アニメのフレーム数計算用  roopがtrueならループする speed = RoopのSpeed Frame = フレーム数*/
	void AnimeFrame(bool roop, int speed);
	/*オーダーが入ったので追加*/
	void AnimeFrame(bool roop, int speed,int frame);
	/*使い方 sizex,sizeyに画像のサイズを入れる*/
	void LimitDisp(int sizex, int sizey);
	/*ランダムpos制御*/
	void RandLimitDisp(int sizex, int sizey,int limitleft,int limitright);
	/*
	攻撃範囲を決める
	ベースにある変数を使う
	float Forwordは現在の向きを入れる
	0以上　が　右
	0未満　が  左
	float x , y , mAxis は攻撃範囲 ,Cvector2は　自分のposを入れる
	*/
	void Attack(float Forword, float x, float y, float mAxis, CVector2 &mPos);
	/*回転rect関数*/
	void TurnRect(CRectangle *rect);
	void JumpAttack(float Forword, float x, float y, float mAxis, CVector2 &mPos);
	bool FrameTime(float time);
	void RandPos(int x, int y, CVector2 *mPos,int limitleft ,int limitright);		//ポジションをランダムにする	サイズをx,yに当てはめる
	/*HPによるアラート関数*/
	void AlertHPRect(CRectangle *rect,float &Hp);

};
#endif
