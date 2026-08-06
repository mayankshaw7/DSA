#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*>children;
    bool endofword;
    Node(){
        endofword=false;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }
    bool search(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endofword;
    }
};

int main(){
    vector<string>words={"Their","The","a","Their","any","Thee"};
    Trie trie;
    
    // Corrected loop header: added 'i++'
    for(int i=0; i < words.size(); i++){
        trie.insert(words[i]);
    }
    
    cout << trie.search("Their") << " found"; // Output: 1 found
    return 0;
}
