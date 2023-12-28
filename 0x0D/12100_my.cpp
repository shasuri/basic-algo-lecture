#define DEBUG_MODE

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

typedef Block int;

short N;
Block maxBlock = 0;
constexpr short MAX_N = 20;
constexpr short DIR = 4;
constexpr short START_STEP = 1;
constexpr short END_STEP = 5;
constexpr Block Blank = 0;

enum DIRECTION
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

void input(Block[MAX_N][MAX_N]);
void tryAllCase(const Block[MAX_N][MAX_N]);
void swipeBoard(const short, const Block[MAX_N][MAX_N], const short step);

#ifdef DEBUG_MODE
void printBoard(Block board[MAX_N][MAX_N])
{
    for (short i = 0; i < N; i++)
    {
        for (short j = 0; j < N; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
#endif

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Block board[MAX_N][MAX_N];
    input(board);

    // printBoard(board);

    tryAllCase(board);
}

void input(Block board[MAX_N][MAX_N])
{
    cin >> N;

    for (short i = 0; i < N; i++)
    {
        for (short j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
}

void tryAllCase(const Block board[MAX_N][MAX_N])
{
    for (short dir = 0; dir < DIR; dir++)
    {
        swipeBoard(dir, board, START_STEP);
    }
}

void swipeBoard(const short dirSwipe, const Block src[MAX_N][MAX_N], const short step)
{
    Block dst[MAX_N][MAX_N];

#ifdef DEBUG_MODE
    cout << step << '-' << dirSwipe << " : " << static_cast<const void *>(src) << " -> " << static_cast<void *>(dst) << '\n';
#endif

    mergeBlocks(dirSwipe, dst);

    if (step >= END_STEP)
    {
        for (short i = 0; i < count; i++)
        {
            for (short j = 0; j < count; j++)
            {
                maxBlock = max(dst[i][j], maxBlock);
            }
        }
        return;
    }

    for (short dir = 0; dir < DIR; dir++)
    {
        swipeBoard(dir, dst, step + 1);
    }
}

void mergeBlocks(const short dir, Block dst[MAX_N][MAX_N])
{
    switch (dir)
    {
    case UP:
        mergeUp(dst);
        break;

    case DOWN:
        mergeDown(dst);
        break;

    case LEFT:
        mergeLeft(dst);
        break;

    case RIGHT:
        mergeRight(dst);
        break;

    default:
        break;
    }
}

void mergeLeft(Block dst[MAX_N][MAX_N])
{
    for (short r = 0; r < N; r++)
    {
        for (short c = 0; c < count; c++)
        {
            /* code */
        }
        
    }
    
}