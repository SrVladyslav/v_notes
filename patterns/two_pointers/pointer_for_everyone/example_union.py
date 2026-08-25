"""
Given two sorted lists: nums1 and nums2, we need to return one sorted list
containing all the unique elements from nums1 and nums2.

Example:
nums1 = [1,3,5,7]
nums2= [2,4,6,8]
res-> [1,2,3,4,5,6,7,8]
"""


def union(nums1: list[int], nums2: list[int]) -> list[int]:
    """The approach will be the same, two pointers, so when they are equal, we skip all those same pointer and got to the next."""
    union_list: list[int] = []
    p1: int = 0
    p2: int = 0

    while p1 < len(nums1) and p2 < len(nums2):
        if nums1[p1] < nums2[p2]:
            union_list.append(nums1[p1])
            p1 += 1
        elif nums2[p2] < nums1[p1]:
            union_list.append(nums2[p2])
            p2 += 1
        else:
            p1 += 1
            p2 += 1

    # Now we should add all the remaining elements from the remaining list
    while p1 < len(nums1) and nums1[p1] not in union_list:
        union_list.append(nums1[p1])
        p1 += 1

    while p2 < len(nums2) and nums2[p2] not in union_list:
        union_list.append(nums2[p2])
        p2 += 1

    return union_list


if __name__ == "__main__":
    print(f"Union: {union([1, 3, 5, 7], [2, 4, 6, 8])}")  # [1,2,3,4,5,6,7,8]
