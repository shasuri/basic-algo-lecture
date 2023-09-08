#include <iostream>
#include <queue>
// #include <stdio.h>

#define MAX_NK 100001

using namespace std;

struct Seeker
{
    int pos;
    int step = 0;
};

void input(int &, int &);
int seekHider(int, int);
bool isVisitable(int, bool *);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    input(N, K);

    cout << seekHider(N, K) << '\n';
}

void input(int &N, int &K)
{
    cin >> N >> K;
}

int seekHider(int seekerStart, int hider)
{
    if (seekerStart == hider)
    {
        return 0;
    }

    bool seekerVisit[MAX_NK] = {
        false,
    };

    queue<Seeker> sQue;

    sQue.push({seekerStart});
    seekerVisit[seekerStart] = true;

    Seeker present;

    int nexts[3];

    while (!sQue.empty())
    {
        present = sQue.front();
        sQue.pop();

        int nexts[3] = {
            present.pos + 1,
            present.pos - 1,
            present.pos * 2,
        };

        for (int i = 0; i < 3; i++)
        {
            if (nexts[i] == hider)
            {
                return present.step + 1;
            }

            if (isVisitable(nexts[i], seekerVisit))
            {
                sQue.push({nexts[i], present.step + 1});
                seekerVisit[nexts[i]] = true;
            }
        }
    }
}

bool isVisitable(int p, bool *seekerVisit)
{
    return p >= 0 && p < MAX_NK && !seekerVisit[p];
}
