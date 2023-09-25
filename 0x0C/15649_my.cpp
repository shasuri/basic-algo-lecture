#include <iostream>

using namespace std;

constexpr int MAX_NM = 8;

int N, M;
int trail[MAX_NM];
int visited = 0;

void input(void);
void dfs(int);
void visitHere(int);
bool isVisited(int);
void revertVisited(int);
int indToBit(int);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    dfs(0);
}

void input(void)
{
    cin >> N >> M;
}

void dfs(int depth)
{
    if (depth >= M)
    {
        for (int m = 0; m < M; m++)
        {
            cout << trail[m] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int n = 1; n <= N; n++)
    {
        if (!isVisited(n))
        {
            visitHere(n);
            
            trail[depth] = n;
            dfs(depth + 1);
            
            revertVisited(n);
        }
    }
}

void visitHere(int ind)
{
    visited |= indToBit(ind);
}

bool isVisited(int ind)
{
    return visited & indToBit(ind);
}

void revertVisited(int ind)
{
    visited ^= indToBit(ind);
}

int indToBit(int ind)
{
    return (1 << (ind - 1));
}
