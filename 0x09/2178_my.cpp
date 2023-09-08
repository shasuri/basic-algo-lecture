#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAX_NM 100

int N, M;
int map[MAX_NM][MAX_NM];
int step[MAX_NM][MAX_NM];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void input()
{
    cin >> N >> M;

    string row;

    for (int n = 0; n < N; n++)
    {
        cin >> row;

        for (int m = 0; m < M; m++)
        {
            map[n][m] = row[m] - '0';
            step[n][m] = -1;
        }
    }
}

bool isVisitable(pair<int, int> p)
{
    const int y = p.first;
    const int x = p.second;
    if (y >= 0 && y < N &&
        x >= 0 && x < M)
    {
        return map[y][x] != 0 && step[y][x] == -1;
    }
    return false;
}

int find()
{
    queue<pair<int, int>> que;
    que.push({0, 0});
    step[0][0] = 1;

    pair<int, int> present, next;
    while (!que.empty())
    {
        present = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            next = {present.first + dy[i], present.second + dx[i]};
            if (next.first == N - 1 && next.second == M - 1)
            {
                return step[present.first][present.second] + 1;
            }
            
            if (isVisitable(next))
            {
                step[next.first][next.second] = step[present.first][present.second] + 1;
                // cout << next.first << "," << next.second << " : " << step[next.first][next.second] << '\n';
                que.push(next);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << find();
}