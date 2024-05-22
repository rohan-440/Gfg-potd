//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        // Code here
        double l = 0;
        double r = stations[stations.size() - 1];
        double ans = 1e9;
        while (r - l > 0.00001)
        {
            double mid = (l + r) / 2;
            int cnt = k;
            for (int i = 1; i < stations.size(); i++)
                cnt -= max(0, (int)(ceil)(((double)(stations[i] - stations[i - 1]) / mid)) - 1);
            if (cnt >= 0)
            {
                ans = mid;
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return ans;
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
        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends