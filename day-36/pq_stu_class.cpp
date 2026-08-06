#include<bits\stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int marks;
    Student(string name, int marks){
        this->name=name;
        this->marks=marks;
    }
    //operator overloading 
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks; //this signifies that it is an max heap
        //return this->marks > obj.marks; //this signifies that it is an min heap
    }
};  
int main(){
    //it is an PQ of student which store s the Student objects 
    priority_queue<Student>pq;
    pq.push(Student("Chetan",56));
    pq.push(Student("Priya",90));
    pq.push(Student("Vivek",66));
    //popping and orinting the values
    while(!pq.empty()){
        cout<<"Top="<<pq.top().name <<" , "<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}