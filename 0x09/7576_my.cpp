#include <iostream>
#include <queue>
#include <utility>

#define MAX_NM 1000

using namespace std;

int N, M;

int farm[MAX_NM][MAX_NM];

typedef pair<int, int> Tomato;

queue<Tomato> tQue;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void setFarm()
{
    cin >> M >> N;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> farm[y][x];
            if (farm[y][x] == 1)
            {
                tQue.push({y, x});
            }
        }
    }
}

bool isVisitable(Tomato t)
{
    int y = t.first;
    int x = t.second;
    if (y >= 0 && y < N && x >= 0 && x < M)
    {
        return farm[y][x] == 0;
    }
    return false;
}

void ripeTomato()
{
    Tomato present, next;

    while (!tQue.empty())
    {
        present = tQue.front();
        tQue.pop();

        for (int i = 0; i < 4; i++)
        {
            next = {present.first + dy[i], present.second + dx[i]};
            if (isVisitable(next))
            {
                farm[next.first][next.second] = farm[present.first][present.second] + 1;
                tQue.push(next);
            }
        }
    }
}

int getMaxDay(){
    
    int maxDay = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (farm[y][x] == 0)
            {
                return -1;
            }
            
            if (maxDay < farm[y][x])
            {
                maxDay = farm[y][x];
            }
        }
    }
    return maxDay - 1;
}

void printFarm(){
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cout << farm[y][x] << ' ';
        }
        cout << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    setFarm();
    ripeTomato();
    // printFarm();
    cout << getMaxDay() << '\n';
}
