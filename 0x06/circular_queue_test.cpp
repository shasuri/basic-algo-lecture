// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MX = 10;
int dat[MX + 1];
int head = 0, tail = 0;


bool empty()
{
  return tail == head;
}

bool full()
{
  return (tail + 1) % MX == head;
}

int size()
{
  return (tail - head) % MX;
}

void push(int x)
{
  if (!full())
  {
    dat[tail] = x;
    tail = (tail + 1) % MX;
  }
}

void pop()
{
  if (!empty())
  {
    head = (head + 1) % MX;
  }
}

int front()
{
  return empty() ? -1 : dat[head];
}

int back()
{
  return empty() ? -1 : dat[(tail - 1) % MX];
}

void test()
{
  push(10);
  cout << size() << '\n'; // 10
  push(20);
  cout << size() << '\n'; // 10
  push(30);
  cout << size() << '\n'; // 10
  pop();
  cout << size() << '\n'; // 10
  pop();
  cout << size() << '\n'; // 10
  push(15);
  cout << size() << '\n'; // 10
  push(25);
  cout << size() << '\n'; // 10
}

int main(void)
{
  test();
}
