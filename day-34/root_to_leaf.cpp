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
// you can a;sp execute using helpere and refernece vector
vector<int>vec;
void print_path(vector<int>vec){
    int n=vec.size();
    cout<<"Path :";
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
void print_root_to_leaf(Node* root){
    if(root==NULL) return;
    vec.push_back(root->data);
    if(!root->left && !root->right){ //condition of leaf 
        print_path(vec);
        vec.pop_back();//doing for the when backtracking
        return;
    }
    if(root->left){
        print_root_to_leaf(root->left);
    }
    if(root->right){
    print_root_to_leaf(root->right);
    }
    //this step is necessary while returnign to the exact backtracking
     vec.pop_back();
}
// if you wamt inorder traversal then print root right left
int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7};
    Node *root = build_bst(arr, 6);
    print_root_to_leaf(root);
    //  delete root;  // calls destructor to free entire tree
    return 0;
}
