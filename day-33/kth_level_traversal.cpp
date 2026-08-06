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
Node* build_tree(vector<int>& nodes, int &idx) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node* curr_node = new Node(nodes[idx]);
    curr_node->left = build_tree(nodes, idx);
    curr_node->right = build_tree(nodes, idx);
    return curr_node;
}

vector<int> ans;
void kth_traversal(Node* root, int level, int k) {
    if (root == NULL) return;
    if (k == level) {
        ans.push_back(root->data);
    }
    kth_traversal(root->left, level + 1, k);
    kth_traversal(root->right, level + 1, k);
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    cout << "Enter the Kth level to search the element: ";
    int k;
    cin >> k;

    int idx = -1;
    Node* root = build_tree(nodes, idx);

    // If you want 1-based level: kth_traversal(root,1,k);
    kth_traversal(root, 0, k);

    cout << "Nodes at level " << k << ": ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
