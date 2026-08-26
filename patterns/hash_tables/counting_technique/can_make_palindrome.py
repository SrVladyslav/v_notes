"""
Given a list of chars chars. You should return tru if is possible to
re-arrange its chars the way that we obtain a palindrome.
"""


def can_make_palindrome(chars: list[str]) -> bool:
    """This approach will strictly follow the counting technique of hash tables.
    We should know things like that the palindrome is formed only when has all the letters
    even number of times or when all are even and only one is odd.
    """
    char_counter: dict[str, int] = {}

    # Go trough all the chars and count them one by one O(n)
    for c in chars:
        char_counter[c] = char_counter.get(c, 0) + 1

    # Now we check if the palindrome is possible by looking how many time we have odd and even.
    odd_counter: int = 0
    for v in char_counter.values():
        if v % 2 == 1:
            odd_counter += 1

    return odd_counter <= 1


if __name__ == "__main__":
    true_chars: list[str] = ["a", "b", "a", "a", "b", "c", "c"]
    false_chars: list[str] = ["a", "b", "c"]
    print(f"Chars: {true_chars} -> Solution: {can_make_palindrome(true_chars)}")
    print(f"Chars: {false_chars} -> Solution: {can_make_palindrome(false_chars)}")
