#include "GameManager.h"

USING_NS_CC;

//////////////キャラクターレイヤー//////
//////////////キャラクター//////////////
Vec2 GameManager::PlayerSpd = (Vec2(7.0f,0.0f));//速度
Vec2  GameManager::PlayerSize = Vec2(64, 64);//サイズ
Vec2  GameManager::PlayerPos = Vec2(300.0f,300.0f);//座標
float  GameManager::ScoreCorrection = 0.0f;//スコア補正
bool GameManager::GroundFlag = false;//地面についているか

///////////////ステージレイヤー/////////
//struct GameManager::SlopePos
//{
//	Vec2 LeftEnd;//左端
//	Vec2 RightEnd;//右端
//};


int GameManager::ScoreMaxDigit = 0;//最大桁数
int GameManager::DistanceMaxDigit = 0;//最大桁数
int GameManager::Digit = 0;//桁数
int GameManager::SaveDistance = 0;//距離を保存する
int GameManager::SaveScore = 0;//スコアを保存する
int GameManager::SpriteCnt = 0;//何個目のスプライトかカウントする
bool GameManager::UsedFlag = false;//この関数がすでに呼ばれたか

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

/************************************************************************************
*|	概要　　衝突判定判定
*|	引数　　オブジェクト座標,オブジェクトサイズ,プレイヤー座標,オブジェクトサイズ
*|　戻り値　0:空中	1:マップレイヤーの上に乗った	2:マップレイヤーの右側に当たった
*************************************************************************************/
int  GameManager::CollisionDetermination(Vec2 Apos,Vec2 Asize, Vec2 Bpos,Vec2 Bsize)
{
	//マップレイヤーの上に乗ったか
	if (Apos.x <= Bpos.x + Bsize.x / 2)
	{
		if (Apos.x + Asize.x >= Bpos.x - Bsize.x / 2)
		{
			if (Apos.y >= Bpos.y)
			{
				if (Apos.y - GameManager::PlayerSpd.y <= Bpos.y)
				{
					{
						return up;
					}
				}
			}
		}
	}

	//マップレイヤーの下に乗ったか
	if (Apos.x <= Bpos.x + Bsize.x / 2)
	{
		if (Apos.x + Asize.x >= Bpos.x - Bsize.x / 2)
		{
			if (Apos.y - Asize.y <= Bpos.y + Bsize.y)
			{
				if (Apos.y - Asize.y + GameManager::PlayerSpd.y >= Bpos.y + Bsize.y)
				{
					{
						return under;
					}
				}
			}
		}
	}

	//マップレイヤーの左側に当たったか
	if (Apos.x + GameManager::PlayerSpd.y >= Bpos.x + Bsize.x / 2)
	{
		if (Apos.x <= Bpos.x + Bsize.x / 2)
		{
			if (Apos.y >= Bpos.y)
			{
				if (Apos.y - Asize.y <= Bpos.y + Bsize.y)
				{
					{
						return left;
					}
				}
			}
		}
	}


	//マップレイヤーの右側に当たったか
	if (Apos.x + Asize.x - GameManager::PlayerSpd.y <= Bpos.x - Bsize.x / 2)
	{
		if (Apos.x + Asize.x >= Bpos.x - Bsize.x / 2)
		{
			if (Apos.y >= Bpos.y)
			{
				if (Apos.y - Asize.y <= Bpos.y + Bsize.y)
				{
					{
						return right;
					}
				}
			}
		}
	}



	//何にも当たっていない
	return exception;
}


/************************************************************************************
*|	概要　　衝突判定(斜辺)
*|	引数　　斜辺左端座標,斜辺右端座標,オブジェクト座標
*|　戻り値　true当たった　false 当たってない
*************************************************************************************/
int GameManager::DiagonalCollisionDetermination(Vec2 Apos, Vec2 Bpos, Vec2 Object) {

	Vec2 v;
	Vec2 A;
	Vec2 B;
	float w;
	float d;
	bool direction;

	//キャラクターの中心を求める
	Object.y += GameManager::PlayerSize.y / 2;

	v = Bpos - Apos;
	A = Object - Apos;
	B = Object - Bpos;

	//AposとBposの距離
	w = Apos.distance(Bpos);
	//
	d = v.cross(A) / w;

	//マイナスの時
	if (d > 0)
	{
		//整数に変える
		d *= -1.0f;
		direction = false;
	}
	else
	{
		direction = true;
	}


	if (d <= PlayerSize.y)
	{
		if (A.dot(v) * B.dot(v) <= 0)
		{
			if (direction == true)
			{
				return up;
			}
			else
			{
				return under;
			}
		}
	}

	//何にも当たっていない
	return exception;

}

/************************************************************************************
*|	概要　　あたり判定
*|	引数　　対象二つの座標
*|　戻り値　true当たった　false 当たってない
*************************************************************************************/
bool GameManager::HitJudgment(Vec2 Apos, Vec2 Asize, Vec2 Bpos, Vec2 Bsize)
{

	if ((Apos.x <= Bpos.x + Bsize.x / 2)
		|| (Apos.x + Asize.x >= Bpos.x - Bsize.x / 2)
		|| (Apos.y >= Bpos.y)
		|| (Apos.y - Asize.y <= Bpos.y + Bsize.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}


