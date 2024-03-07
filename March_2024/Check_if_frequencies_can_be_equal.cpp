//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool sameFreq(string s)
    {
        // code here
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i] - 'a']++;
        }
        int mini = 1e9;
        for (auto x : mp)
        {
            // cout<<x.first<<"->"<<x.second<<endl;
            mini = min(mini, x.second);
        }
        int cnt = 0;
        for (auto x : mp)
        {
            if (x.second == mini)
                continue;
            else if (x.second - 1 == mini)
            {
                cnt++;
                continue;
            }
            else
                return 0;
        }
        if (cnt > 1)
            return 0;
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.sameFreq(s) << endl;
    }
}

// } Driver Code Ends