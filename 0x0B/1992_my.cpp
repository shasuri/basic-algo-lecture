#include <iostream>

using namespace std;

struct Pixel
{
    short y, x;
};

constexpr char QUAD_START = '(';
constexpr char QUAD_END = ')';

constexpr short MAX_N = 64;
short N;
bool frame[MAX_N][MAX_N];

string zip = "";

void input(void);
void checkPerfect(short, Pixel);
char boolToChar(bool);
void output(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    checkPerfect(N, {0, 0});
    output();
}

void input(void)
{

    cin >> N;

    string frameLine;

    for (short i = 0; i < N; i++)
    {
        cin >> frameLine;
        for (short j = 0; j < N; j++)
        {
            frame[i][j] = frameLine[j] - '0';
        }
    }
}

void checkPerfect(short n, Pixel start)
{

    bool isPerfect = true;
    bool stdPixel = frame[start.y][start.x];

    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < n; j++)
        {
            if (stdPixel != frame[start.y + i][start.x + j])
            {
                isPerfect = false;
                break;
            }
        }
    }

    if (isPerfect)
    {
        zip.push_back(boolToChar(stdPixel));
    }
    else
    {
        zip.push_back(QUAD_START);

        short nextN = n / 2;

        for (short i = 0; i < 2; i++)
        {
            for (short j = 0; j < 2; j++)
            {
                checkPerfect(nextN,
                             {static_cast<short>(start.y + i * (nextN)),
                              static_cast<short>(start.x + j * (nextN))});
            }
        }

        zip.push_back(QUAD_END);
    }
}

char boolToChar(bool b)
{
    return b ? '1' : '0';
}

void output(void)
{
    cout << zip << '\n';
}