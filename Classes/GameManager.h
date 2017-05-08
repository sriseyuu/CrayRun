#pragma once
#include "cocos2d.h"

//方向
enum Direction
{
	up,
	under,
	left,
	right,
	exception
};

class GameManager 
{
public:
	////////////////プレイシーン/////////////
	//衝突判定(ブロック)
	static Direction  CollisionDetermination(cocos2d::Vec2 Apos, cocos2d::Vec2 Asize, cocos2d::Vec2 Bpos, cocos2d::Vec2 Bsize);
	//衝突判定2(ブロック)
	static Direction  CollisionDetermination2(cocos2d::Vec2 Apos, cocos2d::Vec2 Asize, cocos2d::Vec2 Bpos, cocos2d::Vec2 Bsize);

	//衝突判定(斜面)
	static Direction DiagonalCollisionDetermination(cocos2d::Vec2 Apos, cocos2d::Vec2 Bpos, cocos2d::Vec2 Object);
	//当たり判定
	static bool HitJudgment(cocos2d::Vec2 Apos, cocos2d::Vec2 Asize, cocos2d::Vec2 Bpos, cocos2d::Vec2 Bsize);
	
	static const int BOX_COLLIDER;			//あたり判定時に使用するタイルレイヤーの淵から少しだけ内側に入っているか確かめるための数
	static const int BOX_COLLIDER2;			//あたり判定時に使用するタイルレイヤーの淵から少しだけ内側に入っているか確かめるための数

	GameManager();

	~GameManager();
	//////////////キャラクターレイヤー//////
	/////////////キャラクター/////////////
	static cocos2d::Vec2 PlayerSpd;//速度
	static cocos2d::Vec2 PlayerPos;//座標
	static  cocos2d::Vec2 PlayerSize;//サイズ
	static float ScoreCorrection;//スコア補正
	static bool RightFlag;//右側に当たったか

	///////////////ステージレイヤー/////////
	static cocos2d::TMXTiledMap*  map;//マップ
	static const cocos2d::Vec2 MAP_SIZE;//マップ大きさ
	static const cocos2d::Vec2 LAYRE_SIZE;//レイヤーの大きさ
	static int StageLoopCnt;//ステージをループさせた回数
	//////////////床///////////////////////
	static std::vector < std::vector< cocos2d::Vec2 >> FloorPos;//床座標
	static std::vector < cocos2d::Vec2> FloorPos2;//床座標


	////斜面座標
	static int SlopeCnt;//斜面カウント

	static std::vector<cocos2d::Vec2> LeftPos;//左端
	static std::vector<cocos2d::Vec2> RightPos;//右端


	static float SlopePosY;//斜面座標Y
	//////////////コイン//////////////
	std::vector<cocos2d::Sprite*> s_score;//コイン
	static int CoinCnt;//コインをカウント
	///////////////UIレイヤー///////////////
	///////////////スコア///////////////////
	static int Score;//スコア
	//////////////距離//////////////////
	const static int DISTANCE_MAX_NUMBER;//スコアのスプライトの数
	static int SaveDistance;//距離を保存する
	static std::vector<int> CoinPoint;//コインのポイント
	///////////////////カメラ/////////////////////////
	static float m_cameraposx;
	const static float m_cameraspdx;

private:

};



