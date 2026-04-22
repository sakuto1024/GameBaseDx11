#include "PlayScene.h"
#include "Engine/Model.h"

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
}

void PlayScene::Update()
{
	//ot_.position_ = { 0.0f, 0.0f, 0.0f };
	
	ot_.rotate_.y += 0.6f; //回転させる
	ot_.rotate_.x -= 0.4f;
	
	ot_.position_.x += speed_;
	//ot_.scale_.x += speed_;
	//ot_.scale_.y += speed_;
	ot_.scale_.z += speed_;

	if (ot_.position_.x > 2)
	{
		speed_ += -0.001f;
	}

	if (ot_.position_.x < -2)
	{
		speed_ += 0.001f;
	}

}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}


