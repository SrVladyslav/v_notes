"""
Given a list of segments where each segment represents the time of a meeting in a cabine.
Each segment has the time started and time finished the meetup in the cabine. Your goal
is to find the minimum number of cabins that you need to meet all the meetings. You can only
book a cabine when is freed.

e.g.
segments = [[2,5], [1,3], [2,4]]
output = 3
"""


def find_minimum_cabines(segments: list[list[int]]) -> int:
    """In this approach we will use the dots methods, which in this case we will
    handle just a counter for how many people are currently in a meeting. For each meeting
    start we will add +1, and then if its ended, we will rest the -1. But we should do it
    chronologically, so first of all we should sort all the segments by time."""

    # Stage 1: Add to each time the state, if its free or busy
    times: list[list[int]] = []

    for segment in segments:
        times.append([segment[0], 1])  # We show that the person took started a meeting
        times.append([segment[1], -1])  # We show that the person ended the meeting

    # Stage 2: Sort the time chronologically
    times.sort()

    # Stage 3: Now we should iterate over the times and find the maximum concurrent meetings
    current: int = 0
    max_concurrent: int = 0

    for time in times:
        current += time[1]
        max_concurrent = max(max_concurrent, current)

    return max_concurrent


if __name__ == "__main__":
    segments: list[list[int]] = [[2, 5], [1, 3], [2, 4]]
    print(f"Segments: {segments}")
    response: int = find_minimum_cabines(segments)

    print(f"Minimum cabines needed: {response}")
