#pragma once
#include "Game.h"



typedef struct plane
{
	int x;	//x���� 
	int y;	//y���� 
	int d;	//���� 
	
	struct plane *next;
}Plane;

//��ʼ�ɻ�,2��2�� 
void setPlane();

//����ɻ�
void paintPlane();

//��ӷɻ�
void addPlane();


