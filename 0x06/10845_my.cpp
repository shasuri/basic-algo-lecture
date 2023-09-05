#include <iostream>

using namespace std;

int que[10000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int head = 0;
    int tail = 0;

    cin >> N;

    string c;
    int arg;

    for (int i = 0; i < N; i++)
    {
        cin >> c;

        if (c == "push")
        {
            cin >> arg;
            que[head++] = arg;
            // cout << que[head-1] << '\n';
        }
        else if (c == "pop")
        {
            cout << ((head - tail <= 0) ? -1 : que[tail++]) << '\n';
        }
        else if (c == "size")
        {
            cout << head - tail << '\n';
        }
        else if (c == "empty")
        {
            cout << ((head - tail <= 0) ? 1 : 0) << '\n';
        }
        else if (c == "front")
        {
            cout << ((head - tail <= 0) ? -1 : que[tail]) << '\n';
        }
        else if (c == "back")
        {
            cout << ((head - tail <= 0) ? -1 : que[head - 1]) << '\n';
        }
    }
}