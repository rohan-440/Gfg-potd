//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string compareFrac(string str)
    {

        // Code here
        // #include <bits/stdc++.h>
        int a = -1, b = -1, c = -1, d = -1;
        int temp = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]))
                temp = (temp * 10 + (str[i] - '0'));
            else if (str[i] == '/' || str[i] == ' ')
            {
                if (a == -1)
                    a = temp;
                else if (b == -1)
                    b = temp;
                else if (c == -1)
                    c = temp;
                else if (d == -1)
                    d = temp;
                temp = 0;
            }
        }
        if (d == -1)
        {
            d = temp;
        }
        if (a * d > c * b)
            return to_string(a) + '/' + to_string(b);
        else if (a * d < c * b)
            return to_string(c) + '/' + to_string(d);
        return "equal";
    }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends