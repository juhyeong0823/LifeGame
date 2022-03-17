#include <iostream>
#include <Windows.h>
using namespace std;


void gotoxy(int x, int y);
void CheckAround(int y, int x);
void CheckWholeCell();
void DrawGrids();

const int WAYS = 8;
const int WAY[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 }, { 1, 1 } };

int grid[10][10] =
{
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

bool isAlive[10][10] = 
{
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int main()
{
    while (true)
    {
        DrawGrids();
        Sleep(4000);
        CheckWholeCell();
    }
}


void gotoxy(int x, int y)
{
    COORD pos = { x*2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void CheckAround(int y, int x)
{
    int aliveCell = 0;

    for (int i = 0; i < WAYS; i++) 
    {
        if (grid[y + WAY[i][1]][x + WAY[i][0]] == 1) aliveCell++;
    }

    if (aliveCell == 2 ) 
    {
        isAlive[y][x] = isAlive[y][x];
    }
    else if (aliveCell == 3)
    {
        isAlive[y][x] = true;
    }
    else 
    {
        isAlive[y][x] = false;
    }
}

void CheckWholeCell()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            CheckAround(y, x);
        }
    }

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (isAlive[y][x] == true) 
            {
                grid[y][x] = 1;
            }
            else 
            {
                grid[y][x] = 0;
            }
        }
    }
}

void DrawGrids()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            gotoxy(y, x);
            cout << grid[y][x];
        }
    }
}

