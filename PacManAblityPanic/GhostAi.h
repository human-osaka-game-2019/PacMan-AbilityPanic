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
	* @brief 現在のモードによって対応する関数を実行する関数
	*/
	void RedGhostUpdate ();
};

#endif

