#include "TestScene.h"
#include "Engine/Image.h" //イメージクラスが使えるようになる
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"), hTitlePic_(-1)
{
}

//初期化
void TestScene::Initialize()
{
	hTitlePic_ = Image::Load("Title.png");
	assert(hTitlePic_ >= 0);
}

//更新
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))//DIKはダイレクトxのコードらしい
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	transform_.scale_ = { 1.5f,1.5f,1.5f };
	Image::SetTransform(hTitlePic_, transform_);//画像の位置や向きなどの設定
	Image::Draw(hTitlePic_);//画像を表示
}

//開放
void TestScene::Release()
{
}
