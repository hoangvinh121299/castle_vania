﻿#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "define.h"
#include "GSprite.h"
#include "Camera.h"
#include "TextureManager.h"
#include "GTexture.h"

using namespace std;

class GameObject;
typedef GameObject* LPGAMEOBJECT;

struct CollisionEvent;
typedef CollisionEvent* LPCOLLISIONEVENT;

struct CollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;
	CollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL)
	{
		this->t = t;
		this->nx = nx;
		this->ny = ny;
		this->obj = obj;
	}

	static bool compare(const LPCOLLISIONEVENT& a, LPCOLLISIONEVENT& b)
	{
		return a->t < b->t;
	}
};

class GameObject
{

protected:
	DWORD LastTimeAttacked; // thời điểm bị tấn công cuối cùng
	int objectHealth;
	int objectId;

	int direction;	// hướng -1 : trái, 1: phải
	objectType oType; // Loại Object

	float x;
	float y;

	float dx;
	float dy;

	float vx;
	float vy;

	DWORD dt;

	GTexture* objectTexture;
	GSprite* objectSprite;



public:

	GameObject();
	virtual ~GameObject();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render(Camera* camera) = 0;

	void SetObjectPosition(float x, float y);
	void SetObjectSpeed(float vx, float vy);
	void GetObjectPosition(float& x, float& y);
	void GetObjectSpeed(float& vx, float& vy);

	int GetObjectHealth();
	void SetObjectHealth(int h);
	void SubObjectHealth(int th);
	void SetObjectDirection(int d);
	int GetObjectDirection();
	void SetObjectId(int ID);
	int GetObjectId();

	// Position, kích thước của object và get loại object
	float GetObjectCoordinateX();
	float GetObjectCoordinateY();
	float GetObjectVx();
	float GetObjectVy();
	void SetObjectCoordinateX(float X);
	void SetObjectCoordinateY(float Y);
	void SetObjectVx(float VX);
	void SetObjectVy(float VY);
	int GetObjectHeight();
	int GetObjectWidth();
	objectType GetObjectType();

	void RenderBoundingBox(Camera* camera);
	LPCOLLISIONEVENT SweptAABBEx(GameObject* coO);
	void CalcPotentialCollisions(vector<GameObject*>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT>& coEvents,
		vector<LPCOLLISIONEVENT>& coEventsResult,
		float& min_tx,
		float& min_ty,
		float& nx,
		float& ny);

	bool isCollitionObjectWithObject(GameObject* obj); 	// kiểm tra bằng AABB và Sweept AABB
	bool checkAABB(GameObject* obj);

	DWORD GetLastTimeAttacked();
	void SetLastTimeAttacked(DWORD t);

	void SetTexture(GTexture* tex);
	GSprite* GetSprite();
};

#endif