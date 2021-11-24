//Adding Big Numbers
/*
We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.
Example

add("123", "321"); -> "444"
add("11", "99");   -> "110"

Notes

    The input numbers are big.
    The input is a string of only digits
    The numbers are positives
*/
#include <iostream>
#include <string>
std::string add(const std::string &a, const std::string &b) {
  std::string ans = "";
  int lenA = a.length() - 1;
  int lenB = b.length() - 1;
  int carry = 0;
  int temp = 0;
  while (lenA >= 0 || lenB >= 0 || carry) {
    temp = ((lenA >= 0) ? (a[lenA] - '0') : 0) +
           ((lenB >= 0) ? (b[lenB] - '0') : 0) + carry;
    ans = std::to_string(temp % 10) + ans;
    carry = 0;
    if (temp > 9) {
      carry = temp / 10;
    }

    if (lenA >= 0)
      lenA--;
    if (lenB >= 0)
      lenB--;
  }
  return ans;
}

int main() {
  std::cout << add("123", "456") << "\n";
  std::cout << add("0", "0") << "\n";
  std::cout << add("99", "2") << "\n";
  std::cout << add("10", "35679") << "\n";
  std::cout << add("", "5") << "\n";
  std::cout << add("192", "") << "\n";
  std::cout << add("9999", "1111") << "\n";
}