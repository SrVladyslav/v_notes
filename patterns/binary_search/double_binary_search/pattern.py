"""
Pattern double binary search:
The idea is to use two binary searches, one to search for the first elements of the
list be looking for the target in the bad side, and the other binary search
looking for the last element of the target in the good side.

Time: O(2*log(n)) -> O(log(n))
Memory: O(1)
"""


# =============================================================================
# Stage 1: Searching for the first element of the target in the list
# =============================================================================
def search_first(nums: list[int], target: int) -> int:
    # This is the approach to search for the bad element of target, the right part
    left, right = -1, len(nums) - 1

    while right - left > 1:
        middle: int = left + (right - left) // 2

        # THE BASE PROBLEM HERE IS TO UNDERTAND WHICH IS THE GOOD
        # FUNCTION WILL BE USED HERE
        if ...:
            left = middle
        else:
            right = middle
    return ...


# =============================================================================
# Stage 2: Searching for the last element of the target in the list
# =============================================================================
def search_last(nums: list[int], target: int) -> int:
    # This is the approach to search for the good element of target, the left part
    left, right = 0, len(nums)
    while right - left > 1:
        middle: int = left + (right - left) // 2

        # THE BASE PROBLEM HERE IS TO UNDERTAND WHICH IS THE GOOD
        # FUNCTION WILL BE USED HERE
        if ...:
            right = middle
        else:
            left = middle
    return ...


# =============================================================================
# Stage 3: Processing the results of the both searches
# =============================================================================
def search_range(nums: list[int], target: int) -> list[int]:
    # Processing the results of the two searches.
    ...
