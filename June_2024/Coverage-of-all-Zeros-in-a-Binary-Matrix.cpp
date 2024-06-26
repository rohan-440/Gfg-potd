//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &matrix)
    {
        int sum = 0;
        if (i > 0)
        {
            sum += matrix[i - 1][j];
        }
        if (i < matrix.size() - 1)
        {
            sum += matrix[i + 1][j];
        }
        if (j > 0)
        {
            sum += matrix[i][j - 1];
        }
        if (j < matrix[0].size() - 1)
        {
            sum += matrix[i][j + 1];
        }
        return sum;
    }
    int FindCoverage(vector<vector<int>> &matrix)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    sum += f(i, j, matrix);
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.FindCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends