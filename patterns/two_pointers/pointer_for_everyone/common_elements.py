"""
Given two lists: [0,2,4] and [1,2,2,8] you should return all the common elements.

Response here: [2]
"""

import os

LIST_A: list[int] = [0, 2, 4, 5, 8]
LIST_B: list[int] = [1, 2, 3, 4, 8, 8, 8]


def read_input() -> tuple[list, int]:
    """Reads the input, first the array and then the target, it returns the tuple of the array in
    an int format and the target in an int format"""
    try:
        with open(os.path.join(os.path.dirname(__file__), "input.txt")) as f:
            array_a = list(map(int, f.readline().strip("\n").split(",") or LIST_A))
            array_b = list(map(int, f.readline().strip("\n").split(",") or LIST_B))
            return array_a, array_b
    except FileNotFoundError:
        return LIST_A, LIST_B


def common_elements(array_a: list, array_b: list) -> list[int]:
    """The basic approach is also to have two pointers on the start, move the smaller one,
    if they are equal, then we mark them as found and move both one step.

    The current approach only works if the list are sorted"""
    common_elements: list[int] = []
    p1: int = 0
    p2: int = 0

    while p1 < len(array_a) and p2 < len(array_b):
        if array_a[p1] < array_b[p2]:
            p1 += 1
        elif array_b[p2] < array_a[p1]:
            p2 += 1
        else:
            common_elements.append(array_a[p1])
            p1 += 1
            p2 += 1

    return common_elements


if "__main__" == __name__:
    array_a, array_b = read_input()
    print(f"Array A: {array_a} | Array B: {array_b}")
    solution = common_elements(array_a, array_b)
    print(f"Solution: {solution}")
