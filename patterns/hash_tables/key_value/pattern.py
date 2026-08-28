# Time: O(n)
# Memory: O(n)


def frequency_sort(chars: str) -> str:
    # Stage 1: KV -> Basically doying the counting
    count: dict[str, int] = {}  # Key:Value -> Char:Frequency
    for char in chars:
        ...

    # Stage 2: VK (Inversion of frequencies)
    # CORE PROBLEM: Understand that the problem needs the inversion, if you know that
    # then you can solve it easily
    frequency_list: list[list[str]] = [
        [] for _ in range(len(chars) + 1)  # Index: frequency -> quantity: symbols
    ]

    for char, freq in count.items():
        ...

    # Stage 3: Grouping the result
    result: list[str] = []
    ...

    return "".join(result)
