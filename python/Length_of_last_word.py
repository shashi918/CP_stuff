
from typing import List
def plusOne(digits: List[int]) -> List[int]:
    total = 0
    for digit in digits:
        total = total * 10 + digit

    total = total + 1
    digits = [int(digit) for digit in str(total)]
    print(digits)

plusOne([1,2,3])