#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyDark.h"
#include "Engine\\SceneManager.h"
#include "Engine/VFX.h"
#include "Engine/Camera.h"

namespace
{
	const int ENEMY_MAX = 5;
	XMFLOAT3 startPos = { 0.0f, 0.0f, 0.0f };

	Transform start;
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);  //Playerのインスタンス＝プレイヤーのオブジェクトを作る
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		Enemy* e = Instantiate<Enemy>(this);
		e->SetPosition(XMFLOAT3(transform_.position_.x + (i * 200.0f), transform_.position_.y, transform_.position_.z));
	}
	//Instantiate<Enemy>(this);
	//Instantiate<EnemyDark>(this);
	//Instantiate<Bullet>(this);  //Bulletのインスタンス＝弾オブジェクトを作る

	Camera::SetPosition(XMFLOAT3(0.0f, 15.0f, -10.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 10.0f));
}

void PlayScene::Update()
{
	//for (int i = 0; i < ENEMY_MAX; i++)
	//{
	//	if (time % 60 == 0)
	//	{
	//		Enemy* e = Instantiate<Enemy>(this->GetParent());
	//		e->SetPosition(transform_.position_);
	//	}
	//}

	if (FindObject("Enemy") == nullptr && FindObject("EnemyDark") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}


