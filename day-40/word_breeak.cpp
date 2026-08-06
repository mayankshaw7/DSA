#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endofword;
    Node()
    {
        endofword = false;
    }
};
class Trie
{
public:
    // in order to implement memoization
    unordered_map<stirng, bool> memo;
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            // if (temp->children.count(key[i]) == 0)
            if (temp->children.find(key[i]) == temp->children.end())
            {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endofword = true;
    }
    bool search(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->endofword;
    }
    bool helper(Trie &trie, string key)
    {
        int n = key.size();
        if (n == 0)
            return true;
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }
        for (int i = 0; i < n; i++)
        {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);
            if (helper(trie, second) && trie.search(first))
            {
                return true;
            }
        }
        memo[key] = false;
        return false;
    }
};
bool wordBreak(string s, vector<string> &wordDict)
{
    Trie trie;
    for (auto it : wordDict)
    {
        trie.insert(it);
    }
    return trie.helper(trie, s);
}
int main()
{
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout << wordBreak("abgeds", dict) << endl;
    cout << wordBreak("i", dict) << endl;
    cout << wordBreak("SAM", dict) << endl; // since it is case sensitive t
    cout << wordBreak("samsung", dict) << endl;
    return 0;
}
