# Time: O(n)
# Memory: O(n)


def not_overlaping_windows(nums: list[int]) -> list[str]:
    # =============================================================================
    # 1) Left & Right initializations
    # =============================================================================
    left: int = 0
    right: int = 0
    groups: list[str] = []

    # =============================================================================
    # 2) Outer loop while checking all the conditions
    # =============================================================================
    while left < len(nums):
        # =============================================================================
        # 3) Expanding the right boundary while it meets all the conditions
        # Basically we need to handle here the condition of expanding the inner window
        # THE PROBLEM IS IN THIS POINT, TO KNOW HOW TO EXPAND THE WINDOW
        # =============================================================================
        while right + 1 < len(nums) and ...:
            right += 1

            # =============================================================================
            # 4) Working on the current inner window
            # =============================================================================
            ...

            # =============================================================================
            # 5) Changing to the next window when all the conditions are met.
            # Basically we do one more step from the last window pointer to start the next window
            # =============================================================================
            left = right + 1
            right = right + 1

        return groups
