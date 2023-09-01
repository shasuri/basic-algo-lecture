#include <iostream>
#include <map>

using namespace std;

const int MAX_C = 10000;
const int MAX_W = MAX_C * 2;
const int INVALID = -1;

enum Command
{
    PUSH_FRONT,
    PUSH_BACK,
    POP_FRONT,
    POP_BACK,
    SIZE,
    EMPTY,
    FRONT,
    BACK
};

static map<string, int> commandMap = {
    {"push_front", PUSH_FRONT},
    {"push_back", PUSH_BACK},
    {"pop_front", POP_FRONT},
    {"pop_back", POP_BACK},
    {"size", SIZE},
    {"empty", EMPTY},
    {"front", FRONT},
    {"back", BACK},
};

class MyDeq;
void command(int, MyDeq);


class MyDeq
{
private:
    int deq[MAX_W];
    int head = MAX_C;
    int tail = MAX_C;

public:
    MyDeq() {}

    int size(void)
    {
        return tail - head;
    }

    bool empty(void)
    {
        return size() <= 0;
    }

    void pushFront(int x)
    {
        deq[--head] = x;
    }

    void pushBack(int x)
    {
        deq[tail++] = x;
    }

    int popFront(void)
    {
        return empty() ? INVALID : deq[head++];
    }

    int popBack(void)
    {
        return empty() ? INVALID : deq[--tail];
    }

    int front(void)
    {
        return empty() ? INVALID : deq[head];
    }

    int back(void)
    {
        return empty() ? INVALID : deq[tail - 1];
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    command(N, MyDeq());
}

void command(int cmdN, MyDeq md)
{
    string commandIn = "";
    int arg;

    for (int i = 0; i < cmdN; i++)
    {
        cin >> commandIn;
        switch (commandMap[commandIn])
        {
        case PUSH_FRONT:
            cin >> arg;
            md.pushFront(arg);
            break;
        case PUSH_BACK:
            cin >> arg;
            md.pushBack(arg);
            break;
        case POP_FRONT:
            cout << md.popFront() << '\n';
            break;
        case POP_BACK:
            cout << md.popBack() << '\n';
            break;
        case SIZE:
            cout << md.size() << '\n';
            break;
        case EMPTY:
            cout << md.empty() << '\n';
            break;
        case FRONT:
            cout << md.front() << '\n';
            break;
        case BACK:
            cout << md.back() << '\n';
            break;
        default:
            cout << "INVALID COMMAND!" << '\n';
            break;
        }
    }
}