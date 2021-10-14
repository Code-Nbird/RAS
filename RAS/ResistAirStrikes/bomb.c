#pragma once
#include "Game.h"

extern Bomb bb[BOMB_N];
extern int score;

//炸弹
//初始化炸弹 5个炸弹每2秒装填一个
void setBomb()
{
	/*bb = create();*/
	for (int i = 0; i < BOMB_N; i++)
	{
		bb[i].b_r = 30;
		bb[i].b_c.x = (bty.u1.x + bty.u2.x) / 2;
		bb[i].b_c.y = (bty.u1.y + bty.u2.y) / 2;
		bb[i].b_v = 0;
	}
	bomb_n = BOMB_N;
	score = 0;
}

//建造炸弹
void paintBomb()
{
	
	char bomb_num[BOMB_N+1][2] = { 0 };
	for (int i = 0; i <= BOMB_N; i++) 
	{
		bomb_num[i][0] = '0' + i;
		bomb_num[i][1] = '\0';
	}
	setBrushColor(RED);
	
	
		for (int i = 0; i < BOMB_N; i++)
		{
			if (bb[i].b_v == 0)
			{
				bb[i].b_c.x = (bty.u1.x + bty.u2.x) / 2;
				bb[i].b_c.y = (bty.u1.y + bty.u2.y) / 2;
				if (bomb_n == 0)
					continue;
			}
			ellipse(bb[i].b_c.x - bb[i].b_r, bb[i].b_c.y - bb[i].b_r,
				bb[i].b_c.x + bb[i].b_r, bb[i].b_c.y + bb[i].b_r);
	
		}
		
	
	setPenColor(BLACK);
	setTextSize(20);
	paintText(50, 565, "剩余炮弹数量:");
	paintText(230, 565, bomb_num[bomb_n]);
	paintText(600, 565, "得分:");
	char num[9] = { 0 }, c[9] = { 0 };
	const char* s = getScore(score, num, c);
	paintText(700, 565,s);

}

void reloadBomb()
{
	for (int i = 0; i < BOMB_N; i++)
	{
		if (bb[i].b_c.x > WIDTH+bb->b_r || bb[i].b_c.y > HEIGHT+bb->b_r ||
			bb[i].b_c.x < -bb->b_r || bb[i].b_c.y < -bb->b_r)
		{
			bb[i].b_c.x = (bty.u1.x + bty.u2.x) / 2;
			bb[i].b_c.y = (bty.u1.y + bty.u2.y) / 2;
			bb[i].b_v = 0;		
		}
	}
	if (bomb_n < BOMB_N)
		bomb_n++;	
}


//炮弹移动
void moveBomb()
{
	for (int i = 0; i < BOMB_N; i++)
	{
		if (bb[i].b_v != 0)
		{
			bb[i].b_c.x += Round(bb[i].b_v * sin(PAI *bb[i].b_angle));
			bb[i].b_c.y -= Round(bb[i].b_v * cos(PAI *bb[i].b_angle));
		}
	}
}

//炮台射击
void shootBomb()
{
	if (bomb_n)
	{
		for (int i = 0; i < BOMB_N; i++)
		{
			if (bb[i].b_v == 0)
			{
				playSound(*S_Shoot, 0);
				bb[i].b_v = BOMB_V;
				bb[i].b_angle = bty.angle;
				bomb_n--;
				break;
			}
		}
	}
}	

//分数字符串

char* getScore(int s, char num[], char c[])
{
	int n = s;
	int i = 0, t = 0;
	
	if (n == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return num;
	}

	while (n)
	{
		t = n % 10;
		c[i++] = '0' + t;
		n /= 10;
	}
	c[i] = '\0';
	num[i] = '\0';
	for (int j = 0; j < i; j++)
	{
		num[i - j - 1] = c[j];
	}
	return num;
}