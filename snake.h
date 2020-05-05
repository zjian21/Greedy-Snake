#pragma once
#ifndef SNAKE_H
#define	SNAKE_H

#include <stdio.h>
#include <stdlib.h>

/*-------	宏定义	-------*/

/*-------	结构体定义	--------*/
typedef struct snake
{
	int Frame_X ;
	int Frame_Y ;
	int Snake_length = 1;	//长度
	int path;	//前进的方向
	struct snake* next;
}Snake;

/*-------	变量定义	--------*/


/*------	函数定义	--------*/
Snake* create();
int Insert_Data(int x, int y, int path);
void Insert_Data3(int x, int y, int path);
void Move_Snake(int path);
int Snake_Collision();
#endif // !_SNAKE
