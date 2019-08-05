/**
* @file GhostStatus.h
* @brief ゴースト情報の宣言
*/
#ifndef GHOST_STATUS_H_
#define GHOST_STATUS_H_


struct TERRITORY {
	float X;				//! 縄張りのX軸
	float Y;				//! 縄張りのY軸
	const float XSize = 0;	//! 各ゴーストの縄張りのサイズ（X軸）
	const float YSize = 0;	//! 各ゴーストの縄張りのサイズ（Y軸）
};



/**
* @enum GHOST_MODE_FLAG
* @brief ゴーストのモードの種類
*/
enum GHOST_MODE
{
	NormalMode,	//!<通常モード
	ScatterMode,//!<スキャッターモード
	IzikeMode	//!<イジケモード
}; 

/**
* @brief ゴースト情報の継承元クラス
*/
class GHOST_BASE
{
public:
	int		Mode;			//! ゴーストの現在のモード
	float	Speed;			//! ゴーストの移動速度
	bool	Is_dead;		//! ゴーストの生存フラグ
	int Direction_of_travel;
	// いるかわからないが取り敢えず書いておく
	float	pos_X, pos_Y;			//! ゴーストのXY座標
	float	Width, Height;	//! ゴーストの幅、高さ

	void CoordinatesInput(float x, float y)
	{
		pos_X = x;
		pos_Y = y;
	}
	
};

enum DIRECTION_OF_TRAVEL
{
	up,
	down,
	right,
	left
};

#endif