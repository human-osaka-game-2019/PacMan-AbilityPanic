#ifndef COLLISON_DETECTION_H_
#define COLLISON_DETECTION_H_

const int MAP_SIZE_WIDTH = 19;
const int MAP_SIZE_HEIGHT = 22;

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
NowStateId CollisionDetectionMapChip(MapChipData mapchip, float now_x, float now_y, int push_key, int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]);

#endif // !COLLISON_DETECTION_H_

