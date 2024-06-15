//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    map<int, vector<int>> mp;

    long long f(int i, int last, vector<vector<long long>> &dp)
    {
        if (i == 0)
            return 1;
        if (dp[i][last] != -1)
            return dp[i][last];
        long long ans = 0;
        for (auto x : mp[last])
        {
            ans += f(i - 1, x, dp);
        }
        return dp[i][last] = ans;
    }
    long long getCount(int n)
    {
        // Your code goes here
        mp[0] = {0, 8};
        mp[1] = {1, 2, 4};
        mp[2] = {1, 2, 3, 5};
        mp[3] = {6, 2, 3};
        mp[4] = {1, 4, 5, 7};
        mp[5] = {2, 4, 5, 6, 8};
        mp[6] = {3, 5, 6, 9};
        mp[7] = {7, 4, 8};
        mp[8] = {8, 7, 9, 0, 5};
        mp[9] = {9, 6, 8};
        long long count = 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(11, -1));
        for (int i = 0; i < 10; i++)
        {
            count += f(n - 1, i, dp);
        }
        return count;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends