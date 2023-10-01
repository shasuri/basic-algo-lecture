#include <iostream>
#include <queue>

using namespace std;

struct Move
{
    int src;
    int dst;
};

queue<Move> moves;

void move(int, int, int);
int getWaypoint(int, int);
void output(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tower;

    cin >> tower;

    move(tower, 1, 3);

    output();
}

void move(int amount, int src, int dst)
{
    if (amount == 0)
    {
        return;
    }

    move(amount - 1, src, getWaypoint(src, dst));

    // cout << src << ' ' << dst << '\n';
    moves.push({src, dst});

    move(amount - 1, getWaypoint(src, dst), dst);
}

int getWaypoint(int src, int dst)
{
    return 6 - (src + dst);
}

void output(void)
{
    cout << moves.size() << '\n';

    Move m;

    while (!moves.empty())
    {
        m = moves.front();
        moves.pop();

        cout << m.src << ' ' << m.dst << '\n';
    }
}
/*
1 3
*/

/*
1 2 (move 1 to 2)
1 3
2 3 (move 1 to 3)
*/

/*
1 3
1 2
3 2 (move 2 to 2)
1 3
2 1
2 3
1 3 (move 2 to 3)
*/