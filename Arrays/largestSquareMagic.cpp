/*
 * Problem: 1895. Largest Magic Square
 *
 * Given a 2D grid of integers, find the largest square submatrix
 * where:
 *  - All rows have the same sum
 *  - All columns have the same sum
 *  - Both diagonals have the same sum
 *
 * Approach:
 *  - Use prefix sums for rows, columns, and both diagonals
 *  - Try square sizes from largest to smallest
 *  - For each square, validate row sums, column sums, and diagonals
 *  - Return the largest valid square size found
 *
 * Time Complexity:
 *  - O(min(n, m) * n * m)
 *
 * Space Complexity:
 *  - O(n * m) for prefix sums
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Prefix sums
        vector<vector<int>> row(n, vector<int>(m + 1, 0));
        vector<vector<int>> col(n + 1, vector<int>(m, 0));
        vector<vector<int>> diag(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> anti(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(n, m); k >= 1; k--) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {

                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // rows
                    for (int r = i; r < i + k && ok; r++)
                        if (row[r][j + k] - row[r][j] != target)
                            ok = false;

                    // cols
                    for (int c = j; c < j + k && ok; c++)
                        if (col[i + k][c] - col[i][c] != target)
                            ok = false;

                    // diagonals
                    if (diag[i + k][j + k] - diag[i][j] != target)
                        ok = false;
                    if (anti[i + k][j] - anti[i][j + k] != target)
                        ok = false;

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};
