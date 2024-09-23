
from typing import List


def plusOne(self, digits: List[int]) -> List[int]:
        total = 0
        for i in digits:
            total = total * 10 + i
        total = total + 1
        digits = [int(digit) for digit in  str(total)]
        return digits