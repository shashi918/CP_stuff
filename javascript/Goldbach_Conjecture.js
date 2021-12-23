//Goldbach's Conjecture
/*
Goldbach's conjecture is amongst the oldest and well-known unsolved mathematical problems out there. In correspondence with Leonhard Euler in 1742, German mathematician Christian Goldbach made a conjecture stating that:

"Every even integer greater than 2 can be written as the sum of two primes"

which is known today as the (strong) Goldbach's conjecture.

Even though it's been thoroughly tested and analyzed and seems to be true, it hasn't been proved yet (thus, remaining a conjecture.)

Your task is to implement the function in the starter code, taking into account the following:

    If the argument isn't even and greater than two, return an empty array/tuple.
    For arguments even and greater than two, return a two-element array/tuple with two prime numbers whose sum is the given input.
    The two prime numbers must be the farthest ones (the ones with the greatest difference)
    The first prime number must be the smallest one.

A few sample test cases:

checkGoldbach(2)/check_goldbach(2) should return []

checkGoldbach(5)/check_goldbach(5) should return []

checkGoldbach(4)/check_goldbach(4) should return [2, 2]

checkGoldbach(6)/check_goldbach(6) should return [3, 3]

checkGoldbach(14)/check_goldbach(14) should return [3, 11]
*/

function checkPrime(number) {
    for (let i = 2; i <= number / 2; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

var checkGoldbach = function (number) {
    if (number < 4 || number % 2 != 0)
        return [];
    else {
        if (number == 4)
            return [2, 2];
        let arr = [];
        let len = Math.ceil(Math.sqrt(number));
        for (let i = 0; i <= len; i++)
            arr.push(true);
        for (let i = 2; i <= len; i++) {
            if (arr[i] == true) {
                for (let j = i * i; j <= len; j += i) {
                    arr[j] = false;
                }
            }
        }
        let first = 0, second = 0;
        for (let i = 2; i <= len; i++) {
            if (arr[i] == true) {
                first = i;
                second = number - first;
                if (checkPrime(second)) {
                    return [first, second];
                } else {
                    continue;
                }
            }
        }
    }
}

    console.log(checkGoldbach(2));
    console.log(checkGoldbach(5));
    console.log(checkGoldbach(15));
    console.log(checkGoldbach(4));
    console.log(checkGoldbach(8));
    console.log(checkGoldbach(10));
    console.log(checkGoldbach(100));
    console.log(checkGoldbach(24));

