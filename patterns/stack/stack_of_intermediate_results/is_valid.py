"""
We are given with a list of symbols, we need to check if every opening symbol
has its closing symbol.

e.g.
symbols = ["(","(", "<", "[","{","}","]",">"]
output = True

symbols = ["(","(",")"]
output = False

This is a stack problem, so we need to use a stack to keep track of the opening symbols.
"""


def is_good(symbols: list[str]) -> bool:
    stack: list[str] = []

    patterns: dict[str, str] = {"(": ")", "[": "]", "{": "}", "<": ">"}

    for symbol in symbols:
        if symbol in patterns:
            # CHAR is an opening symbol, so we add it to the stack
            stack.append(symbol)
        elif len(stack) == 0:
            # CHAR is a closing symbol, but without openning one, so finish that
            return False
        else:
            # CHAR is closing one, but we have elements in the stack, so we check
            top = stack.pop()
            if symbol != patterns[top]:
                return False

    return len(stack) == 0


if __name__ == "__main__":
    symbols: list[str] = ["(", ")", "<", "[", "{", "}", "]", ">"]
    bad_symbols: list[str] = ["(", "(", ")"]

    print(f"Symbols: {symbols} -> {is_good(symbols)}")
    print(f"Bad symbols: {bad_symbols} -> {is_good(bad_symbols)}")
