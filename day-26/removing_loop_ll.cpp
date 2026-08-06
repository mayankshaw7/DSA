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
    void reverse_LinkedList(Node* head){
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

    void remove_loop(Node* temp){
        Node* slow=temp;
        Node* fast=temp;
        bool isCYCLE=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"Cycle exist\n";
                isCYCLE=true;
                break;
            }
        }
        if(!isCYCLE){
            cout<<"CYCle doesn't exist\n";
            return;
        }
        //special case if the head and the slow pointer is pointing to the same node
         //in nushell tail is connected with the head
        slow=head;
        if(slow==fast){
            while(fast->next!= slow){
                fast=fast->next;

            }fast->next=NULL;
        }else{ //for all the normal cases we can approach to onne point of end
            Node* prev=NULL;
            while(slow!=fast){
                slow=slow->next;
                prev=fast; 
                fast=fast->next; //moving both with one step in order to remove cycle from the loop
            }
            prev->next=NULL;
        }
        // Note - removingcycle traverse all slow and fast with 1st step
        cout<<"Cycle removed";
    }
};
int main(){
    Listt n1;
    n1.push_back(1);
    n1.push_back(2);
    n1.push_back(3);
    n1.push_back(4);
    n1.tail->next=n1.head;
    n1.remove_loop(n1.head);
    n1.print();
    // n1.reverse_LinkedList();
    // n1.print();

    return 0;
}