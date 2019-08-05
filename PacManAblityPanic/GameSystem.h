#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include"class.h"
#include"GameScene.h"

enum NowStateId
{
	//! キャラクターと衝突した
	Appulse,
	//! 現在移動中
	NowMove,
	//! 目の前に何もない
	Null
};


const int WIDTH_POS = 40;
const int HEIGHT_POS = 40;

void CharTextureMove(Count* count, VariableNumber* var, int MapChipList[22][19], PLAYER* Pac_man);

/**
* @brief マップチップ用の当たり判定関数
* @param (float now_x) キャラクターの現在のX座標
* @param (float now_z) キャラクターの現在のY座標
* @param (int push_key) キャラクターがどの方向を見ているか（進もうとしているか）
* @param (int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]) マップチップの二次元配列
*/
NowStateId CollisionDetectionMapChip(float now_x, float now_y, int push_key, int MapChipList[22][19]);

void Pac_Mon_Move(VariableNumber* var, PLAYER* Pac_man, int MapChipList[22][19]);
#endif // !1
