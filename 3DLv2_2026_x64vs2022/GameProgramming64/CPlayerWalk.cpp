#include "CPlayerWalk.h"
#include "CXCharacter.h"
//回転速度
#define ROTATIONSPEED 2.0f
//移動速度
#define VELOCITY 0.1f

void CPlayerWalk::Start(CXCharacter* parent)
{
	//親のポインタを保存
	mpParent = parent;
	//アニメーションの変更
	mpParent->ChangeAnimation(1, true, 60);
	mState = EState::EWALK; //状態の種類を歩くにする
}
void CPlayerWalk::Update()
{
	if (mInput.Key('W'))
	{
		CVector p = mpParent->Position();
		mpParent->Position(p +
			mpParent->MatrixRotate().VectorZ() * VELOCITY);
		//右へ回転する
		if (mInput.Key('D'))
		{
			CVector r = mpParent->Rotation() +
				CVector(0.0f, -ROTATIONSPEED, 0.0f);
			mpParent->Rotation(r);
		}
		//左へ回転する
		if (mInput.Key('A'))
		{
			CVector r = mpParent->Rotation() +
				CVector(0.0f, ROTATIONSPEED, 0.0f);
			mpParent->Rotation(r);
		}
		if (mInput.Key('I'))
		{
			mState = EState::EATTACK;
		}

	}
	else
	{
		//Wキーが押されてないときは待機状態にする
		mState = EState::EIDLE;
	}
}