"""
Given a sorted array of numbers nums and a number tg.
We should find the last index of the number tg in the list.

e.g.
nums = [1,2,6,6,9,10,11,13,14]
tg = 6
output = 3
"""


def find_last_index_for_n(nums: list[int], target: int) -> int:
    # =============================================================================
    # 1) Looking for last good, then response in pointer left -> l=0, r=len(nums)
    # 2) Looking for first bad, then response in pointer right -> l=-1, r = len(nums) -1
    # =============================================================================
    left, right = 0, len(nums)

    while (
        right - left > 1
    ):  # We use this instead of left < right so if they are equal, they don't go into infinite loop
        middle: int = left + (right - left) // 2

        # ==========================================================================
        # TYPICAL PROBLEM: USE LEFT AND RIGHT INSIDE THE GOOD FUNCTION.
        # INSIDE THIS FUNCTION WE SHOULD ONLY USE THE MIDDLE VALUE.
        # ¡AGAIN, DO NOT F. USE THE LEFT AND RIGHT IN HERE!
        # ==========================================================================
        if nums[middle] <= target:
            left = middle
        else:
            right = middle

    return left if nums[left] == target else -1


if __name__ == "__main__":
    nums: list[int] = [1, 2, 6, 6, 9, 10, 11, 13, 14]
    target: int = 14

    last_index: int = find_last_index_for_n(nums, target)

    print(f"Last index for {target} in {nums}: {last_index}")
