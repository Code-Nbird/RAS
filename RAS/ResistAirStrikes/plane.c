#pragma once
#include "Game.h"

extern Plane pl[PLANE_N];

//设置飞机
void setPlane()
{
	//随机树种子
	srand((unsigned int)time(NULL));
	
	//飞机模型
	POINT p1, p2, p3, p4, p5, p6;
	//tail
	p1.x = 8; p1.y = 55;
	p2.x = 15; p2.y = 75;
	//body
	p3.x = 100; p3.y = 75;
	p4.x = 110; p4.y = 85;
	//wing
	p5.x = 75; p5.y = 45;
	p6.x = 45; p6.y = 110;

	

	for (int i = 0; i < PLANE_N; i++)
	{
		
		if (i < BEGIN_PLANE_N)
			pl[i].show = 1;
		else
			pl[i].show = 0;
		pl[i].live = PLANE_HP;
		pl[i].isAttack = 0;
		//随机左右方向飞
		pl[i].d = rand() % 2;
		//随机位置
		long r_x = 7 + 150 * (rand()%2 + rand()%2);
		long r_y = 5 + 100 * (rand()%2);
		int d = RIGHT;
		if (pl[i].d == LEFT)
			d = LEFT;
		pl[i].p_tail[0] = randPoint(p1, d, r_x, r_y);
		pl[i].p_tail[1] = randPoint(p2, d, r_x, r_y);
		pl[i].p_body[0] = randPoint(p2, d, r_x, r_y);
		pl[i].p_body[1] = randPoint(p3, d, r_x, r_y);
		pl[i].p_body[2] = randPoint(p4, d, r_x, r_y);
		pl[i].p_wing[0] = randPoint(p5, d, r_x, r_y);
		pl[i].p_wing[1] = randPoint(p6, d, r_x, r_y);
		
	}
}

//创建平移点
POINT randPoint(POINT p,int d, long r_x, long r_y)
{
	
	POINT pt;
	pt.x = p.x  + r_x;
	pt.y = p.y  +r_y;
	if (d == LEFT)
	{
		pt.x = 800 - pt.x;
		pt.y = pt.y;
	}

	return pt;
}

//建造飞机
void paintPlane()
{
	for (int i = 0; i < PLANE_N; i++)
	{
		if (pl[i].show == 0)
			continue;
		
		if (pl[i].isAttack == 1)
		{
			setPenColor(RGB(240,230,140));
			pl[i].isAttack = 0;
		}
		setPenWidth(7);
		line(pl[i].p_tail[0].x, pl[i].p_tail[0].y,
			pl[i].p_tail[1].x, pl[i].p_tail[1].y);
		
		/*if (pl[i].live > PLANE_HP - 2)*/
		
		setPenWidth(10);
		line(pl[i].p_wing[0].x, pl[i].p_wing[0].y,
			pl[i].p_wing[1].x, pl[i].p_wing[1].y);
		
			
		polygon(pl[i].p_body, 3);
		setPenColor(BLACK);
		setPenWidth(1);
	}
}

//添加飞机
void addPlane()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < PLANE_N; i++)
		{
			if (pl[i].show == 0)
			{
				pl[i].show = 1;
				break;
			}

		}
	}
	
}

//飞机移动
void movePlane()
{
	//飞机模型
	POINT p1, p2, p3, p4, p5, p6;
	//tail
	p1.x = 8; p1.y = 55;
	p2.x = 15; p2.y = 75;
	//body
	p3.x = 100; p3.y = 75;
	p4.x = 110; p4.y = 85;
	//wing
	p5.x = 75; p5.y = 45;
	p6.x = 45; p6.y = 110;

	for (int i = 0; i < PLANE_N; i++)
	{
		if (pl[i].show != 0)
		{
			int d = 1;
			if (pl[i].d == LEFT)
				d = -1;
			pl[i].p_tail[0] = randPoint(pl[i].p_tail[0], 1, d*PLANE_V, 0);
			pl[i].p_tail[1] = randPoint(pl[i].p_tail[1], 1, d*PLANE_V, 0);
			pl[i].p_body[0] = randPoint(pl[i].p_body[0], 1, d*PLANE_V, 0);
			pl[i].p_body[1] = randPoint(pl[i].p_body[1], 1, d*PLANE_V, 0);
			pl[i].p_body[2] = randPoint(pl[i].p_body[2], 1, d*PLANE_V, 0);
			pl[i].p_wing[0] = randPoint(pl[i].p_wing[0], 1, d*PLANE_V, 0);
			pl[i].p_wing[1] = randPoint(pl[i].p_wing[1], 1, d*PLANE_V, 0);
		}
		if (pl[i].p_body[2].x < 0 || pl[i].p_tail->x>800)
		{
			pl[i].show = 0;
			pl[i].live = PLANE_HP;
			//随机左右方向飞
			pl[i].d = rand() % 2;
			//随机位置
			long r_x = 7 + 150 * (rand() % 1 + rand() % 2);
			long r_y = 5 + 100 * (rand() % 2);
			int d = RIGHT;
			if (pl[i].d == LEFT)
				d = LEFT;
			pl[i].p_tail[0] = randPoint(p1, d, r_x, r_y);
			pl[i].p_tail[1] = randPoint(p2, d, r_x, r_y);
			pl[i].p_body[0] = randPoint(p2, d, r_x, r_y);
			pl[i].p_body[1] = randPoint(p3, d, r_x, r_y);
			pl[i].p_body[2] = randPoint(p4, d, r_x, r_y);
			pl[i].p_wing[0] = randPoint(p5, d, r_x, r_y);
			pl[i].p_wing[1] = randPoint(p6, d, r_x, r_y);
		}
	}
}