#include <iostream>
using namespace std;

// #define DEBUG_MODE

typedef unsigned long long ull;

constexpr short MAX_NM = 40;
constexpr short MAX_RC = 10;
constexpr ull PIXEL = 1;
constexpr short DIR = 4;
struct Sticker
{
    short R = 0;
    short C = 0;
    short ns = 0;
    ull sticker[MAX_RC] = {
        0,
    };
};

ull laptop[MAX_NM] = {
    0,
};

short N, M, K, pasted;

void input(void);
void tryPasteSticker(void);
void inputSticker(Sticker &);
bool findPastableDirection(Sticker &);
void rotateSticker(Sticker &);
bool findPastablePosition(Sticker &);
bool checkUncovered(Sticker &, short, short);
bool isRowCovered(ull, ull);
void pasteSticker(Sticker &, short, short);

#ifdef DEBUG_MODE
string PASTED = "◼";
string BLANK = "◻";
void printLaptop(void)
{
    for (short h = 0; h < N; h++)
    {
        for (short w = 0; w < M; w++)
        {
            cout << ((laptop[h] & (PIXEL << w)) ? PASTED : BLANK);
        }
        cout << '\n';
    }
    cout << '\n';
}

void printSticker(Sticker s){
    for (short h = 0; h < s.R; h++)
    {
        for (short w = 0; w < s.C; w++)
        {
            cout << ((s.sticker[h] & (PIXEL << w)) ? PASTED : BLANK);
        }
        cout << '\n';
    }
    cout << '\n';
}

void printRow(ull r, short rowLen)
{
    for (short w = 0; w < rowLen; w++)
    {
        cout << ((r & (PIXEL << w)) ? PASTED : BLANK);
    }
}

#endif

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    for (short k = 0; k < K; k++)
    {
        tryPasteSticker();
#ifdef DEBUG_MODE
        printLaptop();
#endif
    }

    cout << pasted << '\n';
}

void input(void)
{
    cin >> N >> M >> K;
}

void tryPasteSticker(void)
{
    bool pastable = false;
    Sticker s;

    inputSticker(s);

#ifdef DEBUG_MODE
    cout << "Input sticker =>\n";
    printSticker(s);
#endif

    if (findPastableDirection(s))
    {
        pasted += s.ns;
    }
}

void inputSticker(Sticker &s)
{
    cin >> s.R >> s.C;

    bool pixel;

    for (short r = 0; r < s.R; r++)
    {
        for (short c = 0; c < s.C; c++)
        {
            cin >> pixel;

            if (pixel)
            {
                s.sticker[r] |= (PIXEL << c);
                s.ns++;
            }
        }
    }
}

bool findPastableDirection(Sticker &s)
{
    for (short d = 0; d < DIR; d++)
    {
        if (d != 0)
        {
            rotateSticker(s);
        }
        
        if (findPastablePosition(s))
        {
            return true;
        }
    }
    return false;
}

void rotateSticker(Sticker &s)
{
    Sticker tmp = s;

    s.C = tmp.R;
    s.R = tmp.C;

    for (short r = 0; r < tmp.R; r++)
    {
        s.sticker[r] = 0;
    }

    for (short r = 0; r < s.R; r++)
    {
        for (short c = 0; c < s.C; c++)
        {
#ifdef DEBUG_MODE
            printRow(s.sticker[r], s.C);
            cout << " |= ";
            printRow(tmp.sticker[tmp.R - c - 1], tmp.C);
            cout << " & ";
            printRow(PIXEL << r, tmp.C);
#endif
            if (tmp.sticker[tmp.R - c - 1] & (PIXEL << r))
            {
                s.sticker[r] |= PIXEL << c;
            }
#ifdef DEBUG_MODE
            cout << " -> ";
            printRow(s.sticker[r], s.C);
            cout << '\n';
#endif
        }
    }

#ifdef DEBUG_MODE
    cout << "rotated : " << '\n';
    printSticker(s);
#endif
}

bool findPastablePosition(Sticker &s)
{
    for (short r = 0; r <= N - s.R; r++)
    {
        for (short c = 0; c <= M - s.C; c++)
        {
            if (checkUncovered(s, r, c))
            {
                pasteSticker(s, r, c);
                return true;
            }
        }
    }
    return false;
}

bool checkUncovered(Sticker &s, short h, short w)
{
#ifdef DEBUG_MODE
    cout << "====" << '\n';
#endif
    for (short r = 0; r < s.R; r++)
    {
        if (isRowCovered(laptop[r + h], s.sticker[r] << w))
        {
            return false;
        }
    }
    return true;
}

bool isRowCovered(ull l, ull s)
{

#ifdef DEBUG_MODE
    cout << 'l';
    printRow(l, M);
    cout << '\n';
    cout << 's';
    printRow(s, M);
    cout << '\n';
#endif

    return l & s;
}

void pasteSticker(Sticker &s, short h, short w)
{
    for (short r = 0; r < s.R; r++)
    {
        laptop[h + r] |= (s.sticker[r] << w);
    }
}