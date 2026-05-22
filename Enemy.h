#pragma once
#include "Engine\\GameObject.h"

class Enemy :
	public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);
	~Enemy();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;

private:
	int hModel_;    //モデルのハンドル
	//Transform tr_;  //トランフォーム(アフィン返還のパラメータを保存している)
	float speed_;
};

