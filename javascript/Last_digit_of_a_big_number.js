//Last digit of a big number
/*
Define a function that takes in two non-negative integers aaa and bbb and returns the last decimal digit of aba^bab. Note that aaa and bbb may be very large!

For example, the last decimal digit of 979^797 is 999, since 97=47829699^7 = 478296997=4782969. The last decimal digit of (2200)2300({2^{200}})^{2^{300}}(2200)2300, which has over 109210^{92}1092 decimal digits, is 666. Also, please take 000^000 to be 111.

You may assume that the input will always be valid.
Examples

lastDigit("4", "1")            // returns 4
lastDigit("4", "2")            // returns 6
lastDigit("9", "7")            // returns 9    
lastDigit("10","10000000000")  // returns 0

Remarks
JavaScript, C++, R, PureScript

Since these languages don't have native arbitrarily large integers, your arguments are going to be strings representing non-negative integers instead.
*/

function modulo(a, b) {
  let mod = 0;
  for (let i of b) {
    mod = (mod * 10 + parseInt(i - '0') )% a;
  }
  return mod;
}

function lastDigit(str1, str2) {
  let exp = modulo(4, str2);
  if (exp == 0)
    exp = 4;
  let ans = Math.pow(str1[str1.length - 1], exp);
  return ans % 10;
}











console.log(lastDigit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651"));
console.log(lastDigit("4", "1"));
console.log(lastDigit("2", "2"));
console.log(lastDigit("9", "7"));
console.log(lastDigit("10", "100000"));
console.log(lastDigit("4", "2"));
console.log(lastDigit("3", "688196152215529972737174557165657483427362207517952651"));
