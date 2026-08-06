// leetcode- 108
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
Node *convert_to_bst(int nums[], int st,int end){
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

Node* sortedArrayToBST(int nums[],int n) {
    int end = n- 1;
    return convert_to_bst(nums, 0, end);
}

void preorder_traversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// if you wamt inorder traversal then print root right left
int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    Node * root = sortedArrayToBST(arr, 7);
    preorder_traversal(root);
    return 0;
}
