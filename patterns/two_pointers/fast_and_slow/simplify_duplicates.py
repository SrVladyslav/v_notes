"""
Given a list of symbols chars. You should change all the following voids to one space only.
All the changes should be done inplace, aka without creating a new list.
"""

INPUT = [
    "¡",
    "",
    "",
    "H",
    "I",
    "",
    "",
    "",
    "",
    "!",
    "",
    "",
    "",
    "!",
    "",
]  # Solution ["", "H", "I", "!", ""]


def simplify_duplicates(chars: list[str]) -> list[str]:
    """The approach will be using the same slow and fast pointers"""
    p_fast: int = 1
    p_slow: int = 1

    # Use for loop here, since p_fast is always added in each iteration
    while p_fast < len(chars):
        # Case when the items should be deleted
        if chars[p_slow - 1] == "" and chars[p_fast] == "":
            p_fast += 1
            continue

        chars[p_slow] = chars[p_fast]
        p_slow += 1
        p_fast += 1

    del chars[p_slow:]


def simplify_duplicates_optimized(chars: list[str]) -> list[str]:
    slow: int = 1
    for fast in range(1, len(chars)):
        if chars[slow - 1] == "" and chars[fast] == "":
            continue

        chars[slow] = chars[fast]
        slow += 1

    del chars[slow:]

    return chars


if "__main__" == __name__:
    print(f"Input: {INPUT}")

    simplify_duplicates(INPUT)
    print(f"Solution: {INPUT}")
