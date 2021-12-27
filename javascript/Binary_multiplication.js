//Binary multiplication
/* You will be given two numbers m,n. The numbers could span from 0 to 10000. We can get their product by using binary reduction as show in the table below.

// Example (to understand the table please read the description below it)
// real value of m(r) 	m 	n 	(r*n)
// 0 	100 	15 	0
// 0 	50 	30 	0
// 1 	25 	60 	60
// 0 	12 	120 	0
// 0 	6 	240 	0
// 1 	3 	480 	480
// 1 	1 	960 	960

// Above, we are given two numbers 100 and 15. we keep reducing the bigger number by dividing it by 2 and hold the integer part of the division till it is no more divisible by 2. Then we assign the real values to these reduced parts of m. Any reduced number [1,m] has real value of 0 if it is even, and it will have real value of 1 if it is odd. On the other hand the smaller number in this case n keeps on doubling itself the same amount of times m reduces itself. The idea of this method is to change multiplication of two big number to a sequence of multiplication by 0 or 1 and perform addition to get the final product. You can see that from the last column (r*n) above.
// if we sum the last column we get 0+60+0+0+480+960=1500=100*15 Now your task for this kata will be to get those non-zero number in the last column in an array and return it sorted in descending order.so for the above example the return will be [960,480,60].

 Beware: m,n are not necessarily ordered.
*/


function binMul(p, q) {
	let m, n;
	m = Math.max(p, q);
	n = Math.min(p, q);
	let ans = m * n;
	let arrM = [];
	let arrN = [];
	while (m) {
		arrM.push(m);
		arrN.push(n);
		m = parseInt(m / 2);
		n = parseInt(n * 2);
	}
	let ansArr = [];
	for (let i = arrM.length - 1; i >= 0; i--) {
		if (ans) {
			if (arrN[i] <= ans) {
				ansArr.push(arrN[i]);
				ans -= arrN[i];
			}
		}
	}
	if (ans) {
		for (let i = arrM.length - 1; i >= 0; i--) {
			if (ans) {
				if (arrM[i] <= ans) {
					ansArr.push(arrM[i]);
					ans -= arrM[i];
				}
			}

		}
	}
	return ansArr;
}

console.log(binMul(100, 15));
console.log(binMul(7569, 3323))
console.log(binMul(6509, 6287));

