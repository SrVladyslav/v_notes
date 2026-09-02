"""
Given a sorted array of numbers nums and a number tg.
We should find the first and the last index of the number tg in the list.

e.g.
nums = [2,3,3,3,3,7,8]
tg = 3
response = [1,4]
"""


def search_first(nums: list[int], target: int) -> int:
    """Using the first binary search to look for the bad element, the first changed."""
    left: int = -1
    right: int = len(nums) - 1

    while right - left > 1:
        middle: int = left + (right - left) // 2

        if nums[middle] < target:  # Should be only equal to excludethe left
            left = middle
        else:
            right = middle
    return right if nums[right] == target else -1


def search_last(nums: list[int], target: int) -> int:
    """Using the binary search to look for the first good element, the left part basically."""
    left: int = 0
    right: int = len(nums)
    while right - left > 1:
        middle: int = left + (right - left) // 2
        if nums[middle] <= target:
            left = middle
        else:
            right = middle
    return left if nums[left] == target else -1


def find_first_and_last_index(nums: list[int], target: int) -> list[int]:
    """Using the double binary search. Processing the binary search results."""

    if not nums:
        return [-1, -1]

    return [search_first(nums, target), search_last(nums, target)]


if __name__ == "__main__":
    nums: list[int] = [2, 3, 3, 3, 3, 7, 8]
    target: int = 3

    print(
        f"First and last index for {target} in {nums}: {find_first_and_last_index(nums, target)}"
    )
