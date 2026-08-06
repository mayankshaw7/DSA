#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        this->next=NULL;

    }
    ~Node(){
     cout << "Destructor called  " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    } // as 
};
class Listt{
    public:
    Node* head;
    Node* tail;
    Listt(){
    head=NULL;
    tail=NULL;
    }
    ~Listt(){
        cout<<"Destructor called for list \n";
        if(head!=NULL){
            delete head;
            head=NULL;
        }
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
    void reverse_LinkedList(){
        Node* current=head;
        Node* previous=NULL;
        Node* nextt=head;
        while(current!=NULL){
            nextt=current->next;
            current->next=previous;
            previous=current;
            current=nextt;
        }
        head=previous;
    }
    
};
int main(){
    Listt n1;
    n1.push_back(34);
    n1.push_back(346);
    n1.push_back(6);
    n1.push_back(45);
    n1.print();
    n1.reverse_LinkedList();
    Node* newnode=new Node(65);
    n1.print();

    return 0;
}