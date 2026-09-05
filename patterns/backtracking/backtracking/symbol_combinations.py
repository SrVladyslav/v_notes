"""
Given number n, you need to generate all the possible combinations of same pair symbosl ().
It should have the opening and closing symbols in the same pair.
The idea of the optimal solution is to generate all the good combinations from start

Example:
n = 3
result ["((()))", "(()())", "(())()", "()()()"]
"""


def generate_symbol_pair_combinations(n: int) -> list[str]:
    """
    The main idea here is to use counters while we are generating the combinations.

    In this approach we wil have the running queue with a stete of 3, the value of stroken,
    the opening and closing symbol counters.
    """
    result: list[str] = []

    # To make the code more functional, we will do the loop approach, so we need to use the queue in order to have the things to process
    running_queue: list[tuple[str, int, int]] = [("", 0, 0)]

    while running_queue and len(running_queue[0][0]) < 2 * n:
        # As in bruteforce, we need to extract the first element from the queue
        first_element, opening, closing = running_queue.pop(0)

        # First we will be adding the opening symbol, then the closing one
        if opening < n:
            new_element: tuple[str, int, int] = (
                first_element + "(",
                opening + 1,
                closing,
            )
            running_queue.append(new_element)

        if opening > closing:
            new_element: tuple[str, int, int] = (
                first_element + ")",
                opening,
                closing + 1,
            )
            running_queue.append(new_element)

    return [prefix for prefix, _, _ in running_queue]


if __name__ == "__main__":
    print("Generating symbol pair combinations for 3:")
    res = generate_symbol_pair_combinations(3)
    print(res)
