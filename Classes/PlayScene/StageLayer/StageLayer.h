/***************************************************************************
*|
*|	概要　　ステージレイヤーの宣言
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/20
*|___________________________________________________________________________
****************************************************************************/

#pragma once 
/* ---- ライブラリのインクルード ---------- */
#include "cocos2d.h"
#include "Coin.h"
#include "CrayStage.h"
#include "Stage.h"
#include "Slope.h"

class StageLayer :public cocos2d::Layer
{

public:
	virtual bool init();

	CREATE_FUNC(StageLayer);


private:

	////毎フレーム呼び出される関数
	void update(float delta)override;
	//プレイヤーとコインの当たり判定後
	void AfterHittingCoin();

	//コイン
	Coin* coin;

	int loop;
};


