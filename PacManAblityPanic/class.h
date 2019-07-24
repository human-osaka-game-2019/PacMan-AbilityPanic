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
	LPDIRECT3DDEVICE9 pDevice;
	LPDIRECTINPUT8 pDinput;
	LPDIRECTINPUTDEVICE8 pkey;
};

// テクスチャデータ
struct TextureData
{
	LPDIRECT3DTEXTURE9 m_pTexture;  // テクスチャ情報
	float m_Width;					// テクスチャの幅
	float m_Height;					// テクスチャの高さ
};

// テクスチャ //
const int D3DFVF_CUSTOMVERTEX(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
// テクスチャのFVF情報

// キーボード //
static const int MAX_KEY_NUMBER = 256;
// 入力キーを入れる値
BYTE KeyState[MAX_KEY_NUMBER];
// 256の配列を持つ
const int MASK_NUM = 0x80;

enum SceneId
{
	TitleScene,			//!< タイトルシーン
	SetScene,			//!< 難易度設定シーン
	OptionScene,        //!< ヘルプ(遊戯説明画面)シーン
	GameScene,			//!< ゲーム本編シーン
	ResultScene,		//!< リザルトシーン
	SceneIdMax			//!< シーンID最大
};

enum SceneStep
{
	InitStep,			//!< 初期化
	MainStep,			//!< メイン
	EndStep,			//!< 終了
};

#endif // !1