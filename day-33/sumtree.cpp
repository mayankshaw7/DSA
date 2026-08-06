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

void level_order_traversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // number of nodes at current level
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl; // new line after each level
    }
}

//fucntion the tree sum //o(n)
int transform_to_sum_tree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_old=transform_to_sum_tree(root->left);
    int right_old=transform_to_sum_tree(root->right);
    int current_old=root->data;

    // root->data= left_old + right_old + root->left->data+root->right->data;
    //we need to check where node exist or not
    root->data= left_old + right_old; +root->right->data;

    //check left
    if(root->left!= nullptr){
        root->data+= root->left->data;
    }
    if(root->right!= nullptr){
        root->data+= root->right->data;
    }

    return current_old;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    int idx = -1;
    Node* root = build_tree(arr, idx);
    level_order_traversal(root);
    transform_to_sum_tree(root);
    level_order_traversal(root);
    return 0;
}