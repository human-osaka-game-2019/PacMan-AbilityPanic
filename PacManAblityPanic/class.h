#ifndef CLASS_H
#define CLASS_H

#include<stdio.h>
#include<windows.h>
#include<d3dx9.h>
#include<tchar.h>
#include<dinput.h>

#define TEXTUREMAX (20);

typedef struct
{
	float	// 頂点座標
		x,  // 幅
		y,  // 高さ
		z;  // 奥行

	float   // 除算数
		rhw;

	DWORD
		dwColor; // 頂点の色

	float   // テクスチャ座標
		tu,  // 幅
		tv;	// 高さ
} CUSTOMVERTEX, * P_CUSTOMVERTEX;

class Pointa
{
public:
	
	LPDIRECT3D9 pDirect3d;
	LPDIRECT3DDEVICE9 pDevice = NULL;
	LPDIRECTINPUT8 pDinput;
	LPDIRECTINPUTDEVICE8 pkey;
	
};


// テクスチャデータ
struct TEXTUREDATA
{
	LPDIRECT3DTEXTURE9 m_pTexture;  // テクスチャ情報
	float m_Width;					// テクスチャの幅
	float m_Height;					// テクスチャの高さ
};

// マップチップでの画像数
enum MAPCHIP_TEXTURE_ID
{
	Non = -1,		// 無し
	MapChip,		// マップチップ	
	MaxTextureId	// 最大数
};

// SceneId の数
enum SceneId
{
	TitleScene,			//!< タイトルシーン
	SetScene,			//!< 難易度設定シーン
	OptionScene,        //!< ヘルプ(遊戯説明画面)シーン
	GameScene,			//!< ゲーム本編シーン
	ResultScene,		//!< リザルトシーン
	SceneIdMax,			//!< シーンID最大
};

// Step 数
enum SceneStep
{
	InitStep,			//!< 初期化
	MainStep,			//!< メイン
	EndStep,			//!< 終了
};

enum TitleTextureList
{
	MsinTitleTexture,
	MaxTitleTexture,

};

enum SetTextureList
{
	MsinSetTexture,
	MaxSetTexture,

};

enum OptionTextureList
{
	MsinOptionTexture,
	MaxOptionTexture,

};

enum GameTextureList
{
	MsinGameTexture,
	MaxGameTexture,

};

enum ResultTextureList
{
	MsinResultTexture,
	MaxResultTexture,

};
//共通のインスタンス
extern Pointa point;

#endif // !1