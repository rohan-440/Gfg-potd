//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {
        if (nums.size() == 1)
            return {1};
        vector<long long int> preMul;
        vector<long long int> sufMul;
        preMul.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            preMul.push_back(preMul.back() * nums[i]);
        }
        sufMul.push_back(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            sufMul.push_back(sufMul.back() * nums[i]);
        }
        reverse(sufMul.begin(), sufMul.end());
        vector<long long int> v;
        v.push_back(sufMul[1]);
        for (int i = 1; i < nums.size() - 1; i++)
        {
            v.push_back(preMul[i - 1] * sufMul[i + 1]);
        }
        v.push_back(preMul[nums.size() - 2]);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends