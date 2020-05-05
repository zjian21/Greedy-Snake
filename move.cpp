
#include"function.h"
#include"snake.h"
#include "food.h"
extern char data[LENGTH][LENGTH];	//�ṹ��ָ����Կ�cpp�ļ�
extern Snake* head;
static int MOVE = 4;	//���ݳ�ʼ���ķ���

/*--------------------------
* Function����ȡ����
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
* Function��������
--------------------------*/
void Handle_key()
{
	Snake* p;
	MOVE = ChangeSnake();

	p = head->next;
//	printf(" Chang:%d\n",MOVE);
	if (MOVE == 1)				//����
	{
		if (p->path != 2)		//�����෴�����ƶ�
		{
			p->path = 1;
		}
	}
	else if (MOVE == 2)		//����
	{
		if (p->path != 1)
		{
			p->path = 2;
		}
	}
	else if (MOVE == 3)		//����
	{
		if (p->path != 4)
		{
			p->path = 3;
		}
	}
	else if (MOVE == 4)		//����
	{
		if (p->path != 3)
		{
			p->path = 4;
		}
	}
}
