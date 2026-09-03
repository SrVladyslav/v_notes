/**
Given a matrix of int nuymbers, find the max sum.

e.g.
matrix:
1,5,1,-1
3,1,2,7
3,5,2,0

result: 22
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int find_max_sum_in_matrix(const vector<vector<int>> &matrix)
{
    // Stage 1: Initialization
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> row_sums(rows, 0);
    vector<int> col_sums(cols, 0);

    // Stage 2: Preprocessing, calculate the sum listsd for rows and cols
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];
        }
    }

    // Stage 3: Search for the response using the calculated sums in an organized way
    int max_sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int row_sum = row_sums[i] - matrix[i][j];
            int col_sum = col_sums[j] - matrix[i][j];
            max_sum = max(max_sum, row_sum + col_sum);
        }
    }

    return max_sum;
}

int main()
{
    vector<vector<int>> matrix{
        {1, 5, 1, -1},
        {3, 1, 2, 7},
        {3, 5, 2, 0}};

    cout << "Matrix:\n";
    for (auto row : matrix)
        for (auto col : row)
            cout << col << " ";
    cout << endl;

    int response = find_max_sum_in_matrix(matrix);
    cout << "Max sum: " << response << endl;

    return 0;
}