"""
Sum matrix
Time: O(n*m)
Memory: O(n+m)
"""


def max_rook_sum(board: list[list[int]]) -> int:
    # =============================================================================
    # Stage 1: Initialization
    # =============================================================================
    n: int = len(board)
    m: int = len(board[0])

    # THE BASE PROBLEM IS TO KNOW HOW MANY SUM MATRICES WE NEED AND WHICH ONES
    rows_sum: list[int] = [0] * n
    cols_sum: list[int] = [0] * m

    # =============================================================================
    # Stage 2: Sum rows and cols, create a prefix list basically
    # =============================================================================
    for i in range(n):
        for j in range(m):
            ...

    # =============================================================================
    # Stage 3: Search for the response: Use the pre-computed sums to find the
    # solution in an optimal way.
    # =============================================================================
    max_sum: int = 0
    for i in range(n):
        for j in range(m):
            # Sum calculations for the position [i,j]
            ...

    return max_sum
