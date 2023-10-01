#include <iostream>
#include <stack>

using namespace std;

constexpr char MAX_N = 20;

struct Dns
{
    int depth;
    int sum;
};

int N, S;

int seq[MAX_N];

int ans = 0;

void input(void);
void stacking(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    stacking();

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

void stacking(void)
{
    stack<Dns> stk;

    stk.push({0, 0});

    Dns dns;

    while (!stk.empty())
    {
        dns = stk.top();
        stk.pop();
        
        if (dns.depth >= N)
        {
            continue;
        }

        if (dns.sum + seq[dns.depth] == S)
        {
            ans++;
        }
        
        stk.push({dns.depth + 1, dns.sum + seq[dns.depth]});
        stk.push({dns.depth + 1, dns.sum});
    }
}