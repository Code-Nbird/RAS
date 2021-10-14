#include "Game.h"

//参数设置
void Setting()
{
	setPlane();
	setBomb();
	setBattery();
}

//游戏开始 
void GameBegin()
{	
	S_Open = (ACL_Sound*)malloc(sizeof(ACL_Sound*));
	S_Shoot = (ACL_Sound*)malloc(sizeof(ACL_Sound*));
	S_War = (ACL_Sound*)malloc(sizeof(ACL_Sound*));
	S_People = (ACL_Sound*)malloc(sizeof(ACL_Sound*));
	beginpaint = (ACL_Image*)malloc(sizeof(ACL_Image*));
	/*beginPaint();
	setBrushColor(YELLOW);
	rectangle(100, 50, 700, 200);
	rectangle(215, 220, 585, 400);
	
	setTextColor(GREEN);
	setTextBkColor(YELLOW);
	setTextFont("宋体");
	
	setTextColor(RED); 
	setTextSize(55);
	paintText(200,90,"<< 抵御空袭 >>");
	
	setTextColor(BLACK);	
	
	setTextSize(25);
	paintText(230, 250, "按 \"<-\" \"->\" 控制炮台角度!");
	paintText(230, 325, "按 space 空格键 发射!");
	setTextBkColor(WHITE);
	setTextSize(20); 
	paintText(240,440, "-----按 ENTER 进入游戏-----");
	GameOn = 0;
	
	endPaint();	 */
	
	//音效
	loadSound("open.mp3", S_Open);
	loadSound("war.mp3", S_War);
	loadSound("shoot.mp3", S_Shoot);
	loadSound("people.mp3", S_People);
	loadImage("begin.jpg", beginpaint);
	beginPaint();
	putImageScale(beginpaint,0, 0, WIDTH, HEIGHT);
	endPaint();
	playSound(*S_Open, 5);

}

//回车进入游戏
void enterGame()
{
	if (GameOn == 0)
	{
		Setting();
		Paint();
		GameOn = 1;
		stopSound(*S_Open);
		playSound(*S_War, 100);
		playSound(*S_People, 100);
		
	}
}

//左右键移动空格射击炮台
void KeyBoardEvent(int key, int event)
{
	if (event == 0)
	{
		switch (key)
		{
			//左键
		case 37:
		{
			if (bty.angle > -75 && GameOn == 1)
			{
				bty.angle -= BATTERY_TRUN;
			}
		}
		break;
			//右键
		case 39:
		{
			if (bty.angle < 75 && GameOn == 1)
			{
				bty.angle += BATTERY_TRUN;
			}
		}
		break;
			//空格键
		case 32:
			if (GameOn == 1)
				shootBomb();
			break;
			//enter键
		case 13:
			enterGame();
			break;
		default:
			break;
		}
	}
}


//画面
void Paint()
{
	beginPaint();
	clearDevice();
	paintBattery();
	paintPlane();
	paintBomb();
	endPaint();
}

//每50毫秒刷新画面
void flashDevice()
{
	Paint();
}

void TimerEvent(int id)
{
	if (GameOn == 1)
	{
		switch (id)
		{
		case FLASH:
			flashDevice();
			break;
		case NOTETIME:
			Move();
			break;
		case RELOAD:
			reloadBomb();
			break;
		case BUIDEPLANE:
			addPlane();
		default:
			break;
		}
	}
	
}

void Move()
{
	moveBomb();
	movePlane();
	isBoom();
}


//游戏初始化
void GameLoading()
{
	registerKeyboardEvent(KeyBoardEvent);
	registerTimerEvent(TimerEvent);
	
	//刷新画面
	startTimer(FLASH, 150);
	//记录时间
	startTimer(NOTETIME, 75);
	//装填弹药
	startTimer(RELOAD, 1500);
	//生成飞机
	startTimer(BUIDEPLANE, 7000);
} 

//四舍五入
long Round(double x)
{
	int i = (int)x;
	double y = x - i;
	y = (y > 0) ? y : -y;
	if ( y < 0.5)
		return i;
	else
		return i + 1;
}

void Line(POINT p1, POINT p2)
{
	line(p1.x, p1.y, p2.x, p2.y);
}
