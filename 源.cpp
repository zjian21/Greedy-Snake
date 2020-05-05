#include "function.h"
#include "snake.h"
#include "food.h"

HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
COORD coord = { 0,0 };
//双缓冲处理显示
DWORD bytes = 0;
extern char data[LENGTH][LENGTH];	//防止重定义
extern Snake* head;

void Frame(char a[][LENGTH])    //画边框
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COLUMN; j++)
        {
            if (a[i][j] == '*')
                continue;
            if (i == 0 || i == ROW - 1)
            {
                a[i][j] = '*';
            }
            else
                a[i][j] = ' ';
        }
    }
    for (j = 0; j < COLUMN; j++)
    {
        for (i = 1; i < ROW - 1; i++)
        {
            if (a[i][j] == '*')
                continue;
            if (j == 0 || j == COLUMN - 1)
            {
                a[i][j] = '*';
            }
            else
                a[i][j] = ' ';
        }
    }
}

void Frame_Buff(char data[][LENGTH])   //边框缓存区
{
    int i;
    Frame(data);    //先画边框
   

    for (i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutBuf, data[i], LENGTH, coord, &bytes);
    }
    //设置新的缓冲区为活动显示缓冲
    SetConsoleActiveScreenBuffer(hOutBuf);
  
}

void Map_Set_Buff(char data[][LENGTH])      //地图设置缓存区
{
    int i;  
    Frame(data);    //先画边框
   
    Move_Snake(head->next->path);

    for (i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutput, data[i], LENGTH, coord, &bytes);
    }
    //设置新的缓冲区为活动显示缓冲
    SetConsoleActiveScreenBuffer(hOutput);
}

void Create_Buf()
{
    //创建新的控制台缓冲区
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,      //定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,   //定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,      //定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,   //定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //隐藏两个缓冲区的光标
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
}

int main()
{
    Create_Buf();
//--------------------初始化蛇的信息-----------------------  
    create();
    Creat_Food();   //产生食物
    Insert_Data(15, 1, 4);
    data[head->next->Frame_X][head->next->Frame_Y] = '*';
    srand((int)time(NULL));     //随机数种子

    while (1)
    {
        Handle_key();   //按键处理

        Frame_Buff(data);   //画边框
        Eat_Food();
        Sleep(100);
        Map_Set_Buff(data);     //缓冲区画蛇的位置
        Sleep(100);

//---------------------- 越界、碰撞退出-------------------
        if (head->next->Frame_X >= 20 || head->next->Frame_Y >= 50 || head->next->Frame_X < 1 || head->next->Frame_Y < 1 || Snake_Collision())
            break;
    }
    return 0;
}




/*------------  测试用的伪代码 ------------*/
/*
头插法
    Insert_Data3(3, 2, 1);
    Insert_Data3(3, 2, 1);
    Print_Snake();
    system("pause");

点位置与方向
     printf("%d %d %d\n", head->next->Frame_X, head->next->Frame_Y, head->next->path);
*/