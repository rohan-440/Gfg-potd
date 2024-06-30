//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        // code here
        long long num = (2 * n) - q;
        num = min(num, q - 2);
        return num + 1 < 0 ? 0 : num + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;

        cin >> n >> q;

        Solution ob;
        cout << ob.sumMatrix(n, q) << endl;
    }
    return 0;
}
// } Driver Code Ends