#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Player.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("bullet.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { 0.0f, -2.5f, 0.0f };

	GameObject* p = FindObject("Player");

	Transform ptr_ = p->GetRootJob();
}

void Bullet::Update()
{
	tr_.position_.z += 1.0f;

	if (tr_.position_.z >= 100.0f)
	{
		this->Release();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
