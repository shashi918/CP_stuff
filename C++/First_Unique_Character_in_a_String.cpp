// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"
// Output: 0

// Example 2:

// Input: s = "loveleetcode"
// Output: 2

// Example 3:

// Input: s = "aabb"
// Output: -1


#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
using namespace std;
int firstUniqChar(string s) {
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        arr[s[i]- 'a']++;
    }
    int ans = -1;
    for (int i = 0; i < s.length(); i++) {
        if (arr[s[i] - 'a'] == 1) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {
    {
    string s = "leetcode";
    cout << firstUniqChar(s);
    }
    {
    string s = "loveleetcode";
    cout << firstUniqChar(s);
    }
}