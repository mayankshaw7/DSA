#include<list>
#include<iostream>
#include<iterator>
using namespace std;
void printlinkedlist(list<int> ll){
        list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }cout<<"NULL"<<endl;
}
int main(){
    list<int>ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);

    cout<<"Size of Linked list is :: "<<ll.size()<<endl;
    printlinkedlist(ll);
    cout<<"Front element of ll is :: "<<ll.front()<<endl;
    cout<<"last element of ll is :: "<<ll.back();

}