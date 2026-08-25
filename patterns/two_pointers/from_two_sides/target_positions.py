"""
Given the sorted list of [-2, 1, 6, 9, 12, 21] and the target = 18, you should return
the indices of the two elements in the list that add up to the target value.

e.g. 6+12 = 18  -> return [2,4]
"""

import os

DEFAULT_LIST: list[int] = [-2, 1, 6, 9, 12, 21]
DEFAULT_TARGET: int = 18


def read_input() -> tuple[list, int]:
    """Reads the input, first the array and then the target, it returns the tuple of the array in
    an int format and the target in an int format"""
    try:
        with open(os.path.join(os.path.dirname(__file__), "input.txt")) as f:
            array = list(map(int, f.readline().strip("\n").split(",") or DEFAULT_LIST))
            target = int(f.readline() or DEFAULT_TARGET)
            return array, target
    except FileNotFoundError:
        return DEFAULT_LIST, DEFAULT_TARGET


def target_postitions(array: list, target: int) -> list[int]:
    """Returns the indices of the two elements in the list that add up to the target value."""
    l = 0
    r = len(array) - 1

    while l < r:
        curr_sum: int = array[l] + array[r]
        if curr_sum == target:
            return [l, r]
        elif curr_sum < target:
            l += 1
        else:
            r -= 1

    return [-1, -1]


def main(**kwargs) -> None:
    print("Hello World")
    array, target = read_input()
    print(f"Array: {array} | Target: {target}")

    solution = target_postitions(array, target)
    print(f"Solution: {solution}")


if __name__ == "__main__":
    main()
