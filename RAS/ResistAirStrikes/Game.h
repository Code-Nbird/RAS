#pragma once
#include "acllib.h" 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define WIDTH 800
#define HEIGHT 640
#define PAI (3.1415926/180)
#define BATTERY_TRUN 20
#define BOMB_N 6
#define BOMB_V 50
#define PLANE_V 5
#define BEGIN_PLANE_N 2
#define PLANE_N 7
#define PLANE_HP 3


typedef enum
{
	LEFT = 0,
	RIGHT,
}Air_Direction;

typedef enum
{
	FLASH = 0,
	NOTETIME,
	RELOAD,
	BUIDEPLANE,
}Timer;

//�ɻ�
typedef struct plane
{
	//����
	Air_Direction d;
	//����ֵ
	int live;
	//����
	int show;
	//�ɻ�ģ��
	POINT p_body[3];
	POINT p_wing[2];
	POINT p_tail[2];
	//�ܻ��ж�
	int isAttack;
	
}Plane;

//�ڵ� 
typedef struct bomb
{
	//�ڵ�Բ��
	POINT b_c;
	//�ڵ��뾶
	int b_r;
	//�ڵ��ٶ�
	int b_v;
	//�ڵ�����Ƕ�
	int b_angle;
	
}Bomb;
//��ը 

//��̨
typedef struct
{
	//��̨����
	int len;
	//��Բ�󽻵�
	POINT d1;
	//��Բ�ҽ���
	POINT d2;

	//�ڿ���
	POINT u1;
	//��¥��
	POINT u2;
	//˨Բ
	long c_R;	//�뾶
	POINT c;

	//��ת�Ƕ�
	int angle;
	int i;

}Battery;

typedef struct {
	POINT c;
	
}Boom;

//ȫ�ֱ���
Battery bty;
Plane pl[PLANE_N];
int GameOn;	//��Ϸ��ʼ��־
Bomb bb[BOMB_N];
Boom bm;
int bomb_n;	//�ڵ�����	
int plane_n;	//�ɻ�����
int score;	//�÷�
ACL_Sound *S_Open;
ACL_Sound*S_Shoot;
ACL_Sound* S_War;
ACL_Sound* S_People;
ACL_Image* beginpaint;

//�ɻ�
//��ʼ�ɻ�,2��2�� 
void setPlane();

//����ɻ�
void paintPlane();

//��ӷɻ�
void addPlane();

//�ɻ��ƶ�
void movePlane();

//����ƽ�Ƶ�
POINT randPoint(POINT p, int d, long r_x, long r_y);



//��̨
//��ʼ����̨
void setBattery();

//������̨
void paintBattery();



//ը��
//��ʼ��ը�� 5��ը��ÿ2��װ��һ��
void setBomb();

//����ը��
void paintBomb();

//�ӵ�װ��
void reloadBomb();

//�ӵ��ƶ�
void moveBomb();

//��̨���
void shootBomb();



//��ը
//��ը�ж�
void isBoom();

//��ը����()
void Boomhappen(int p_i, int b_i);

//���챬ը()
void paintBoom();



//��Ϸ��ʼ 
void GameBegin();

//��Ϸ����
void GameLoading(); 

//ͼ������
void Setting();

//�س�������Ϸ
void enterGame();

//����
void Paint();

//ˢ�»���
void flashDevice();

//�����¼� ���Ҽ��ƶ��ո����
void KeyBoardEvent(int key, int event);

//�ɻ��ڵ��ƶ�
void Move();

//��������
long Round(double x);

//ʱ���¼�
void TimerEvent(int id);

//�����ַ���
char* getScore(int score, char num[], char c[]);

//��������
void Line(POINT p1, POINT p2);




