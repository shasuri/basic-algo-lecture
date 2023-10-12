#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXV = 100001;
constexpr int INPUT_EOL = -1;
constexpr int STARTER = 1;
constexpr int NO_WAY = 0;

class RadiusPair
{
public:
    int first = 0;
    int second = 0;

    RadiusPair() {}

    void pushRadius(int newRad)
    {
        if (first < newRad)
        {
            second = first;
            first = newRad;
        }
        else if (second < newRad)
        {
            second = newRad;
        }
    }

    int getDiameter(void)
    {
        return first + second;
    }
};

struct Edge
{
    int dst;
    int cost;
};

int V;
vector<Edge> tree[MAXV];
bool visit[MAXV];
int maxDiameter = 0;

int main(void);
void input(void);
int dfs(int);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs(STARTER);

    cout << maxDiameter << '\n';
}

void input(void)
{
    cin >> V;
    int src, dst, cost;

    for (int i = 0; i < V; i++)
    {
        cin >> src;

        while (true)
        {
            cin >> dst;
            if (dst == INPUT_EOL)
            {
                break;
            }

            cin >> cost;

            tree[src].push_back({dst, cost}); // input distance.
        }
    }
}

int dfs(int src)
{
    RadiusPair radPair;
    Edge edge;
    int childRadius;

    for (vector<Edge>::iterator it = tree[src].begin(); it != tree[src].end(); it++)
    {
        edge = *it;
        if (!visit[edge.dst])
        {
            visit[edge.dst] = true;

            childRadius = dfs(edge.dst) + edge.cost;
            radPair.pushRadius(childRadius);
        }
    }

    maxDiameter = max(maxDiameter, radPair.getDiameter());

    return radPair.first;
}
