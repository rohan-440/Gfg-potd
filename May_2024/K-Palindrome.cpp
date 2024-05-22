//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int lcs(int i, int j, string &s, string &r, vector<vector<int>> &dp)
    {
        if (i >= s.size() || j >= r.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int len = 0;
        if (s[i] == r[j])
        {
            len = 1 + lcs(i + 1, j + 1, s, r, dp);
        }
        else
        {
            len = max(lcs(i + 1, j, s, r, dp), lcs(i, j + 1, s, r, dp));
        }
        return dp[i][j] = len;
    }
    int kPalindrome(string s, int n, int k)
    {
        // code here
        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int LCS = lcs(0, 0, s, r, dp);
        return n - LCS <= k ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        Solution ob;
        cout << ob.kPalindrome(str, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends