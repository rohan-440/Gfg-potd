//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    int f(int i, long long int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        //   if(sum == 0 ) return 1;
        if (i == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2;
            if (sum == 0 || arr[0] == sum)
                return 1;
            return 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int notTake = f(i - 1, sum, arr, dp);
        int take = 0;
        if (arr[i] <= sum)
        {
            take = f(i - 1, sum - arr[i], arr, dp);
        }
        return dp[i][sum] = (notTake % mod + take % mod) % mod;
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        long long int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        if (sum - d < 0)
            return 0;
        long long int ans = (sum - d);
        if (ans % 2)
            return 0;
        return f(arr.size() - 1, ans / 2, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends