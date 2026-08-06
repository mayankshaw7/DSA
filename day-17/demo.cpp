#include<bits/stdc++.h>
using namespace std;
class student{
        public:
    string name;

        float cgpa;
        void get_percentage(){
            cout<<(cgpa*10)<<" % \n";
        }

};
int main(){
    student s1;
    s1.name="Mayank";
    s1.cgpa=9.0;
    s1.get_percentage();
    return 0;
}