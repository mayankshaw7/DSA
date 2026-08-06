#include<bits\stdc++.h>
using namespace std;
class Heap{
    vector<int>vec; //CBT
    public:
    void push(int val){
        vec.push_back(val);
        int child_idx=vec.size()-1;
        int parent_idx=(child_idx-1)/2;
        while(parent_idx>=0 && vec[child_idx]>vec[parent_idx]){ //log(n) in worst case it may run
        // while(parent_idx>=0 && vec[child_idx]<vec[parent_idx]){// for converting the max hrap to min heap
            swap(vec[child_idx],vec[parent_idx]);
            child_idx=parent_idx;
            parent_idx=(child_idx-1)/2;
        }
    } 
void heapify(int parent_idx) {
    int n = vec.size();
    int largest = parent_idx;
    int left = 2 * parent_idx + 1;  // Index of left child
    int right = 2 * parent_idx + 2; // Index of right child

    // Check if the left child exists and is greater than the parent
    if (left < n && vec[left] > vec[largest]) {
        largest = left;
    }
    
    // Check if the right child exists and is greater than the largest found so far
    if (right < n && vec[right] > vec[largest]) {
        largest = right;
    }

    // If the largest is not the parent, swap and continue heapifying
    if (largest != parent_idx) {
        swap(vec[parent_idx], vec[largest]);
        heapify(largest); // Recursive call to heapify the affected subtree
    }
}

    void pop(){
        int last_idx=vec.size()-1;
        //step 1
        swap(vec[0],vec[last_idx]);
        //step2
        vec.pop_back();
        //step 3 calling the heapify function
        heapify(0);
    } 
    int top(){
        cout<<"TOP element is "<<vec[0]<<endl;
    }
    bool empty(){
        if(vec.empty()) return true;
        else return false;
    }
    
};
int main(){
    Heap h;
    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);
    while(!h.empty()){
        h.top();
        h.pop();
    }
    return 0;
 }