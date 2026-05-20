#include "CPlayerAttack.h"
#include "CXCharacter.h"


void CPlayerAttack::Start(CXCharacter* parent)
{
	//親のポインタを保存
	mpParent = parent;
	//アニメーションの変更
	mpParent->ChangeAnimation(3, false, 30);
	mState = EState::EATTACK; //状態の種類を攻撃にする
}
void CPlayerAttack::Update()
{
	//アニメーションが終了しているか
	if (mpParent->IsAnimationFinished())
	{	
		//アニメーションが終了していたら待機状態にする
		mState = EState::EIDLE;
	}
}