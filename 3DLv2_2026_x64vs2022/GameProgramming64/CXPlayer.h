#pragma once
#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CCharacter.h"
#include "CColliderLine.h"
#include "CCollisionManager.h"
class CXPlayer : public CXCharacter
{
public:
	CXPlayer();
	//衝突処理
    //Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	void Collision();

	void Update() override;
	CColliderLine mColliderLine;  //ラインコライダ
};
#endif