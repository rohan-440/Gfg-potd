//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<string> v;
    void f(int n, string s)
    {
        if (n == 0)
        {
            int cnt = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
                if (cnt < 0)
                {
                    break;
                }
            }
            if (cnt >= 0)
            {
                v.push_back(s);
            }
            return;
        }
        s.push_back('0');
        f(n - 1, s);
        s.pop_back();
        s.push_back('1');
        f(n - 1, s);
        s.pop_back();
    }
    vector<string> NBitBinary(int n)
    {
        // Your code goes here
        string s = "";
        f(n, s);
        sort(v.rbegin(), v.rend());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends