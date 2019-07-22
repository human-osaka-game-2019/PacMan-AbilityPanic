/**
* @file GhostStatus.h
* @brief ゴースト情報の宣言
*/
#ifndef GHOST_STATUS_H_
#define GHOST_STATUS_H_

/**
* @brief ゴースト情報の継承元クラス
*/
class GHOST_COMMON_STATUS
{
public:
	float	MovementSpeed;	//! ゴーストの移動速度
	bool	LiveFlag;		//! ゴーストの生存フラグ
};

#endif