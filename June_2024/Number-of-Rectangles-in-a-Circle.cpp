//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        // code here
        int d = 2 * r;
        int num = 0;
        for (int a = 1; a < 2 * r; a++)
        {
            for (int b = 1; b < 2 * r; b++)
            {
                if (pow(a, 2) + pow(b, 2) <= pow(d, 2))
                    num++;
            }
        }
        return num;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends