#include <iostream>
using namespace std;

void input(void);
void command(void);

void moveLeft(void);
void moveRight(void);
void removeCharacter(void);
void addCharacter(char c);

void print(void);

const int MAXN = 100001;
char initialContent[MAXN];
int M;

const char LEFT = 'L';
const char RIGHT = 'D';
const char REMOVE = 'B';
const char ADD = 'P';

const int MAX_EDITOR = 600001;
struct Character
{
    char content;
    Character *next;
    Character *prev;
} Editor[MAX_EDITOR];

int unused = 0;
Character head, tail;
Character *cursor;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    head.next = &tail;
    tail.prev = &head;
    cursor = &head;

    input();
    command();
    print();
}

void input(void)
{
    cin >> initialContent;

    int i = 0;
    while (initialContent[i] != '\0')
    {
        addCharacter(initialContent[i++]);
    }

    cin >> M;
}

void command(void)
{
    char editorCommand;
    char editorCharacter;

    for (int i = 0; i < M; i++)
    {
        cin >> editorCommand;

        switch (editorCommand)
        {
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
        case REMOVE:
            removeCharacter();
            break;
        case ADD:
            cin >> editorCharacter;
            addCharacter(editorCharacter);
            break;

        default:
            // cout << "Invalid input.\n";
            break;
        }
    }
}

void moveLeft(void)
{
    if (cursor != &head)
    {
        cursor = cursor->prev;
        // cout << "LEFT : " << "cursor : " << cursor->content << '\n';
    }
}

void moveRight(void)
{
    if (cursor->next != &tail)
    {
        cursor = cursor->next;
    }
    // cout << "RIGHT : " << "cursor : " << cursor->content << '\n';
}

void removeCharacter(void)
{
    if (cursor != &head)
    {
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        cursor = cursor->prev;
    }
    // cout << "REMOVE : " << "cursor : " << cursor->content << '\n';
}
void addCharacter(char c)
{
    Character *newChar = &Editor[unused++];
    newChar->content = c;

    newChar->next = cursor->next;
    newChar->prev = cursor;

    cursor->next->prev = newChar;
    cursor->next = newChar;

    cursor = newChar;

    // cout << "ADD : " << cursor->prev->content << cursor->content << cursor->next->content << '\n';
}

void print(void)
{
    Character *cur = head.next;

    if (cur == &tail)
    {
        cout << '\n';
        return;
    }

    while (cur != &tail)
    {
        cout << cur->content;
        cur = cur->next;
    }
    cout << '\n';
}