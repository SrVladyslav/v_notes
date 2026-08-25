"""
Given world s. You need to find if this world is a palindrome or not.
yes: 12321 -> 12321
no: 123 -> 321
"""


def is_palindrome(s: str) -> bool:
    """The easiest way here is to count the chars in the string and use the dictionary counting
    approach, since palindromes should have the even number of chars or one odd and the other even.
    """

    l: int = 0
    r: int = len(s) - 1

    while l < r:
        # Here we should check the opposite chars, so we need to move the counters
        # at the same time
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1
    return True


if __name__ == "__main__":
    print(f"FALSE: {is_palindrome("123")}")
    print(f"TRUE: {is_palindrome("12321")}")
    print(f"FALSE: {is_palindrome("12")}")
    print(f"TRUE: {is_palindrome("1")}")
    print(f"FALSE: {is_palindrome("hola")}")
    print(f"TRUE: {is_palindrome("ABBA")}")
