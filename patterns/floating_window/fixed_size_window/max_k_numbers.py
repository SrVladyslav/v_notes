"""
Given a list of number and a number k, you should return the k numbers in the
list which sums the most.
"""

from os import path

DEFAULT_LIST: list[int] = [3, 2, 0, 9, 1, 2, 8, 5, 2]  # Solution: 25
DEFAULT_NUMBER: int = 5


def read_input() -> tuple[list[int], int]:
    try:
        with open(path.join(path.dirname(__file__), "input.txt")) as f:
            inputs = list(map(int, f.readline().strip("\n").split(",") or DEFAULT_LIST))
            number = int(f.readline().strip("\n") or DEFAULT_NUMBER)
            return inputs, number

    except FileNotFoundError:
        return DEFAULT_LIST, DEFAULT_NUMBER


def max_sum_k_number(nums: list[int], k: int) -> int:
    """For this approach we will be using the sliding window approach"""
    window_sum: int = 0
    for i in range(k):
        window_sum += nums[i]

    max_sum = window_sum

    for r in range(k, len(nums)):
        window_sum = window_sum - nums[r - k] + nums[r]
        max_sum = max(
            max_sum,
            window_sum,
        )

    return max_sum


def max_sum_k_number_unoptimized(nums: list[int], k: int) -> int:
    """More typical approach, but IDK if it will be allowed in code platforms"""
    max_sum: int = 0

    for i in range(len(nums) - k + 1):
        max_sum = max(max_sum, sum(nums[i : i + k]))

    return max_sum


if __name__ == "__main__":
    l, k = read_input()

    print(f"List: {l} | Number: {k}")
    max_sum = max_sum_k_number(l, k)
    print(f"Solution: {max_sum}")

    print(f"New list: {max_sum_k_number([3,2,0,9,1,2,8,5,-5,7,2], k)}")
