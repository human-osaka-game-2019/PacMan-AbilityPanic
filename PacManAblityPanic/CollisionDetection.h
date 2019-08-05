#ifndef COLLISON_DETECTION_H_
#define COLLISON_DETECTION_H_

const int MAP_SIZE_WIDTH_POS =  19;
const int MAP_SIZE_HEIGHT_POS = 22;

enum Key 
{
	Right,
	Left,
	Down,
	Up
};
/**
* @enum NowStateId
* 当たり判定でのキャラクターの状態(クッキーは無視する)
*/
const int WIDTH_POS = 40;
const int HEIGHT_POS = 40;

enum NowStateId
{
	//! キャラクターと衝突した
	Appulse,
	//! 現在移動中
	NowMove,
	//! 目の前に何もない
	Null
};
/**
* @brief マップチップ用の当たり判定関数
* @param (apChipData mapchip) マップチップサイズを含むクラス
* @param (float now_x) キャラクターの現在のX座標
* @param (float now_z) キャラクターの現在のY座標
* @param (int push_key) キャラクターがどの方向を見ているか（進もうとしているか）
* @param (int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]) マップチップの二次元配列
*/
NowStateId CollisionDetectionMapChip(float now_x, float now_y, int push_key, int MapChipList[MAP_SIZE_HEIGHT_POS][MAP_SIZE_WIDTH_POS]);

#endif // !COLLISON_DETECTION_H_

