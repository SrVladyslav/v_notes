"""
Pattern: Dots method

Time: O(n*log(n))
Memory: O(n)
"""


def minimum_meeting_rooms(segments: list[list[int]]) -> int:
    # =============================================================================
    # Stage 1: We transform the segments into points
    # The start is represented as +1 and the end as -1
    # =============================================================================
    points: list[list[int]] = []
    for segment in segments:
        ...

    # =============================================================================
    # Stage 2: Sort the points by time
    # =============================================================================
    points.sort()

    # =============================================================================
    # Stage 3: Find the solution. THIS IS THE MAIN PROBLEM, HOW TO FORM THE GOOD RESPONSE
    # =============================================================================
    max_rooms: int = 0
    curr_room: int = 0

    for point in points:
        ...

    return max_rooms
