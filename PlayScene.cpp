#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine\\SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);  //Playerのインスタンス＝プレイヤーのオブジェクトを作る
	Instantiate<Enemy>(this);
	//Instantiate<Bullet>(this);  //Bulletのインスタンス＝弾オブジェクトを作る
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
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


