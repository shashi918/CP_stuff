//Permutations
/*
In this kata you have to create all permutations of an input string and remove duplicates, if present. This means, you have to shuffle all letters from the input in all possible orders.

Examples:

permutations("a"); // => vector<string> {"a"}
permutations("ab"); // => vector<string> {"ab", "ba"}
permutations("aabb"); // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}

The order of the permutations doesn't matter.
*/

#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_set>

void recursive(std::string s,std:: unordered_set<std::string>& ans, std::string temp, int arr[]) {
  if (temp.size() == s.size()) {
    ans.insert(temp);
    return;
  }
  for (int i = 0; i < s.size(); i++) {
    if (!arr[i]) {
      temp += s[i];
      arr[i] = 1;
      recursive(s, ans, temp, arr);
      arr[i] = 0;
      temp.pop_back();
    }
  }
}
std::vector<std::string> permutations(std::string s) {
  int len = s.length();
  int arr[len];
  std::fill(arr, arr + len,0);
  std::unordered_set<std::string> ans;
  std::string temp = "";
  recursive(s,ans,temp,arr);
  std::vector<std::string> out;
  for (auto i : ans)
    out.push_back(i);
  return out;
}
int main() {
  std::string s = "aabb";
  std::vector<std::string> ans = permutations(s);
  for (auto i : ans) {
    std::cout<<i<<std::endl;
  }
}