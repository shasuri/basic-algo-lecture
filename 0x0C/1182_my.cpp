#include <iostream>

using namespace std;

constexpr char MAX_N = 20;

int N, S;

int seq[MAX_N];

int ans = 0;

void input(void);
void dfs(int, int);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();

    dfs(0, 0);

    cout << ans << '\n';
}

void input(void)
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }
}

void dfs(int depth, int sum)
{

    if (depth >= N)
    {
        return;
    }

    if (sum + seq[depth] == S)
    {
        ans++;
        // return;
    }
    dfs(depth + 1, sum + seq[depth]);
    dfs(depth + 1, sum);
}