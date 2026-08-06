#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
class Stack
{
public:
    vector<T> st;

    bool isEmpty()
    {
        return st.empty();
    }

    void push(T val)
    {
        st.push_back(val);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        T value = st.back();
        st.pop_back();
        cout << "Popped element: " << value << endl;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T(); // Return default value of T
        }
        return st.back();
    }
};

int main()
{
    Stack<char> s; // specify type

    s.push('a');
    s.push('b');
    cout << "Top: " << s.top() << endl;
 s.top();
    s.pop();
    s.pop();
    s.pop(); // will print "Stack is empty"
    s.top();
    return 0;
}
