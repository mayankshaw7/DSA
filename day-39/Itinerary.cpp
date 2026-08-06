#include<bits\stdc++.h>
using namespace std;

void path(unordered_map<string,string> tickets){
    //starting point
    unordered_set<string>to;
    for(pair<string,string> ticket:tickets)
        to.insert(ticket.second);

    string start="";
    for(pair<string,string> ticket:tickets) {  //ticket .first -->from 
        if(to.find(ticket.first)==to.end()){
            start=ticket.first;//got the starting piint
            break;
        }
    }
    cout<< start <<"--> ";
    //plain printing 
    while(tickets.count(start)){
        cout<<tickets[start]<<"-->";
        start=tickets[start];
    }
    cout<<"Destination";
}
int main(){
    unordered_map<string,string>tickets;
    tickets["Chennai"]="Benguluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Goa";
    path(tickets);  
    return 0;
}