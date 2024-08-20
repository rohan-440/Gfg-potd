//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    int n = 0;

    int bfs(unordered_map<int, vector<int>> &adj, int target)
    {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(target);
        vis[target] = 1;
        int sec = 0;
        while (!q.empty())
        {
            int size = q.size();
            sec++;
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                for (auto x : adj[node])
                {
                    if (vis[x] == 0)
                    {
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }
        return sec - 1;
    }

    int inorder(Node *root, unordered_map<int, vector<int>> &mp)
    {
        if (root == NULL)
            return -1;
        int l = inorder(root->left, mp);
        if (l != -1)
        {
            mp[root->data].push_back(l);
            mp[l].push_back(root->data);
        }
        int r = inorder(root->right, mp);
        if (r != -1)
        {
            mp[root->data].push_back(r);
            mp[r].push_back(root->data);
        }
        n = max(n, root->data);
        return root->data;
    }
    int minTime(Node *root, int target)
    {
        // Your code goes here
        unordered_map<int, vector<int>> adj;

        inorder(root, adj);

        // for(auto x:adj){
        //     cout<<x.first<<"->";
        //     for(int i = 0 ; i < x.second.size() ; i++){
        //         cout<<x.second[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // vector<int>vis(n+1,0);

        return bfs(adj, target);
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}

// } Driver Code Ends