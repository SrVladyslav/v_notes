"""
Given a list of numbers of 0s and 1s, and a value k, you are allowed
to change the k times zeros to ones. You should find the maximum number of the
following ones in the list.

e.g.
nums = [1,0,1,0,1,0,1,1]
k = 2

res = 6
"""


def max_ones_with_changes(nums: list[int], k: int) -> int:
    left: int = 0
    right: int = -1
    result: int = 0

    zeroes_counter: int = 0

    while left < len(nums):
        while right + 1 < len(nums) and (nums[right + 1] == 1 or zeroes_counter < k):
            if nums[right + 1] == 0:
                zeroes_counter += 1
            right += 1

        # Now we check the maximum result
        result = max(result, right - left + 1)

        if nums[left] == 0:
            zeroes_counter -= 1
        left += 1

    return result


if __name__ == "__main__":
    input_list: list[int] = [0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1]

    print(f"Input: {input_list}")
    result = max_ones_with_changes(nums=input_list, k=2)
    print(f"Solution: {result}")
