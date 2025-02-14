#pragma once
#include "cMyTimer.h"

#define Max_Building_Num 2

enum Timer_Type
{
	Timer_Draw,
	Timer_AddMonster,
	Timer_MonsterMove,
	Timer_Attack
};

enum BuildingType
{
	Building_Type1,
	Building_Type2,
	Building_Num
};

enum MonsterType
{
	Monster_Type1,
	Monster_Type2
};

struct stBuildingInfo
{
	tagPOINT pt;
	BuildingType type;
	int curIndex;
};
struct RadishInfo
{
	tagPOINT pt;
	int curindex;
	int curHp = 100;
};
struct stMonsterInfo
{
	tagPOINT pt;
	int curHp;
	MonsterType type;
	int speed;
	int curPicIndex;	//当前动画帧
	unsigned id;		//怪物的ID
	int curDesPtIndex;	//行走的目标点
};

struct stBulletInfo
{
	tagPOINT pt;
	tagPOINT ptDes;
	unsigned monsterId;
	BuildingType type;
};

typedef list<stBuildingInfo> BuildList;
typedef list<stMonsterInfo> MonsterList;
typedef list<RadishInfo> RadishList;
typedef list<stBulletInfo> BulletList;

class cDefense :public cMyTimer
{
public:
	cDefense();
	~cDefense();

	virtual int OnTimer(int id, int iParam = 0, string str = "");

	void BeginGame(HWND hWnd);
	void GameOver();
	void DrawAll();
	void DrawMap(HDC dcMem);
	void InitBase();
	void DrawItem(HDC dcMem);
	void DrawRadish(HDC dcMem);
	void OnLButtonUp(LPARAM lParam);
	void OnRButtonDown(LPARAM lParam);
	bool  IsInRect(tagPOINT pt, RECT rect);
	int GetBaseIndex(tagPOINT pt);
	void AddBuilding(int baseIndex);
	void AddMonster();
	void MonsterMove();
	float Distance(tagPOINT pt1, tagPOINT pt2);
	void DrawMonster(HDC dcMem);
	void BuildingAttack();
	bool GetNearestMonster(stBuildingInfo stBuild, stMonsterInfo& stMonster);
	void BulletMove();
	void AttackMonster(int id, BuildingType type);
	void DrawBullet(HDC dcMem);
private:
	HWND m_hWnd;
	list<tagPOINT> m_ptBaseList;	//地基
	RECT m_rectBuilding[Max_Building_Num];	//图标 rect

	int m_mouseItemIndex;	//标识标识上现在有什么

	int m_iMoney;

	BuildList m_buildList;
	MonsterList m_monsterList;
	BulletList m_bulletList;
	RadishList m_radishList;
};