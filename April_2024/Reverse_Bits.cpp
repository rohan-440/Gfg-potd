//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        vector<int> v(32, 0);
        int j = 31;
        while (x > 0 && j >= 0)
        {
            v[j] = x & 1;
            j--;
            x >>= 1;
        }
        long long ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
                ans += pow(2, i) * v[i];
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
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends