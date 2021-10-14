#include "acllib.h"
#include <stdio.h>
#include "Game.h"

int Setup()
{
	initWindow("µÖÓù¿ÕÏ®", DEFAULT, DEFAULT, WIDTH, HEIGHT);
	/*beginPaint();
	setBrushColor(RGB(240, 230, 140));
	rectangle(0, 0, 200, 200);
	endPaint();*/
	
	GameBegin();
	GameLoading();
	
	return 0;
} 