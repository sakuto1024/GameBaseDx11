#include "EnemyDark.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Engine\\SphereCollider.h"

EnemyDark::EnemyDark(GameObject* parent)
	:GameObject(parent, "EnemyDark"), hModel_(-1), speed_(0.1f)
{
}

EnemyDark::~EnemyDark()
{
}

void EnemyDark::Initialize()
{
	hModel_ = Model::Load("DarkEnemy.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 200.0f, 0.0f, 200.0f };
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	transform_.rotate_ = { 0.0f, 180.0f, 0.0f };

	//SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	//AddCollider(collider);
}

void EnemyDark::Update()
{
	//ot_.position_ = { 0.0f, 0.0f, 0.0f };

	static float time = 0.0f;

	transform_.position_ = { 0.0f, 0.0f, 10.0f };
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f };

	//ot_.rotate_.y = time;
	time += 0.025f;
	transform_.position_.x = 6.0 * cos(time);

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

void EnemyDark::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void EnemyDark::Release()
{
}

void EnemyDark::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();  //バレットを消す
		KillMe();  //自分も消す
	}
}
