//Minimum Deletions to Make Character Frequencies Unique
/*
A string s is called good if there are no two different characters in s that
have the same frequency.

Given a string s, return the minimum number of characters you need to delete to
make s good.

The frequency of a character in a string is the number of times it appears in
the string. For example, in the string "aab", the frequency of 'a' is 2, while
the frequency of 'b' is 1.



Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string
"aaabbc".

Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end
(i.e. frequency of 0 is ignored).
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int minDeletions(string s) {
  vector<int> v(27);
  for (auto a : s) {
    v[a - 'a']++;
  }
  sort(v.begin(), v.end(), greater<int>());
  int temp = v[0];
  int ans = 0;
  for (int i = 1; i <= 26; i++) {
    if (v[i] != 0) {
      if (v[i] == temp) {
        if (temp > 1)
          temp -= 1;
        ans++;
      } else {
        if (v[i]< temp) {
          temp = v[i];
        } else {
          ans += (v[i] - temp) + 1;
          if (temp > 1)
            temp = temp - 1;
        }
      }
    }
  }
  return ans;
}

int main() {
  cout << minDeletions("abcabc") << "\n";           // 3
  cout << minDeletions("accdcdadddbaadbc") << "\n"; // 1
  cout << minDeletions("aab") << "\n";              // 0
  cout << minDeletions("aaabbbcc") << "\n";         // 2
  cout << minDeletions("ceabaacb") << "\n";         // 2
  cout << minDeletions(
              "abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijkl"
              "mnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwx"
              "wzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghij"
              "klmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuv"
              "wxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefgh"
              "ijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrst"
              "uvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdef"
              "ghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqr"
              "stuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcd"
              "efghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnop"
              "qrstuvwxwzabcdefghijklmnopqrstuvwxwz")
       << "\n";                                  // 276
  cout << minDeletions("bbcebab") << "\n";       // 2
  cout << minDeletions("beaddedbacdcd") << "\n"; // 5
}