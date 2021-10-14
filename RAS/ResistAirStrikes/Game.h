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

//飞机
typedef struct plane
{
	//方向
	Air_Direction d;
	//生命值
	int live;
	//显形
	int show;
	//飞机模型
	POINT p_body[3];
	POINT p_wing[2];
	POINT p_tail[2];
	//受击判断
	int isAttack;
	
}Plane;

//炮弹 
typedef struct bomb
{
	//炮弹圆心
	POINT b_c;
	//炮弹半径
	int b_r;
	//炮弹速度
	int b_v;
	//炮弹射出角度
	int b_angle;
	
}Bomb;
//爆炸 

//炮台
typedef struct
{
	//炮台长度
	int len;
	//矩圆左交点
	POINT d1;
	//矩圆右交点
	POINT d2;

	//炮口左
	POINT u1;
	//炮楼右
	POINT u2;
	//栓圆
	long c_R;	//半径
	POINT c;

	//所转角度
	int angle;
	int i;

}Battery;

typedef struct {
	POINT c;
	
}Boom;

//全局变量
Battery bty;
Plane pl[PLANE_N];
int GameOn;	//游戏开始标志
Bomb bb[BOMB_N];
Boom bm;
int bomb_n;	//炮弹数量	
int plane_n;	//飞机数量
int score;	//得分
ACL_Sound *S_Open;
ACL_Sound*S_Shoot;
ACL_Sound* S_War;
ACL_Sound* S_People;
ACL_Image* beginpaint;

//飞机
//初始飞机,2左2右 
void setPlane();

//建造飞机
void paintPlane();

//添加飞机
void addPlane();

//飞机移动
void movePlane();

//创建平移点
POINT randPoint(POINT p, int d, long r_x, long r_y);



//炮台
//初始化炮台
void setBattery();

//建造炮台
void paintBattery();



//炸弹
//初始化炸弹 5个炸弹每2秒装填一个
void setBomb();

//建造炸弹
void paintBomb();

//子弹装填
void reloadBomb();

//子弹移动
void moveBomb();

//炮台射击
void shootBomb();



//爆炸
//爆炸判定
void isBoom();

//爆炸处理()
void Boomhappen(int p_i, int b_i);

//制造爆炸()
void paintBoom();



//游戏开始 
void GameBegin();

//游戏加载
void GameLoading(); 

//图形配置
void Setting();

//回车进入游戏
void enterGame();

//画面
void Paint();

//刷新画面
void flashDevice();

//键盘事件 左右键移动空格射击
void KeyBoardEvent(int key, int event);

//飞机炮弹移动
void Move();

//四舍五入
long Round(double x);

//时间事件
void TimerEvent(int id);

//分数字符串
char* getScore(int score, char num[], char c[]);

//两点连线
void Line(POINT p1, POINT p2);




