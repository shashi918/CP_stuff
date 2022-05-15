//Letter
/*
Vasya decided to write an anonymous letter cutting the letters out of a newspaper heading. He knows heading s1 and text s2 that he wants to send. Vasya can use every single heading letter no more than once. Vasya doesn't have to cut the spaces out of the heading — he just leaves some blank space to mark them. Help him; find out if he will manage to compose the needed text.
Input

The first line contains a newspaper heading s1. The second line contains the letter text s2. s1 и s2 are non-empty lines consisting of spaces, uppercase and lowercase Latin letters, whose lengths do not exceed 200 symbols. The uppercase and lowercase letters should be differentiated. Vasya does not cut spaces out of the heading.
Output

If Vasya can write the given anonymous letter, print YES, otherwise print NO
*/

#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s1 = "";
  string s2 = "";
  getline(cin,s1);
  getline(cin,s2);
  vector<int> counter(130, 0);
  for (int i = 0; i < s1.length(); i++) {
    counter[s1[i]]++;
  }
  for (int i = 0; i < s2.length(); i++) {
    if (s2[i] != ' ') {
      if (counter[s2[i]] != 0) {
        counter[s2[i]]--;
      } else {
        cout << "NO"
             << "\n";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
  return;
}

int main() { solve(); }