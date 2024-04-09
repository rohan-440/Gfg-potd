//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int f(int i, int j, vector<vector<int>> &points, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return points[i][j];
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        int down = points[i][j] + f(i + 1, j, points, m, n, dp);
        int right = points[i][j] + f(i, j + 1, points, m, n, dp);
        down = min(down, 0);
        right = min(right, 0);
        return dp[i][j] = max(down, right);
    }

public:
    int minPoints(int m, int n, vector<vector<int>> points)
    {
        // Your code goes here
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
        int x = f(0, 0, points, m, n, dp);

        return abs(x) + 1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        Solution ob;
        cout << ob.minPoints(m, n, a) << "\n";
    }
    return 0;
}

// } Driver Code Ends