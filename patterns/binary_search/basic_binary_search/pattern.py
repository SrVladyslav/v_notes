"""Pattern for the basic binary search

Time: O(log(n))
Memory: O(1)
"""


def search_last(nums: list[int], target: int) -> int:
    # =============================================================================
    # Stage 1: Initialization
    # 1) Looking for last good, then response in pointer left -> l=0, r=len(nums)
    #   e.g. Search for the last index on the list that x
    # 2) Looking for first bad, then response in pointer right -> l=-1, r = len(nums) -1
    #   e.g. Search for the first index on the list that is not x
    # =============================================================================
    left: int = 0
    right: int = len(nums) - 1

    # =============================================================================
    # Stage 2: Main loop, use this instead of left < right so it can handle better the case
    # =============================================================================
    while right - left > 1:
        # ==========================================================================
        # Stage 3: Find the middle, this is the int overflow approach, in Python etc,
        # (right + left) // 2 is good enough
        # ==========================================================================
        middle: int = left + (right - left) // 2

        # ==========================================================================
        # Stage 4: Decrementing the search space
        # ==========================================================================
        if (
            ...
        ):  # MAIN PROBLEM HERE; WHICH WILL SPLIT THE RESPONSES IN GOOD AND BAD ONES
            left = middle
        else:
            right = middle
    # =============================================================================
    # Stage 5: Response processing
    # =============================================================================
    ...
