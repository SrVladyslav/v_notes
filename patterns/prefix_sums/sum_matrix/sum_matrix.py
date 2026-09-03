"""
Given a matrix of int nuymbers, find the max sum.

e.g.
matrix:
1,5,1,-1
3,1,2,7
3,5,2,0

result: 22
"""


def find_max_sum_in_matrix(matrix: list[list[int]]) -> int:
    # Stage 1: Initialization
    rows: int = len(matrix)
    cols: int = len(matrix[0])
    row_sums: list[int] = [0] * rows
    col_sums: list[int] = [0] * cols

    # Stage 2: Preprocess the row and col sums with the prefix lists
    for row in range(rows):
        for col in range(cols):
            row_sums[row] += matrix[row][col]
            col_sums[col] += matrix[row][col]

    # Stage 3: Search for the response using the calculated sums
    max_sum: int = 0
    for row in range(rows):
        for col in range(cols):
            row_sum: int = row_sums[row] - matrix[row][col]
            col_sum: int = col_sums[col] - matrix[row][col]
            max_sum = max(max_sum, row_sum + col_sum)

    return max_sum


if __name__ == "__main__":
    matrix: list[list[int]] = [[1, 5, 1, -1], [3, 1, 2, 7], [3, 5, 2, 0]]

    response: int = find_max_sum_in_matrix(matrix)
    print(f"Matrix: {matrix} -> Max sum: {response}")
