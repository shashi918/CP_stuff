from typing import List

def removeElement( nums: List[int], val: int) -> int:
    count_val = 0
    for i in range(0, len(nums)):
        if nums[i] != val:
            count_val+= 1
    return count_val

print(removeElement([3,2,2,3],3))