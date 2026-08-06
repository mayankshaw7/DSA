#include<bits/stdc++.h>
using namespace std;
class Node{
public: 
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
static int idx=-1;
Node* build_tree(vector<int>&nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* curr_node=new Node(nodes[idx]);
    curr_node->left=build_tree(nodes);
    curr_node->right=build_tree(nodes);

    return curr_node;
}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void In_order(Node* root){
    if(root==NULL){
        return ;
    }
    In_order(root->left);
    cout<<root->data<<" ";
    In_order(root->right);
}
void post_order(Node* root){
    if(root==NULL){
        return ;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}
void level_order(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
int height_of_tree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_ht=height_of_tree(root->left);
    int right_ht=height_of_tree(root->right);
    int curr_height=max(left_ht,right_ht)+1;
    return curr_height;
}

int count_no_of_nodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_cnt=count_no_of_nodes(root->left);
    int right_cntt=count_no_of_nodes(root->right);
    return left_cnt + right_cntt + 1;
}

int sum_of_nodes(Node* root){
 if(root==NULL){
        return 0;
    }
    int left_sum=sum_of_nodes(root->left);
    int right_sum=sum_of_nodes(root->right);
    return left_sum+right_sum+root->data;
}
int diameter_fo_tree(Node* root,int &diameter){
    if(root==NULL){
        return 0;
    }
    int left_ht=diameter_fo_tree(root->left,diameter);
    int right_ht=diameter_fo_tree(root->right,diameter);
    diameter=max(diameter,left_ht+right_ht);
    return  1+ max(left_ht,right_ht);

}
int main(){
    // vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int>nodes={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=build_tree(nodes);
    // cout<<"Data of root "<< root->data;
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal : ";
    In_order(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    post_order(root);
    cout<<endl;
    cout<<"Level Order Traversal : ";
    level_order(root);
    cout<<"Height of a tree is "<<height_of_tree(root)<<endl;
    cout<<"Number  of a nodes avaliable in tree is "<<count_no_of_nodes(root)<<endl;

    cout<<" Sum of all the node's value is "<<sum_of_nodes(root);
    int diameter=0;
    diameter_fo_tree(root,diameter);
    cout<<"\nDiameter of a tree is :"<<diameter;
    Node* root2=new Node(4);
    root->left=new Node(3);
    root->right=new Node(43);
    cout<<"\nNumber  of a nodes avaliable in 2nd tree is "<<count_no_of_nodes(root)<<endl;
    //experiment on the second tree


    
    cout<<"-------------------------"<<endl;
    return 0;
}