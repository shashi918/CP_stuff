
// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

// Note:

//     Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
//     In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        n -= n & (-n); 
        ans++;
    }
    return ans;
}
int main() {
    {
        uint32_t n = 00000000000000000000000000001011;
        cout << hammingWeight(n);
    }
}