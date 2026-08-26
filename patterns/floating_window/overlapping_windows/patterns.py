"""
The idea is to basically use two pointers too, then we add a counter
store the changes we are making on the window. So we start moving
right pointer, if there is a zero or the respective number, we only
move the pointer if the counter is less than the number. So we
increase the pointer while we are not at the end of the counter
is greater than the number of zeros in the window.
"""

# Time: O(n)
# Memory: O(1)


def longest_ones_with_flips(nums: list[int], k: int) -> int:
    # =============================================================================
    # 1) Left & Right initializations
    # =============================================================================

    left: int = 0
    right: int = -1  # In order to not process the first element independently
    result: int = 0

    # =============================================================================
    # 2) Initializing the window state. THIS IS THE MAIN PROBLEM
    # YOU NEED TO UNDERSTAND WHAT IS THE REAL STATE OF THE WINDOW
    # =============================================================================
    ...

    # =============================================================================
    # 3) Outer loop
    # =============================================================================
    while left < len(nums):
        # =============================================================================
        # 4) Widering window loop
        # =============================================================================
        while right + 1 < len(nums) and ...:  # THINK ABOUT THE EXPANSION STATE
            # updating the window state
            right += 1
            ...  # WINDOW STATE UPDATE TOO

        # =============================================================================
        # 5) Renewind the result
        # =============================================================================
        result = max(result, right - left + 1)

        # =============================================================================
        # 6) Window decrementation
        # =============================================================================
        ...  # STATUS UPDATE
        left += 1
    return result
