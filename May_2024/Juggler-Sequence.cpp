//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> jugglerSequence(int n)
    {
        // code here
        vector<int> v;
        while (n != 1)
        {
            v.push_back(n);
            if (n % 2 == 0)
            {
                n = pow(n, 0.5);
            }
            else
            {
                n = pow(n, 1.5);
            }
        }
        v.push_back(1);
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
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends