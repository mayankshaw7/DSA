#include <iostream>
using namespace std;
//mistake was happening in the run that the destructor was called 
//over and over again throught which problem was occuring
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Destructor called  " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    } // as
};
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
    // ~Listt()
    // {
    //     cout << "\nDestructor called for list \n";
    //     if (head != NULL)
    //     {
    //         delete head;
    //         head = NULL;
    //     }
    // }
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
// su functino for the merge sort spliting the LL in two halfs
Node *split_at_mid(Node *temp)
{
    Node *slow = temp;
    Node *fast = temp;
    Node *prev = NULL;
    bool isCYCLE = false;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}
Node *merge(Node *left, Node *right)
{
    Node *i = left;
    Node *j = right;
    Listt ans;
    while (i != NULL && j != NULL)
    {
        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    // if element left in left subarray
    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }
    // if element left in right subarray
    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;//also can you dummy node
}
Node *merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *left_head = head;
    Node *right_head = split_at_mid(head);
    Node *left = merge_sort(left_head);
    Node *right = merge_sort(right_head);
    return merge(left, right); // head of sorted ll
}

int main()
{
    Listt n1;
    n1.push_back(4);
    n1.push_back(3);
    n1.push_back(2);
    n1.push_back(1);

    n1.print();
    n1.head = merge_sort(n1.head); // Corrected call
    n1.print();

    return 0;
}