#include <iostream>

using namespace std;

const int MAX_LEN = 100;

const char DOT = '.';
const string YES = "yes";
const string NO = "no";

enum BRK
{
    PARENTHESIS,
    BRACE,
    BRACKET
};

int stk[MAX_LEN];
int pos = 0;

void push(int);
int pop(void);
int size(void);
bool empty(void);

bool isBalanced(string);

int main(void)
{
    string s;

    while (1)
    {
        cin.ignore();
        getline(cin, s);
        if (s[0] == DOT)
        {
            break;
        }
        cout << (isBalanced(s) ? YES : NO) << '\n';
    }
}

bool isBalanced(string s)
{
    int i = 0;

    while (s[i] != DOT)
    {
        switch (s[i])
        {
        case '(':
            push(PARENTHESIS);
            break;
        case ')':
            if (pop() != PARENTHESIS)
            {
                return false;
            }
            break;
        case '{':
            push(BRACE);
            break;
        case '}':
            if (pop() != BRACE)
            {
                return false;
            }
            break;
        case '[':
            push(BRACKET);
            break;
        case ']':
            if (pop() != BRACKET)
            {
                return false;
            }
            break;

        default:
            break;
        }
        i++;
    }

    return empty();
}

void push(int n)
{
    stk[pos++] = n;
}
int pop(void)
{
    return empty() ? -1 : stk[--pos];
}
int size(void)
{
    return pos;
}
bool empty(void)
{
    return size() <= 0;
}