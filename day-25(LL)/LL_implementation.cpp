#include <bits/stdc++.h>
using namespace std;
// Creating a Node structure
class Node
{

public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        cout << "Destructor called  " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    } // as sson as the mainfunctionend our list will get delelte simultanuously
};
// creating a class list
class Listt
{
public:
    Node *head;
    Node *tail;
    Listt()
    {
        head = NULL;
        tail = NULL;
    }
    ~Listt()
    { // calling destructor
        cout << "destructorcalledfor list\n";
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
    void push_front(int val)
    {
        Node *newnode = new Node(val); // dynamic memory allocation
        // Node* newnode(val);//static allocation after the program ends it memory get freed up
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        //   print(head);
    }
    void push_back(int val)
    {
        Node *newnode = new Node(val); // dynamic memory allocation
        // Node* newnode(val);//static allocation after the program ends it memory get freed up
        if (head == NULL && tail == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        // print(head);
    }

    void Insert_at_position(int pos, int val)
    {
        Node *current = head;
        Node *previuos = NULL;
        if (current == NULL)
        {
            return;
        }
        int cnt = 1;
        while (cnt < pos)
        {
            previuos = current;
            current = current->next;
            cnt++;
        }
        Node *newNode = new Node(val);

        newNode->next = current;
        previuos->next = newNode;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LL is empty ";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (tail == NULL)
        {
            cout << "List is empty ";
        }
        Node *temp = head;
        // while(temp->next->next!=NULL) //if no tial is given
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    // searching in iterative method
    int searchItr(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp->next != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }
    //this fucntion is made becuase we need to 
    //find the key using recursive function with the use of helper
    int helper(Node *temp, int key)
    {
        if (temp == NULL)
        {
            return -1;
        }
        if (temp->data == key)
        {
            return 0;
        }
        int idx = helper(temp->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }
    int search_recursively(int key)
    {
        return helper(head, key);
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main()
{
    Listt ll;
    ll.push_front(10);
    cout << endl;
    ll.push_front(20);
    cout << endl;
    ll.push_front(30);
    cout << endl;

    ll.push_back(40);
    ll.push_back(50);
    ll.Insert_at_position(3, 100);
    ll.print();
    ll.pop_back();
    cout << endl;
    ll.pop_front();
    cout << endl;
    ll.print();
    cout << ll.searchItr(20) << endl;
    cout << ll.searchItr(100) << endl;
    cout << "<<<<<<<<<";
    cout << ll.search_recursively(100) << endl;

    return 0;
}