//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    char nthCharacter(string s1, int r, int n)
    {
        // code here
        string s = s1;
        for (int i = 0; i < r; i++)
        {
            string res = "";
            for (int j = 0; j <= n; j++)
            {
                if (s[j] == '0')
                {
                    res.push_back('0');
                    res.push_back('1');
                }
                else
                {
                    res.push_back('1');
                    res.push_back('0');
                }
            }
            // cout<<res<<endl;
            s = res;
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends