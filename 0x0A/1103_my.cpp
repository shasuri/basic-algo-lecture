#include <iostream>
#include <stack>

// #define DEBUG_MODE

using namespace std;

const int MAX_MN = 51;
const char HOLE = 'H';
const int HOLE_I = -1;
const int DIR = 4;

struct Coin
{
    int y;
    int x;
    int turn = 0;
};

int N, M;
int board[MAX_MN][MAX_MN];
int turnDp[MAX_MN][MAX_MN];
bool visited[MAX_MN][MAX_MN];

int maxTurn = 0;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void inputBoard(void);
void dfs(Coin);
void visitHere(Coin);
bool isVisited(Coin);
void revertVisited(Coin);
bool isGameOver(Coin);
bool isOutOfBoard(Coin);
void printDP(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    inputBoard();
    Coin start {0, 0, 0};
    visitHere(start);
    dfs(start);

    if (maxTurn != -1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                maxTurn = max(turnDp[i][j], maxTurn);
            }
        }

        maxTurn++;
    }
#ifdef DEBUG_MODE
    printDP();
#endif
    cout << maxTurn << '\n';
}

void inputBoard(void)
{
    cin >> N >> M;

    char row[MAX_MN + 1];

    for (int y = 0; y < N; y++)
    {
        cin >> row;
        for (int x = 0; x < M; x++)
        {
            if (row[x] == HOLE)
            {
                board[y][x] = HOLE_I;
            }
            else
            {
                board[y][x] = row[x] - '0';
            }
        }
    }
}

void dfs(Coin present)
{
    Coin next;

    int moves = board[present.y][present.x];

    for (int i = 0; i < DIR; i++)
    {
        next = {present.y + (dy[i] * moves),
                present.x + (dx[i] * moves),
                present.turn + 1};

        if (!isGameOver(next))
        {
            if (isVisited(next))
            {
                maxTurn = -1;
                return;
            }

            if (turnDp[next.y][next.x] >= next.turn)
            {
                continue;
            }
            else
            {
                turnDp[next.y][next.x] = next.turn;
            }

            visitHere(next);
            dfs(next);
            if (maxTurn == -1)
            {
                return;
            }
            revertVisited(next);
        }
    }
}

void visitHere(Coin c)
{
    visited[c.y][c.x] = true;
}

void revertVisited(Coin c)
{
    visited[c.y][c.x] = false;
}

bool isGameOver(Coin c)
{
    return isOutOfBoard(c) || board[c.y][c.x] == HOLE_I;
}

bool isOutOfBoard(Coin c)
{
    return c.y < 0 || c.y >= N || c.x < 0 || c.x >= M;
}

bool isVisited(Coin c)
{
    return visited[c.y][c.x];
}

void printDP(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << turnDp[i][j] << ' ';
        }
        cout << '\n';
    }
}