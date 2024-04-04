//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int min_operations(vector<int> &nums)
    {
        // Code here
        int lis = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i - j <= nums[i] - nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                lis = max(lis, dp[i]);
            }
        }
        return nums.size() - lis;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends