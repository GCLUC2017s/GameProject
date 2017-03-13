#pragma once

/* 2次元のベクトルクラスを作成する */
class CVector2 {
public:
	float x;	//X軸への大きさ
	float y;	//Y軸への大きさ

	CVector2();	//デフォルトコンストラクタ
	CVector2(float x, float y);	//コンストラクタ

	/*　+=演算子のオーバーライド
	CVector2 += CVector2　の宣言
	*/
	void operator+=(const CVector2 &v);

	/*　*演算子のオーバーライド
	CVector2 + CVector2　の宣言
	*/
	const CVector2 operator+(const CVector2 &v) const;
	const CVector2 operator-(const CVector2 &v) const;

	/*　*演算子のオーバーライド
	CVector2 * float　の宣言
	*/
	const CVector2 operator*(float f) const;

	/*　*=演算子のオーバーライド
	CVector2 *= CVector2　の宣言
	*/
	void operator*=(const CVector2 &v);

	float dot(const CVector2 &v);

	const CVector2 normalize();

	float length();
};
