#define TEST_MODE

#include <iostream>
#include <math.h>
using namespace std;

constexpr int NOT_PERFECT = -2;
constexpr int BASE = 3;
constexpr int MAX_N = pow(BASE, 7);
int N;
int globalCounter[BASE] = {
    0,
};

struct Paper
{
    int y;
    int x;
};

int canvas[MAX_N][MAX_N];

void input(void);
int checkPerfect(int, Paper);
Paper getNextLoc(Paper, int, int, int);
int baseLog(int);
void countPaper(const int[BASE]);
void output(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    int globalPaper = checkPerfect(N, {0, 0});
    
    if (globalPaper != NOT_PERFECT)
    {
        globalCounter[globalPaper + 1]++;
    }

    output();
}

void input(void)
{
#ifndef TEST_MODE
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> canvas[i][j];
        }
    }
#else
    N = pow(3,7);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            canvas[i][j] = 1;
        }
    }
#endif

}

int checkPerfect(int level, Paper start)
{
    if (level == 0)
    {
        return canvas[start.y][start.x];
    }

    int stdPaper, paper;
    bool perfect = true;
    int counter[BASE] = {
        0,
    };

    for (int i = 0; i < BASE; i++)
    {
        for (int j = 0; j < BASE; j++)
        {
            paper = checkPerfect(level / 3, getNextLoc(start, level, i, j));

            counter[paper + 1]++;

            if (i == 0 && j == 0)
            {
                stdPaper = paper;
            }

            if (paper != stdPaper)
            {
                perfect = false;
            }
        }
    }

    if (perfect)
    {
        return stdPaper;
    }
    else
    {
        countPaper(counter);
        return NOT_PERFECT;
    }
}

Paper getNextLoc(Paper p, int level, int y, int x)
{
    return {p.y + (int)(y * (level / 3)), p.x + (int)(x * (level / 3))};
}

int baseLog(int x)
{
    return (log(x) / log(BASE));
}

void countPaper(const int counter[BASE])
{
    for (int i = 0; i < BASE; i++)
    {
        globalCounter[i] += counter[i];
    }
}

void output(void)
{
    for (int i = 0; i < BASE; i++)
    {
        cout << globalCounter[i] << '\n';
    }
}