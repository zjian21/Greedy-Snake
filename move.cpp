
#include"function.h"
#include"snake.h"
#include "food.h"
extern char data[LENGTH][LENGTH];	//结构体指针可以跨cpp文件
extern Snake* head;
static int MOVE = 4;	//根据初始化的方向

/*--------------------------
* Function：获取按键
--------------------------*/
int ChangeSnake()
{
	char click = ' ';
	if (_kbhit())
	{
		click = _getch();
	}
	if (click == 'w')
	{
		return 1;
	}
	else if (click == 's')
	{
		return 2;
	}
	else if (click == 'a')
	{
		return 3;
	}
	else if (click == 'd')
	{
		return 4;
	}
	else
		return MOVE;
}

/*--------------------------
* Function：处理按键
--------------------------*/
void Handle_key()
{
	Snake* p;
	MOVE = ChangeSnake();

	p = head->next;
//	printf(" Chang:%d\n",MOVE);
	if (MOVE == 1)				//向上
	{
		if (p->path != 2)		//避免相反可以移动
		{
			p->path = 1;
		}
	}
	else if (MOVE == 2)		//向下
	{
		if (p->path != 1)
		{
			p->path = 2;
		}
	}
	else if (MOVE == 3)		//向左
	{
		if (p->path != 4)
		{
			p->path = 3;
		}
	}
	else if (MOVE == 4)		//向右
	{
		if (p->path != 3)
		{
			p->path = 4;
		}
	}
}
