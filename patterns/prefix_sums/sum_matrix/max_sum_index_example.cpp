/**
 * Given a matrix of int numbers. You should find the position with the
 * maximum sum of the cells. You can go in row, column and the two diagonals.
 *
 * e.g.
 * matrix = [
 *  [1,2,3],
 *  [4,5,6],
 *  [7,8,9]
 * ]
 *
 * response = (1,1)
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> find_max_sum_index(const vector<vector<int>> &matrix)
{
    // Stage 1: Initialization
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> row_sums(rows, 0);
    vector<int> col_sums(cols, 0);
    vector<int> desc_diagonal_sums(rows + cols - 1, 0);
    vector<int> asc_diagonal_sums(rows + cols - 1, 0);

    // Stage 2: Preprocessing, calculating the sum lists for the rows, cols and diagonals
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];

            // Descending diagonal is always (i-j), but since i-j can be
            // newgative e.g. i=0;j=2 -> -2, then we add an offset (cols-1)
            desc_diagonal_sums[i - j + cols - 1] += matrix[i][j];

            // Ascending diagonal is alñways (i+j)
            asc_diagonal_sums[i + j] += matrix[i][j];
        }
    }

    // Stage 3: Search for the maximum sum, and therefore the position
    int max_sum = 0;
    pair<int, int> response{-1, -1};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int row_sum = row_sums[i] - matrix[i][j];
            int col_sum = col_sums[j] - matrix[i][j];
            int asc_diagonal_sum = asc_diagonal_sums[i + j] - matrix[i][j];
            int desc_diagonal_sum = desc_diagonal_sums[i - j + cols - 1] - matrix[i][j];

            int new_sum = row_sum + col_sum + asc_diagonal_sum + desc_diagonal_sum;
            if (
                new_sum > max_sum)
            {
                max_sum = new_sum;
                response.first = i;
                response.second = j;
            }
        }
    }

    return response;
}

int main()
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Matrix:\n";
    for (auto row : matrix)
        for (auto col : row)
            cout << col << " ";
    cout << endl;

    pair<int, int> response = find_max_sum_index(matrix);
    cout << "Max sum index: " << response.first << ", " << response.second << endl;

    return 0;
}