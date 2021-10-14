#pragma once
#include "Game.h"

//爆炸判定
void isBoom()
{

	for (int i = 0; i < PLANE_N; i++)
	{
		if (pl[i].show == 0)
			continue;
		long y = (pl[i].p_wing[0].y+pl[i].p_wing[1].y)/ 2;
		for (int j = 0; j < BOMB_N; j++)
		{
			long left, right;
			if (pl[i].d == LEFT)
			{
				left = pl[i].p_body[2].x;
				right = pl[i].p_wing[0].x;
			}
			else
			{
				left = pl[i].p_wing[0].x;
				right = pl[i].p_body[2].x;
			}
			if ((bb[j].b_c.y + bb[j].b_r )<= y
				&& (bb[j].b_c.x + bb[j].b_r)> left 
				&& (bb[j].b_c.x -bb[j].b_r)< right)
			{
				bm.c.x = bb[j].b_c.x - BOMB_V + 30;
				bm.c.y = bb[j].b_c.y + BOMB_V-10;
				Boomhappen(i, j);
			}
		}
	}

}

//爆炸处理
void Boomhappen(int p_i, int b_i)
{
	beginPaint();
	pl[p_i].live--;
	pl[p_i].isAttack = 1;
	paintPlane();
	//paintBomb();
	if (pl[p_i].live == 0)
	{
		pl[p_i].show = 0;
		score += 50;
		//paintBomb();
		paintBoom();
	}
	
	
	endPaint();
	bb[b_i].b_c.x = 2000;
}


//制造爆炸()
void paintBoom()
{
	//143, 153
	int x = bm.c.x;
	int y = bm.c.y;
	POINT p_cloud[] =
	{
		{x + 3,y - 13},

		{x - 12,y - 32},
		{x + 34,y - 35},
		{x + 37,y - 21},

		{x + 45,y - 32},
		{x + 78,y - 12},
		{x + 67,y - 1},

		{x + 87,y - 16},
		{x + 105,y + 24},
		{x + 79,y + 30},

		{x + 94,y + 43},
		{x + 61,y + 65},
		{x + 53,y + 51},

		{x + 55,y + 61},
		{x + 15,y + 60},
		{x + 19,y + 48},

		{x + 8,y + 58},
		{x - 36,y + 28},
		{x - 14,y + 21},

		{x - 34,y + 15},
		{x - 13,y - 21},
		{x + 3,y - 13}
	};

	POINT p_flower1[] =
	{
		{x - 19,y - 19},

		{x - 20,y - 11},
		{x - 33,y - 23},
		{x - 25,y - 27},

		{x - 32,y - 35},
		{x - 19,y - 39},
		{x - 17,y - 31},

		{x - 13,y - 35},
		{x - 6,y - 26},
		{x - 12,y - 23},

		{x - 9,y - 15},
		{x - 12,y - 15},
		{x - 17,y - 17}
	};

	POINT p_flower2[] =
	{
		{x + 78,y - 19},

		{x + 69,y - 21},
		{x + 79,y - 30},
		{x + 80,y - 24},

		{x + 87,y - 34},
		{x + 100,y - 27},
		{x + 90,y - 21},

		{x + 99,y - 16},
		{x + 89,y - 6},
		{x + 81,y - 12},

		{x + 77,y - 12},
		{x + 73,y - 9},
		{x + 78,y - 19},
	};

	POINT p_line[] =
	{
		{x - 2,y - 40},
		{x + 5,y - 31},

		{x + 30,y - 44},
		{x + 28,y - 33},

		{x + 59,y - 42},
		{x + 55,y - 28},

		{x + 107,y},
		{x + 92,y + 3},

		{x + 104,y + 33},
		{x + 94,y + 29}
	};
	setPenColor(RGB(178, 34, 34));
	setPenWidth(3);
	Line(p_line[0], p_line[1]);
	Line(p_line[2], p_line[3]);
	Line(p_line[4], p_line[5]);
	Line(p_line[6], p_line[7]);
	Line(p_line[8], p_line[9]);
	polyBezier(p_flower1, sizeof(p_flower1) / sizeof(p_flower1[0]));
	polyBezier(p_flower2, sizeof(p_flower2) / sizeof(p_flower2[0]));
	polyBezier(p_cloud, sizeof(p_cloud) / sizeof(p_cloud[0]));
	setPenColor(RGB(178, 34, 34));
	setTextColor(RGB(128, 0, 0));
	setTextSize(34);
	setTextFont("Consolas");
	paintText(x, y, "BOOM");

	setPenColor(BLACK);
	setPenWidth(1);
	setTextFont("宋体");
	setPenColor(BLACK);
	setTextColor(BLACK);
}