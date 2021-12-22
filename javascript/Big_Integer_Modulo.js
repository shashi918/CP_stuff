//Big Integer Modulo
/*
Calculating the remainder (modulo) of a given division is a pretty common task in programming as you might already know. Applications include checksum verification, prime numbers testing and cryptography, among others.

The default integer modulo implementations (%) for many languages only deal limited-length integers (like 32-bit or 64-bit integers); thus, they can't be used for calculating the modulo of greater or arbitrary-length integers.

Your task for this kata is to implement the function bigModulo(numString, divisor) where numString is a string containg the integer to divide and divisor is the integer by which you're going to divide.

For the tests, you can assume that:

    numString has an arbitrary-length string containing a positive (>0) integer
    divisor will always be a native integer greater than 1.

You cannot use bignumber.js in JavaScript and your total code length should be less than or equal to 3000 symbols.
Hints

    Remember that decimal integers can be represented as a sum of products of its digits by powers of 10.
    There are certain mathematical properties of modulos regarding to sums and multiplications, you should check them if you don't know (or remember) them.

*/

function bigModulo(numString, divisor) {
    let temp = "0" + numString;
    let len = temp.length - 1;
    let i = 0;
    let ans = 0;
    while (i <= len) {
        ans = (ans * 10 + (temp[i] - '0')) % divisor
        i++;
    }
    return ans;
}

console.log(bigModulo('12345', 123));
console.log(bigModulo('987654321', 54321));
