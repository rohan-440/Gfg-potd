//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    int isValid(string str)
    {
        // code here
        int num = 0;
        int dot = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '.')
            {
                dot++;
                if (num < 0 || num > 255)
                    return false;
                num = 0;
            }
            else
                num = num * 10 + (str[i] - '0');
            if (dot > 3)
                return false;
        }

        if (num < 0 || num > 255 || dot > 3)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends