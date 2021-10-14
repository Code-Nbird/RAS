#pragma once
#include "Game.h"

extern Battery bty;

//初始炮台
void setBattery()
{
	//基础设置
	bty.c_R = 30; bty.len = 50;
	bty.c.x = WIDTH / 2; bty.c.y = 525;
	bty.d1.x = bty.c.x - bty.c_R; bty.d1.y = bty.c.y;
	bty.d2.x = bty.c.x + bty.c_R; bty.d2.y = bty.c.y;
	bty.u1.x = bty.d1.x; bty.u1.y = bty.c.y-bty.len;
	bty.u2.x = bty.d2.x; bty.u2.y = bty.u1.y;
	bty.angle = 0;
	
}

//建造炮台
void paintBattery()
{	
		//更新坐标
		bty.d1.x = Round(bty.c.x - bty.c_R + (1.0 - cos(PAI * bty.angle)) * bty.c_R);
		bty.d2.x = Round(bty.c.x + bty.c_R - (1.0 - cos(PAI * bty.angle)) * bty.c_R);
		bty.u1.x = Round(bty.d1.x + bty.len * sin(PAI * bty.angle));
		bty.u2.x = Round(bty.d2.x + bty.len * sin(PAI * bty.angle));

		bty.d1.y = Round(bty.c.y - bty.c_R * sin(PAI * bty.angle));
		bty.d2.y = Round(bty.c.y + bty.c_R * sin(PAI * bty.angle));
		bty.u1.y = Round(bty.d1.y - cos(PAI * bty.angle) * bty.len);
		bty.u2.y = Round(bty.d2.y - cos(PAI * bty.angle) * bty.len);
		
		//更新点
		POINT rc[4] = {bty.d1, bty.d2, bty.u2, bty.u1};

		
		//R = 30
		//炮台地基
		line(0, 555, 800, 555);
		//炮台边框(340,525)yt 
		arc(310, 495, 370, 555, 340, 600, 370, 525);
		//(460,525)
		arc(430, 495, 490, 555, 370, 525, 460, 600);
		//(400,525)
		setBrushColor(BLACK);
		
		polygon(rc, 4);
		
		ellipse(bty.c.x - bty.c_R, bty.c.y - bty.c_R,
			bty.c.x + bty.c_R, bty.c.y + bty.c_R);

}