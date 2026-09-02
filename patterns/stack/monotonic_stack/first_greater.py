"""
Given a list of numbers nums, we should return a new list where
the index of original contains the first element greater than its value.
Otherwise return -1.

e.g.
nums = [2,5,1,3,0,4]
output = [5,-1,3,4,4,-1]
"""


def find_greaters(nums: list[int]) -> list[int]:
    result: list[int] = [-1] * len(nums)
    stack: list[int] = []

    i: int = len(result) - 1
    while i >= 0:
        if len(stack) == 0:
            stack.append(nums[i])
            i -= 1
        elif nums[i] < stack[-1]:
            result[i] = stack[-1]
            stack.append(nums[i])
            i -= 1
        else:
            stack.pop()

    return result


def find_greaters_optimized(nums: list[int]) -> list[int]:
    n = len(nums)
    stack = []
    result = [-1] * n

    for i in range(n - 1, -1, -1):
        while stack and nums[i] >= stack[-1]:
            stack.pop()

        if stack:
            result[i] = stack[-1]

        stack.append(nums[i])

    return result


if __name__ == "__main__":
    nums: list[int] = [2, 5, 1, 3, 0, 4]
    print(f"Numbers: {nums}")
    result: list[int] = find_greaters(nums)
    result_optimized: list[int] = find_greaters_optimized(nums)
    print(f"Result: {result}")
    print(f"Result optimized: {result_optimized}")
