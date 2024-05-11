//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int step = 0;
    int f(int i, int d)
    {
        if (i >= d)
        {
            if ((i - d) % 2 == 0)
                return step;
        }
        step++;
        return f(i + step, d);
    }
    int minSteps(int d)
    {
        // code here
        return f(0, d);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends