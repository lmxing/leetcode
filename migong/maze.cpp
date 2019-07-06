#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <termios.h>

using namespace std;

#define MAX_X 20
#define MAX_Y 30
bool flag = false;
bool slow = false;

bool autogame = true;

int maze[MAX_X][MAX_Y]; // 迷宫矩阵

// 创建迷宫
void createMaze()
{
    int maxway = MAX_X * MAX_Y; // 最大路径；
    int x, y;
    // 设置默认值=1 都是死路
    for (x = 0; x < MAX_X; ++x)
        for (y = 0; y < MAX_Y; ++y)
            maze[x][y] = 1;
    // 以时间参数，设置随机种子
    srand((unsigned)time(NULL));
    // 构建迷宫
    for (int i = 0; i < maxway; ++i) {
        x = rand() %(MAX_X - 2) + 1;
        y = rand() %(MAX_Y - 2) + 1;
        maze[x][y] = 0;
    }
    // 入口
    maze[1][1] = 0;
    // 出口
    maze[MAX_X - 2][MAX_Y - 2] = 0;
}

void printMaze()
{
    int x, y;
    system("clear");
    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++) {
            if(maze[x][y] == 0) {cout << "  ";}
            if(maze[x][y] == 1) {cout << "♦️ ";}
            if(maze[x][y] == 2) {cout << "x ";}
            if(maze[x][y] == 3) {cout << "↓ ";}
            if(maze[x][y] == 4) {cout << "→ ";}
            if(maze[x][y] == 5) {cout << "← ";}
            if(maze[x][y] == 6) {cout << "↑ ";}
            if(maze[x][y] == 7) {cout << "⭐";}
        }
        cout<<"\n";
    }
    if (slow) {
        sleep(1);
    }
}

void menu()
{
    createMaze();
    printMaze();


}

int main(int argc)
{
    menu();
    return 0;
}
