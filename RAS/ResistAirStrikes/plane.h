#pragma once
#include "Game.h"



typedef struct plane
{
	int x;	//x坐标 
	int y;	//y坐标 
	int d;	//方向 
	
	struct plane *next;
}Plane;

//初始飞机,2左2右 
void setPlane();

//建造飞机
void paintPlane();

//添加飞机
void addPlane();


