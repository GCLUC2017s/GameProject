#ifndef MYNUMBER_HPP
#define MYNUMBER_HPP

/*
使い方

プレイヤーなら　E_PLAYER を，
エネミーなら    E_ENEMY　を,

task　の　属性を知るために使う

mPriorityRにも使うrender
mPriorityUにも使う

E_ERRORは初期値として入れる

*/
enum  EMyNumber
{
	E_BACKGROWND = -100, E_MTITLE, E_PLAYER = 0, E_ENEMY00, E_ENEMY01, E_BOSS, E_UI,E_CLEAR=80 ,E_CAMERA = 90, E_ERROR = 999
};

#endif