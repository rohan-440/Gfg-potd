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
    int ls(int i, int prev, vector<int> &a, vector<vector<int>> &dp)
    {
        if (i >= a.size())
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0;
        if (prev == -1 || abs(a[prev] - a[i]) == 1)
            take = 1 + ls(i + 1, i, a, dp);
        int notake = ls(i + 1, prev, a, dp);
        return dp[i][prev + 1] = max(take, notake);
    }
    int longestSubseq(int n, vector<int> &a)
    {
        // code here
        vector<vector<int>> dp(a.size() + 1, vector<int>(a.size() + 1, -1));
        return ls(0, -1, a, dp);
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

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends