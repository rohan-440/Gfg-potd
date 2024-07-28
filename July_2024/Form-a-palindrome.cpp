//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int lcs(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return 1 + lcs(i - 1, j - 1, s, t, dp);
        return dp[i][j] = max(lcs(i - 1, j, s, t, dp), lcs(i, j - 1, s, t, dp));
    }
    int countMin(string s)
    {
        // complete the function here
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        int len = lcs(s.size() - 1, t.size() - 1, s, t, dp);
        return s.size() - len;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}

// } Driver Code Ends