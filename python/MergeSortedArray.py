from typing import List


def merge(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    for i in range(m,m+n):
        nums1[i] = nums2[i-m]
    nums1.sort()
    print(nums1)


merge( [1,2,3,0],3,[3],1)