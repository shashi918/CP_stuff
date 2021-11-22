//Large Factorials
/*
In mathematics, the factorial of integer n is written as n!. It is equal to the product of n and every integer preceding it. For example: 5! = 1 x 2 x 3 x 4 x 5 = 120

Your mission is simple: write a function that takes an integer n and returns the value of n!.

You are guaranteed an integer argument. For any values outside the non-negative range, return null, nil or None (return an empty string "" in C and C++). For non-negative numbers a full length number is expected for example, return 25! = "15511210043330985984000000" as a string.

For more on factorials, see http://en.wikipedia.org/wiki/Factorial

NOTES:

    The use of BigInteger or BigNumber functions has been disabled, this requires a complex solution

    I have removed the use of require in the javascript language.

*/
#include <iostream>
#include <string>
std::string factorial(int factorial) {
  std::string ans = "1";
  int carry = 0;
  for (int i = factorial; i >= 1; i--) {
    int len = ans.length() - 1;
    std::string temp = "";
    while (len >= 0) {
      int temp_ans = i * (ans[len] - '0') + carry;
      carry = 0;
      temp = std::to_string(temp_ans % 10) + temp;
      if (temp_ans > 9)
        carry = temp_ans / 10;
      len--;
    }
    if (carry != 0) {
      temp = std::to_string(carry) + temp;
      carry = 0;
    }
    ans = temp;
  }
  return ans;
}

int main() {
  int n = 6;
  std::string ans = factorial(n);
  std::cout << ans;
}