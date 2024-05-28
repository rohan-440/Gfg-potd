//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int f(int i, int w, vector<int> &cost, vector<vector<int>> &dp)
    {
        if (i < 0 || w < 0)
            return 1e9;
        if (w == 0)
            return 0;
        if (dp[i][w] != -1)
            return dp[i][w];

        int take = 1e9;
        if (cost[i] != -1)
        {
            take = cost[i] + f(i, w - (i + 1), cost, dp);
        }
        int notake = f(i - 1, w, cost, dp);
        return dp[i][w] = min(take, notake);
    }
    int minimumCost(int n, int w, vector<int> &cost)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        int ans = f(n - 1, w, cost, dp);
        return ans == 1e9 ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends