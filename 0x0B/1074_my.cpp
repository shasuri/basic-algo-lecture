#include <iostream>

using namespace std;

int N, r, c;

void input(void);
int getTurn(int,int,int);
int getHalf(int);
int getBase(int);

int main(void)
{
    input();

    cout << getTurn(N, r, c) << '\n';
}

void input(void)
{
    cin >> N >> r >> c;
}

int getTurn(int depth, int row, int col)
{
    int quart = 0;
    int halfLine = getHalf(depth);

    if (row >= halfLine)
    {
        quart += 2;
        row -= halfLine;
    }

    if (col >= halfLine)
    {
        quart += 1;
        col -= halfLine;
    }

    if (depth == 1)
    {
        return quart;
    }
    else
    {
        return quart * getBase(depth) + getTurn(depth - 1, row, col);
    }
}

int getHalf(int depth)
{
    return 1 << (depth - 1);
}

int getBase(int depth)
{
    // 1 -> 1
    // 2 -> 4
    // 3 -> 16
    return 1 << (2 * (depth - 1));
}

/*
0 1
2 3
*/

/*
0 1 4 5
2 3 6 7
8 9 1213
10111415

00 01 02 03
10 11 12 13
20 21
*/