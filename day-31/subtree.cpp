#include <bits/stdc++.h>
using namespace std;

// ---------------- Node class ----------------
class Node {
public: 
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// ---------------- Build Tree ----------------
// preorder build: -1 means NULL
Node* build_tree(vector<int>& nodes, int &idx) {
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* curr_node = new Node(nodes[idx]);
    curr_node->left = build_tree(nodes, idx);
    curr_node->right = build_tree(nodes, idx);

    return curr_node;
}

// ---------------- Check Identical ----------------
bool is_identical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    return is_identical(root1->left, root2->left) &&
           is_identical(root1->right, root2->right);
}

// ---------------- Check Subtree ----------------
bool issubtree(Node* root, Node* subroot) {
    if (subroot == NULL) return true;   // empty tree is always subtree
    if (root == NULL) return false;

    if (root->data == subroot->data) {
        if (is_identical(root, subroot)) {
            return true;
        }
    }
    return issubtree(root->left, subroot) || issubtree(root->right, subroot);
}

// ---------------- Utility: Print inorder (for debug) ----------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------- Main ----------------
int main() {
    // Build main tree
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    int idx = -1;
    Node* root = build_tree(nodes, idx);

    // Build subtree manually
    Node* subroot = new Node(6);
    subroot->left = new Node(-1);
    subroot->right = new Node(7);

    cout << "Inorder of main tree: ";
    inorder(root);
    cout << "\nInorder of sub tree: ";
    inorder(subroot);

    cout << "\nIs subtree? " << (issubtree(root, subroot) ? "Yes" : "No") << endl;

    return 0;
}
