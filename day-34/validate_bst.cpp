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

 bool validate_helper(Node* root,Node*min,Node* max){
        if(root==NULL) return true;
         if(min!=NULL && root->data <= min->data ) return false;
         if(max!=NULL && root->data >= max->data ) return false;

        return validate_helper(root->left,min,root) &&
            validate_helper(root->right,root,max);
    }
    bool isValidBST(Node* root) {
        if(root == NULL) return true;
        return validate_helper(root,NULL,NULL);
    }

// for handling duplicate case  we are making the range inclusive not exclusive
//         (2)
//          \
//           (2)
//             \
//              (2)
int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7};
    Node *root = build_bst(arr, 6);
    cout<<isValidBST(root);
    return 0;
}
