#ifndef CLASS_H
#define CLASS_H

#include<stdio.h>
#include<windows.h>
#include<d3dx9.h>
#include<tchar.h>
#include<dinput.h>

const int TEXTUREMAX (5);

typedef struct
{
	float	// 頂点座標
		x,  // 幅
		y,  // 高さ
		z;  // 奥行

	float   // 除算数
		rhw;

	float   // テクスチャ座標
		tu,  // 幅
		tv;	// 高さ
} CUSTOMVERTEX, * P_CUSTOMVERTEX;

//enum TextureList
//{
//	TitleSceneTexture,
//	SetSceneBackTexture,
//	SelectGametexture,
//	OptionSceneTexture,
//	GameSceneTexture,
//	MapChipTexture,
//	ResultSceneTexture,
//	MaxTexture
//};

class Pointa
{
public:
	

	LPDIRECT3D9 pDirect3d;
	LPDIRECT3DDEVICE9 pDevice;
	LPDIRECTINPUT8 pDinput;
	LPDIRECTINPUTDEVICE8 pkey;
	
	
};

// テクスチャデータ
struct TEXTUREDATA
{

	LPDIRECT3DTEXTURE9 m_pTexture[TEXTUREMAX];  // テクスチャ情報
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

class VariableNumber
{
public:
	int SceneSelect;
	int count = 0;
	int Keystate = 0;
	int temp;
	float MoveSpeed = 2;
};

class Count
{
public:
	int Frame = 0;
	int Frame2 = 0;
	int Frame3 = 0;
	int Frame4 = 0;
};

// extern VariableNumber var;

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
	MainTitleTexture,
	MaxTitleTexture,

};

enum SetTextureList
{
	BackTexture,
	levelselectTexture,
	MaxSetTexture,

};

enum OptionTextureList
{
	MainOptionTexture,
	MaxOptionTexture,

};

enum GameTextureList
{
	MainGameTexture,
	MapChipTexture,
	MaxGameTexture,

};

enum ResultTextureList
{
	MainResultTexture,
	MaxResultTexture,

};


//共通のインスタンス
extern Pointa point;

class MapChipData
{
public:
	int Map_HeigjtNumber = 22;
	int Map_WidhtNumber = 19;
	float MapChipHeight = 40;
	float MapChipWidht = 40;
	float Texture_Height = 512;
	float Texture_Widht = 512;
	float x;
	float y;
	float chip_x;
	float chip_y;
	/*void draw_point(int a, int b);
	void draw_chip(int a, int b);*/
};

//void MapChipData::draw_point(int a, int b)
//{
//	x = a;
//	y = b;
//};
//
//void MapChipData::draw_chip(int a, int b)
//{
//	chip_x = a;
//	chip_y = b;
//};


extern MapChipData MapData;
#endif // !1