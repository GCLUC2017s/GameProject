#pragma once
#include "define.h"
#include "CRectangle.h"
#include <stdio.h>
#include <list>
#include <iostream>

class CMap {
public:
/*リストの使い方*//*
	"#includeするもの"
		#include <list>
		#include <iostream>
	//書き方

			std::list<型の指定(例)int, float class名　など> 好きな名前

	//使い方  (値を入れる方法)

			intlist.push_back(引数); これで要素を追加していく    "(  )"の中には定義した時の <型の指定> と同じものを入れる

			intlist.pop_back();	　　 これで要素を削除していく

	[重要点]

		※リストはそのままでは使えない		イテレータ―と呼ばれるものを使わないといけない "iterator"

	//書き方

			std::list<型の指定(例)int, float class名　など>::iterator 好きな名前; 
			これでリストで作った型を使うことができる
			(例)
		

			
			#include <list>
			#include <iostream>

			int main()
			{
			using namespace std;

			list<int> intlist;  // int型の双方向リスト
			int i;

			// 10個の要素を追加していく
			for( i = 0; i < 10; ++i )
			{
			intlist.push_back( i );
			}

			list<int>::iterator it = intlist.begin(); // イテレータ

			while( it != intlist.end() )  // listの末尾まで
			{
				printf("%d,it"); // 要素を出力
				++it;  // イテレータを１つ進める
			}

			return 0;
			}



	
	
*//*終了*/

	CRectangle BGrect; //背景のrect

	CTexture *BackGround;

	~CMap();
	CMap();

	void init();
	void update();
	void render();	
};