//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countPairs(int arr[], int n)
    {
        // Your code goes here
        int count = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(i * arr[i]);
        vector<int> temp = v;
        sort(temp.begin(), temp.end());
        for (int i = n - 1; i >= 0; i--)
        {
            int h = upper_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            int l = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            count += (temp.size() - h);
            temp.erase(temp.begin() + l);
        }
        return count;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countPairs(a, n) << endl;
    }
}
// } Driver Code Ends