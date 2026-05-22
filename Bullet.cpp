#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Player.h"
#include "Engine\\SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1), speed_(0.8f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("bullet.fbx");
	assert(hModel_ >= 0);

	//Player* player = static_cast<Player*>(FindObject("Player"));

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.1f);
	AddCollider(collider);
}

void Bullet::Update()
{
	transform_.position_.z = transform_.position_.z + speed_;

	if (transform_.position_.z >= 100.0f)
	{
		KillMe();  //自分を削除する
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
