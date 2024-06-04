//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    10000

    */
    string binaryNextNumber(string s)
    {
        // code here.
        bool flag = false;
        string ans = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
                s[i] = '0';
            else if (s[i] == '0')
            {
                s[i] = '1';
                flag = true;
                break;
            }
        }
        if (flag == true)
            ans = s;
        else
        {
            ans = "1";
            ans += s;
            return ans;
        }
        int i = 0;
        while (s[i] == '0')
            i++;
        return ans.substr(i);
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
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends