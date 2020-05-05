#include "function.h"
#include "snake.h"
#include "food.h"

HANDLE hOutput, hOutBuf;//����̨��Ļ���������
COORD coord = { 0,0 };
//˫���崦����ʾ
DWORD bytes = 0;
extern char data[LENGTH][LENGTH];	//��ֹ�ض���
extern Snake* head;

void Frame(char a[][LENGTH])    //���߿�
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

void Frame_Buff(char data[][LENGTH])   //�߿򻺴���
{
    int i;
    Frame(data);    //�Ȼ��߿�
   

    for (i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutBuf, data[i], LENGTH, coord, &bytes);
    }
    //�����µĻ�����Ϊ���ʾ����
    SetConsoleActiveScreenBuffer(hOutBuf);
  
}

void Map_Set_Buff(char data[][LENGTH])      //��ͼ���û�����
{
    int i;  
    Frame(data);    //�Ȼ��߿�
   
    Move_Snake(head->next->path);

    for (i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutput, data[i], LENGTH, coord, &bytes);
    }
    //�����µĻ�����Ϊ���ʾ����
    SetConsoleActiveScreenBuffer(hOutput);
}

void Create_Buf()
{
    //�����µĿ���̨������
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,      //������̿�����������д����
        FILE_SHARE_WRITE,   //���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,      //������̿�����������д����
        FILE_SHARE_WRITE,   //���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //���������������Ĺ��
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
}

int main()
{
    Create_Buf();
//--------------------��ʼ���ߵ���Ϣ-----------------------  
    create();
    Creat_Food();   //����ʳ��
    Insert_Data(15, 1, 4);
    data[head->next->Frame_X][head->next->Frame_Y] = '*';
    srand((int)time(NULL));     //���������

    while (1)
    {
        Handle_key();   //��������

        Frame_Buff(data);   //���߿�
        Eat_Food();
        Sleep(100);
        Map_Set_Buff(data);     //���������ߵ�λ��
        Sleep(100);

//---------------------- Խ�硢��ײ�˳�-------------------
        if (head->next->Frame_X >= 20 || head->next->Frame_Y >= 50 || head->next->Frame_X < 1 || head->next->Frame_Y < 1 || Snake_Collision())
            break;
    }
    return 0;
}




/*------------  �����õ�α���� ------------*/
/*
ͷ�巨
    Insert_Data3(3, 2, 1);
    Insert_Data3(3, 2, 1);
    Print_Snake();
    system("pause");

��λ���뷽��
     printf("%d %d %d\n", head->next->Frame_X, head->next->Frame_Y, head->next->path);
*/