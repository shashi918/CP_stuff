// Sum of Digits / Digital Root
/*
Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.
Examples

    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/

function digital_root(n) {
    let temp;
    while (n >= 10) {
        temp = 0;
        while (n) {
            temp +=  n % 10;
            n = parseInt(n / 10);
        }
        if(temp>=10)
        n = temp;
    }
    return temp;
}

console.log(digital_root(493193));