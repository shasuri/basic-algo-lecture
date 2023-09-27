#include <iostream>
// #define DEBUG_MODE
using namespace std;

constexpr int MAX_N = 14;

struct Space
{
    int y;
    int x;
};

int N, nQueen;
int board[MAX_N][MAX_N];

bool verticalAttacked[MAX_N];
bool frontSlashAttacked[MAX_N + MAX_N - 1];
bool backSlashAttacked[MAX_N + MAX_N - 1];

void input(void);
void setMthQueen(int);

bool isSettable(Space);
bool isAttackedByVertical(Space);
bool isAttackedByFrontSlash(Space);
bool isAttackedByBackSlash(Space);

void setAttacked(Space, bool);
void setAttackedByVertical(Space, bool);
void setAttackedByFrontSlash(Space, bool);
void setAttackedByBackSlash(Space, bool);

#ifdef DEBUG_MODE
void printBoard(void)
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << "---------------\n";
}
#endif

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    
    nQueen = 0;
    setMthQueen(0);

    cout << nQueen << '\n';
}

void input(void)
{
    cin >> N;
}

void setMthQueen(int m)
{
    if (m >= N)
    {
        nQueen++;
#ifdef DEBUG_MODE
        printBoard();
#endif
        return;
    }

    for (int x = 0; x < N; x++)
    {
        if (isSettable({m, x}))
        {
            setAttacked({m, x}, true);
            setMthQueen(m + 1);
            setAttacked({m, x}, false);
        }
    }
}

bool isSettable(Space s)
{
    return !(isAttackedByVertical(s) ||
             isAttackedByFrontSlash(s) ||
             isAttackedByBackSlash(s));
}

bool isAttackedByVertical(Space s)
{
    return verticalAttacked[s.x];
}

bool isAttackedByFrontSlash(Space s)
{
    return frontSlashAttacked[s.y + s.x];
}

bool isAttackedByBackSlash(Space s)
{
    return backSlashAttacked[s.y - s.x + MAX_N - 1];
}

void setAttacked(Space s, bool attacked)
{
    setAttackedByVertical(s, attacked);
    setAttackedByFrontSlash(s, attacked);
    setAttackedByBackSlash(s, attacked);
}

void setAttackedByVertical(Space s, bool attacked)
{
    verticalAttacked[s.x] = attacked;
}

void setAttackedByFrontSlash(Space s, bool attacked)
{
    frontSlashAttacked[s.y + s.x] = attacked;
}

void setAttackedByBackSlash(Space s, bool attacked)
{
    backSlashAttacked[s.y - s.x + MAX_N - 1] = attacked;
}
/*
00 01 02 03 ... 0D
10 11 12 13
20 21 22 23
30 31 32 33
.
D0              DD
D + D = 26
*/