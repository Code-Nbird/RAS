#pragma once
#include <stdio.h>
#include <stdlib.h> 


typedef struct
{
	int x;	//x���� 
	int y;	//y���� 
	int d;	//���� 
	
	Plane *next;
}Plane;

void BuildPlane(Plane *p)	//�����ʼ�ɻ�,2��2�� 
{
	Plane *l1 = (Plane *)malloc(sizeof(Plane));
	Plane *l2 = (Plane *)malloc(sizeof(Plane));
	Plane *r1 = (Plane *)malloc(sizeof(Plane));
	Plane *r2 = (Plane *)malloc(sizeof(Plane));	
	
	l1.x = 
	
} 
