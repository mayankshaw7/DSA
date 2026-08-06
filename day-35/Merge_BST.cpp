#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }

    ~Node()
    {
        delete left; // recursively deletes entire subtree
        delete right;
    }
};
// Function to return a list of integers denoting the node
// values of both the BST in a sorted order.
void getInorder(Node *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    getInorder(root->left, vec);
    vec.push_back(root->data);
    getInorder(root->right, vec);
}
// Node *build_bst(vector<int> &vec)
// {
//     Node *root = new Node(vec[0]);
//     int n = vec.size();
//     for (int i = 1; i < n; i++)
//     {
//         if (vec[i] < root->data)
//         {
//             root->left = new Node(vec[i]);
//         }
//         else if (vec[i] >= root->data) // or you can either write here else meaning of both the statement is same
//         {
//             root->right = new Node(vec[i]);
//         }
//     }
//     return root;
// }
Node *convert_to_bst(vector<int>&nums, int st,int end){
        if (st > end)
            return NULL;
        //reason behind where we didnt used equal to because there must be some 
        // point exist where the both  start and end are pointing to the similar
        //  object at tim,e alos we have to make a node we cant return a NULL value at tha point of time
        int mid = st + (end - st) / 2;
        Node* root = new Node(nums[mid]);
        root->left = convert_to_bst(nums, st, mid - 1);
        root->right = convert_to_bst(nums, mid + 1, end);
        return root;
    }

Node* sortedArrayToBST(vector<int>&nums) {
    int end = nums.size()- 1;
    return convert_to_bst(nums, 0, end);
}
Node* merge(Node *root1, Node *root2)
{
    // Your code here
    vector<int> node1;
    vector<int> node2;
    vector<int> merged;
    getInorder(root1, node1);
    getInorder(root2, node2);
    int i = 0;
    int j = 0;
    while (i < node1.size() && j < node2.size())
    {
        if (node1[i] <= node2[j])
        {
            merged.push_back(node1[i]);
            i++;
        }
        else
        {
            merged.push_back(node2[j]);
            j++;
        }
    }
    while (i < node1.size())
    {
        merged.push_back(node1[i]);
        i++;
    }
    while (j < node2.size())
    {
        merged.push_back(node2[j]);
        j++;
    }
   return sortedArrayToBST(merged);
}
void preorder_traversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
int main()
{
    // sub BST 1
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);
    // sub BST 2
    Node *root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);
    Node *merged=merge(root1,root2);
    preorder_traversal(merged);
    return 0;
}