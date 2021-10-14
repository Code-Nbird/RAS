#pragma once
#include "Game.h"
typedef struct 
{
	//炮台长度
	int len;
	//矩圆左交点
	int x1;	
	int y1;
	//矩圆右交点
	int x2;
	int y2;

	//栓圆
	int c_R;	//半径
	int c_x;
	int c_y;

}Battery;

Battery bty;

//初始化炮台
void setBattery();


//建造炮台
void paintBattery();
