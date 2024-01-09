#define DEBUG_MODE

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

typedef int Block;

short N;
Block maxBlock = 0;
constexpr short MAX_N = 20;
constexpr short DIR = 4;
constexpr short START_STEP = 1;
constexpr short END_STEP = 5;
constexpr Block BLANK = 0;

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
void mergeBlocks(const short dir, Block board[MAX_N][MAX_N]);
void mergeUp(Block[MAX_N][MAX_N]);
void mergeLeft(Block[MAX_N][MAX_N]);

#ifdef DEBUG_MODE
void printBoard(const Block board[MAX_N][MAX_N])
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

void testMerge(Block board[MAX_N][MAX_N], const short d)
{
    cout << "BEFORE Merge " << d << '\n';
    printBoard(board);

    mergeBlocks(d, board);

    cout << "AFTER Merge" << '\n';
    printBoard(board);
}

void printSpace(short r1, short c1, short r2, short c2)
{
    cout << "(" << r1 << "," << c1 << ") (" << r2 << "," << c2 << ")";
}
#endif

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Block board[MAX_N][MAX_N];
    input(board);

#ifdef DEBUG_MODE
    testMerge(board, UP);
#endif

    // tryAllCase(board);
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

void swipeBoard(const short dirSwipe, const Block before[MAX_N][MAX_N], const short step)
{
    Block after[MAX_N][MAX_N];

#ifdef DEBUG_MODE
    cout << step << '-' << dirSwipe << " : " << static_cast<const void *>(before) << " -> " << static_cast<void *>(after) << '\n';
#endif

    mergeBlocks(dirSwipe, after);

    if (step >= END_STEP)
    {
        for (short i = 0; i < N; i++)
        {
            for (short j = 0; j < N; j++)
            {
                maxBlock = max(after[i][j], maxBlock);
            }
        }
        return;
    }

    for (short dir = 0; dir < DIR; dir++)
    {
        swipeBoard(dir, after, step + 1);
    }
}

void mergeBlocks(const short dir, Block board[MAX_N][MAX_N])
{
    switch (dir)
    {
    case UP:
        mergeUp(board);
        break;

    case DOWN:
        // mergeDown(board);
        break;

    case LEFT:
        mergeLeft(board);
        break;

    case RIGHT:
        // mergeRight(board);
        break;

    default:
        break;
    }
}

void mergeUp(Block board[MAX_N][MAX_N])
{
    short dst = 0;
    for (short c = 0; c < N; c++)
    {
        dst = 0;
        for (short r = 0; r < N; r++)
        {
            if (board[r][c] != BLANK)
            {
                // ---> stay
                if (dst == r)
                {
#ifdef DEBUG_MODE
                    printSpace(r, dst, r, c);
                    cout << " ---> stay" << '\n';
                    printBoard(board);
#endif
                }
                else
                {
                    // ---> merge
                    if (board[r][c] == board[dst][c])
                    {
                        board[r][c] = BLANK;
                        board[dst][c] *= 2;
                    }
                    else
                    {
                        // ---> stack
                        if (dst != r)
                        {
                            if (board[dst][c] != BLANK)
                            {
                                dst++;
                            }

                            board[dst][c] = board[r][c];
                            board[r][c] = BLANK;
                        }
                    }
                }
            }
        }
    }
}

void mergeLeft(Block board[MAX_N][MAX_N])
{
    short dst = 0;
    for (short r = 0; r < N; r++)
    {
        dst = 0;
        for (short c = 0; c < N; c++)
        {
            if (board[r][c] != BLANK)
            {
                // ---> stay
                if (dst == c)
                {
#ifdef DEBUG_MODE
                    printSpace(r, dst, r, c);
                    cout << " ---> stay" << '\n';
                    printBoard(board);
#endif
                }
                else
                {
                    if (board[r][c] == board[r][dst])
                    {
                        board[r][c] = BLANK;
                        board[r][dst] *= 2;
#ifdef DEBUG_MODE
                        printSpace(r, dst, r, c);
                        cout << " ---> merge" << '\n';
                        printBoard(board);
#endif
                    }
                    else
                    {
                        // ---> stack
                        if (board[r][dst] != BLANK)
                        {
                            dst++;
                        }

                        board[r][dst] = board[r][c];
                        board[r][c] = BLANK;
#ifdef DEBUG_MODE
                        printSpace(r, dst, r, c);
                        cout << " ---> stack" << '\n';
                        printBoard(board);
#endif
                    }
                }
            }
        }
    }
}