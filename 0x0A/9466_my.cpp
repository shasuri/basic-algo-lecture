#include <iostream>
// #define DEBUG_MODE
#define DEBUG_INFO student << " -> " << wish << " : "
using namespace std;

const int MAX_N = 100001;

struct Student
{
    int wish;
    bool visit;
    int teamed = -1;
};

int N;
int solo;
Student teamWish[MAX_N];

void testCase(void);
void wishInput(void);
void getSolo(void);
int getCycle(int);
int countSolo(void);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        testCase();
    }
}

void testCase(void)
{
    wishInput();
    getSolo();

    cout << countSolo() << '\n';
}

void wishInput(void)
{
    cin >> N;
    solo = N;
    for (int n = 1; n <= N; n++)
    {
        cin >> teamWish[n].wish;
        teamWish[n].visit = false;
        teamWish[n].teamed = -1;
    }
}

void getSolo(void)
{
    for (int n = 1; n <= N; n++)
    {
        if (!teamWish[n].visit)
        {
            teamWish[n].visit = true;
            getCycle(n);
        }
    }
}

int getCycle(int student)
{
    int wish = teamWish[student].wish;

    if (wish == student)
    {
#ifdef DEBUG_MODE
        cout << DEBUG_INFO << "self cycle" << endl;
#endif
        teamWish[student].visit = true;
        teamWish[student].teamed = 1;
        return -1; // self cycle
    }

    if (!teamWish[wish].visit)
    {
        teamWish[wish].visit = true;

        int cycleResult = getCycle(wish);

        if (cycleResult == student)
        {
#ifdef DEBUG_MODE
            cout << DEBUG_INFO << "end cycle" << endl;
#endif
            teamWish[student].teamed = 1;
            return -1; // end cycle
        }
        else if (cycleResult == -1)
        {
#ifdef DEBUG_MODE
            cout << DEBUG_INFO << "not cycle" << endl;
#endif
            teamWish[student].teamed = 0;
            return -1; // not cycle
        }
        else
        {
#ifdef DEBUG_MODE
            cout << DEBUG_INFO << "keep cycle" << endl;
#endif
            teamWish[student].teamed = 1;
            return cycleResult; // keep cycle
        }
    }
    else
    {
        if (teamWish[wish].teamed == 1)
        {
#ifdef DEBUG_MODE
            cout << DEBUG_INFO << "find already cycle" << endl;
#endif
            teamWish[student].teamed = 0;
            return -1; // find already cycle
        }

        if (teamWish[wish].teamed == 0)
        {
#ifdef DEBUG_MODE
            cout << DEBUG_INFO << "find not cycle" << endl;
#endif
            teamWish[student].teamed = 0;
            return -1; // find not cycle
        }

        if (teamWish[wish].teamed == -1)
        {
#ifdef DEBUG_MODE
            cout << DEBUG_INFO << "find cycle" << endl;
#endif
            teamWish[student].teamed = 1;
            return wish; // find cycle
        }
    }

    return 0;
}

int countSolo(void)
{
    int solo = 0;
    for (int i = 1; i <= N; i++)
    {
#ifdef DEBUG_MODE
        cout << i << " : " << teamWish[i].teamed << endl;
#endif
        if (teamWish[i].teamed == 0)
        {
            solo++;
        }
    }

    return solo;
}