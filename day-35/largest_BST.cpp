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

class Info
{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz)
    {
        this->isBST = isBST;
        this->max = max;
        this->min = min;
        this->sz = sz;
    } // we will be returning the pointer to the abjects
};
// No need to declare its value
static int max_size;
// making functin which will going to return the infomation
Info *largest_BST(Node *root)
{
    // base case -Condition -01
    if (root == NULL)
        return new Info(true, INT_MAX, INT_MIN, 0);
    //base case condition -02
    // if(root==NULL) return NULL;
    // if(root->left ==NULL && root->right==NULL){
    //     return new Info(true,root->data,root->data,1);
    // }
    Info *leftInfo = largest_BST(root->left);
    Info *rightinfo = largest_BST(root->right);
    int curr_min = min(root->data, min(leftInfo->min, rightinfo->min));
    int curr_max = max(root->data, max(leftInfo->max, rightinfo->max));
    int curr_size = leftInfo->sz + rightinfo->sz + 1;

    // Now we will be checking condition for the Valid BST
    if (leftInfo->isBST && rightinfo->isBST &&
        leftInfo->max < root->data &&
        rightinfo->min > root->data)
    {
        max_size = max(max_size, curr_size);
        return new Info(true, curr_min, curr_max, curr_size);
    }
    // In case of an invalid BST it will return below thing
    return new Info(false, curr_min, curr_max, curr_size);
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    root->right->right->left = new Node(65);
    largest_BST(root);
    cout<<"Maximum size of the largest BST ::-->" <<max_size;
    return 0;
}
