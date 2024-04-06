//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int f(int n, int m, int a[], int b[], vector<vector<int>> &dp)
    {
        if (m < 0)
            return 0;
        if (n < 0)
            return INT_MIN;
        if (dp[n][m] != -1)
            return dp[n][m];
        int take = a[n] * b[m] + f(n - 1, m - 1, a, b, dp);
        int nottake = f(n - 1, m, a, b, dp);
        return dp[n][m] = max(take, nottake);
    }
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n - 1, m - 1, a, b, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxDotProduct(n, m, a, b) << "\n";
    }
    return 0;
}

// } Driver Code Ends