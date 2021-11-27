//The observed PIN
/*
Alright, detective, one of our colleagues successfully observed our target
person, Robby the robber. We followed him to a secret warehouse, where we assume
to find all the stolen stuff. The door to this warehouse is secured by an
electronic combination lock. Unfortunately our spy isn't sure about the PIN he
saw, when Robby entered it.

The keypad has the following layout:

┌───┬───┬───┐
│ 1 │ 2 │ 3 │
├───┼───┼───┤
│ 4 │ 5 │ 6 │
├───┼───┼───┤
│ 7 │ 8 │ 9 │
└───┼───┼───┘
    │ 0 │
    └───┘

He noted the PIN 1357, but he also said, it is possible that each of the digits
he saw could actually be another adjacent digit (horizontally or vertically, but
not diagonally). E.g. instead of the 1 it could also be the 2 or 4. And instead
of the 5 it could also be the 2, 4, 6 or 8.

He also mentioned, he knows this kind of locks. You can enter an unlimited
amount of wrong PINs, they never finally lock the system or sound the alarm.
That's why we can try out all possible (*) variations.

* possible in sense of: the observed PIN itself and all variations considering
the adjacent digits

Can you help us to find all those variations? It would be nice to have a
function, that returns an array (or a list in Java/Kotlin and C#) of all
variations for an observed PIN with a length of 1 to 8 digits. We could name the
function getPINs (get_pins in python, GetPINs in C#). But please note that all
PINs, the observed one and also the results, must be strings, because of
potentially leading '0's. We already prepared some test cases for you.

Detective, we are counting on you!
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
void gen_combination(std::vector<std::string> &ans,
                     std::map<char, std::string> &combination,
                     std::string observed, int i, int j, int l);
std::vector<std::string> get_pins(std::string observed) {
  std::map<char, std::string> combination;
  combination.insert(std::pair<char, std::string>('1', "24"));
  combination.insert(std::pair<char, std::string>('2', "135"));
  combination.insert(std::pair<char, std::string>('3', "26"));
  combination.insert(std::pair<char, std::string>('4', "157"));
  combination.insert(std::pair<char, std::string>('5', "2486"));
  combination.insert(std::pair<char, std::string>('6', "359"));
  combination.insert(std::pair<char, std::string>('7', "48"));
  combination.insert(std::pair<char, std::string>('8', "5790"));
  combination.insert(std::pair<char, std::string>('9', "86"));
  combination.insert(std::pair<char, std::string>('0', "8"));
  std::vector<std::string> ans;
  ans.push_back(observed);
  for (int i = 0; i <= observed.length() - 1; i++) {
    int len = ans.size() - 1;
    auto it = combination.find(observed[i]);
    int k = ans.size() - 1;
    while (k >= 0) {
      int j = 0;
      while (it->second[j] != '\0') {
        std::string temp = ans[k];
        temp[i] = it->second[j];
        ans.push_back(temp);
        j++;
      }
      k--;
    }
  }
std::sort(ans.begin(), ans.end());
ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
return ans;
}

int main() {
  std::vector<std::string> ans = get_pins("369");
  std::sort(ans.begin(), ans.end());
  for (auto i : ans) {
    std::cout << i << "\n";
  }
}

