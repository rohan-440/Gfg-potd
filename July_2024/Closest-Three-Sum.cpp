//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int closet = 0;
        int minDiff = INT_MAX;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            int l = i + 1;
            int r = arr.size() - 1;
            while (l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                int diff = abs(sum - target);
                if (minDiff > diff)
                {
                    minDiff = diff;
                    closet = sum;
                }
                else if (diff == minDiff) //&& sum > closet){
                {
                    closet = max(closet, sum);
                }
                if (sum == target)
                    return target;
                if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return closet;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends