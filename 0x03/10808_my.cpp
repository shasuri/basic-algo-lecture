#include <bits/stdc++.h>
using namespace std;

#define ALP 26

const char stdChar = 'a';
int alpFreq[ALP];

void initArr(int* arr, int len){
    fill(arr,arr+len,0);
}

int charToIndex(char chr){
    return chr - stdChar;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  
  initArr(alpFreq, ALP);
  
  for(char c : s){
    alpFreq[charToIndex(c)]++;
  }

  for (int i = 0; i < ALP; i++){
    cout << alpFreq[i] << ' ';
  }
}
