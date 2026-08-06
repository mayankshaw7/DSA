#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        this->data = x;
        left = right = NULL;
    }
};

// build tree from preorder with -1 as NULL marker
Node* build_tree(vector<int>& arr, int &idx) {
    idx++;
    if (arr[idx] == -1) {
        return NULL;
    }
    Node* curr_node = new Node(arr[idx]);
    curr_node->left = build_tree(arr, idx);
    curr_node->right = build_tree(arr, idx);
    return curr_node;
}

Node* LCA(Node* root,int p,int q){
    if(root==NULL || root->data==p || root->data==q){
        return root;
    }
    Node* left= LCA(root->left,p,q);
    Node* right= LCA(root->right,p,q);
    if(!left){
        return right;
    }
    else if(!right){
        return left;
    }else {
        return root;
    }
}
int dist(Node* root,int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftdist= dist(root->left,n);
    if(leftdist!=-1){
        return leftdist+1;
    }
    int rightdist= dist(root->right,n);
        if(rightdist!=-1){
        return rightdist+1;
    }
    return -1;
}
int minmun_distance_two_node(Node* root,int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    
    int dist1=dist(lca ,n1);
    int dist2=dist(lca ,n2);
    return  dist1 + dist2;
}
int main() {
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    int p, q;
    cout<<"Enter p: ";
    cin >> p;
    cout<<"Enter q: ";
    cin >> q;

    int idx = -1;
    Node* root = build_tree(arr, idx);

    Node* ans = LCA(root, p, q);
    if(ans) cout << "LCA: " << ans->data << endl;
    else cout << "LCA not found" << endl;

    int res=minmun_distance_two_node(root,p,q);
    cout<<"\nMinimum distance between two nodes is "<<res;
    return 0;
}
