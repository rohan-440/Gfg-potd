//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool kPangram(string str, int k)
    {
        // code here
        unordered_map<char, int> mp;
        int len = 0;
        for (auto x : str)
        {
            if (x != ' ')
            {
                mp[x]++;
                len++;
            }
        }
        if (len < 26)
            return false;
        if (mp.size() == 26)
            return true;
        if (26 - mp.size() <= k)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends