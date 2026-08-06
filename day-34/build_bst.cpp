#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

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

void inorder_traversal(Node *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
// searching in BST
// time complexity is O(heigh) or O(log n ) in average
bool search_in_bst(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
    {
        cout << "Node found " << endl;
        return true;
    }
    if (root->data < key)
    {
        return search_in_bst(root->right, key);
    }
    else
    {
        return search_in_bst(root->right, key);
    }
}

void print_in_range(Node *root, int start, int end)
{
    if (root == NULL)
        return;
    if (root->data >= start && root->data <= end)
    {
        cout << root->data << " ";
        print_in_range(root->left, start, end);
        cout << root->data << " ";
        print_in_range(root->right, start, end);
    }
    else if (root->data > end)
        print_in_range(root->left, start, end);
    else
        print_in_range(root->right, start, end);
}
// if you wamt inorder traversal then print root right left
int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7};
    Node *root = build_bst(arr, 6);

    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;
    cout <<"Searching in BST \n"<<search_in_bst(root, 5) << endl;
    cout <<"Searching in BST\n"<< search_in_bst(root, 6)<<endl;


    //  delete root;  // calls destructor to free entire tree
     cout <<"Printing in range from 0 to 6\n"<<endl;
    print_in_range(root, 4, 7);
    return 0;
}
