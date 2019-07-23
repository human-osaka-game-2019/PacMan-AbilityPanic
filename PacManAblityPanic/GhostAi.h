/**
* @file GhostAi.h
* @brief ゴーストAIの関数の宣言
*/
#ifndef GHOST_AI_H_
#define GHOST_AI_H_
/**
* @brief ブリンキー（赤いゴースト）のAI作成用クラス
*/
class RED_GHOST : public GHOST_BASE
{
public:
	/**
	* @fn void RedGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void RedGhostUpdate ();
};

/**
* @brief ピンキー（ピンクのゴースト）のAI作成用クラス
*/
class PINK_GHOST : public GHOST_BASE
{
public:
	/**
	* @fn void RedGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void PinkGhostUpdate ();
};

/**
* @brief インキー（水色のゴースト）のAI作成用クラス
*/
class WATERY_GHOST : public GHOST_BASE
{
public:
	/**
	* @fn void WateryGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void WateryGhostUpdate ();
};

/**
* @brief クライド（オレンジ色のゴースト）のAI作成用クラス
*/
class ORANGE_GHOST : public GHOST_BASE
{
public:
	/**
	* @fn void OrangeGhostUpdate ()
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void OrangeGhostUpdate ();
};

#endif

