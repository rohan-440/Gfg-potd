//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeDups(string str)
    {
        // Your code goes here
        vector<int> fq(26, 0);
        string s = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (fq[str[i] - 'a'] == 0)
            {
                s.push_back(str[i]);
                fq[str[i] - 'a'] = fq[str[i]] + 1;
            }
        }
        return s;
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends