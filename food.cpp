#include "food.h"
#include "function.h"
#include  "snake.h"

extern char data[LENGTH][LENGTH];	//结构体指针可以跨cpp文件
extern  Snake* head;
int food_x;
int food_y;

/*--------------------------
* Function：生成食物
--------------------------*/
void Creat_Food()
{
    food_x = rand() % 19 + 1;
    food_y = rand() % 49 + 1;
    data[food_x][food_y] = '*';
}

/*--------------------------
* Function：处理食物
--------------------------*/
void Eat_Food()
{
    Snake* p;
    p = head->next;
    if (p->Frame_X == food_x && p->Frame_Y == food_y)
    {
        Insert_Data3(food_x, food_y, p->path);
        Creat_Food();  
    }
}



