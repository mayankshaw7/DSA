// leetcode- 1382
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
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *build_bst(int arr[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}
void preorder_traversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void calculate_inorder(Node *root, vector<int> &sorted)
{
    if (root == NULL)
        return;
    calculate_inorder(root->left, sorted);
    sorted.push_back(root->data);
    calculate_inorder(root->right, sorted);
}
Node *convert_to_bst(vector<int> &sorted, int st, int end)
{
    if (st > end)
        return NULL;
    // reason behind where we didnt used equal to because there must be some
    //  point exist where the both  start and end are pointing to the
    //  similar
    //   object at tim,e alos we have to make a node we cant return a NULL
    //   value at tha point of time
    int mid = st + (end - st) / 2;
    Node *root = new Node(sorted[mid]);
    root->left = convert_to_bst(sorted, st, mid - 1);
    root->right = convert_to_bst(sorted, mid + 1, end);
    return root;
}

int main()
{
    int arr[] = {4, 6, 5, 7, 6, 4, 8};
    Node *root = build_bst(arr, 7);
    vector<int> sorted;
    calculate_inorder(root, sorted);
    int end = sorted.size() - 1;
    root = convert_to_bst(sorted, 0, end);
    preorder_traversal(root);
    return 0;
}

// for  cross check 
// output of this program is 6 4 4 5 7 6 8