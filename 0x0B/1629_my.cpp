#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull A, B, C;

void input(void);
ull recursion(ull);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    ull ans;

    ans = recursion(B);

    cout << ans << '\n';
}

void input(void)
{
    cin >> A >> B >> C;
}

ull recursion(ull b)
{
    if (b == 0)
    {
        return 1;
    }
    
    if (b == 1)
    {
        return A % C;
    }

    ull half = recursion(b / 2);

    if (b % 2 == 0)
    {
        return half * half % C;
    }
    else
    {
        return A * (half * half % C) % C;
    }
}