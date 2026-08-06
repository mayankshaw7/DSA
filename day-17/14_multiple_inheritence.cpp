#include<bits/stdc++.h>
using namespace std;
class teacher{
  public:
    int salary;
    string subject;
};
class student{
  public:
    int roll_no;
    float cgpa;
};
class TA:public student, public teacher{
    string d;

};
int main(){
    TA t1;
    t1.subject="Operatinf system";
    t1.salary=150000;
    t1.roll_no=10191;
    t1.cgpa=9.1 ;
    cout<<t1.cgpa<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.roll_no<<endl;
    cout<<t1.salary<<endl;
    return 0;
}
