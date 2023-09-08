// #define DEBUG_MODE

#include <iostream>
#include <queue>

using namespace std;

#define MAX_RC 1000
#define MAX_STEP 1001001

struct Space
{
    int y;
    int x;
    int step = 0;
};

int maze[MAX_RC + 1][MAX_RC + 1];
bool jihoonVisit[MAX_RC + 1][MAX_RC + 1];
int R, C;
Space jihoonStart;
queue<Space> fQue;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void setMaze(void);
void fireMaze(void);
bool isFirable(int, int);
bool isInMaze(int, int);
int escapeMaze(void);
bool isVisitable(Space);
bool isExit(Space);
void printMaze(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    setMaze();
    fireMaze();

#ifdef DEBUG_MODE
    printMaze();
#endif

    int escapeTime = escapeMaze();

    if (escapeTime == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << escapeTime << '\n';
    }
}

void setMaze()
{
    cin >> R >> C;
    string row;

    for (int y = 0; y < R; y++)
    {
        cin >> row;
        for (int x = 0; x < C; x++)
        {
            jihoonVisit[y][x] = false;
            switch (row[x])
            {
            case '#':
                maze[y][x] = MAX_STEP;
                break;
            case '.':
                maze[y][x] = MAX_STEP + 1;
                break;
            case 'J':
                jihoonStart = {y, x, 0};
                maze[y][x] = MAX_STEP + 1;
                break;
            case 'F':
                fQue.push({y, x});
                maze[y][x] = 0;
                break;
            default:
                break;
            }
        }
    }
}

void fireMaze(void)
{
    Space fPresent;
    int ny, nx;

    while (!fQue.empty())
    {
        fPresent = fQue.front();
        fQue.pop();

        for (int i = 0; i < 4; i++)
        {
            ny = fPresent.y + dy[i];
            nx = fPresent.x + dx[i];

            if (isFirable(ny, nx))
            {
                maze[ny][nx] = maze[fPresent.y][fPresent.x] + 1;
                fQue.push({ny, nx});
            }
        }
    }
}

bool isFirable(int y, int x)
{
    return isInMaze(y, x) &&
           maze[y][x] == MAX_STEP + 1;
}

bool isInMaze(int y, int x)
{
    return y >= 0 && y < R &&
           x >= 0 && x < C;
}

int escapeMaze(void)
{
    if (isExit(jihoonStart))
    {
        return 1;
    }

    queue<Space> jQue;
    jihoonVisit[jihoonStart.y][jihoonStart.x] = true;
    jQue.push(jihoonStart);

    Space jPresent, jNext;

    while (!jQue.empty())
    {
        jPresent = jQue.front();
        jQue.pop();

        for (int i = 0; i < 4; i++)
        {
            jNext = {jPresent.y + dy[i], jPresent.x + dx[i], jPresent.step + 1};

            if (isVisitable(jNext))
            {
                if (isExit(jNext))
                {
#ifdef DEBUG_MODE
                    cout << jNext.y << jNext.x << '\n';
#endif
                    return jNext.step + 1;
                }
                jihoonVisit[jNext.y][jNext.x] = true;
                jQue.push(jNext);
            }
        }
    }

    return -1;
}

bool isVisitable(Space j)
{
    return isInMaze(j.y, j.x) &&
           !jihoonVisit[j.y][j.x] &&
           maze[j.y][j.x] > j.step &&
           maze[j.y][j.x] != MAX_STEP;
}

bool isExit(Space j)
{
    return j.y == 0 || j.y == R - 1 ||
           j.x == 0 || j.x == C - 1;
}

void printMaze(void)
{
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cout << maze[y][x] << ' ';
        }

        cout << '\n';
    }
}