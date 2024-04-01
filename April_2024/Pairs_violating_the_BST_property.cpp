//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution
{
public:
    /*You are required to complete below function */

    vector<int> v;
    void f(Node *root)
    {
        if (root == NULL)
            return;
        f(root->left);
        v.push_back(root->data);
        f(root->right);
    }

    vector<int> bit;
    void update(int ind, int val)
    {
        for (int i = ind; i < bit.size(); i += i & (-i))
        {
            bit[i] += val;
        }
    }
    int sumFunc(int ind)
    {
        int sum = 0;
        for (int i = ind; i > 0; i -= i & (-i))
        {
            sum += bit[i];
        }
        return sum;
    }

    int pairsViolatingBST(int n, Node *root)
    {
        // your code goes here
        f(root);
        bit.resize(n + 1, 0);
        int cnt = 0;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < v.size(); i++)
        {
            pairs[i] = {v[i], i + 1};
        }
        sort(pairs.rbegin(), pairs.rend());
        for (auto x : pairs)
        {
            cnt += sumFunc(x.second - 1);
            update(x.second, 1);
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    getchar();

    while (t--)
    {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node *root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends