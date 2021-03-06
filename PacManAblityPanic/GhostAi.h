﻿/**
* @file GhostAi.h
* @brief ゴーストAIの関数の宣言
*/
#ifndef GHOST_AI_H_
#define GHOST_AI_H_
#include"GhostStatus.h"

//TERRITORY GHOST_TERRITORY[4];

/**
* @brief ブリンキー（赤いゴースト）のAI作成用クラス
*/
class RED_GHOST : public GHOST_BASE
{
public:
	void RedAbilityUse();
	/**
	* @fn void RedNormalMoving ()
	* @ brief ブリンキーのノーマルモード時の挙動
	*/
	void RedNormalMoving (RED_GHOST* red, int** MapChipList,int randm);
	/**
	* @fn void RedGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void RedGhostUpdate (RED_GHOST* red, int** MapChipList,int randm);
};

/**
* @brief ピンキー（ピンクのゴースト）のAI作成用クラス
*/
class PINK_GHOST : public GHOST_BASE
{
public:

	/**
	* @fn void PinkNormalMoving ()
	* @ brief ピンキーのノーマルモード時の挙動
	*/
	void PinkNormalMoving(PINK_GHOST* pink, int** MapChipList, int randm);
	/**
	* @fn void RedGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void PinkGhostUpdate (PINK_GHOST* pink, int** MapChipList, int randm);
};

/**
* @brief インキー（水色のゴースト）のAI作成用クラス
*/
class WATERY_GHOST : public GHOST_BASE
{
public:
	/**
	* @fn void WateryNormalMoving ()
	* @ brief インキーのノーマルモード時の挙動
	*/
	void WateryNormalMoving(WATERY_GHOST* watery, int** MapChipList, int randm);
	/**
	* @fn void WateryGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void WateryGhostUpdate (WATERY_GHOST* watery, int** MapChipList, int randm);
};

/**
* @brief クライド（オレンジ色のゴースト）のAI作成用クラス
*/
class ORANGE_GHOST : public GHOST_BASE
{
public:
	/**
	* @fn void OrangeNormalMoving ()
	* @ brief クライドのノーマルモード時の挙動
	*/
	void OrangeNormalMoving(ORANGE_GHOST* orange, int** MapChipList, int randm);

	/**
	* @fn void OrangeGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void OrangeGhostUpdate (ORANGE_GHOST* orange, int** MapChipList, int randm);
};
/**
* @brief スキャッターモード時の処理
*/
void ScatterMoving ();
/**
* @brief イジケモード時の処理
*/
void IzikeMoving ();

void randm();
#endif

