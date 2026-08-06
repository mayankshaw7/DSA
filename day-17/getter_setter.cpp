#include <bits/stdc++.h>
using namespace std;
class student
{
    string name;

    float cgpa;

public:
    void get_percentage()
    {
        cout << (cgpa * 10) << " % \n";
    }
    void setName(string Name)
    {
        name = Name;
    }
    void setCgpa(float n)
    {
        cgpa = n;
    }
    string getName(){
        return name;
    }
    float getCgpa(){
        return cgpa;
    }
};
int main()
{
    student s1;
    s1.setName("Mayank");
    s1.setCgpa(9.0);
    s1.get_percentage();
    cout<<s1.getName()<<endl;
    cout<<s1.getCgpa();
    return 0;
}