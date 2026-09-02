"""
Given two sorted lists of segments, we should find all the intersection between them,
between the two lists of given segments.

e.g.
seg1 = [[1,2],[3,4], [6,7]]
seg2 = [[1,5], [7,8]]

result: [[1,2],[3,4],[7,7]]

This approach should be using two pointers, one for each list of segments.
Then the approach is like in the pointer problems, but chekcing for intersections
"""


def intersection(seg1: list[int], seg2: list[int]) -> list[int]:
    start: int = max(seg1[0], seg2[0])
    end: int = min(seg1[-1], seg2[-1])

    if start <= end:
        return [start, end]
    else:
        return []


def multi_segment_intersections(
    seg1: list[list[int]], seg2: list[list[int]]
) -> list[list[int]]:
    if len(seg1) < 1 or len(seg2) < 1:
        return []

    # Stage 1: Init the pointers for the two lists and then check forth eintersections
    p1: int = 0
    p2: int = 0
    result: list[list[int]] = []

    while p1 < len(seg1) and p2 < len(seg2):
        if intersect := intersection(seg1[p1], seg2[p2]):
            result.append(intersect)

        if seg1[p1][1] < seg2[p2][1]:
            p1 += 1
        else:
            p2 += 1

    return result


if __name__ == "__main__":
    seg1: list[list[int]] = [[1, 2], [3, 4], [6, 7]]
    seg2: list[list[int]] = [[1, 5], [7, 8]]

    print(
        f"Segments 1: {seg1}\nSegments 2: {seg2}\nIntersections: {multi_segment_intersections(seg1, seg2)}"
    )
