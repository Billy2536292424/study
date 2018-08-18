#include<graphics.h>//图形库头文件
#include<conio.h>//按键相关的头文件
#include<time.h>
#include<imapi.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define MAX 1000//蛇的最大节数
#define SIZE 20//蛇的尺寸
IMAGE sheadup, sheaddown, sheadleft, sheadright,body, sfood;

struct COOR//坐标类
{
	int x;
	int y;
};
enum CH
{
	up=72,//键码值
	down=80,
	left=75,
	right=77
};
//蛇类
struct SNAKE
{
	int n;//蛇的节数
	COOR scr[MAX];//蛇的坐标
	CH ch;//蛇的方向
}snake;

struct FOOD//食物类	
{
	COOR fcr;//食物坐标
	int  flag;//食物是否生成的标志
}food;

void initGame()
{
	initgraph(640, 480);//窗口宽度，高度
	
	setbkcolor(WHITE);
	cleardevice();
	//加载图片
	loadimage(&sheadup, L"蛇头上.jpg", SIZE, SIZE);
	loadimage(&sheaddown, L"蛇头下.jpg", SIZE, SIZE);
	loadimage(&sheadleft, L"蛇头左.jpg", SIZE, SIZE);
	loadimage(&sheadright, L"蛇头右.jpg", SIZE, SIZE);
	loadimage(&body, L"蛇身.jpg", SIZE, SIZE);
	loadimage(&sfood, L"西瓜.jpg", SIZE, SIZE);
	snake.n = 1;//蛇的节数初始化
	snake.scr[0].x = 0;//蛇的坐标
	snake.scr[0].y = 0;
	snake.ch = right;

	food.flag = 0;//生成食物
}

//绘制蛇
void SnakePaint()
{
	//绘制蛇头
	/*fillrectangle(snake.scr[0].x, snake.scr[0].y, snake.scr[0].x + SIZE, \
		snake.scr[0].y + SIZE);*/
	switch (snake.ch)
	{
	case up:
		putimage(snake.scr[0].x, snake.scr[0].y, &sheadup);
		break;
	case down:
		putimage(snake.scr[0].x, snake.scr[0].y, &sheaddown);
		break;
	case left:
		putimage(snake.scr[0].x, snake.scr[0].y, &sheadleft);
		break;
	case right:
		putimage(snake.scr[0].x, snake.scr[0].y, &sheadright);
		break;
	default:
		break;
	}
	//绘制蛇身
	for (int i = snake.n - 1; i > 0; i--)
	{
		/*fillrectangle(snake.scr[i].x, snake.scr[i].y, snake.scr[i].x + \
			SIZE, snake.scr[i].y + SIZE);*/
		putimage(snake.scr[i].x, snake.scr[i].y, &body);
	}
}
//蛇的移动
void SnakeMove()
{
	for (int i = snake.n - 1; i > 0; i--)
	{
		snake.scr[i].x = snake.scr[i - 1].x;
		snake.scr[i].y = snake.scr[i - 1].y;
 	}
	switch (snake.ch)
	{
	case up:
		snake.scr[0].y -= SIZE;
		break;
	case down:
		snake.scr[0].y += SIZE;
		break;
	case left:
		snake.scr[0].x -= SIZE;
		break;
	case right:
		snake.scr[0].x += SIZE;
		break;
	default:
		break;
	}
}
//控制蛇的方向
void ChangeSnakech()
{
	switch (_getch())
	{
	case 72:
		if (snake.ch != down)
			snake.ch = up;
		break;
	case 80:
		if (snake.ch != up)
			snake.ch = down;
		break;
	case 75:
		if (snake.ch != right)
			snake.ch = left;
		break;
	case 77:
		if (snake.ch != left)
			snake.ch = right;
		break;
	default:
		break;
	}
}
//生成食物坐标
void FoodCoor()
{
	//随机数种子
	srand((unsigned)time(NULL));
	food.fcr.x = rand() % 32 * SIZE;
	food.fcr.y = rand() % 24 * SIZE;
	food.flag = 1;//生成坐标以后先不生成食物

}
//绘制食物
void FoodPaint()
{
	/*setlinecolor(BLUE);
	roundrect(food.fcr.x,food.fcr.y,\
		food.fcr.x+SIZE,food.fcr.y+SIZE,10,10);*///绘制圆角矩形
	putimage(food.fcr.x, food.fcr.y, &sfood);
}

//吃食物
void EatFood()
{
	if (snake.scr[0].x == food.fcr.x&&snake.scr[0].y == food.fcr.y)
	{
		snake.n++;
		food.flag = 0;
	}
}

void judge()
{
	cleardevice();
	settextcolor(LIGHTGREEN);
	settextstyle(50, 0, L"宋体");
	outtextxy(200, 200, L"Game Over");

	Sleep(3000);
	exit(0);
}
//判断游戏结束
void GameOver()
{
	//蛇头撞到了墙
	if (snake.scr[0].x<0 || snake.scr[0].x>620 ||\
		snake.scr[0].y<0 || snake.scr[0].y>460)
	{
		judge();
	}
	//蛇头撞到了蛇身
	for (int i = snake.n - 1; i > 0; i--)
	{
		if (snake.scr[0].x == snake.scr[i].x\
			&&snake.scr[0].y == snake.scr[i].y)
		{
			judge();
		}
	}
}
int main()
{
	
	initGame();

	PlaySound(L"F:\\Documents\\工程\\贪吃蛇\\贪吃蛇\\PGL - Dear mom.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	while (1)
	{
		while (!_kbhit())//当按下按键退出循环
		{
			if (food.flag == 0)
				FoodCoor();
			cleardevice();//刷新屏幕
			FoodPaint();
			SnakeMove();//蛇的移动
			SnakePaint();//蛇的绘制
			Sleep(300);
			EatFood();
			GameOver();
		}
		
		ChangeSnakech();
	}

	return 0;
}