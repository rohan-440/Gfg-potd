//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    int mod = 1e9 + 7;

    long long sumSubstrings(string s)
    {

        // your code here
        vector<long long> dp(s.size(), 0);

        dp[0] = s[0] - '0';
        long long int ans = dp[0];
        for (int i = 1; i < s.size(); i++)
        {
            dp[i] = ((dp[i - 1] * 10) + ((s[i] - '0') * (i + 1)) % mod) % mod;
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking string
        string s;
        cin >> s;
        Solution ob;
        // calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
    }
    return 0;
}

// } Driver Code Ends