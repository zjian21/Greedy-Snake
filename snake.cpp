#include "snake.h"
#include "function.h"

Snake* head;
char data[LENGTH][LENGTH];

/*--------------------------
* Function：生成头
--------------------------*/
Snake* create()
{
	head = (Snake*)malloc(sizeof(Snake));
	if (head == NULL)
		printf("error");
	else 
		head->next = NULL;
	return head;
}
/*----------------------------
* Function：初始化链头
-----------------------------*/
int Insert_Data(int x, int y, int path)
{
	Snake* p, * q;
	p = (Snake*)malloc(sizeof(Snake));
	if (p == NULL)
		return 0;
	p->Frame_X = x;
	p->Frame_Y = y;
	p->path = path;
	q = head;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;
	p->next = NULL;
	return 0;
}

/*----------------------------
* Function：插入数据，增加长度
* Method:	头插法
-----------------------------*/
void Insert_Data3(int x, int y, int path)
{
	Snake* p;
	p = (Snake*)malloc(sizeof(Snake));

//吃完后往后面插一个
	if (path == 1)		
	{
		p->Frame_X = x - 1;
		p->Frame_Y = y ;
	}
	else if (path == 2)
	{
		p->Frame_X = x + 1;
		p->Frame_Y = y;
	}
	else if (path == 3)
	{
		p->Frame_X = x;
		p->Frame_Y = y - 1;
	}
	else if (path == 4)
	{
		p->Frame_X = x;
		p->Frame_Y = y + 1;
	}
	p->path = path;
	p->next = head->next;
	head->next = p;
}

/*----------------------------
* Function： 移动蛇身
* Parameter: path(方向)
----------------------------*/ 
void Move_Snake(int path)
{
	int i=0;	

	int ago_data_x[100];		//存储链表里还没移动的值
	int ago_data_y[100];

	Snake* p;
	p = head->next;
	if (path == 1)
	{
		i = 0;
		while (p != NULL)
		{
			if (p->next == NULL)		
				data[p->Frame_X][p->Frame_Y] = ' ';		//消去最后一个  
			ago_data_x[i] = p->Frame_X;
			ago_data_y[i] = p->Frame_Y;
			if (i == 0)
			{
				p->Frame_X--;
				data[p->Frame_X][p->Frame_Y] = '*';	
				p = p->next;
				i++;
				continue;
			}
			p->Frame_X = ago_data_x[i - 1];		//储存上一个节点的值
			p->Frame_Y = ago_data_y[i - 1];
			data[p->Frame_X][p->Frame_Y] = '*';
			p = p->next;
			i++;
		}
	}			
	else if (path == 2)
	{
		i = 0;
		while (p != NULL)
		{
			if (p->next == NULL)
				data[p->Frame_X][p->Frame_Y] = ' ';		//消去最后一个  */
			ago_data_x[i] = p->Frame_X;
			ago_data_y[i] = p->Frame_Y;
			if (i == 0)
			{
				p->Frame_X++;
				data[p->Frame_X][p->Frame_Y] = '*';
				p = p->next;
				i++;
				continue;
			}
			p->Frame_X = ago_data_x[i - 1];
			p->Frame_Y = ago_data_y[i - 1];
			data[p->Frame_X][p->Frame_Y] = '*';
			p = p->next;
			i++;
		}
	}
	else if (path == 3)
	{
		i = 0;
		while (p != NULL)
		{
			if (p->next == NULL)
				data[p->Frame_X][p->Frame_Y] = ' ';		//消去最后一个  

			ago_data_x[i] = p->Frame_X;
			ago_data_y[i] = p->Frame_Y;
			  
			if (i == 0)
			{
				p->Frame_Y--;
				data[p->Frame_X][p->Frame_Y] = '*';
				p = p->next;
				i++;
				continue;
			}
			p->Frame_X = ago_data_x[i - 1];
			p->Frame_Y = ago_data_y[i - 1];
			data[p->Frame_X][p->Frame_Y] = '*';

			p = p->next;
			i++;
		}
	}
	else if (path == 4)
	{
		i = 0;
		while (p != NULL)
		{
			if (p->next == NULL)
				data[p->Frame_X][p->Frame_Y] = ' ';		//消去最后一个  */
			ago_data_x[i] = p->Frame_X;
			ago_data_y[i] = p->Frame_Y;
			if (i == 0)
			{
				p->Frame_Y++;
				data[p->Frame_X][p->Frame_Y] = '*';
				p = p->next;
				i++;
				continue;
			}

			p->Frame_X = ago_data_x[i - 1];
			p->Frame_Y = ago_data_y[i - 1];
			data[p->Frame_X][p->Frame_Y] = '*';

			p = p->next;
			i++;
		}
	}
}

/*----------------------------
* Function： 碰到蛇身退出
* Return：	 1-> 碰到	2->正常
----------------------------*/
int Snake_Collision()
{
	Snake* p;
	int X, Y,flag=0;
	p = head->next;
	X = p->Frame_X;
	Y = p->Frame_Y;
	p = p->next;
	while (p != NULL)
	{
		if (X == p->Frame_X && Y == p->Frame_Y)
			return 1;
		p = p->next;
	}
	return 0;
}