#include "Game.h"

//��������
void Setting()
{
	setPlane();
	setBomb();
	setBattery();
}

//��Ϸ��ʼ 
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
	setTextFont("����");
	
	setTextColor(RED); 
	setTextSize(55);
	paintText(200,90,"<< ������Ϯ >>");
	
	setTextColor(BLACK);	
	
	setTextSize(25);
	paintText(230, 250, "�� \"<-\" \"->\" ������̨�Ƕ�!");
	paintText(230, 325, "�� space �ո�� ����!");
	setTextBkColor(WHITE);
	setTextSize(20); 
	paintText(240,440, "-----�� ENTER ������Ϸ-----");
	GameOn = 0;
	
	endPaint();	 */
	
	//��Ч
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

//�س�������Ϸ
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

//���Ҽ��ƶ��ո������̨
void KeyBoardEvent(int key, int event)
{
	if (event == 0)
	{
		switch (key)
		{
			//���
		case 37:
		{
			if (bty.angle > -75 && GameOn == 1)
			{
				bty.angle -= BATTERY_TRUN;
			}
		}
		break;
			//�Ҽ�
		case 39:
		{
			if (bty.angle < 75 && GameOn == 1)
			{
				bty.angle += BATTERY_TRUN;
			}
		}
		break;
			//�ո��
		case 32:
			if (GameOn == 1)
				shootBomb();
			break;
			//enter��
		case 13:
			enterGame();
			break;
		default:
			break;
		}
	}
}


//����
void Paint()
{
	beginPaint();
	clearDevice();
	paintBattery();
	paintPlane();
	paintBomb();
	endPaint();
}

//ÿ50����ˢ�»���
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


//��Ϸ��ʼ��
void GameLoading()
{
	registerKeyboardEvent(KeyBoardEvent);
	registerTimerEvent(TimerEvent);
	
	//ˢ�»���
	startTimer(FLASH, 150);
	//��¼ʱ��
	startTimer(NOTETIME, 75);
	//װ�ҩ
	startTimer(RELOAD, 1500);
	//���ɷɻ�
	startTimer(BUIDEPLANE, 7000);
} 

//��������
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
