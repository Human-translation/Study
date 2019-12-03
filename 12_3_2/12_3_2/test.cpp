#define _CRT_SECURE_NO_WARNINGS

#define ROWS 12
#define COLS 12
#define ZXDJ 10
#define XXDJ 14
#include <iostream>
#include <vector>
using namespace std;

struct MyPoint
{
	int row;
	int col;
	int f;
	int g;
	int h;
	void setF(){ f = g + h; }
};

struct pathNode
{
	int val;
	bool isFind; //是否走过
};

enum direct{p_up,p_down,p_left,p_right,p_lup,p_ldown,p_rup,p_rdown};

struct treeNode
{
	MyPoint pos;
	treeNode* pParent;
	vector<treeNode*> child;
};

bool canWalk(MyPoint pos, pathNode pathmap[ROWS][COLS]);
int getG(MyPoint pos, MyPoint endpos);
int main()
{
	int map[ROWS][COLS] = {
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	};

	MyPoint begPos = { 1, 1 };
	MyPoint endPos = { 5, 10 };

	pathNode pathmap[ROWS][COLS] = { 0 };
	for (int i = 0; i < ROWS;i++)
	for (int j = 0; j < COLS; j++)
		pathmap[i][j].val = map[i][j];

	treeNode* pRoot = NULL;

	pathmap[begPos.row][begPos.col].isFind = true;

	pRoot = new treeNode;
	memset(pRoot, 0, sizeof(treeNode));
	pRoot->pos = begPos;

	vector<treeNode*> buff;
	vector<treeNode*>::iterator itMin;
	vector<treeNode*>::iterator it;

	bool isFindEnd = false;

	treeNode* pTemp = pRoot;
	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			treeNode* pChild = new treeNode;
			memset(pChild, 0, sizeof(treeNode));
			pChild->pos = pTemp->pos;
			switch (i)
			{
			case p_up:
				pChild->pos.row--;
				pChild->pos.g += ZXDJ;
				break;
			case p_down:
				pChild->pos.row++;
				pChild->pos.g += ZXDJ;
				break;
			case p_left:
				pChild->pos.col--;
				pChild->pos.g += ZXDJ;
				break;
			case p_right:
				pChild->pos.col++;
				pChild->pos.g += ZXDJ;
				break;
			case p_lup:
				pChild->pos.row--;
				pChild->pos.col--;
				pChild->pos.g += XXDJ;
				break;
			case p_ldown:
				pChild->pos.row++;
				pChild->pos.col--;
				pChild->pos.g += XXDJ;
				break;
			case p_rup:
				pChild->pos.row--;
				pChild->pos.col++;
				pChild->pos.g += XXDJ;
				break;
			case p_rdown:
				pChild->pos.row++;
				pChild->pos.col++;
				pChild->pos.g += XXDJ;
				break;
			}
			if (canWalk(pChild->pos, pathmap))
			{
				pChild->pos.g = getG(pChild->pos, endPos);
				pChild->pos.setF();
				pTemp->child.push_back(pChild);
				pChild->pParent = pTemp;

				buff.push_back(pChild);
			}
			vector<treeNode*>::iterator itMin = buff.begin();
			for (it = buff.begin(); it != buff.end(); it++)
			{
				if ((*itMin)->pos.f > (*it)->pos.f)
				{
					itMin = it;
				}
			}

			pathmap[pTemp->pos.row][pTemp->pos.col].isFind = true;

			pTemp = *itMin;

			buff.erase(itMin);
			if (pTemp->pos.row == endPos.row &&
				pTemp->pos.col == endPos.col)
			{
				isFindEnd = true;
				break;
			}

			if (buff.empty()) break;
		}
		if (isFindEnd)
		{
			printf("找到终点啦\n");
			while (pTemp)
			{
				printf("(%d %d)", pTemp->pos.row, pTemp->pos.col);
			}
			pTemp = pTemp->pParent;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


bool canWalk(MyPoint pos, pathNode pathmap[ROWS][COLS])
{
	if (pos.row < 0 || pos.row >= ROWS || pos.col < 0 || pos.col  >= COLS)
		return false;
	if (pathmap[pos.row][pos.col].val == 1)
		return false;
	if (pathmap[pos.row][pos.col].isFind == 1)
		return false;

	return true;
}

int getG(MyPoint pos, MyPoint endpos)
{
	int x = pos.col > endpos.col ? (pos.col - endpos.col) : (endpos.col - pos.col);
	int y = pos.row > endpos.row ? (pos.row - endpos.row) : (endpos.row - pos.row);

	return ZXDJ*(x + y);
}