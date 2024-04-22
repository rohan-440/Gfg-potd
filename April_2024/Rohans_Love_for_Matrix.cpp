//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int mod = 1e9 + 7;
    // int f(int n,vector<int> &dp){
    //     if(n == 1 || n == 2) return 1;
    //     if(n < 1) return 0;
    //     return ((f(n-1,dp) % mod) + (f(n-2,dp)% mod))%mod;

    // }
    int firstElement(int n)
    {
        // code here
        vector<int> dp(n + 10, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; i++)
        {
            dp[i] = ((dp[i - 1] % mod) + (dp[i - 2] % mod)) % mod;
        }

        return dp[n - 1] % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends