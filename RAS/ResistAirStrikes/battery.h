#pragma once
#include "Game.h"
typedef struct 
{
	//��̨����
	int len;
	//��Բ�󽻵�
	int x1;	
	int y1;
	//��Բ�ҽ���
	int x2;
	int y2;

	//˨Բ
	int c_R;	//�뾶
	int c_x;
	int c_y;

}Battery;

Battery bty;

//��ʼ����̨
void setBattery();


//������̨
void paintBattery();
