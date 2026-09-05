"""
Given a string with two numbers in it from 1 to 9.
Every number has a combination of characters in it,
you are tasked with finding all possible combinations of characters.

Example:

input = "24"
output = ["ag","ah", "ai","bg","bh","bi", "cg","ch","ci"]

For the solution, we will start with a first item from the nums iput,
then will bruteforce all thecombinations and add them to the list again,
finally if the next item has the same number of characters, is the response
"""

from collections import deque


def generate_combinations(combination: str) -> list[str]:
    phone_map: dict[int, str] = {
        2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz",
    }

    ## Initialize the queue or deque. Queue inside has the deque
    result: deque[str] = deque([""])

    while result and len(result[0]) < len(combination):
        prefix: str = result.popleft()
        digit: int = int(combination[len(prefix)])

        for letter in phone_map[digit]:
            result.append(prefix + letter)

    return list(result)


if __name__ == "__main__":
    combination: str = "24"
    print("Combinations for 24: ", generate_combinations(combination))
