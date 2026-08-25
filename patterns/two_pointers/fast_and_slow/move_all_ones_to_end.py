"""
Given a list with n numbers, we need to move all the m numbers to the end of the list.
The approach is to use two pointers, one for the fast pass and another for the slow pass.

It should be done inplace, aka without creating a new list basically.
"""

import os

DEFAULT_LIST: list[int] = [1, 0, 1, 1, 5, 42, 7]  # Solution: [0,5,42,7,1,1,1]
DEFAULT_NUMBER: int = 1


def read_input() -> tuple[list[int], int]:
    try:
        with open(os.path.join(os.path.dirname(__file__), "input.txt")) as f:
            inputs = list(map(int, f.readline().strip("\n").split(",") or DEFAULT_LIST))
            number = int(f.readline().strip("\n") or DEFAULT_NUMBER)
            return inputs, number

    except FileNotFoundError:
        return DEFAULT_LIST, DEFAULT_NUMBER


def move_all_ones_to_end(
    nums: list[int], loockup_num: int = DEFAULT_NUMBER
) -> list[int]:
    """Given the array, it moves all the ones to the end of the list
    using the fast and slow pointers pattern
    """
    p_fast: int = 0
    p_slow: int = 0

    while p_slow < len(nums) and p_fast < len(nums):
        if nums[p_fast] == loockup_num:
            p_fast += 1
            continue

        elif nums[p_slow] == loockup_num and nums[p_fast] != loockup_num:
            # Use just pointers to move the ones to the end
            nums[p_slow], nums[p_fast] = nums[p_fast], nums[p_slow]

        # Edge case when the slow and fast pointers start inside a bad number
        p_slow += 1
        p_fast += 1


def move_all_ones_to_end_optimized(
    nums: list[int], loockup_num: int = DEFAULT_NUMBER
) -> list[int]:
    """Given the array, it moves all the ones to the end of the list
    using the fast and slow pointers pattern
    """
    p_fast: int = 0
    p_slow: int = 0

    while p_fast < len(nums):
        if nums[p_fast] != loockup_num:
            nums[p_slow], nums[p_fast] = nums[p_fast], nums[p_slow]
            p_slow += 1

        # The fast pointer should be moving always
        p_fast += 1


if __name__ == "__main__":
    inputs, loockup_num = read_input()
    print(f"Array: {inputs} | Number: {loockup_num}")
    move_all_ones_to_end(nums=inputs, loockup_num=loockup_num)
    print(f"Solution: {inputs} \n")

    inputs, loockup_num = read_input()
    move_all_ones_to_end_optimized(nums=inputs, loockup_num=loockup_num)
    print(f"Solution: {inputs}")
