/***************************************************************************
*|
*|	�T�v�@�@���@�g���N���X��錾����
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/6/2
*|___________________________________________________________________________
****************************************************************************/

/* ---- ���d�C���N���[�h�̖h�~ ---------- */
#pragma once
/* ----  �C���N���[�h ---------- */
/***************************************************************************
*|
*|	�T�v�@�@���@�g���N���X��錾����
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/6/2
*|___________________________________________________________________________
****************************************************************************/
/* ---- ���d�C���N���[�h�̖h�~ ---------- */
#pragma once
/* ----  �C���N���[�h ---------- */
#include "cocos2d.h"
#include "Character.h"

class Witch : public Character
{
public:
	bool init();
	CREATE_FUNC(Witch);

	void Animation();
private:
	const float SCORECORRECTION = 1.0f;
};