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
int kth_Ancester(Node* root,int node,int k){
    //condition 1
    if(root==NULL){
        return -1;
    }
     //condition 2
    if(root->data==node){
        return 0;
    }
    //recursive check to every node
    int leftDist=kth_Ancester(root->left,node,k);
    int rightDist=kth_Ancester(root->right,node,k);
    //condition 3rd 
    if(leftDist==-1 && rightDist == -1){
        return -1;
    }
    //condition if any one the condition is false and one is true
    int valid_val=leftDist == -1 ? rightDist : leftDist;
    if(valid_val+1 == k ){
        cout<<"Kth ancester here is "<<root->data;
    }
    //returning the distance to the node 
    return valid_val+1 ;//ass discussed in the concept we will return  the path
    }

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    int idx = -1;
    Node* root = build_tree(arr, idx);

    cout<<"Enter the Kth ancester which you want"<<endl;
    int k=2,node =5;
    kth_Ancester(root,node,k);
    return 0;
}