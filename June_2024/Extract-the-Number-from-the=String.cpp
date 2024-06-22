//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isNumber(long long n)
    {
        while (n)
        {
            if (n % 10 == 9)
                return 0;
            n /= 10;
        }
        return 1;
    }
    long long ExtractNumber(string sentence)
    {

        // code here
        long long num = 0;
        long long maxi = -1;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (isdigit(sentence[i]))
            {
                num = (num * 10) + (sentence[i] - '0');
            }
            else
            {
                if (isNumber(num))
                    maxi = max(maxi, num);
                num = 0;
            }
        }
        if (maxi == 0)
            return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends