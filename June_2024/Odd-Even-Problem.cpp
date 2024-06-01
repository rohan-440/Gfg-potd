//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string oddEven(string s)
    {
        // code here
        unordered_map<char, int> mp;
        for (auto x : s)
            mp[x]++;
        int odd = 0;
        int even = 0;
        for (auto x : mp)
        {
            int count = x.second;
            if (count % 2 == 0 && int(x.first - 'a') % 2 != 0)
            {
                even++;
            }
            else if (count % 2 != 0 && int(x.first - 'a') % 2 == 0)
            {
                odd++;
            }
        }
        return (even + odd) % 2 == 0 ? "EVEN" : "ODD";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends