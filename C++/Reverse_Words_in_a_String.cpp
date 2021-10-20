//Reverse words in a string
/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"

Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
*/
#include <bits/stdc++.h>
#include <string>
using namespace std;
string reverseWords(string s) {
  string temp = "";
  string ans = "";
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ')
      count++;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      ans = temp + ans;
      if (temp.size() != 0)
        count -=temp.size();
      if (count != 0 && temp.size() != 0) {
        ans = " " + ans;
      }
      temp ="";
      
    }
    else temp+=s[i];
  }
  ans = temp +ans;
  return ans;
}
int main() {
  cout << reverseWords("the sky is blue")<<"\n";
  cout << reverseWords("  hello world  ")<<"\n";
  cout<<reverseWords("a good   example")<<"\n";
  cout<<reverseWords("  Bob    Loves  Alice   ")<<"\n";
  cout<<reverseWords("Alice does not even like bob")<<"\n";
  return 0;
  }
