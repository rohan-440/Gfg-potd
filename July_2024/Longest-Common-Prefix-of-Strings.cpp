//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        // your code here
        sort(arr.begin(), arr.end());
        string s = "";
        string temp = arr[0];
        for (int i = 0; i < temp.size(); i++)
        {
            char ch = temp[i];
            bool flag = 1;
            for (int j = 0; j < arr.size(); j++)
            {
                if (ch != arr[j][i])
                {
                    flag &= 0;
                }
            }
            if (flag == 1)
                s.push_back(ch);
            else
                break;
        }
        if (s.size() == 0)
            return "-1";
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends