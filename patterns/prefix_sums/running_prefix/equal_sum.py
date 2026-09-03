"""
Given a list of numbers, we need to find an elemnt where all the sums of numbers
before it are equal to the sum of the elements after it.

e.g.
nums = [7,-1, 4, 10, 5, 5]

result = 3.

Since we have the sums before it = 10 and after it also equals 10.
"""


def find_equal_sum(nums: list[int]) -> int:
    # Stage 1: Initialization
    total_sum: int = sum(nums)
    left_sum: int = 0

    # Stage 2: While loop while seaching for the response
    for i, num in enumerate(nums):
        if left_sum == total_sum - num - left_sum:
            return i

        left_sum += num

    return -1


if __name__ == "__main__":
    nums: list[int] = [7, -1, 4, 10, 5, 5]

    response: int = find_equal_sum(nums)
    print(f"Nums: {nums} -> Equal sum: {response}")
