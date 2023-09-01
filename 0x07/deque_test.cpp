// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MX = 1000005;
const int END = 2 * MX + 1;
int dat[END];
int head = MX, tail = MX;

int size()
{
  return tail - head;
}

bool empty()
{
  return size <= 0;
}

void push_front(int x)
{
  if (head > 0)
  {
    dat[--head] = x;
  }
}

void push_back(int x)
{
  if (tail < END)
  {
    dat[tail++] = x;
  }
}

void pop_front()
{
  if (!empty())
  {
    head++;
  }
}

void pop_back()
{
  if (!empty())
  {
    tail--;
  }
}

int front()
{
  if (!empty())
  {
    return dat[head];
  }
  else
  {
    return -1;
  }
}

int back()
{
  if (!empty())
  {
    return dat[tail - 1];
  }
  else
  {
    return -1;
  }
}

void test()
{
  push_back(30);           // 30
  cout << front() << '\n'; // 30
  cout << back() << '\n';  // 30
  push_front(25);          // 25 30
  push_back(12);           // 25 30 12
  cout << back() << '\n';  // 12
  push_back(62);           // 25 30 12 62
  pop_front();             // 30 12 62
  cout << front() << '\n'; // 30
  pop_front();             // 12 62
  cout << back() << '\n';  // 62
}

int main(void)
{
  test();
}
