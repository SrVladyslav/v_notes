"""
Given a list with characters. Yous should sort its symbols by their frequency,
from the most frequent to the least frequent.

e.g.
chars = ["B", "A", "B", "B", "C", "B", "C"]
Solution = BBBBCCA

"""


def sort_by_frequency(chars: list[str]) -> str:
    """This approach shoudl only use th ehash tables key value pattern"""

    # First pass, counting the frequency of each char
    counter: dict[str, int] = {}
    for char in chars:
        counter[char] = counter.get(char, 0) + 1

    # Second pass, we create the frequency list
    frequency_list: list[list[str]] = [[] for _ in range(len(chars) + 1)]

    for char, freq in counter.items():
        frequency_list[freq].append(char)

    # Create the final responmse list with the sorted chars
    result: list[str] = []
    for i in range(len(frequency_list) - 1, 0, -1):
        for char in frequency_list[i]:
            result.append(char * i)

    return "".join(result)


if __name__ == "__main__":
    input_list: list[str] = ["B", "A", "B", "B", "C", "B", "C"]

    result: str = sort_by_frequency(input_list)
    print(f"Input: {input_list} | Solution: {result}")
