
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};
//basically the mistake was happening here when I was not declaring class template
//NOte: For each of the structure we need to define template <class T>
template <class T>
class Stack {
public:
    Node<T>* head;

    Stack() {
        head = NULL;
    }
//difference here we need to declare 
    //that which kind of pointer you want  
    void push(T val) {
        Node<T>* newnode = new Node<T>(val);
        newnode->next = head;
        head = newnode;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        cout << temp->data << endl;
        delete temp;
    }

    T top() {
        if (head == NULL) {
            cout << "Stack is empty\n";
            return T(); // return default value
        }
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
    //  void pushBottom(int val) {
    //     if (isEmpty()) {
    //         push(val);
    //         return;
    //     }

    //     int topElement = peek();
    //     pop();
    //     pushBottom(val);
    //     push(topElement);
    // }
    //question found in the GFG only
    void push_at_bottom(T val){
        if(isEmpty()){
            push(val);
            return ;
        }
        T temp=top();
        pop();
        push_at_bottom(val);
        push(temp);
    }
    
};

int main() {
    Stack<int> s;//declareing data type is necessary
    s.push(76);
    s.push(76);
    s.push(6);
    s.push(7);
    s.push(0);
    s.push_at_bottom(600);
    cout << "Popped element: ";
    s.pop();
    cout << "Popped element: ";
    s.pop();
    cout << "Popped element: ";
    s.pop();
    cout << "Popped element: ";
    s.pop();
    cout << "Popped element: ";
    s.pop();
    cout << "Popped element: ";
    s.pop();

    cout << "Top element: " << s.top() << endl;

    return 0;
}
