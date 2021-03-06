﻿#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include"class.h"
#include"GameScene.h"

enum NOW_STATE_ID
{
	//! キャラクターと衝突した
	Appulse,
	//! 現在移動中
	NowMove,
	//! 目の前に何もない
	Null
};

enum MAP_CHIP_ID
{
	Road, Cookie = 12
};


const int WIDTH_POS = 40;
const int HEIGHT_POS = 40;

void CharTextureMove(Count* count, VariableNumber* var, int MapChipList[22][19], PLAYER* Pac_man);

/**
* @brief マップチップ用の当たり判定関数
* @param (float now_x) キャラクターの現在のX座標
* @param (float now_z) キャラクターの現在のY座標
* @param (int push_key) キャラクターがどの方向を見ているか（進もうとしているか）
* @param (int MapChipList[22][19]) マップチップの二次元配列
*/
NOW_STATE_ID CollisionDetectionMapChip(float now_x, float now_y, int push_key, int MapChipList[22][19]);

NOW_STATE_ID CollisionDetectionMapChipZ(float now_x, float now_y, int push_key, int** MapChipList);

/**
* @brief ゴーストが分かれ道にいるかどうか判断する用の関数
* @param (float char_x) キャラクターの現在のX座標
* @param (float char_z) キャラクターの現在のY座標
* @param (int** MapChipList) マップチップの二次元配列
*/
bool BifurcatioCheck(float char_x, float char_y, int** MapChipList);

void Pac_Mon_Move(VariableNumber* var, PLAYER* Pac_man, int MapChipList[22][19]);
void EatCookie(VariableNumber* var, PLAYER* Pac_man, int MapChipList[22][19]);



#endif // !1
