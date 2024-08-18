//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    sum-curr= sum/2
    sum - sum/2 = arr[i]
    sum/2 = arr[i]
    sum = 2 * arr[i]
    */
    bool canSplit(vector<int> &arr)
    {
        // code here
        long long int sum = accumulate(arr.begin(), arr.end(), 0);
        long long int curr = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            curr += arr[i];
            if (2 * (sum - curr) == sum)
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp)
        {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends