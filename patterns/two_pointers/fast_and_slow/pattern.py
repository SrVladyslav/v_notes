# Time: O(n)
# Memory: O(1)


def move_all_m_to_end_pattern(nums: list, target: int) -> list[int]:
    # =============================================================================
    # 1) Slow and fast pointers initializations
    # =============================================================================
    slow = 0
    fast = 0

    # =============================================================================
    # 2) While loop while we check all the conditions
    # =============================================================================
    while fast < len(nums):
        # =============================================================================
        # 3) Pointer logic movement: IS THE KEY TO THE SOLUTION, UNDERSTAND WHEN
        # TO MOVE THEM, is this is understood, the problem is solved automatically
        # =============================================================================
        ...
        # The fast pointer moves always but the slow only in some cases.
        # Since the fast pointer moves always, therefore the main problem
        # is to understand when to move the slow pointer
