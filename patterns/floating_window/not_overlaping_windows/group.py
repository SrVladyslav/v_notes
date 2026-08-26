"""
Given a sorte list of integers. You should group it by grouping the
following numbers in the same group, if the next number is greater than
the previous in one, then they are in th e same group. In each group you should add withg the "->"
the follwoed numbers from the first and last of each group.

Example:
[1,2,3,5,8,9,14]
Solution: ["1->3", "5], "8->9", "14"]
"""


def format_group(*kwargs) -> str:
    if len(kwargs) > 1:
        return f"{kwargs[0]}->{kwargs[-1]}"
    return str(kwargs[0])


def group_numbers(nums: list[int]) -> list[str]:
    """The approach that we will be using is a not overlaping windows.

    Is a similar approach as in the slow and fast pointers, so basically we start with
    two pointers and we move them one step at a time, if the next number is greater
    thatn the previous in more than one, then this is one group.
    """
    groups: list[str] = []

    slow: int = 0
    fast: int = 0

    while slow < len(nums):
        # Now we need to expand the right boundary iwhile it means the condition
        while fast + 1 < len(nums) and nums[fast] + 1 == nums[fast + 1]:
            fast += 1

        # If the boundary stopped expanding, what we need to do is to add the ggroup now
        if fast != slow:
            groups.append(format_group(nums[slow], nums[fast]))
        else:
            groups.append(format_group(nums[slow]))

        slow = fast + 1
        fast = fast + 1

    return groups


if __name__ == "__main__":
    EXAMPLE_LIST: list[int] = [1, 2, 3, 5, 8, 9, 13, 14, 16]
    print(f"Example list: {EXAMPLE_LIST}")
    res = group_numbers(EXAMPLE_LIST)
    print(f"Solution: {res}")
