#include "CBullet.h"
#include "CPlayer.h"
#define VELOCITY CVector(0.0f, 0.0f, 0.1f) //移動速度
//幅と奥行きの設定
//Set(幅, 奥行)
void CBullet::Set(float w, float d) 
{
	//頂点1､頂点2､頂点3の作成
	CVector v0, v1, v2;
	//頂点1の座標を設定する
	v0.Set(-w, 0.0f, 0.0f);
	//頂点2の座標を設定する
	v1.Set(w, 0.0f, 0.0f);
	//頂点3の座標を設定する
	v2.Set(0.0f, 0.5f, d);
	//スケール設定
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//三角形の頂点設定
	mT.mV[0] = v0;
	mT.mV[1] = v1;
	mT.mV[2] = v2;
	//w, 0.0f, 0.0f    -w , 0.0f, 0.0f		0.0f, 0.0f, d
	//三角形の法線設定
	mT.Normal(CVector(0.0f, 1.0f, 0.0f));
}

//更新
void CBullet::Update() {
	CTransform::Update();
	//位置更新　進行方向へ１進む
	if (mInput.KeyTrigger(VK_SPACE)) {
		mIsShot = true;
	}

	// 発射後は自動で進み続ける
	if (mIsShot) {
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
}

//描画
void CBullet::Render()
{
	//DIFFUSE黄色設定
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	// 位置・回転・スケール反映
	glTranslatef(mPosition.X(), mPosition.Y(), mPosition.Z()); 
	// 三角形描画
	mT.Render();
}

