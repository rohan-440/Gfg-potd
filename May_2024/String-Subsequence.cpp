//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int mod = 1e9 + 7;
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (j == s2.size())
            return 1;
        if (i >= s1.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
        {
            return dp[i][j] = ((f(i + 1, j + 1, s1, s2, dp) % mod) + (f(i + 1, j, s1, s2, dp) % mod)) % mod;
        }
        return dp[i][j] = f(i + 1, j, s1, s2, dp) % mod;
    }
    int countWays(string s1, string s2)
    {
        // code here
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return f(0, 0, s1, s2, dp) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends