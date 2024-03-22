//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> Series(int n)
    {
        // Code here
        int mod = 1e9 + 7;
        vector<int> v;
        int a = 0;
        v.push_back(a);
        int b = 1;

        for (int i = 0; i < n; i++)
        {
            int c = ((a % mod) + (b % mod)) % mod;
            v.push_back(c);
            b = a;
            a = c;
        }
        return v;
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends