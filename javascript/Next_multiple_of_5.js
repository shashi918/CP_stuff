//Next multiple of 5
/*
Write a function that receives a non-negative integer n ( n >= 0 ) and returns the next higher multiple of five of that number, obtained by concatenating the shortest possible binary string to the end of this number's binary representation.
Examples

1.  nextMultipleOfFive(8)

Steps:

    8 to binary == '1000'
    concatenate shortest possible string '11' to obtain '1000' + '11' == '100011'
    '100011' to decimal == 35 => the answer

('001' would do the job too, but '11' is the shortest string here)

2.  nextMultipleOfFive(5)

Steps:

    5 to binary =='101'
    concatenate shortest possible string '0' to obtain '101' + '0' == '1010'
    '1010' to decimal == 10

(5 is already a multiple of 5, obviously, but we're looking for the next multiple of 5)
Note

    Numbers up to 1e10 will be tested, so you need to come up with something smart.

*/

function nextMultipleOfFive(n) {
    if (n == 0)
        return 5;
    let count = 1;
    n = n << 1;
    while (n % 5 != 0) {
        if (((n%5) + count)>=5) {
            n = n + count;
            ans = n % 5;
            n -= ans;
        } else {
            count = count*2 +1;
            n = n+n;
        }
    }
    return n;
}

console.log(nextMultipleOfFive(8)); //35
console.log(nextMultipleOfFive(1)); //5
console.log(nextMultipleOfFive(5)); //10
console.log(nextMultipleOfFive(826392039)); //6611136315
console.log(nextMultipleOfFive(994156574)); //7953252595


// function nextMultipleOfFive(n) {
//     if (n == 0)
//         return 5;
//     let count = 1;
//     n = n << 1;
//     while (n % 5 != 0) {
//         if (((n%5) + count)>=5) {
//             n = n + count;
//             ans = n % 5;
//             n -= ans;
//         } else {
//             count = count*2 +1;
//             n = n << 1;
//         }
//     }
//     return n;
// }

