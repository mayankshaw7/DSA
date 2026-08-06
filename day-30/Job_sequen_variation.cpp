// variation is like this they might asked the index of selected jobs to be return at the output

#include <bits/stdc++.h>
using namespace std;
class Jobs
{
public:
    int idx;
    int deadline;
    int earn;
    Jobs(int idx, int deadline, int earn)
    {
        this->idx = idx;
        this->deadline = deadline;
        this->earn = earn;
    }
};
void job_squence(vector<pair<int, int>> &pair)
{
    int n = pair.size();
    vector<Jobs> job;
    for (int i = 0; i < n; i++)
    {
        job.emplace_back(i, pair[i].first, pair[i].second); // idx,deadline,earn
    }
    int profit = job[0].earn;
    cout<<"Selecting Jobs "<<job[0].idx<<endl;
    int safe_deadline = 2;
    // greedy method applies here
    sort(job.begin(), job.end(), [](Jobs &a, Jobs &b)
         { return b.earn < a.earn; });

    
    for (int i = 1; i < n; i++)
    {
        if (job[i].deadline >= safe_deadline)
        {
            profit += job[i].earn;
            safe_deadline++;
            cout<<"Selecting Jobs "<<job[i].idx;
        }
    }
    cout<<"\nMaximum Profit is "<<profit;
}
int main()
{
    vector<pair<int, int>> job = {{1, 40}, {1, 15}, {4, 20}, {1, 30}};
    job_squence(job);
    return 0;
}
// Instead of taking an already constructed object as an argument 
// (like push_back()), emplace_back() takes the arguments required 
// for the constructor of the element type. It then uses these arguments
//  to construct the new element directly within the memory allocated by the vector.
// Memory Management:
// If the vector's current capacity is insufficient to accommodate the 
// new element, emplace_back() will trigger a reallocation of memory, 
// similar to push_back(). The elements are then moved (or copied, 
// if a move constructor is not available) to the 
// new memory location, and the new element is constructed in 
// the newly allocated space