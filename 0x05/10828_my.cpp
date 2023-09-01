#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 10000;
const int INVALID = -1;

enum Command
{
    PUSH,
    POP,
    SIZE,
    EMPTY,
    TOP
};

static map<string, int> commandMap = {
    {"push", PUSH},
    {"pop", POP},
    {"size", SIZE},
    {"empty", EMPTY},
    {"top", TOP},
};

class MyStack
{
private:
    int stk[MAX_N];
    int pos = 0;

public:
    MyStack();

    void push(int);
    int pop(void);
    int size(void);
    bool empty(void);
    int top(void);

    void command(string);
};

void command(int, MyStack);
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    command(N, MyStack());
}

void command(int cmdN, MyStack ms)
{
    string cmdIn;

    for (int i = 0; i < cmdN; i++)
    {
        cin >> cmdIn;
        ms.command(cmdIn);
    }
}

void MyStack::command(string cmdIn)
{
    int arg;
    switch (commandMap[cmdIn])
    {
    case PUSH:
        cin >> arg;
        push(arg);
        break;
    case POP:
        cout << pop() << '\n';
        break;
    case SIZE:
        cout << size() << '\n';
        break;
    case EMPTY:
        cout << empty() << '\n';
        break;
    case TOP:
        cout << top() << '\n';
        break;

    default:
        cout << "INVALID COMMAND!" << '\n';
        break;
    }
}

MyStack::MyStack(){}

void MyStack::push(int n)
{
    if (pos < MAX_N)
    {
        stk[pos++] = n;
    }
}

int MyStack::pop(void)
{
    return empty() ? INVALID : stk[--pos];
}

int MyStack::size(void)
{
    return pos;
}

bool MyStack::empty(void)
{
    return pos <= 0;
}

int MyStack::top(void)
{
    return empty() ? INVALID : stk[pos - 1];
}
