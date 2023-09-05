#include <iostream>
#include <queue>
using namespace std;
#define MAX_MN 500

struct Pixel
{
    int y;
    int x;
    bool colored = false;
    bool visited = false;
};

struct answerSet
{
    int maxWidth;
    int paintCount;

    answerSet)_
};


Pixel paper[MAX_MN][MAX_MN];

void drawPaint(int &, int &);
int traversePaper(int, int);
int measurePaint(Pixel *);
bool isVisitable(Pixel *);

int main(void)
{
    int N, M;
    drawPaint(N, M);
    traversePaper(N, M);
}

void drawPaint(int &N, int &M)
{
    int p;

    cin >> N >> M;

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cin >> p;
            paper[n][m].colored = p;
            paper[n][m].y = n;
            paper[n][m].x = m;
        }
    }
}

int traversePaper(int N, int M)
{
    queue<Pixel *> nextPixels;
    Pixel *p;
    
    int paintCount = 0;
    int maxWidth = 0;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            p = &paper[y][x];
            if (isVisitable(p))
            {
                p->visited = true;
                paintCount++;
                maxWidth = max(measurePaint(p), maxWidth);
            }
        }
    }

    return {maxWidth, paintCount};
}

bool isVisitable(Pixel *p)
{
    return (p->colored && !p->visited);
}