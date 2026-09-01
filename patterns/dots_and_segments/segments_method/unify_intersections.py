"""
Given a list of segments, return a new list with all the interesected
segments unified into a single segment.

e.g.
segments = [[2,4], [1,3],[5,6], [6,7], [8,8]]
output: [[1,4],[5,7], [8,8]]

First of all we need to sort the segment by their starting point
"""


def is_intersection(s1: list[int], s2: list[int]) -> bool:
    return max(s1[0], s2[0]) <= min(s1[-1], s2[-1])


def merge_segments(s1: list[int], s2: list[int]) -> list[int]:
    return [min(s1[0], s2[0]), max(s1[-1], s2[-1])]


def unify_intersections(segments: list[list[int]]) -> list[list[int]]:
    if len(segments) < 2:
        return segments

    # Stage 1: Sorting the segments by their starting point
    segments.sort(key=lambda x: x[0])

    # Stage2: Initializing the first segment
    result: list[list[int]] = [segments[0]]

    for i in range(1, len(segments)):
        # Stage 3: Checking for intersections over the rest of the segments
        if is_intersection(result[-1], segments[i]):
            result[-1] = merge_segments(result[-1], segments[i])
        else:
            result.append(segments[i])

    return result


if __name__ == "__main__":
    seg1 = [[2, 4], [1, 3], [5, 6], [6, 7], [8, 8]]
    print(f"Segments: {seg1}\nUnified: {unify_intersections(seg1)}")
