// Error correction #1 - Hamming Code
// Background information

// The Hamming Code is used to correct errors, so-called bit flips, in data transmissions. Later in the description follows a detailed explanation of how it works.
// In this Kata we will implement the Hamming Code with bit length 3; this has some advantages and disadvantages:

//     [ + ] It's simple to implement
//     [ + ] Compared to other versions of hamming code, we can correct more mistakes
//     [ - ] The size of the input triples

// Task 1: Encode function

// Implement the encode function, using the following steps:

//     convert every letter of the text to its ASCII value;
//     convert ASCII values to 8-bit binary;
//     triple every bit;
//     concatenate the result;

// For example:

// input: "hey"
// --> 104, 101, 121                  // ASCII values
// --> 01101000, 01100101, 01111001   // binary
// --> 000111111000111000000000 000111111000000111000111 000111111111111000000111  // tripled
// --> "000111111000111000000000000111111000000111000111000111111111111000000111"  // concatenated

// Task 2: Decode function:

// Check if any errors happened and correct them. Errors will be only bit flips, and not a loss of bits:

//     111 --> 101 : this can and will happen
//     111 --> 11 : this cannot happen

// Note: the length of the input string is also always divisible by 24 so that you can convert it to an ASCII value.

// Steps:

//     Split the input into groups of three characters;
//     Check if an error occurred: replace each group with the character that occurs most often, e.g. 010 --> 0, 110 --> 1, etc;
//     Take each group of 8 characters and convert that binary number;
//     Convert the binary values to decimal (ASCII);
//     Convert the ASCII values to characters and concatenate the result

// For example:

// input: "100111111000111001000010000111111000000111001111000111110110111000010111"
// --> 100, 111, 111, 000, 111, 001, ...  // triples
// -->  0,   1,   1,   0,   1,   0,  ...  // corrected bits
// --> 01101000, 01100101, 01111001       // bytes
// --> 104, 101, 121                      // ASCII values
// --> "hey"

#include <bits/stdc++.h>

#include <bitset>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;
std::string encode(std::string text) {
    bitset<8> bits;
    string ans = "";
    for (int i = 0; i < text.size(); i++) {
        bits = text[i];
        for (int i = bits.size() - 1; i >= 0; i--) {
            if (bits[i] == 1) {
                ans += "111";
            } else {
                ans += "000";
            }
        }
    }
    return ans;
}

std::string decode(std::string binaryText) {
    int tru = 0, fals = 0;
    string temp = "";
    for (int i = 0; i < binaryText.length(); i += 3) {
        int tru = 0, fal = 0;
        tru += ((binaryText[i] == '1') ? 1 : 0) +
               ((binaryText[i + 1] == '1') ? 1 : 0) +
               ((binaryText[i + 2] == '1') ? 1 : 0);
        if (tru >= 2) {
            temp += "1";
        } else {
            temp += "0";
        }
    }
    string ans = "";
    for (int i = 0; i < temp.size(); i += 8) {
        string data = temp.substr(i, 8);
        reverse(data.begin(), data.end());
        bitset<8> bits;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '1') {
                bits[i] = 1;
            } else {
                bits[i] = 0;
            }
        }
        ans += char(bits.to_ullong());
    }
   return ans;
}

int main() {
    std::string text = "hey";
    string ans = encode(text);
    cout << ans << "\n";
    cout << decode(ans);
}

