#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Engine\\SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1), speed_(0.01f)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);

	//transform_.position_ = { 0.0f, 0.0f, 20.0f };
	//transform_.scale_ = { 0.5f, 0.5f, 0.5f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
	//ot_.position_ = { 0.0f, 0.0f, 0.0f };

	static float time = 0.0f;

	//transform_.position_ = { 0.0f, 0.0f, 10.0f };
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f };

	//ot_.rotate_.y = time;
	time += 0.025f;
	//transform_.position_.x = ((float)(rand() % 200 - 100) ) * (sin(time) / 10.0f);

	transform_.position_.x += 0.1f * sin(time * 0.2f);

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

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();  //バレットを消す
		KillMe();  //自分も消す
	}
}
