"""
Given a list of same symbols, we need to check if every opening symbol
has its closing symbol.

e.g.
symbols = ["(",")","(","(",")",")"]
output = True

symbols = ["(","(",")"]
output = False

This approach really does not need the stack, we can just use a counter kek.
"""


def is_valid(symbols: list[str]) -> bool:
    counter: int = 0
    for symbol in symbols:
        if symbol == "(":
            counter += 1
        else:
            counter -= 1

        if counter < 0:
            return False

    return counter == 0


if __name__ == "__main__":
    symbols: list[str] = ["(", ")", "(", "(", ")", ")"]
    bad_symbols: list[str] = ["(", "(", ")"]

    print(f"Symbols: {symbols} -> {is_valid(symbols)}")
    print(f"Bad symbols: {bad_symbols} -> {is_valid(bad_symbols)}")
