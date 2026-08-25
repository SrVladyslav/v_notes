# Patterns for window of fixed length
# Time: O(n)
# Memory: O(1)


def elements_n_max_sum(nums: list[int], k: int) -> int:
    # =============================================================================
    # 1) First filling of the window
    # =============================================================================
    window_sum: int = 0
    for i in range(k):
        window_sum += nums[i]

    max_sum: int = window_sum

    # =============================================================================
    # 2) Loop for windown search
    # =============================================================================
    for r in range(k, len(nums)):
        # The formula of modifying the k elements between the window transitions,
        # which allows us to pass to the next window fastly
        # <THIS IS THE KEY TO THE SOLUTION>
        ...

    return max_sum
