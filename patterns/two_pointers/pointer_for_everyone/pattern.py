# Time: O(a+b)
# Memory: O(min(a,b))


def pointer_for_everyone(a: list, b: list) -> list:
    # =============================================================================
    # 1) Pointers initializations
    # =============================================================================
    p1: int = 0
    p2: int = 0
    result: list = []

    # =============================================================================
    # 2) While loop while we check all the conditions
    # =============================================================================
    while p1 < len(a) and p2 < len(b):
        # =============================================================================
        # 3) Pointer logic movement: IS THE KEY TO THE SOLUTION, UNDERSTAND WHEN
        # TO MOVE THEM, is this is understood, the problem is solved automatically
        # =============================================================================
        ...
        # <The L and R pointers are moved here>

    return result
