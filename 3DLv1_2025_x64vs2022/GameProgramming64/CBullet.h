#pragma once
#ifndef CBULLET_H
#define CBULLET_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
//三角形クラスのインクルード
#include "CTriangle.h"
#include "CInput.h"
#include "CVector.h"
/*
弾クラス
三角形を飛ばす
*/
class CBullet : public CCharacter3 {
public:

	//幅と奥行きの設定
	//Set(幅, 奥行)
	void Set(float w, float d);
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//更新
	void Update();
	//描画
	void Render();
	bool mIsShot = true;
private:
	CVector mN[3];//法線
	CTriangle mV[3];
	//三角形
	CTriangle mT;
	CInput mInput;

};

#endif
