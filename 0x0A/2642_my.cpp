#include <iostream>

using namespace std;

constexpr short CUBE_SPACES = 6;
constexpr short NOT_CUBE = 0;
constexpr short BLANK = 0;

struct Location
{
    short y = -1;
    short x = -1;
};

static short dx[] = {1, -1, 0, 0};
static short dy[] = {0, 0, -1, 1};

Location cubeLocs[CUBE_SPACES];
short paper[CUBE_SPACES][CUBE_SPACES];

short 4(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (!input())
    {
        cout << NOT_CUBE << '\n';
    }
    else
    {
        checkCubeLocs();
    }
}

bool input(void)
{
    short space;

    for (short h = 0; h < CUBE_SPACES; h++)
    {
        for (short w = 0; w < CUBE_SPACES; w++)
        {
            cin >> space;
            paper[h][w] = space;

            if (space > BLANK && space <= CUBE_SPACES)
            {
                if (cubeLocs[space - 1].x != -1)
                {
                    return false;
                }

                cubeLocs[space - 1] = {h, w};
            }
        }
    }

    return true;
}

void checkCubeLocs(void)
{
    Location loc;
    for (short i = 0; i < CUBE_SPACES; i++)
    {
        loc = cubeLocs[i];

        for (short d = 0; d < 4; d++)
        {
            if (isInBoundary(loc.y + dy[d], loc.x + dx[d]))
            {
                paper[loc.y + dy[d]][loc.x + dx[d]];
            }
            
        }
        
    }
}
