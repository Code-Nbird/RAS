#pragma once
#include <stdio.h>
#include <stdlib.h> 


typedef struct
{
	int x;	//x坐标 
	int y;	//y坐标 
	int d;	//方向 
	
	Plane *next;
}Plane;

void BuildPlane(Plane *p)	//建造初始飞机,2左2右 
{
	Plane *l1 = (Plane *)malloc(sizeof(Plane));
	Plane *l2 = (Plane *)malloc(sizeof(Plane));
	Plane *r1 = (Plane *)malloc(sizeof(Plane));
	Plane *r2 = (Plane *)malloc(sizeof(Plane));	
	
	l1.x = 
	
} 
