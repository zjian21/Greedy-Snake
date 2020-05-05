#pragma once
#ifndef SNAKE_H
#define	SNAKE_H

#include <stdio.h>
#include <stdlib.h>

/*-------	�궨��	-------*/

/*-------	�ṹ�嶨��	--------*/
typedef struct snake
{
	int Frame_X ;
	int Frame_Y ;
	int Snake_length = 1;	//����
	int path;	//ǰ���ķ���
	struct snake* next;
}Snake;

/*-------	��������	--------*/


/*------	��������	--------*/
Snake* create();
int Insert_Data(int x, int y, int path);
void Insert_Data3(int x, int y, int path);
void Move_Snake(int path);
int Snake_Collision();
#endif // !_SNAKE
