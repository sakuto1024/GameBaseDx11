#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
	speed_ = 0.1f;
	ot_.scale_ = { 0.5f, 0.5f, 0.5f };
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	Instantiate<Player>(this);  //Playerのインスタンス＝プレイヤーのオブジェクトを作る
}

void PlayScene::Update()
{
	//ot_.position_ = { 0.0f, 0.0f, 0.0f };

	static float time = 0.0f;

	ot_.position_ = { 0.0f, 0.0f, 10.0f };
	ot_.scale_ = { 0.5f, 0.5f, 0.5f };
	ot_.rotate_ = { 0.0f, 0.0f, 0.0f };

	//ot_.rotate_.y = time;
	time += 0.025f;
	ot_.position_.x = 6.0 * sin(time);

	//float posx = 6.0 * sin(0.2f * time);
	//float posy = 6.0 * cos(3.0f * time);
	//ot_.position_.x = posx;
	//ot_.position_.y = posy;
	
	//ot_.rotate_.y += 0.6f; //回転させる
	//ot_.rotate_.x -= 0.4f;
	//
	//ot_.position_.x += speed_;
	////ot_.scale_.x += speed_;
	////ot_.scale_.y += speed_;
	//ot_.scale_.z += speed_;

	//if (ot_.position_.x > 2)
	//{
	//	speed_ += -0.001f;
	//}

	//if (ot_.position_.x < -2)
	//{
	//	speed_ += 0.001f;
	//}

}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}


