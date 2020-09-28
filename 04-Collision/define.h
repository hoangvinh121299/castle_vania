﻿#ifndef _DEFINE_H__
#define _DEFINE_H__


#include <fstream> 
#include <string>
#include <stdio.h>
#include <Windows.h>  
#include <iostream>
#include <map>
#include "debug.h" 
#include <algorithm>
#include <d3dx9.h>
#include <stdlib.h>
#include <iomanip>
#include <d3d9.h>
#include <vector>
#include <iostream>

using namespace std;

#define SCREEN_WIDTH 528
#define SCREEN_HEIGHT 480 

#define MAX_FRAME_RATE 90

extern D3DCOLOR D3DBACKGROUND_COLOR;
#define BACKGROUND_COLOR_DEFAULT D3DCOLOR_XRGB(0, 0, 0);

extern int isDebug_RenderBBox;
#define IS_DEBUG_RENDER_BBOX isDebug_RenderBBox


enum TAG
{
	SIMON = 01,
	SIMON_TRANS = 02,
	SIMON_DEADTH = 03,
	BBOX = 04,

	// Brick
	TEX_BRICK_TRANSPARENT = 25,
	/*TEX_BRICK_MAP_2 = 26,
	TEX_BRICK_3_32 = 27,
	TEX_BRICK_4_32 = 28,*/

	// Object
	TORCH = 41,
	OBJECT_HIDDEN = 42,
	CANDLE = 43,
	

	// Weapon
	MORNINGSTAR = 61,
	DAGGER = 62,

	// Item
	LARGEHEART = 81,
	UPGRADEMORNINGSTAR = 82,
	ITEMDAGGER = 83,
	

};

#ifndef CHECK_OBJECT_IN_CAMERA 
#define CHECK_OBJECT_IN_CAMERA(obj) \
checkObjectInCamera(obj->GetX(), obj->GetY(), (float)obj->GetWidth(),  (float)obj->GetHeight())
#endif


#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif 

#endif