"""
Given a list of numbers and an integer k. You should find the maximum multiplication
of all the numbers in the list.

Example:
nums = [3,0,5,9,4,2] k = 3
res = 180
"""


# O(n*k)
def max_k_product_unoptimized(nums: list[int], k: int) -> int:
    window_mult: int = 1

    for i in range(k):
        window_mult *= nums[i]

    max_prod: int = window_mult

    for right in range(k, len(nums)):
        window_mult = 1
        for i in nums[right - k : right]:
            window_mult *= i
        max_prod = max(max_prod, window_mult)

    return max_prod


# O(n)
def max_k_product(nums: list[int], k: int) -> float:
    window_mult: float = 1
    zero_count: int = 0

    for i in range(k):
        if nums[i] == 0:
            zero_count += 1
        else:
            window_mult *= nums[i]

    max_prod: float = 0 if zero_count > 0 else window_mult

    for right in range(k, len(nums)):
        left = right - k

        # Remove the left element
        if nums[left] == 0:
            zero_count -= 1
        else:
            window_mult //= nums[left]

        # Add the right element
        if nums[right] == 0:
            zero_count += 1
        else:
            window_mult *= nums[right]

        current_prod: float = 0 if zero_count > 0 else window_mult
        max_prod = max(max_prod, current_prod)

    return max_prod


if __name__ == "__main__":
    res = max_k_product(nums=[3, 0, 5, 9, 4, 2], k=3)
    print(f"Solution: {res}")
