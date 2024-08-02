//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (i == s.size())
            return t.size() - j;
        if (j == t.size())
            return s.size() - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = f(i + 1, j + 1, s, t, dp);
        else
        {
            int insert = 1 + f(i + 1, j, s, t, dp);
            int replace = 1 + f(i + 1, j + 1, s, t, dp);
            int del = 1 + f(i, j + 1, s, t, dp);
            return dp[i][j] = min(insert, min(del, replace));
        }
    }
    int editDistance(string str1, string str2)
    {
        // Code here
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size(), -1));
        return f(0, 0, str1, str2, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends