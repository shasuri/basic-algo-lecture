#include <iostream>
using namespace std;

const int MAX_MN = 100001;
const int NO_BOSS = -1;

struct Employee
{
    int boss;
    int compliment = 0;
    bool visited = false;
} emps[MAX_MN];

int N, M;

void input(void);
void traverse(void);
int dfs(Employee *);
void output(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    traverse();
    output();
}

void input(void)
{
    cin >> N >> M;

    for (int n = 1; n <= N; n++)
    {
        cin >> emps[n].boss;
    }

    int empInd, empCmpl;
    for (int m = 0; m < M; m++)
    {
        cin >> empInd >> empCmpl;
        emps[empInd].compliment += empCmpl;
    }
}

void traverse(void)
{
    Employee* e;
    for (int n = 1; n <= N; n++)
    {
        e = &(emps[n]);
        if (e->visited)
        {
            continue;
        }
        dfs(e);
    }
}

int dfs(Employee *e)
{
    if (e->boss != NO_BOSS)
    {
        if (!e->visited)
        {
            e->compliment += dfs(&(emps[e->boss]));
            e->visited = true;
        }
    }

    return e->compliment;
}

void output(void)
{
    for (int n = 1; n <= N; n++)
    {
        cout << emps[n].compliment << ' ';
    }
    cout << '\n';
}