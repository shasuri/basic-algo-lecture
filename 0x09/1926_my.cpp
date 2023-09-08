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

struct Paper
{
    int N;
    int M;
    Pixel pixels[MAX_MN][MAX_MN];
};

struct AnswerSet
{
    int paintCount;
    int maxWidth;
};

void drawPaint(Paper &);
AnswerSet traversePaper(Paper &);
bool isVisitable(Pixel *);
int measurePaint(Pixel *, Paper &);
bool isInPaper(int, int, Paper &);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    static Paper paper;
    drawPaint(paper);
    AnswerSet ans = traversePaper(paper);

    cout << ans.paintCount << '\n'
         << ans.maxWidth << '\n';
}

void drawPaint(Paper &paper)
{
    int p;

    cin >> paper.N >> paper.M;

    for (int n = 0; n < paper.N; n++)
    {
        for (int m = 0; m < paper.M; m++)
        {
            cin >> p;
            paper.pixels[n][m].colored = p;
            paper.pixels[n][m].y = n;
            paper.pixels[n][m].x = m;
        }
    }
}

AnswerSet traversePaper(Paper &paper)
{
    queue<Pixel *> nextPixels;
    Pixel *p;

    int paintCount = 0;
    int maxWidth = 0;

    for (int y = 0; y < paper.N; y++)
    {
        for (int x = 0; x < paper.M; x++)
        {
            p = &(paper.pixels[y][x]);
            if (isVisitable(p))
            {
                p->visited = true;
                paintCount++;
                maxWidth = max(measurePaint(p, paper), maxWidth);
            }
        }
    }

    return {paintCount, maxWidth};
}

bool isVisitable(Pixel *p)
{
    return (p->colored && !p->visited);
}

int measurePaint(Pixel *start, Paper &paper)
{
    int width = 0;
    queue<Pixel *> pixelQueue;

    static const int DIR = 4;
    static const int dy[DIR] = {1, -1, 0, 0};
    static const int dx[DIR] = {0, 0, 1, -1};

    pixelQueue.push(start);

    Pixel *present;
    Pixel *next;
    int ny, nx;

    while (!pixelQueue.empty())
    {
        width++;
        present = pixelQueue.front();
        pixelQueue.pop();

        for (int i = 0; i < DIR; i++)
        {
            ny = present->y + dy[i];
            nx = present->x + dx[i];
            if (isInPaper(ny, nx, paper))
            {
                next = &(paper.pixels[ny][nx]);
                if (isVisitable(next))
                {
                    pixelQueue.push(next);
                    next->visited = true;
                }
            }
        }
    }

    return width;
}

bool isInPaper(int y, int x, Paper &paper)
{
    return (y >= 0 && y < paper.N && x >= 0 && x < paper.M);
}